/*
ShaderGlass shader subframe-bfi/shaders\crt-beam-simulator imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/subframe-bfi/shaders/crt-beam-simulator.slang
See original file for full credits and usage license with excerpts below. 
This file is auto-generated, do not modify directly.

*******************************************************************************************************************
//
//                     Blur Busters CRT Beam Simulator BFI
//                       With Seamless Gamma Correction
//
//         From Blur Busters Area 51 Display Science, Research & Engineering
//                      https://www.blurbusters.com/area51
//
//             The World's First Realtime Blur-Reducing CRT Simulator
//       Best for 60fps on 240-480Hz+ Displays, Still Works on 120Hz+ Displays
//                 Original Version 2022. Publicly Released 2024.
//
// CREDIT: Teamwork of Mark Rejhon @BlurBusters & Timothy Lottes @NOTimothyLottes
// Gamma corrected CRT simulator in a shader using clever formula-by-scanline trick
// (easily can generate LUTs, for other workflows like FPGAs or Javascript)
// - @NOTimothyLottes provided the algorithm for per-pixel BFI (Variable MPRT, higher MPRT for bright pixels)
// - @BlurBusters provided the algorithm for the CRT electron beam (2022, publicly released for first time)
//
// Contact Blur Busters for help integrating this in your product (emulator, fpga, filter, display firmware, video processor)
//
// This new algorithm has multiple breakthroughs:
//
// - Seamless; no banding*!  (*Monitor/OS configuration: SDR=on, HDR=off, ABL=off, APL=off, gamma=2.4)
// - Phosphor fadebehind simulation in rolling scan.
// - Works on LCDs and OLEDs.
// - Variable per-pixel MPRT. Spreads brighter pixels over more refresh cycles than dimmer pixels.
// - No image retention on LCDs or OLEDs.
// - No integer divisor requirement. Recommended but not necessary (e.g. 60fps 144Hz works!)
// - Gain adjustment (less motion blur at lower gain values, by trading off brightness)
// - Realtime (for retro & emulator uses) and slo-mo modes (educational)
// - Great for softer 60Hz motion blur reduction, less eyestrain than classic 60Hz BFI/strobe.
// - Algorithm can be ported to shader and/or emulator and/or FPGA and/or display firmware.
//
// For best real time CRT realism:
//
// - Reasonably fast performing GPU (many integrated GPUs are unable to keep up)
// - Fastest GtG pixel response (A settings-modified OLED looks good with this algorithm)
// - As much Hz per CRT Hz! (960Hz better than 480Hz better than 240Hz)
// - Integer divisors are still better (just not mandatory)
// - Brightest SDR display with linear response (no ABL, no APL), as HDR boost adds banding
//     (unless you can modify the firmware to make it linear brightness during a rolling scan)
//
// *** IMPORTANT ***
// *** DISPLAY REQUIREMENTS ***
//
// - Best for gaming LCD or OLED monitors with fast pixel response.
// - More Hz per simulated CRT Hz is better (240Hz, 480Hz simulates 60Hz tubes more accurately than 120Hz).
// - OLED (SDR mode) looks better than LCD, but still works on LCD
// - May have minor banding with very slow GtG, asymmetric-GtG (VA LCDs), or excessively-overdriven.
// - Designed for sample & hold displays with excess refresh rate (LCDs and OLEDs);
//     Not intended for use with strobed or impulsed displays. Please turn off your displays' BFI/strobing.
//     This is because we need 100% software control of the flicker algorithm to simulate a CRT beam.
//
// SDR MODE RECOMMENDED FOR NOW (Due to predictable gamma compensation math)
//
// - Best results occur on display configured to standard SDR gamma curve and ABL/APL disabled to go 100% bandfree
// - Please set your display gamma to 2.2 or 2.4, turn off ABL/APL in display settings, and set your OLED to SDR mode.
// - Will NOT work well with some FALD and MiniLED due to backlight lagbehind effects.
// - Need future API access to OLED ABL/ABL algorithm to compensate for OLED ABL/APL windowing interference with algorithm.
// - This code is heavily commented because of the complexity of the algorithm.
//
*******************************************************************************************************************
//
// MIT License
//
// Copyright 2024 Mark Rejhon (@BlurBusters) & Timothy Lottes (@NOTimothyLottes)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
*******************************************************************************************************************
//------------------ Constants migrated to runtime params --------------------//
// Brightness-vs-motionblur tradeoff for bright pixel.
//   - Defacto simulates fast/slow phosphor.
//   - 1.0 is unchanged brightness (same as non-CRT, but no blur reduction for brightest pixels, only for dimmer pixels).
//   - 0.5 is half brightness spread over fewer frames (creates lower MPRT persistence for darker pixels).
//   - ~0.7 recommended for 240Hz+, ~0.5 recommended for 120Hz due to limited inHz:outHz ratio.
// Your display's gamma value. Necessary to prevent horizontal-bands artifacts.
// Reduced frame rate mode
//   - This can be helpful to see individual CRT-simulated frames better (educational!)
//   - 1.0 is framerate=Hz, 0.5 is framerate being half of Hz, 0.1 is framerate being 10% of real Hz.
//^^ Slow down or speed up the simulation
//----------------------------------------------------------------------------//
//-----------------------Shadertoy Compatibility Macros-----------------------//
// We include these definitions to assist other environments (untested)
//uniform float     iTimeDelta;            // render time (in seconds)
//uniform float     iChannelTime[4];       // channel playback time (in seconds)
//uniform vec3      iChannelResolution[4]; // channel resolution (in pixels)
//uniform vec4      iMouse;                // mouse pixel coords. xy: current (if MLB down), zw: click
//uniform sampler2D iChannel1;             // input channel 1
//uniform sampler2D iChannel2;             // input channel 2
//uniform sampler2D iChannel3;             // input channel 3
//uniform vec4      iDate;                 // (year, month, day, time in seconds)
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------
// Constants Definitions
// Play with the documented constants!
// - REALTIME: Use FRAMES_PER_HZ=4 for 240Hz and FRAMES_PER_HZ=8 for 480Hz, to simulate a 60Hz tube in realtime
// - SLOMO: Use crazy large FRAMES_PER_HZ numbers to watch a CRT tube like a slo-motion video. Try FRAMES_PER_HZ=100!
// - FRAMESTEP: Use low frame rates to inspect frames.  Try FRAMES_PER_HZ=8 and FPS_DIVISOR=0.02!
// All are floats (keep a .0 for integers)
// Ratio of native Hz per CRT Hz.  More native Hz per CRT Hz simulates CRT better.
//   - Use 4.0 for 60fps at 240Hz realtime.
//   - Use 2.4 for 60fps at 144Hz realtime.
//   - Use 2.75 for 60fps at 165Hz realtime.
//   - Use ~100 for super-slo-motion.
//   - Best to keep it integer divisor but not essential (works!)
//^^automating this to work with whatever the user's subframe setting is
// Splitscreen versus mode for comparing to non-CRT-simulated
// LCD SAVER SYSTEM
//   - Prevents image retention from BFI interfering with LCD voltage polarity inversion algorithm
//   - When LCD_ANTI_RETENTION is enabled:
//     - Automatically prevents FRAMES_PER_HZ from remaining an even integer by conditionally adding a slew float.
//     - FRAMES_PER_HZ 2 becomes 2.001, 4 becomes 4.001, and 6 becomes 6.001, etc.
//     - Scientific Reason: https://forums.blurbusters.com/viewtopic.php?t=7539 BFI interaction with LCD voltage polarity inversion
//     - Known Side effect: You've decoupled the CRT simulators' own VSYNC from the real displays' VSYNC.  But magically, there's no tearing artifacts :-)
//     - Not needed for OLEDs, safe to turn off, but should be ON by default to be foolproof.
//#define LCD_ANTI_RETENTION  true
//^^moved to runtime parameter
//#define LCD_INVERSION_COMPENSATION_SLEW 0.001
//^^moved to runtime parameter
// CRT SCAN DIRECTION. Can be useful to counteract an OS rotation of your display
//   - 1 default (top to bottom), recommended
//   - 2 reverse (bottom to top)
//   - 3 portrait (left to right)
//   - 4 reverse portrait (right to left)
//^^ compensate for RetroArch's weird approach to origin by reversing the scan
//-------------------------------------------------------------------------------------------------
// Utility Macros
// Selection Function: Returns 'b' if 'p' is true, else 'a'.
// LCD SAVER (prevent image retention)
// Adds a slew to FRAMES_PER_HZ when ANTI_RETENTION is enabled and FRAMES_PER_HZ is an exact even integer.
// We support non-integer FRAMES_PER_HZ, so this is a magically convenient solution
//-------------------------------------------------------------------------------------------------
// sRGB Encoding and Decoding Functions, to gamma correct/uncorrect
// Encode linear color to sRGB. (applies gamma curve)
// Decode sRGB color to linear. (undoes gamma curve)
//------------------------------------------------------------------------------------------------
// Gets pixel from the unprocessed framebuffer.
//
// Placeholder for accessing the 3 trailing unprocessed frames (for simulating CRT on)
//   - Frame counter represents simulated CRT refresh cycle number.
//   - Always assign numbers to your refresh cycles. For reliability, keep a 3 frame trailing buffer.
//   - We index by frame counter because it is necessary for blending adjacent CRT refresh cycles,
//      for the phosphor fade algorithm on old frame at bottom, and new frames at top.
//   - Framebuffer to retrieve from should be unscaled (e.g. original game resolution or emulator resolution).
//   - (If you do optional additional processing such as scaling+scanlines+masks, do it post-processing after this stage)
// DEMO version:
//   - We cheat by horizontally shifting shifted pixel reads from a texture.
// PRODUCTION version:
//   - Put your own code to retrieve a pixel from your series of unprocessed frame buffers.
//     IMPORTANT: For integration into firmware/software/emulators/games, this must be executed
//     at refresh cycle granularity independently of your underlying games' framerate!
//     There are three independent frequencies involved:
//     - Native Hz (your actual physical display)
//     - Simulated CRT Hz (Hz of simulated CRT tube)
//     - Underlying content frame rate (this shader doesn't need to know; TODO: Unless you plan to simulate VRR-CRT)
//
// We simulate missing framebuffers (for accurate real world case)
// Continuous horizontal shift depending on hzCounter
//^^disabling this since we'll be providing our own blurry motion :)
// We'll offset uv.x by baseShift, and round-off to screen coordinates to avoid seam artifacts
// Sample texture with no mip (textureLod)
//-------------------------------------------------------------------------------------------------
// CRT Rolling Scan Simulation With Phosphor Fade + Brightness Redistributor Algorithm
//
// New variable 'per-pixel MPRT' algorithm that mimics CRT phosphor decay too.
// - We emit as many photons as possible as early as possible, and if we can't emit it all (e.g. RGB 255)
//   then we continue emitting in the next refresh cycle until we've hit our target (gamma-compensated).
// - This is a clever trick to keep CRT simulation brighter but still benefit motion clarity of most colors.
//   Besides, real CRT tubes behave roughly similar too! (overexcited phosphor take longer to decay)
// - This also concurrently produces a phosphor-fade style behavior.
// - Win-win!
//
// Parameters:
// - c2: total brightness * framesPerHz per channel.
// - crtRasterPos: normalized raster position [0..1] representing current scan line
// - phaseOffset: fractional start of the brightness interval [0..1] (0.0 at top, 1.0 at bottom).
// - framesPerHz: Number of frames per Hz. (Does not have to be integer divisible!)
//
// Get pixels from three consecutive refresh cycles
// Compute "photon budgets" for all three cycles
// Process each color channel independently
// Get brightness lengths for all three cycles
// TODO: Optimize to use only 2 frames.
// Unfortunately I need all 3 right now because if I only do 2,
// I get artifacts at either top OR bottom edge (can't eliminate both)
// What I may do is use a phase offset (e.g. input framebuffer chain
// rotates forward in middle of emulated CRT Hz), as a workaround, and
// see if that solves the problem and reduces the queue to 2.
// (Will attempt later)
// Convert normalized values to frame space
// Define intervals for all three trailing refresh cycles
// Calculate overlaps for all three cycles
// Sum all overlaps for final brightness
// disable the effect if we don't have any subframes
// uv: Normalized coordinates ranging from (0,0) at the bottom-left to (1,1) at the top-right.
//-------------------------------------------------------------------------------------------------
// CRT beam calculations
// Frame counter, which may be compensated by slo-mo modes (FPS_DIVISOR). Does not need to be integer divisible.
// Normalized raster position [0..1] representing current position of simulated CRT electron beam
// CRT refresh cycle counter
//-------------------------------------------------------------------------------------------------
// Splitscreen processing
// crtTube: Boolean indicating whether the current pixel is within the CRT-BFI region.
// When splitscreen is off, apply CRT-BFI to entire screen
// Calculate border regions (in pixels)
// Border only exists in the non-BFI region (x > SPLITSCREEN_X || y > SPLITSCREEN_Y)
// We #ifdef the if statement away for shader efficiency (though this specific one didn't affect performance)
//-----------------------------------------------------------------------------------------
// Get CRT simulated version of pixel
// Brightness compensation for unprocessed pixels through similar gamma-curve (match gamma of simulated CRT)
//-------------------------------------------------------------------------------------------------
// Credits Reminder:
// Please credit BLUR BUSTERS & TIMOTHY LOTTES if this algorithm is used in your project/product.
// Hundreds of hours of research was done on related work that led to this algorithm.
//-------------------------------------------------------------------------------------------------

*/

