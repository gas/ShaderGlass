/*
ShaderGlass shader ntsc/shaders/mame-ntsc\mame-ntsc imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/ntsc/shaders/mame-ntsc/mame-ntsc.slang
See original file for full credits and usage license with excerpts below. 
This file is auto-generated, do not modify directly.

// This is a port of the NTSC encode/decode shader pair in MAME and MESS, modified to use only
// one pass rather than an encode pass and a decode pass. It accurately emulates the sort of
// signal decimation one would see when viewing a composite signal, though it could benefit from a
// pre-pass to re-size the input content to more accurately reflect the actual size that would
// be incoming from a composite signal source.
//
// To encode the composite signal, I convert the RGB value to YIQ, then subsequently evaluate
// the standard NTSC composite equation. Four composite samples per RGB pixel are generated from
// the incoming linearly-interpolated texels.
//
// The decode pass implements a Fixed Impulse Response (FIR) filter designed by MAME/MESS contributor
// "austere" in matlab (if memory serves correctly) to mimic the behavior of a standard television set
// as closely as possible. The filter window is 83 composite samples wide, and there is an additional
// notch filter pass on the luminance (Y) values in order to strip the color signal from the luminance
// signal prior to processing.
//
// Yes, this code could greatly use some cleaning up.
// ported from UltraMoogleMan's "Full MAME/MESS Shader Pipe" shadertoy: https://www.shadertoy.com/view/ldf3Rf
// license: presumably MAME's license at the time, which was noncommercial
// Useful Constants
// NTSC Constants
// Color Convolution Constants
// Deconverge Constants
// Scanline/Pincushion Constants
//const float ScanlineAmount = 0.175; <- move to parameter
// 60Hz Bar Constants
// UVs for four linearly-interpolated samples spaced 0.25 texels apart
//Frequency = Frequency;// Uncomment for bad color sync + (sin(UV.y * 2.0 - 1.0) / CCFrequency) * 0.001;
// Calculated the expected time of the sample.
// Frequency cutoffs for the individual portions of the signal that we extract.
// Y1 and Y2 are the positive and negative frequency limits of the notch filter on Y.
// Y3 is the center of the frequency response of the Y filter.
// I is the center of the frequency response of the I filter.
// Q is the center of the frequency response of the Q filter.
// 83 composite samples wide, 4 composite pixels per texel
// These zero-checks could be made more efficient if WebGL supported mix(vec4, vec4, bvec4)
// Unfortunately, the universe hates us

*/

#pragma once