#pragma once

namespace RetroArchSubframeBfiShadersCrtBeamSimulatorShaderDefs
{
static const BYTE sVertexByteCode[] =
{
68,88,66,67,110,239,
1,38,44,138,120,137,
121,214,212,137,93,170,
129,5,1,0,0,0,
140,3,0,0,5,0,
0,0,52,0,0,0,
60,1,0,0,136,1,
0,0,224,1,0,0,
240,2,0,0,82,68,
69,70,0,1,0,0,
1,0,0,0,96,0,
0,0,1,0,0,0,
60,0,0,0,0,5,
254,255,0,129,0,0,
216,0,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
92,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,1,0,
0,0,85,66,79,0,
92,0,0,0,1,0,
0,0,120,0,0,0,
64,0,0,0,0,0,
0,0,0,0,0,0,
160,0,0,0,0,0,
0,0,64,0,0,0,
2,0,0,0,180,0,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,103,108,
111,98,97,108,95,77,
86,80,0,102,108,111,
97,116,52,120,52,0,
2,0,3,0,4,0,
4,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,171,0,0,0,
77,105,99,114,111,115,
111,102,116,32,40,82,
41,32,72,76,83,76,
32,83,104,97,100,101,
114,32,67,111,109,112,
105,108,101,114,32,49,
48,46,49,0,73,83,
71,78,68,0,0,0,
2,0,0,0,8,0,
0,0,56,0,0,0,
0,0,0,0,0,0,
0,0,3,0,0,0,
0,0,0,0,15,15,
0,0,56,0,0,0,
1,0,0,0,0,0,
0,0,3,0,0,0,
1,0,0,0,3,3,
0,0,84,69,88,67,
79,79,82,68,0,171,
171,171,79,83,71,78,
80,0,0,0,2,0,
0,0,8,0,0,0,
56,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,3,12,0,0,
65,0,0,0,0,0,
0,0,1,0,0,0,
3,0,0,0,1,0,
0,0,15,0,0,0,
84,69,88,67,79,79,
82,68,0,83,86,95,
80,111,115,105,116,105,
111,110,0,171,171,171,
83,72,69,88,8,1,
0,0,80,0,1,0,
66,0,0,0,106,8,
0,1,89,0,0,4,
70,142,32,0,0,0,
0,0,4,0,0,0,
95,0,0,3,242,16,
16,0,0,0,0,0,
95,0,0,3,50,16,
16,0,1,0,0,0,
101,0,0,3,50,32,
16,0,0,0,0,0,
103,0,0,4,242,32,
16,0,1,0,0,0,
1,0,0,0,104,0,
0,2,1,0,0,0,
54,0,0,5,50,32,
16,0,0,0,0,0,
70,16,16,0,1,0,
0,0,56,0,0,8,
242,0,16,0,0,0,
0,0,86,21,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
1,0,0,0,50,0,
0,10,242,0,16,0,
0,0,0,0,6,16,
16,0,0,0,0,0,
70,142,32,0,0,0,
0,0,0,0,0,0,
70,14,16,0,0,0,
0,0,50,0,0,10,
242,0,16,0,0,0,
0,0,166,26,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
2,0,0,0,70,14,
16,0,0,0,0,0,
50,0,0,10,242,32,
16,0,1,0,0,0,
246,31,16,0,0,0,
0,0,70,142,32,0,
0,0,0,0,3,0,
0,0,70,14,16,0,
0,0,0,0,62,0,
0,1,83,84,65,84,
148,0,0,0,6,0,
0,0,1,0,0,0,
0,0,0,0,4,0,
0,0,4,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0
};


static const BYTE sFragmentByteCode[] =
{
68,88,66,67,161,227,
229,229,16,82,9,235,
248,235,117,11,252,57,
53,213,1,0,0,0,
12,25,0,0,5,0,
0,0,52,0,0,0,
156,4,0,0,208,4,
0,0,4,5,0,0,
112,24,0,0,82,68,
69,70,96,4,0,0,
1,0,0,0,184,0,
0,0,3,0,0,0,
60,0,0,0,0,5,
255,255,0,129,0,0,
55,4,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
156,0,0,0,3,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,2,0,0,0,
1,0,0,0,1,0,
0,0,172,0,0,0,
2,0,0,0,5,0,
0,0,4,0,0,0,
255,255,255,255,2,0,
0,0,1,0,0,0,
13,0,0,0,179,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,1,0,
0,0,0,0,0,0,
95,83,111,117,114,99,
101,95,115,97,109,112,
108,101,114,0,83,111,
117,114,99,101,0,80,
117,115,104,0,179,0,
0,0,12,0,0,0,
208,0,0,0,96,0,
0,0,0,0,0,0,
0,0,0,0,176,2,
0,0,0,0,0,0,
16,0,0,0,0,0,
0,0,204,2,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,240,2,0,0,
16,0,0,0,16,0,
0,0,0,0,0,0,
204,2,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
4,3,0,0,32,0,
0,0,16,0,0,0,
2,0,0,0,204,2,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,22,3,
0,0,48,0,0,0,
4,0,0,0,2,0,
0,0,48,3,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,84,3,0,0,
52,0,0,0,4,0,
0,0,2,0,0,0,
48,3,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
106,3,0,0,56,0,
0,0,4,0,0,0,
2,0,0,0,48,3,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,129,3,
0,0,60,0,0,0,
4,0,0,0,2,0,
0,0,156,3,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,192,3,0,0,
64,0,0,0,4,0,
0,0,2,0,0,0,
156,3,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
205,3,0,0,68,0,
0,0,4,0,0,0,
2,0,0,0,156,3,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,224,3,
0,0,72,0,0,0,
4,0,0,0,2,0,
0,0,156,3,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,1,4,0,0,
76,0,0,0,4,0,
0,0,2,0,0,0,
156,3,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
16,4,0,0,80,0,
0,0,4,0,0,0,
2,0,0,0,156,3,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,112,97,
114,97,109,115,95,83,
111,117,114,99,101,83,
105,122,101,0,102,108,
111,97,116,52,0,171,
171,171,1,0,3,0,
1,0,4,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,194,2,
0,0,112,97,114,97,
109,115,95,79,114,105,
103,105,110,97,108,83,
105,122,101,0,112,97,
114,97,109,115,95,79,
117,116,112,117,116,83,
105,122,101,0,112,97,
114,97,109,115,95,70,
114,97,109,101,67,111,
117,110,116,0,100,119,
111,114,100,0,171,171,
0,0,19,0,1,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,40,3,0,0,
112,97,114,97,109,115,
95,84,111,116,97,108,
83,117,98,70,114,97,
109,101,115,0,112,97,
114,97,109,115,95,67,
117,114,114,101,110,116,
83,117,98,70,114,97,
109,101,0,112,97,114,
97,109,115,95,71,65,
73,78,95,86,83,95,
66,76,85,82,0,102,
108,111,97,116,0,171,
0,0,3,0,1,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,149,3,0,0,
112,97,114,97,109,115,
95,71,65,77,77,65,
0,112,97,114,97,109,
115,95,70,80,83,95,
68,73,86,73,83,79,
82,0,112,97,114,97,
109,115,95,76,67,68,
95,65,78,84,73,95,
82,69,84,69,78,84,
73,79,78,95,84,79,
71,71,76,69,0,112,
97,114,97,109,115,95,
80,79,83,95,77,79,
68,0,112,97,114,97,
109,115,95,76,67,68,
95,73,78,86,69,82,
83,73,79,78,95,67,
79,77,80,69,78,83,
65,84,73,79,78,95,
83,76,69,87,0,77,
105,99,114,111,115,111,
102,116,32,40,82,41,
32,72,76,83,76,32,
83,104,97,100,101,114,
32,67,111,109,112,105,
108,101,114,32,49,48,
46,49,0,171,73,83,
71,78,44,0,0,0,
1,0,0,0,8,0,
0,0,32,0,0,0,
0,0,0,0,0,0,
0,0,3,0,0,0,
0,0,0,0,3,3,
0,0,84,69,88,67,
79,79,82,68,0,171,
171,171,79,83,71,78,
44,0,0,0,1,0,
0,0,8,0,0,0,
32,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,15,0,0,0,
83,86,95,84,97,114,
103,101,116,0,171,171,
83,72,69,88,100,19,
0,0,80,0,0,0,
217,4,0,0,106,8,
0,1,89,0,0,4,
70,142,32,0,1,0,
0,0,6,0,0,0,
90,0,0,3,0,96,
16,0,2,0,0,0,
88,24,0,4,0,112,
16,0,2,0,0,0,
85,85,0,0,98,16,
0,3,50,16,16,0,
0,0,0,0,101,0,
0,3,242,32,16,0,
0,0,0,0,104,0,
0,2,8,0,0,0,
69,0,0,139,194,0,
0,128,67,85,21,0,
242,0,16,0,0,0,
0,0,70,16,16,0,
0,0,0,0,70,126,
16,0,2,0,0,0,
0,96,16,0,2,0,
0,0,79,0,0,8,
18,0,16,0,1,0,
0,0,26,128,32,0,
1,0,0,0,3,0,
0,0,1,64,0,0,
2,0,0,0,31,0,
0,3,10,0,16,0,
1,0,0,0,57,0,
0,8,18,0,16,0,
1,0,0,0,1,64,
0,0,0,0,0,0,
42,128,32,0,1,0,
0,0,4,0,0,0,
86,0,0,6,34,0,
16,0,1,0,0,0,
26,128,32,0,1,0,
0,0,3,0,0,0,
56,0,0,7,66,0,
16,0,1,0,0,0,
26,0,16,0,1,0,
0,0,1,64,0,0,
0,0,0,63,65,0,
0,5,130,0,16,0,
1,0,0,0,42,0,
16,0,1,0,0,0,
24,0,0,7,66,0,
16,0,1,0,0,0,
42,0,16,0,1,0,
0,0,58,0,16,0,
1,0,0,0,1,0,
0,7,18,0,16,0,
1,0,0,0,42,0,
16,0,1,0,0,0,
10,0,16,0,1,0,
0,0,52,0,0,8,
66,0,16,0,1,0,
0,0,1,64,0,0,
0,0,128,63,10,128,
32,0,1,0,0,0,
5,0,0,0,51,0,
0,7,66,0,16,0,
1,0,0,0,42,0,
16,0,1,0,0,0,
1,64,0,0,0,0,
122,68,50,0,0,9,
66,0,16,0,1,0,
0,0,42,0,16,0,
1,0,0,0,1,64,
0,0,111,18,131,58,
26,0,16,0,1,0,
0,0,55,0,0,9,
18,0,16,0,1,0,
0,0,10,0,16,0,
1,0,0,0,42,0,
16,0,1,0,0,0,
26,0,16,0,1,0,
0,0,35,0,0,12,
34,0,16,0,1,0,
0,0,10,128,32,0,
1,0,0,0,3,0,
0,0,26,128,32,0,
1,0,0,0,3,0,
0,0,42,128,32,0,
1,0,0,0,3,0,
0,0,86,0,0,5,
34,0,16,0,1,0,
0,0,26,0,16,0,
1,0,0,0,14,0,
0,11,194,0,16,0,
1,0,0,0,2,64,
0,0,0,0,128,63,
0,0,128,63,0,0,
128,63,0,0,128,63,
86,129,32,0,1,0,
0,0,4,0,0,0,
56,0,0,7,34,0,
16,0,1,0,0,0,
42,0,16,0,1,0,
0,0,26,0,16,0,
1,0,0,0,65,0,
0,5,34,0,16,0,
1,0,0,0,26,0,
16,0,1,0,0,0,
14,0,0,7,66,0,
16,0,1,0,0,0,
26,0,16,0,1,0,
0,0,10,0,16,0,
1,0,0,0,65,0,
0,5,66,0,16,0,
1,0,0,0,42,0,
16,0,1,0,0,0,
50,0,0,10,34,0,
16,0,1,0,0,0,
10,0,16,128,65,0,
0,0,1,0,0,0,
42,0,16,0,1,0,
0,0,26,0,16,0,
1,0,0,0,14,0,
0,7,34,0,16,0,
1,0,0,0,26,0,
16,0,1,0,0,0,
10,0,16,0,1,0,
0,0,0,0,0,8,
34,0,16,0,1,0,
0,0,26,0,16,0,
1,0,0,0,58,128,
32,0,1,0,0,0,
4,0,0,0,0,0,
0,10,50,0,16,0,
2,0,0,0,166,10,
16,0,1,0,0,0,
2,64,0,0,0,0,
0,192,0,0,128,191,
0,0,0,0,0,0,
0,0,29,0,0,7,
194,0,16,0,2,0,
0,0,166,10,16,0,
1,0,0,0,6,4,
16,0,2,0,0,0,
31,0,4,3,42,0,
16,0,2,0,0,0,
14,0,0,11,18,0,
16,0,3,0,0,0,
2,64,0,0,0,0,
128,63,0,0,128,63,
0,0,128,63,0,0,
128,63,10,128,32,0,
1,0,0,0,2,0,
0,0,50,0,0,9,
34,0,16,0,3,0,
0,0,10,0,16,0,
3,0,0,0,1,64,
0,0,205,204,204,61,
10,16,16,0,0,0,
0,0,65,0,0,5,
66,0,16,0,3,0,
0,0,26,0,16,0,
3,0,0,0,0,0,
0,8,34,0,16,0,
3,0,0,0,42,0,
16,128,65,0,0,0,
3,0,0,0,26,0,
16,0,3,0,0,0,
50,0,0,10,18,0,
16,0,3,0,0,0,
10,0,16,128,65,0,
0,0,3,0,0,0,
1,64,0,0,205,204,
204,61,26,0,16,0,
3,0,0,0,54,0,
0,5,34,0,16,0,
3,0,0,0,26,16,
16,0,0,0,0,0,
72,0,0,141,194,0,
0,128,67,85,21,0,
114,0,16,0,3,0,
0,0,70,0,16,0,
3,0,0,0,70,126,
16,0,2,0,0,0,
0,96,16,0,2,0,
0,0,1,64,0,0,
0,0,0,0,18,0,
0,1,54,0,0,8,
114,0,16,0,3,0,
0,0,2,64,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,21,0,
0,1,56,0,0,7,
130,0,16,0,3,0,
0,0,10,0,16,0,
3,0,0,0,1,64,
0,0,145,131,158,61,
50,0,0,9,18,0,
16,0,4,0,0,0,
10,0,16,0,3,0,
0,0,1,64,0,0,
110,167,114,63,1,64,
0,0,25,137,85,61,
47,0,0,5,18,0,
16,0,4,0,0,0,
10,0,16,0,4,0,
0,0,56,0,0,8,
18,0,16,0,4,0,
0,0,10,0,16,0,
4,0,0,0,10,128,
32,0,1,0,0,0,
4,0,0,0,25,0,
0,5,18,0,16,0,
4,0,0,0,10,0,
16,0,4,0,0,0,
49,0,0,7,18,0,
16,0,3,0,0,0,
1,64,0,0,230,174,
37,61,10,0,16,0,
3,0,0,0,55,0,
0,9,18,0,16,0,
4,0,0,0,10,0,
16,0,3,0,0,0,
10,0,16,0,4,0,
0,0,58,0,16,0,
3,0,0,0,56,0,
0,7,18,0,16,0,
3,0,0,0,26,0,
16,0,3,0,0,0,
1,64,0,0,145,131,
158,61,50,0,0,9,
130,0,16,0,3,0,
0,0,26,0,16,0,
3,0,0,0,1,64,
0,0,110,167,114,63,
1,64,0,0,25,137,
85,61,47,0,0,5,
130,0,16,0,3,0,
0,0,58,0,16,0,
3,0,0,0,56,0,
0,8,130,0,16,0,
3,0,0,0,58,0,
16,0,3,0,0,0,
10,128,32,0,1,0,
0,0,4,0,0,0,
25,0,0,5,130,0,
16,0,3,0,0,0,
58,0,16,0,3,0,
0,0,49,0,0,7,
34,0,16,0,3,0,
0,0,1,64,0,0,
230,174,37,61,26,0,
16,0,3,0,0,0,
55,0,0,9,34,0,
16,0,4,0,0,0,
26,0,16,0,3,0,
0,0,58,0,16,0,
3,0,0,0,10,0,
16,0,3,0,0,0,
56,0,0,7,18,0,
16,0,3,0,0,0,
42,0,16,0,3,0,
0,0,1,64,0,0,
145,131,158,61,50,0,
0,9,34,0,16,0,
3,0,0,0,42,0,
16,0,3,0,0,0,
1,64,0,0,110,167,
114,63,1,64,0,0,
25,137,85,61,47,0,
0,5,34,0,16,0,
3,0,0,0,26,0,
16,0,3,0,0,0,
56,0,0,8,34,0,
16,0,3,0,0,0,
26,0,16,0,3,0,
0,0,10,128,32,0,
1,0,0,0,4,0,
0,0,25,0,0,5,
34,0,16,0,3,0,
0,0,26,0,16,0,
3,0,0,0,49,0,
0,7,66,0,16,0,
3,0,0,0,1,64,
0,0,230,174,37,61,
42,0,16,0,3,0,
0,0,55,0,0,9,
66,0,16,0,4,0,
0,0,42,0,16,0,
3,0,0,0,26,0,
16,0,3,0,0,0,
10,0,16,0,3,0,
0,0,29,0,0,7,
18,0,16,0,2,0,
0,0,26,0,16,0,
2,0,0,0,10,0,
16,0,2,0,0,0,
1,0,0,7,18,0,
16,0,2,0,0,0,
10,0,16,0,2,0,
0,0,58,0,16,0,
2,0,0,0,31,0,
4,3,10,0,16,0,
2,0,0,0,14,0,
0,11,18,0,16,0,
2,0,0,0,2,64,
0,0,0,0,128,63,
0,0,128,63,0,0,
128,63,0,0,128,63,
10,128,32,0,1,0,
0,0,2,0,0,0,
50,0,0,9,34,0,
16,0,2,0,0,0,
10,0,16,0,2,0,
0,0,1,64,0,0,
205,204,204,61,10,16,
16,0,0,0,0,0,
65,0,0,5,130,0,
16,0,2,0,0,0,
26,0,16,0,2,0,
0,0,0,0,0,8,
34,0,16,0,2,0,
0,0,58,0,16,128,
65,0,0,0,2,0,
0,0,26,0,16,0,
2,0,0,0,50,0,
0,10,18,0,16,0,
2,0,0,0,10,0,
16,128,65,0,0,0,
2,0,0,0,1,64,
0,0,205,204,204,61,
26,0,16,0,2,0,
0,0,54,0,0,5,
34,0,16,0,2,0,
0,0,26,16,16,0,
0,0,0,0,72,0,
0,141,194,0,0,128,
67,85,21,0,178,0,
16,0,2,0,0,0,
70,0,16,0,2,0,
0,0,70,123,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
1,64,0,0,0,0,
0,0,18,0,0,1,
54,0,0,8,178,0,
16,0,2,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,21,0,0,1,
56,0,0,7,18,0,
16,0,3,0,0,0,
10,0,16,0,2,0,
0,0,1,64,0,0,
145,131,158,61,50,0,
0,9,34,0,16,0,
3,0,0,0,10,0,
16,0,2,0,0,0,
1,64,0,0,110,167,
114,63,1,64,0,0,
25,137,85,61,47,0,
0,5,34,0,16,0,
3,0,0,0,26,0,
16,0,3,0,0,0,
56,0,0,8,34,0,
16,0,3,0,0,0,
26,0,16,0,3,0,
0,0,10,128,32,0,
1,0,0,0,4,0,
0,0,25,0,0,5,
34,0,16,0,3,0,
0,0,26,0,16,0,
3,0,0,0,49,0,
0,7,18,0,16,0,
2,0,0,0,1,64,
0,0,230,174,37,61,
10,0,16,0,2,0,
0,0,55,0,0,9,
18,0,16,0,3,0,
0,0,10,0,16,0,
2,0,0,0,26,0,
16,0,3,0,0,0,
10,0,16,0,3,0,
0,0,56,0,0,7,
18,0,16,0,2,0,
0,0,26,0,16,0,
2,0,0,0,1,64,
0,0,145,131,158,61,
50,0,0,9,130,0,
16,0,3,0,0,0,
26,0,16,0,2,0,
0,0,1,64,0,0,
110,167,114,63,1,64,
0,0,25,137,85,61,
47,0,0,5,130,0,
16,0,3,0,0,0,
58,0,16,0,3,0,
0,0,56,0,0,8,
130,0,16,0,3,0,
0,0,58,0,16,0,
3,0,0,0,10,128,
32,0,1,0,0,0,
4,0,0,0,25,0,
0,5,130,0,16,0,
3,0,0,0,58,0,
16,0,3,0,0,0,
49,0,0,7,34,0,
16,0,2,0,0,0,
1,64,0,0,230,174,
37,61,26,0,16,0,
2,0,0,0,55,0,
0,9,34,0,16,0,
3,0,0,0,26,0,
16,0,2,0,0,0,
58,0,16,0,3,0,
0,0,10,0,16,0,
2,0,0,0,56,0,
0,7,18,0,16,0,
2,0,0,0,58,0,
16,0,2,0,0,0,
1,64,0,0,145,131,
158,61,50,0,0,9,
34,0,16,0,2,0,
0,0,58,0,16,0,
2,0,0,0,1,64,
0,0,110,167,114,63,
1,64,0,0,25,137,
85,61,47,0,0,5,
34,0,16,0,2,0,
0,0,26,0,16,0,
2,0,0,0,56,0,
0,8,34,0,16,0,
2,0,0,0,26,0,
16,0,2,0,0,0,
10,128,32,0,1,0,
0,0,4,0,0,0,
25,0,0,5,34,0,
16,0,2,0,0,0,
26,0,16,0,2,0,
0,0,49,0,0,7,
130,0,16,0,2,0,
0,0,1,64,0,0,
230,174,37,61,58,0,
16,0,2,0,0,0,
55,0,0,9,66,0,
16,0,3,0,0,0,
58,0,16,0,2,0,
0,0,26,0,16,0,
2,0,0,0,10,0,
16,0,2,0,0,0,
29,0,0,7,66,0,
16,0,1,0,0,0,
42,0,16,0,1,0,
0,0,42,0,16,0,
1,0,0,0,1,0,
0,7,66,0,16,0,
1,0,0,0,42,0,
16,0,2,0,0,0,
42,0,16,0,1,0,
0,0,31,0,4,3,
42,0,16,0,1,0,
0,0,14,0,0,11,
66,0,16,0,1,0,
0,0,2,64,0,0,
0,0,128,63,0,0,
128,63,0,0,128,63,
0,0,128,63,10,128,
32,0,1,0,0,0,
2,0,0,0,50,0,
0,9,18,0,16,0,
2,0,0,0,42,0,
16,0,1,0,0,0,
1,64,0,0,205,204,
204,61,10,16,16,0,
0,0,0,0,65,0,
0,5,34,0,16,0,
2,0,0,0,10,0,
16,0,2,0,0,0,
0,0,0,8,18,0,
16,0,2,0,0,0,
26,0,16,128,65,0,
0,0,2,0,0,0,
10,0,16,0,2,0,
0,0,50,0,0,10,
18,0,16,0,2,0,
0,0,42,0,16,128,
65,0,0,0,1,0,
0,0,1,64,0,0,
205,204,204,61,10,0,
16,0,2,0,0,0,
54,0,0,5,34,0,
16,0,2,0,0,0,
26,16,16,0,0,0,
0,0,72,0,0,141,
194,0,0,128,67,85,
21,0,114,0,16,0,
2,0,0,0,70,0,
16,0,2,0,0,0,
70,126,16,0,2,0,
0,0,0,96,16,0,
2,0,0,0,1,64,
0,0,0,0,0,0,
18,0,0,1,54,0,
0,8,114,0,16,0,
2,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
21,0,0,1,56,0,
0,7,66,0,16,0,
1,0,0,0,10,0,
16,0,2,0,0,0,
1,64,0,0,145,131,
158,61,50,0,0,9,
130,0,16,0,2,0,
0,0,10,0,16,0,
2,0,0,0,1,64,
0,0,110,167,114,63,
1,64,0,0,25,137,
85,61,47,0,0,5,
130,0,16,0,2,0,
0,0,58,0,16,0,
2,0,0,0,56,0,
0,8,130,0,16,0,
2,0,0,0,58,0,
16,0,2,0,0,0,
10,128,32,0,1,0,
0,0,4,0,0,0,
25,0,0,5,130,0,
16,0,2,0,0,0,
58,0,16,0,2,0,
0,0,49,0,0,7,
18,0,16,0,2,0,
0,0,1,64,0,0,
230,174,37,61,10,0,
16,0,2,0,0,0,
55,0,0,9,18,0,
16,0,5,0,0,0,
10,0,16,0,2,0,
0,0,58,0,16,0,
2,0,0,0,42,0,
16,0,1,0,0,0,
56,0,0,7,66,0,
16,0,1,0,0,0,
26,0,16,0,2,0,
0,0,1,64,0,0,
145,131,158,61,50,0,
0,9,18,0,16,0,
2,0,0,0,26,0,
16,0,2,0,0,0,
1,64,0,0,110,167,
114,63,1,64,0,0,
25,137,85,61,47,0,
0,5,18,0,16,0,
2,0,0,0,10,0,
16,0,2,0,0,0,
56,0,0,8,18,0,
16,0,2,0,0,0,
10,0,16,0,2,0,
0,0,10,128,32,0,
1,0,0,0,4,0,
0,0,25,0,0,5,
18,0,16,0,2,0,
0,0,10,0,16,0,
2,0,0,0,49,0,
0,7,34,0,16,0,
2,0,0,0,1,64,
0,0,230,174,37,61,
26,0,16,0,2,0,
0,0,55,0,0,9,
34,0,16,0,5,0,
0,0,26,0,16,0,
2,0,0,0,10,0,
16,0,2,0,0,0,
42,0,16,0,1,0,
0,0,56,0,0,7,
66,0,16,0,1,0,
0,0,42,0,16,0,
2,0,0,0,1,64,
0,0,145,131,158,61,
50,0,0,9,18,0,
16,0,2,0,0,0,
42,0,16,0,2,0,
0,0,1,64,0,0,
110,167,114,63,1,64,
0,0,25,137,85,61,
47,0,0,5,18,0,
16,0,2,0,0,0,
10,0,16,0,2,0,
0,0,56,0,0,8,
18,0,16,0,2,0,
0,0,10,0,16,0,
2,0,0,0,10,128,
32,0,1,0,0,0,
4,0,0,0,25,0,
0,5,18,0,16,0,
2,0,0,0,10,0,
16,0,2,0,0,0,
49,0,0,7,34,0,
16,0,2,0,0,0,
1,64,0,0,230,174,
37,61,42,0,16,0,
2,0,0,0,55,0,
0,9,66,0,16,0,
5,0,0,0,26,0,
16,0,2,0,0,0,
10,0,16,0,2,0,
0,0,42,0,16,0,
1,0,0,0,56,0,
0,8,66,0,16,0,
1,0,0,0,10,0,
16,0,1,0,0,0,
58,128,32,0,1,0,
0,0,3,0,0,0,
56,0,0,7,114,0,
16,0,2,0,0,0,
166,10,16,0,1,0,
0,0,70,2,16,0,
4,0,0,0,56,0,
0,7,114,0,16,0,
3,0,0,0,166,10,
16,0,1,0,0,0,
70,2,16,0,3,0,
0,0,56,0,0,7,
114,0,16,0,6,0,
0,0,166,10,16,0,
1,0,0,0,70,2,
16,0,5,0,0,0,
29,0,0,10,114,0,
16,0,2,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,70,2,16,0,
2,0,0,0,29,0,
0,10,114,0,16,0,
7,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
70,2,16,0,3,0,
0,0,1,0,0,7,
114,0,16,0,2,0,
0,0,70,2,16,0,
2,0,0,0,70,2,
16,0,7,0,0,0,
29,0,0,10,114,0,
16,0,6,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,70,2,16,0,
6,0,0,0,1,0,
0,7,114,0,16,0,
2,0,0,0,70,2,
16,0,2,0,0,0,
70,2,16,0,6,0,
0,0,56,0,0,7,
130,0,16,0,2,0,
0,0,10,0,16,0,
1,0,0,0,26,16,
16,0,0,0,0,0,
56,0,0,7,130,0,
16,0,3,0,0,0,
10,0,16,0,1,0,
0,0,26,0,16,0,
1,0,0,0,50,0,
0,9,34,0,16,0,
1,0,0,0,26,0,
16,0,1,0,0,0,
10,0,16,0,1,0,
0,0,1,64,0,0,
0,0,128,63,50,0,
0,10,130,0,16,0,
4,0,0,0,26,16,
16,0,0,0,0,0,
10,0,16,0,1,0,
0,0,10,0,16,128,
65,0,0,0,1,0,
0,0,50,0,0,9,
114,0,16,0,4,0,
0,0,70,2,16,0,
4,0,0,0,166,10,
16,0,1,0,0,0,
246,15,16,0,4,0,
0,0,50,0,0,9,
114,0,16,0,3,0,
0,0,86,21,16,0,
0,0,0,0,6,0,
16,0,1,0,0,0,
70,2,16,0,3,0,
0,0,50,0,0,9,
18,0,16,0,1,0,
0,0,26,16,16,0,
0,0,0,0,10,0,
16,0,1,0,0,0,
10,0,16,0,1,0,
0,0,50,0,0,9,
114,0,16,0,5,0,
0,0,70,2,16,0,
5,0,0,0,166,10,
16,0,1,0,0,0,
6,0,16,0,1,0,
0,0,51,0,0,7,
114,0,16,0,4,0,
0,0,86,5,16,0,
1,0,0,0,70,2,
16,0,4,0,0,0,
52,0,0,7,66,0,
16,0,1,0,0,0,
58,0,16,0,3,0,
0,0,58,0,16,0,
4,0,0,0,0,0,
0,8,114,0,16,0,
4,0,0,0,166,10,
16,128,65,0,0,0,
1,0,0,0,70,2,
16,0,4,0,0,0,
52,0,0,10,114,0,
16,0,4,0,0,0,
70,2,16,0,4,0,
0,0,2,64,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,51,0,
0,7,114,0,16,0,
3,0,0,0,86,5,
16,0,1,0,0,0,
70,2,16,0,3,0,
0,0,52,0,0,7,
66,0,16,0,1,0,
0,0,58,0,16,0,
2,0,0,0,58,0,
16,0,3,0,0,0,
0,0,0,8,114,0,
16,0,3,0,0,0,
166,10,16,128,65,0,
0,0,1,0,0,0,
70,2,16,0,3,0,
0,0,52,0,0,10,
114,0,16,0,3,0,
0,0,70,2,16,0,
3,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
51,0,0,7,114,0,
16,0,5,0,0,0,
86,5,16,0,1,0,
0,0,70,2,16,0,
5,0,0,0,52,0,
0,7,18,0,16,0,
1,0,0,0,58,0,
16,0,3,0,0,0,
10,0,16,0,1,0,
0,0,0,0,0,8,
114,0,16,0,1,0,
0,0,6,0,16,128,
65,0,0,0,1,0,
0,0,70,2,16,0,
5,0,0,0,52,0,
0,10,114,0,16,0,
1,0,0,0,70,2,
16,0,1,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,7,
114,0,16,0,3,0,
0,0,70,2,16,0,
3,0,0,0,70,2,
16,0,4,0,0,0,
0,0,0,7,114,0,
16,0,1,0,0,0,
70,2,16,0,1,0,
0,0,70,2,16,0,
3,0,0,0,55,0,
0,12,114,0,16,0,
1,0,0,0,70,2,
16,0,2,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,70,2,16,0,
1,0,0,0,56,0,
0,10,114,0,16,0,
2,0,0,0,70,2,
16,0,1,0,0,0,
2,64,0,0,82,184,
78,65,82,184,78,65,
82,184,78,65,0,0,
0,0,47,0,0,5,
114,0,16,0,1,0,
0,0,70,2,16,0,
1,0,0,0,56,0,
0,7,114,0,16,0,
1,0,0,0,70,2,
16,0,1,0,0,0,
246,15,16,0,1,0,
0,0,25,0,0,5,
114,0,16,0,1,0,
0,0,70,2,16,0,
1,0,0,0,50,0,
0,15,114,0,16,0,
1,0,0,0,70,2,
16,0,1,0,0,0,
2,64,0,0,61,10,
135,63,61,10,135,63,
61,10,135,63,0,0,
0,0,2,64,0,0,
174,71,97,189,174,71,
97,189,174,71,97,189,
0,0,0,0,52,0,
0,10,114,0,16,0,
2,0,0,0,70,2,
16,0,2,0,0,0,
2,64,0,0,213,174,
37,61,213,174,37,61,
213,174,37,61,0,0,
0,0,51,0,0,7,
114,0,16,0,0,0,
0,0,70,2,16,0,
1,0,0,0,70,2,
16,0,2,0,0,0,
21,0,0,1,54,0,
0,5,242,32,16,0,
0,0,0,0,70,14,
16,0,0,0,0,0,
62,0,0,1,83,84,
65,84,148,0,0,0,
167,0,0,0,8,0,
0,0,0,0,0,0,
2,0,0,0,124,0,
0,0,1,0,0,0,
6,0,0,0,4,0,
0,0,4,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
3,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,7,0,
0,0,11,0,0,0,
8,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0
};


static const uint32_t sVertexHash[] = 
{
0x1e4f5f8a,0xbf5ed995,0x7ea7a7ed,0x50403282,0x1e794542,0xb9c8013f,
0x6bf3079e,0x8a942b96
};


static const uint32_t sFragmentHash[] =
{
0xd95b7edd,0xbb0618c3,0xe70522d4,0xa4a81622,0xc7e58b25,0x29fc22b,
0x4b5699d6,0x17eb1665
};

}

namespace RetroArch
{
class SubframeBfiShadersCrtBeamSimulatorShaderDef : public ShaderDef
{
public:
	SubframeBfiShadersCrtBeamSimulatorShaderDef() : ShaderDef{}
	{
		Name = "crt-beam-simulator";
		VertexByteCode = RetroArchSubframeBfiShadersCrtBeamSimulatorShaderDefs::sVertexByteCode;
		VertexLength = sizeof(RetroArchSubframeBfiShadersCrtBeamSimulatorShaderDefs::sVertexByteCode);
		VertexHash = RetroArchSubframeBfiShadersCrtBeamSimulatorShaderDefs::sVertexHash;
		FragmentByteCode = RetroArchSubframeBfiShadersCrtBeamSimulatorShaderDefs::sFragmentByteCode;
		FragmentLength = sizeof(RetroArchSubframeBfiShadersCrtBeamSimulatorShaderDefs::sFragmentByteCode);
		FragmentHash = RetroArchSubframeBfiShadersCrtBeamSimulatorShaderDefs::sFragmentHash;
		Format = "";
		Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("SourceSize", -1, 0, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OriginalSize", -1, 16, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OutputSize", -1, 32, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("FrameCount", -1, 48, 4, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("TotalSubFrames", -1, 52, 4, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("CurrentSubFrame", -1, 56, 4, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("GAIN_VS_BLUR", -1, 60, 4, 0.010000f, 1.000000f, 0.700000f, 0.025000f, "Brightness vs Clarity"));
		Params.push_back(ShaderParam("GAMMA", -1, 64, 4, 1.000000f, 5.000000f, 2.400000f, 0.010000f, "Gamma"));
		Params.push_back(ShaderParam("FPS_DIVISOR", -1, 68, 4, 1.000000f, 10.000000f, 1.000000f, 1.000000f, "FPS Divisor (debug)"));
		Params.push_back(ShaderParam("LCD_ANTI_RETENTION_TOGGLE", -1, 72, 4, 0.000000f, 1.000000f, 1.000000f, 1.000000f, "LCD Anti-Retention On/Off"));
		Params.push_back(ShaderParam("POS_MOD", -1, 76, 4, -10.000000f, 10.000000f, 0.000000f, 0.010000f, "Raster Position Mod"));
		Params.push_back(ShaderParam("LCD_INVERSION_COMPENSATION_SLEW", -1, 80, 4, 0.000000f, 150.000000f, 1.000000f, 10.000000f, "LCD Anti-Retention Slew Multiplier"));
		Samplers.push_back(ShaderSampler("Source", 2));
/*
VertexSource = %*VERTEX_SOURCE*%;
*/
/*
FragmentSource = %*FRAGMENT_SOURCE*%;
*/
	}
};
}