namespace RetroArchNtscShadersMameNtscMameNtscShaderDefs
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
68,88,66,67,162,235,
71,66,113,243,203,92,
25,240,138,239,90,238,
247,161,1,0,0,0,
108,17,0,0,5,0,
0,0,52,0,0,0,
120,2,0,0,172,2,
0,0,224,2,0,0,
208,16,0,0,82,68,
69,70,60,2,0,0,
1,0,0,0,184,0,
0,0,3,0,0,0,
60,0,0,0,0,5,
255,255,0,129,0,0,
20,2,0,0,82,68,
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
0,0,4,0,0,0,
208,0,0,0,64,0,
0,0,0,0,0,0,
0,0,0,0,112,1,
0,0,0,0,0,0,
16,0,0,0,2,0,
0,0,140,1,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,176,1,0,0,
16,0,0,0,16,0,
0,0,0,0,0,0,
140,1,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
196,1,0,0,32,0,
0,0,16,0,0,0,
0,0,0,0,140,1,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,214,1,
0,0,48,0,0,0,
4,0,0,0,0,0,
0,0,240,1,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,112,97,114,97,
109,115,95,83,111,117,
114,99,101,83,105,122,
101,0,102,108,111,97,
116,52,0,171,171,171,
1,0,3,0,1,0,
4,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,130,1,0,0,
112,97,114,97,109,115,
95,79,114,105,103,105,
110,97,108,83,105,122,
101,0,112,97,114,97,
109,115,95,79,117,116,
112,117,116,83,105,122,
101,0,112,97,114,97,
109,115,95,70,114,97,
109,101,67,111,117,110,
116,0,100,119,111,114,
100,0,171,171,0,0,
19,0,1,0,1,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
232,1,0,0,77,105,
99,114,111,115,111,102,
116,32,40,82,41,32,
72,76,83,76,32,83,
104,97,100,101,114,32,
67,111,109,112,105,108,
101,114,32,49,48,46,
49,0,73,83,71,78,
44,0,0,0,1,0,
0,0,8,0,0,0,
32,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,3,3,0,0,
84,69,88,67,79,79,
82,68,0,171,171,171,
79,83,71,78,44,0,
0,0,1,0,0,0,
8,0,0,0,32,0,
0,0,0,0,0,0,
0,0,0,0,3,0,
0,0,0,0,0,0,
15,0,0,0,83,86,
95,84,97,114,103,101,
116,0,171,171,83,72,
69,88,232,13,0,0,
80,0,0,0,122,3,
0,0,106,8,0,1,
89,0,0,4,70,142,
32,0,1,0,0,0,
1,0,0,0,90,0,
0,3,0,96,16,0,
2,0,0,0,88,24,
0,4,0,112,16,0,
2,0,0,0,85,85,
0,0,98,16,0,3,
50,16,16,0,0,0,
0,0,101,0,0,3,
242,32,16,0,0,0,
0,0,104,0,0,2,
17,0,0,0,56,0,
0,8,18,0,16,0,
0,0,0,0,1,64,
0,0,0,0,128,64,
10,128,32,0,1,0,
0,0,0,0,0,0,
14,0,0,7,18,0,
16,0,0,0,0,0,
1,64,0,0,102,102,
82,66,10,0,16,0,
0,0,0,0,56,0,
0,10,242,0,16,0,
1,0,0,0,6,0,
16,0,0,0,0,0,
2,64,0,0,81,154,
32,65,130,174,12,66,
228,203,22,66,59,70,
241,64,56,0,0,10,
242,0,16,0,2,0,
0,0,6,0,16,0,
0,0,0,0,2,64,
0,0,59,70,113,64,
95,124,76,64,24,31,
51,65,0,0,64,65,
56,0,0,10,50,0,
16,0,0,0,0,0,
6,0,16,0,0,0,
0,0,2,64,0,0,
154,153,25,64,154,153,
153,63,0,0,0,0,
0,0,0,0,54,0,
0,5,34,0,16,0,
3,0,0,0,26,16,
16,0,0,0,0,0,
54,0,0,8,242,0,
16,0,4,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,54,0,0,8,
242,0,16,0,5,0,
0,0,2,64,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,54,0,
0,8,242,0,16,0,
6,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
54,0,0,5,66,0,
16,0,0,0,0,0,
1,64,0,0,0,0,
248,193,48,0,0,1,
29,0,0,7,130,0,
16,0,0,0,0,0,
42,0,16,0,0,0,
0,0,1,64,0,0,
0,0,0,66,3,0,
4,3,58,0,16,0,
0,0,0,0,0,0,
0,10,242,0,16,0,
7,0,0,0,166,10,
16,0,0,0,0,0,
2,64,0,0,0,0,
0,0,0,0,128,63,
0,0,0,64,0,0,
64,64,56,0,0,8,
242,0,16,0,8,0,
0,0,70,14,16,0,
7,0,0,0,166,138,
32,0,1,0,0,0,
0,0,0,0,50,0,
0,12,242,0,16,0,
8,0,0,0,70,14,
16,0,8,0,0,0,
2,64,0,0,0,0,
128,62,0,0,128,62,
0,0,128,62,0,0,
128,62,6,16,16,0,
0,0,0,0,54,0,
0,5,18,0,16,0,
3,0,0,0,10,0,
16,0,8,0,0,0,
50,0,0,13,194,0,
16,0,3,0,0,0,
166,142,32,0,1,0,
0,0,0,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,128,62,0,0,
0,0,6,4,16,0,
3,0,0,0,50,0,
0,13,242,0,16,0,
9,0,0,0,246,138,
32,0,1,0,0,0,
0,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,63,0,0,64,63,
86,0,16,0,3,0,
0,0,69,0,0,139,
194,0,0,128,67,85,
21,0,114,0,16,0,
10,0,0,0,70,0,
16,0,3,0,0,0,
70,126,16,0,2,0,
0,0,0,96,16,0,
2,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,114,0,
16,0,11,0,0,0,
230,10,16,0,3,0,
0,0,70,126,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
69,0,0,139,194,0,
0,128,67,85,21,0,
114,0,16,0,12,0,
0,0,38,10,16,0,
9,0,0,0,70,126,
16,0,2,0,0,0,
0,96,16,0,2,0,
0,0,69,0,0,139,
194,0,0,128,67,85,
21,0,114,0,16,0,
13,0,0,0,118,15,
16,0,9,0,0,0,
70,126,16,0,2,0,
0,0,0,96,16,0,
2,0,0,0,54,0,
0,5,50,0,16,0,
9,0,0,0,134,0,
16,0,3,0,0,0,
50,0,0,10,242,0,
16,0,9,0,0,0,
86,5,16,0,3,0,
0,0,86,133,32,0,
1,0,0,0,0,0,
0,0,70,14,16,0,
9,0,0,0,0,0,
0,10,242,0,16,0,
9,0,0,0,70,14,
16,0,9,0,0,0,
2,64,0,0,0,0,
0,63,0,0,0,63,
0,0,0,63,0,0,
0,63,56,0,0,10,
242,0,16,0,9,0,
0,0,70,14,16,0,
9,0,0,0,2,64,
0,0,33,159,148,68,
33,159,148,68,33,159,
148,68,33,159,148,68,
16,0,0,10,18,0,
16,0,14,0,0,0,
70,2,16,0,10,0,
0,0,2,64,0,0,
135,22,153,62,162,69,
22,63,213,120,233,61,
0,0,0,0,16,0,
0,10,34,0,16,0,
14,0,0,0,70,2,
16,0,11,0,0,0,
2,64,0,0,135,22,
153,62,162,69,22,63,
213,120,233,61,0,0,
0,0,16,0,0,10,
66,0,16,0,14,0,
0,0,70,2,16,0,
12,0,0,0,2,64,
0,0,135,22,153,62,
162,69,22,63,213,120,
233,61,0,0,0,0,
16,0,0,10,130,0,
16,0,14,0,0,0,
70,2,16,0,13,0,
0,0,2,64,0,0,
135,22,153,62,162,69,
22,63,213,120,233,61,
0,0,0,0,16,0,
0,10,18,0,16,0,
15,0,0,0,70,2,
16,0,10,0,0,0,
2,64,0,0,216,128,
24,63,27,133,140,190,
149,124,164,190,0,0,
0,0,16,0,0,10,
34,0,16,0,15,0,
0,0,70,2,16,0,
11,0,0,0,2,64,
0,0,216,128,24,63,
27,133,140,190,149,124,
164,190,0,0,0,0,
16,0,0,10,66,0,
16,0,15,0,0,0,
70,2,16,0,12,0,
0,0,2,64,0,0,
216,128,24,63,27,133,
140,190,149,124,164,190,
0,0,0,0,16,0,
0,10,130,0,16,0,
15,0,0,0,70,2,
16,0,13,0,0,0,
2,64,0,0,216,128,
24,63,27,133,140,190,
149,124,164,190,0,0,
0,0,16,0,0,10,
18,0,16,0,10,0,
0,0,70,2,16,0,
10,0,0,0,2,64,
0,0,236,135,88,62,
134,200,5,191,22,77,
159,62,0,0,0,0,
16,0,0,10,34,0,
16,0,10,0,0,0,
70,2,16,0,11,0,
0,0,2,64,0,0,
236,135,88,62,134,200,
5,191,22,77,159,62,
0,0,0,0,16,0,
0,10,66,0,16,0,
10,0,0,0,70,2,
16,0,12,0,0,0,
2,64,0,0,236,135,
88,62,134,200,5,191,
22,77,159,62,0,0,
0,0,16,0,0,10,
130,0,16,0,10,0,
0,0,70,2,16,0,
13,0,0,0,2,64,
0,0,236,135,88,62,
134,200,5,191,22,77,
159,62,0,0,0,0,
77,0,0,7,242,0,
16,0,9,0,0,0,
242,0,16,0,11,0,
0,0,70,14,16,0,
9,0,0,0,50,0,
0,9,242,0,16,0,
11,0,0,0,70,14,
16,0,15,0,0,0,
70,14,16,0,11,0,
0,0,70,14,16,0,
14,0,0,0,50,0,
0,9,242,0,16,0,
9,0,0,0,70,14,
16,0,10,0,0,0,
70,14,16,0,9,0,
0,0,70,14,16,0,
11,0,0,0,0,0,
0,10,242,0,16,0,
9,0,0,0,70,14,
16,0,9,0,0,0,
2,64,0,0,116,36,
143,63,116,36,143,63,
116,36,143,63,116,36,
143,63,50,0,0,15,
242,0,16,0,9,0,
0,0,70,14,16,0,
9,0,0,0,2,64,
0,0,255,255,127,63,
255,255,127,63,255,255,
127,63,255,255,127,63,
2,64,0,0,116,36,
143,191,116,36,143,191,
116,36,143,191,116,36,
143,191,50,0,0,10,
242,0,16,0,8,0,
0,0,86,5,16,0,
3,0,0,0,86,133,
32,0,1,0,0,0,
0,0,0,0,70,14,
16,0,8,0,0,0,
0,0,0,10,242,0,
16,0,8,0,0,0,
70,14,16,0,8,0,
0,0,2,64,0,0,
0,0,0,63,0,0,
0,63,0,0,0,63,
0,0,0,63,56,0,
0,10,242,0,16,0,
8,0,0,0,70,14,
16,0,8,0,0,0,
2,64,0,0,33,159,
148,68,33,159,148,68,
33,159,148,68,33,159,
148,68,56,0,0,10,
242,0,16,0,10,0,
0,0,70,14,16,0,
7,0,0,0,2,64,
0,0,222,64,204,61,
222,64,204,61,222,64,
204,61,222,64,204,61,
77,0,0,6,0,208,
0,0,242,0,16,0,
10,0,0,0,70,14,
16,0,10,0,0,0,
50,0,0,15,242,0,
16,0,10,0,0,0,
70,14,16,0,10,0,
0,0,2,64,0,0,
31,133,235,62,31,133,
235,62,31,133,235,62,
31,133,235,62,2,64,
0,0,113,61,10,63,
113,61,10,63,113,61,
10,63,113,61,10,63,
56,0,0,7,242,0,
16,0,11,0,0,0,
6,0,16,0,1,0,
0,0,70,14,16,0,
7,0,0,0,56,0,
0,7,242,0,16,0,
12,0,0,0,86,5,
16,0,1,0,0,0,
70,14,16,0,7,0,
0,0,56,0,0,7,
242,0,16,0,13,0,
0,0,166,10,16,0,
1,0,0,0,70,14,
16,0,7,0,0,0,
77,0,0,6,242,0,
16,0,14,0,0,0,
0,208,0,0,70,14,
16,0,11,0,0,0,
14,0,0,7,242,0,
16,0,14,0,0,0,
70,14,16,0,14,0,
0,0,70,14,16,0,
11,0,0,0,77,0,
0,6,242,0,16,0,
15,0,0,0,0,208,
0,0,70,14,16,0,
12,0,0,0,14,0,
0,7,242,0,16,0,
15,0,0,0,70,14,
16,0,15,0,0,0,
70,14,16,0,12,0,
0,0,77,0,0,6,
242,0,16,0,16,0,
0,0,0,208,0,0,
70,14,16,0,13,0,
0,0,14,0,0,7,
242,0,16,0,16,0,
0,0,70,14,16,0,
16,0,0,0,70,14,
16,0,13,0,0,0,
24,0,0,10,242,0,
16,0,11,0,0,0,
70,14,16,0,11,0,
0,0,2,64,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,55,0,
0,12,242,0,16,0,
11,0,0,0,70,14,
16,0,11,0,0,0,
2,64,0,0,0,0,
128,63,0,0,128,63,
0,0,128,63,0,0,
128,63,70,14,16,0,
14,0,0,0,24,0,
0,10,242,0,16,0,
12,0,0,0,70,14,
16,0,12,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,55,0,0,12,
242,0,16,0,12,0,
0,0,70,14,16,0,
12,0,0,0,2,64,
0,0,0,0,128,63,
0,0,128,63,0,0,
128,63,0,0,128,63,
70,14,16,0,15,0,
0,0,24,0,0,10,
242,0,16,0,13,0,
0,0,70,14,16,0,
13,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
55,0,0,12,242,0,
16,0,13,0,0,0,
70,14,16,0,13,0,
0,0,2,64,0,0,
0,0,128,63,0,0,
128,63,0,0,128,63,
0,0,128,63,70,14,
16,0,16,0,0,0,
56,0,0,7,242,0,
16,0,12,0,0,0,
166,10,16,0,2,0,
0,0,70,14,16,0,
12,0,0,0,50,0,
0,10,242,0,16,0,
11,0,0,0,70,14,
16,0,11,0,0,0,
86,5,16,0,2,0,
0,0,70,14,16,128,
65,0,0,0,12,0,
0,0,50,0,0,9,
242,0,16,0,11,0,
0,0,70,14,16,0,
13,0,0,0,246,15,
16,0,2,0,0,0,
70,14,16,0,11,0,
0,0,56,0,0,7,
242,0,16,0,11,0,
0,0,70,14,16,0,
10,0,0,0,70,14,
16,0,11,0,0,0,
56,0,0,7,242,0,
16,0,12,0,0,0,
246,15,16,0,1,0,
0,0,70,14,16,0,
7,0,0,0,77,0,
0,6,242,0,16,0,
13,0,0,0,0,208,
0,0,70,14,16,0,
12,0,0,0,14,0,
0,7,242,0,16,0,
13,0,0,0,70,14,
16,0,13,0,0,0,
70,14,16,0,12,0,
0,0,24,0,0,10,
242,0,16,0,12,0,
0,0,70,14,16,0,
12,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
55,0,0,12,242,0,
16,0,12,0,0,0,
70,14,16,0,12,0,
0,0,2,64,0,0,
0,0,128,63,0,0,
128,63,0,0,128,63,
0,0,128,63,70,14,
16,0,13,0,0,0,
56,0,0,7,242,0,
16,0,12,0,0,0,
6,0,16,0,0,0,
0,0,70,14,16,0,
12,0,0,0,56,0,
0,7,242,0,16,0,
12,0,0,0,70,14,
16,0,10,0,0,0,
70,14,16,0,12,0,
0,0,56,0,0,7,
242,0,16,0,7,0,
0,0,6,0,16,0,
2,0,0,0,70,14,
16,0,7,0,0,0,
77,0,0,6,242,0,
16,0,13,0,0,0,
0,208,0,0,70,14,
16,0,7,0,0,0,
14,0,0,7,242,0,
16,0,13,0,0,0,
70,14,16,0,13,0,
0,0,70,14,16,0,
7,0,0,0,24,0,
0,10,242,0,16,0,
7,0,0,0,70,14,
16,0,7,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,55,0,0,12,
242,0,16,0,7,0,
0,0,70,14,16,0,
7,0,0,0,2,64,
0,0,0,0,128,63,
0,0,128,63,0,0,
128,63,0,0,128,63,
70,14,16,0,13,0,
0,0,56,0,0,7,
242,0,16,0,7,0,
0,0,86,5,16,0,
0,0,0,0,70,14,
16,0,7,0,0,0,
56,0,0,7,242,0,
16,0,7,0,0,0,
70,14,16,0,7,0,
0,0,70,14,16,0,
10,0,0,0,50,0,
0,9,242,0,16,0,
4,0,0,0,70,14,
16,0,9,0,0,0,
70,14,16,0,11,0,
0,0,70,14,16,0,
4,0,0,0,77,0,
0,7,242,0,16,0,
8,0,0,0,242,0,
16,0,10,0,0,0,
70,14,16,0,8,0,
0,0,56,0,0,7,
242,0,16,0,10,0,
0,0,70,14,16,0,
9,0,0,0,70,14,
16,0,10,0,0,0,
50,0,0,9,242,0,
16,0,5,0,0,0,
70,14,16,0,10,0,
0,0,70,14,16,0,
12,0,0,0,70,14,
16,0,5,0,0,0,
56,0,0,7,242,0,
16,0,8,0,0,0,
70,14,16,0,8,0,
0,0,70,14,16,0,
9,0,0,0,50,0,
0,9,242,0,16,0,
6,0,0,0,70,14,
16,0,8,0,0,0,
70,14,16,0,7,0,
0,0,70,14,16,0,
6,0,0,0,0,0,
0,7,66,0,16,0,
0,0,0,0,42,0,
16,0,0,0,0,0,
1,64,0,0,0,0,
128,64,22,0,0,1,
17,0,0,10,18,0,
16,0,0,0,0,0,
70,14,16,0,4,0,
0,0,2,64,0,0,
0,0,128,63,0,0,
128,63,0,0,128,63,
0,0,128,63,17,0,
0,10,130,0,16,0,
0,0,0,0,70,14,
16,0,5,0,0,0,
2,64,0,0,0,0,
128,63,0,0,128,63,
0,0,128,63,0,0,
128,63,0,0,0,7,
34,0,16,0,0,0,
0,0,58,0,16,0,
0,0,0,0,58,0,
16,0,0,0,0,0,
17,0,0,10,130,0,
16,0,0,0,0,0,
70,14,16,0,6,0,
0,0,2,64,0,0,
0,0,128,63,0,0,
128,63,0,0,128,63,
0,0,128,63,0,0,
0,7,66,0,16,0,
0,0,0,0,58,0,
16,0,0,0,0,0,
58,0,16,0,0,0,
0,0,16,0,0,10,
18,32,16,0,0,0,
0,0,70,2,16,0,
0,0,0,0,2,64,
0,0,0,0,128,63,
106,188,116,63,219,249,
30,63,0,0,0,0,
16,0,0,10,34,32,
16,0,0,0,0,0,
70,2,16,0,0,0,
0,0,2,64,0,0,
0,0,128,63,150,67,
139,190,203,161,37,191,
0,0,0,0,16,0,
0,10,66,32,16,0,
0,0,0,0,70,2,
16,0,0,0,0,0,
2,64,0,0,0,0,
128,63,104,145,141,191,
231,251,217,63,0,0,
0,0,54,0,0,5,
130,32,16,0,0,0,
0,0,1,64,0,0,
0,0,128,63,62,0,
0,1,83,84,65,84,
148,0,0,0,101,0,
0,0,17,0,0,0,
0,0,0,0,2,0,
0,0,78,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
4,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,8,0,0,0,
5,0,0,0,0,0,
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


static const uint32_t sVertexHash[] = 
{
0x8d7c1562,0x97a9242f,0xbf8494c5,0x71b46398,0x640d0678,0x37fc69de,
0xf0c560c,0x7799ba2b
};


static const uint32_t sFragmentHash[] =
{
0xfb6ed813,0x3704e18b,0xa85643cb,0x9d52f1d,0x68320c34,0x24e3bc97,
0x93ec7f7e,0x7b2b095e
};

}

namespace RetroArch
{
class NtscShadersMameNtscMameNtscShaderDef : public ShaderDef
{
public:
	NtscShadersMameNtscMameNtscShaderDef() : ShaderDef{}
	{
		Name = "mame-ntsc";
		VertexByteCode = RetroArchNtscShadersMameNtscMameNtscShaderDefs::sVertexByteCode;
		VertexLength = sizeof(RetroArchNtscShadersMameNtscMameNtscShaderDefs::sVertexByteCode);
		VertexHash = RetroArchNtscShadersMameNtscMameNtscShaderDefs::sVertexHash;
		FragmentByteCode = RetroArchNtscShadersMameNtscMameNtscShaderDefs::sFragmentByteCode;
		FragmentLength = sizeof(RetroArchNtscShadersMameNtscMameNtscShaderDefs::sFragmentByteCode);
		FragmentHash = RetroArchNtscShadersMameNtscMameNtscShaderDefs::sFragmentHash;
		Format = "";
		Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("SourceSize", -1, 0, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OriginalSize", -1, 16, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OutputSize", -1, 32, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("FrameCount", -1, 48, 4, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
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
