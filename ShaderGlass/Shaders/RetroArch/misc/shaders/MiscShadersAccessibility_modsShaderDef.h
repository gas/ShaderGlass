/*
ShaderGlass shader misc/shaders\accessibility_mods imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/misc/shaders/accessibility_mods.slang
See original file for full credits and usage license with excerpts below. 
This file is auto-generated, do not modify directly.

// Accessibility Mods
// based on work by Karen Stevens for Electronic Arts
// adapted for slang by hunterk
// RGB to LMS and back again
// https://ssodelta.wordpress.com/tag/rgb-to-lms/
// This function draws heavily from Karen Stevens' Daltonization work, found here:
// https://twvideo01.ubm-us.net/o1/vault/gdc2017/Presentations/Stevens_Karen_GameAccessibilityPracticalFixes.pdf

*/

#pragma once

namespace RetroArchMiscShadersAccessibility_modsShaderDefs
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
68,88,66,67,134,15,
144,141,105,37,133,46,
6,148,248,199,61,52,
126,67,1,0,0,0,
204,9,0,0,5,0,
0,0,52,0,0,0,
0,4,0,0,52,4,
0,0,104,4,0,0,
48,9,0,0,82,68,
69,70,196,3,0,0,
1,0,0,0,184,0,
0,0,3,0,0,0,
60,0,0,0,0,5,
255,255,0,129,0,0,
156,3,0,0,82,68,
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
0,0,10,0,0,0,
208,0,0,0,80,0,
0,0,0,0,0,0,
0,0,0,0,96,2,
0,0,0,0,0,0,
16,0,0,0,0,0,
0,0,124,2,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,160,2,0,0,
16,0,0,0,16,0,
0,0,0,0,0,0,
124,2,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
180,2,0,0,32,0,
0,0,16,0,0,0,
0,0,0,0,124,2,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,198,2,
0,0,48,0,0,0,
4,0,0,0,0,0,
0,0,224,2,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,4,3,0,0,
52,0,0,0,4,0,
0,0,2,0,0,0,
28,3,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
64,3,0,0,56,0,
0,0,4,0,0,0,
2,0,0,0,28,3,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,84,3,
0,0,60,0,0,0,
4,0,0,0,2,0,
0,0,28,3,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,102,3,0,0,
64,0,0,0,4,0,
0,0,2,0,0,0,
28,3,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
118,3,0,0,68,0,
0,0,4,0,0,0,
2,0,0,0,28,3,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,136,3,
0,0,72,0,0,0,
4,0,0,0,2,0,
0,0,28,3,0,0,
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
0,0,114,2,0,0,
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
216,2,0,0,112,97,
114,97,109,115,95,80,
114,111,116,97,110,111,
112,105,97,0,102,108,
111,97,116,0,0,0,
3,0,1,0,1,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
22,3,0,0,112,97,
114,97,109,115,95,68,
101,117,116,101,114,97,
110,111,112,105,97,0,
112,97,114,97,109,115,
95,84,114,105,116,97,
110,111,112,105,97,0,
112,97,114,97,109,115,
95,68,95,102,97,99,
116,111,114,0,112,97,
114,97,109,115,95,68,
95,99,111,110,116,114,
97,115,116,0,112,97,
114,97,109,115,95,68,
95,98,114,105,103,104,
116,110,101,115,115,0,
77,105,99,114,111,115,
111,102,116,32,40,82,
41,32,72,76,83,76,
32,83,104,97,100,101,
114,32,67,111,109,112,
105,108,101,114,32,49,
48,46,49,0,73,83,
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
83,72,69,88,192,4,
0,0,80,0,0,0,
48,1,0,0,106,8,
0,1,89,0,0,4,
70,142,32,0,1,0,
0,0,5,0,0,0,
90,0,0,3,0,96,
16,0,2,0,0,0,
88,24,0,4,0,112,
16,0,2,0,0,0,
85,85,0,0,98,16,
0,3,50,16,16,0,
0,0,0,0,101,0,
0,3,242,32,16,0,
0,0,0,0,104,0,
0,2,3,0,0,0,
50,0,0,10,18,0,
16,0,0,0,0,0,
26,128,32,0,1,0,
0,0,4,0,0,0,
1,64,0,0,0,0,
160,64,1,64,0,0,
0,0,128,63,69,0,
0,139,194,0,0,128,
67,85,21,0,226,0,
16,0,0,0,0,0,
70,16,16,0,0,0,
0,0,54,121,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
0,0,0,10,114,0,
16,0,1,0,0,0,
150,7,16,0,0,0,
0,0,2,64,0,0,
0,0,0,191,0,0,
0,191,0,0,0,191,
0,0,0,0,50,0,
0,12,114,0,16,0,
1,0,0,0,70,2,
16,0,1,0,0,0,
6,0,16,0,0,0,
0,0,2,64,0,0,
0,0,0,63,0,0,
0,63,0,0,0,63,
0,0,0,0,0,0,
0,8,114,0,16,0,
1,0,0,0,150,7,
16,128,65,0,0,0,
0,0,0,0,70,2,
16,0,1,0,0,0,
50,0,0,10,114,0,
16,0,0,0,0,0,
6,128,32,0,1,0,
0,0,4,0,0,0,
70,2,16,0,1,0,
0,0,150,7,16,0,
0,0,0,0,50,0,
0,11,114,0,16,0,
0,0,0,0,166,138,
32,0,1,0,0,0,
4,0,0,0,6,128,
32,0,1,0,0,0,
4,0,0,0,70,2,
16,0,0,0,0,0,
16,0,0,10,130,0,
16,0,0,0,0,0,
70,2,16,0,0,0,
0,0,2,64,0,0,
78,209,131,64,145,126,
119,64,168,198,187,63,
0,0,0,0,16,0,
0,10,18,0,16,0,
1,0,0,0,70,2,
16,0,0,0,0,0,
2,64,0,0,125,16,
46,66,66,62,217,65,
195,187,60,62,0,0,
0,0,56,0,0,7,
34,0,16,0,1,0,
0,0,10,0,16,0,
1,0,0,0,1,64,
0,0,123,21,77,63,
16,0,0,10,66,0,
16,0,1,0,0,0,
70,2,16,0,0,0,
0,0,2,64,0,0,
40,15,143,65,48,42,
93,64,173,110,245,60,
0,0,0,0,50,0,
0,9,34,0,16,0,
1,0,0,0,42,0,
16,0,1,0,0,0,
1,64,0,0,28,181,
202,190,26,0,16,0,
1,0,0,0,0,0,
0,8,34,0,16,0,
1,0,0,0,58,0,
16,128,65,0,0,0,
0,0,0,0,26,0,
16,0,1,0,0,0,
50,0,0,10,66,0,
16,0,2,0,0,0,
58,128,32,0,1,0,
0,0,3,0,0,0,
26,0,16,0,1,0,
0,0,58,0,16,0,
0,0,0,0,56,0,
0,10,162,0,16,0,
1,0,0,0,246,15,
16,0,0,0,0,0,
2,64,0,0,0,0,
0,0,100,204,33,64,
0,0,0,0,80,199,
159,63,50,0,0,10,
130,0,16,0,0,0,
0,0,10,0,16,0,
1,0,0,0,1,64,
0,0,10,128,1,64,
26,0,16,128,65,0,
0,0,1,0,0,0,
50,0,0,9,34,0,
16,0,1,0,0,0,
42,0,16,0,1,0,
0,0,1,64,0,0,
179,8,253,62,58,0,
16,0,1,0,0,0,
0,0,0,8,34,0,
16,0,1,0,0,0,
10,0,16,128,65,0,
0,0,1,0,0,0,
26,0,16,0,1,0,
0,0,50,0,0,10,
34,0,16,0,2,0,
0,0,42,128,32,0,
1,0,0,0,3,0,
0,0,26,0,16,0,
1,0,0,0,10,0,
16,0,1,0,0,0,
0,0,0,8,130,0,
16,0,0,0,0,0,
42,0,16,128,65,0,
0,0,1,0,0,0,
58,0,16,0,0,0,
0,0,50,0,0,10,
18,0,16,0,2,0,
0,0,26,128,32,0,
1,0,0,0,3,0,
0,0,58,0,16,0,
0,0,0,0,42,0,
16,0,1,0,0,0,
16,0,0,10,18,0,
16,0,1,0,0,0,
70,2,16,0,2,0,
0,0,2,64,0,0,
230,174,165,61,231,29,
39,188,82,73,157,185,
0,0,0,0,16,0,
0,10,34,0,16,0,
1,0,0,0,70,2,
16,0,2,0,0,0,
2,64,0,0,203,161,
5,190,27,47,93,61,
75,89,134,187,0,0,
0,0,16,0,0,10,
66,0,16,0,1,0,
0,0,70,2,16,0,
2,0,0,0,2,64,
0,0,105,0,239,61,
30,167,232,189,55,137,
49,63,0,0,0,0,
0,0,0,8,114,0,
16,0,1,0,0,0,
70,2,16,0,0,0,
0,0,70,2,16,128,
65,0,0,0,1,0,
0,0,0,0,0,7,
98,0,16,0,1,0,
0,0,6,0,16,0,
1,0,0,0,86,6,
16,0,1,0,0,0,
54,0,0,5,18,0,
16,0,1,0,0,0,
1,64,0,0,0,0,
0,0,0,32,0,7,
114,0,16,0,1,0,
0,0,70,2,16,0,
0,0,0,0,70,2,
16,0,1,0,0,0,
0,0,0,8,114,0,
16,0,1,0,0,0,
70,2,16,128,65,0,
0,0,0,0,0,0,
70,2,16,0,1,0,
0,0,50,0,0,10,
114,32,16,0,0,0,
0,0,6,128,32,0,
1,0,0,0,4,0,
0,0,70,2,16,0,
1,0,0,0,70,2,
16,0,0,0,0,0,
54,0,0,5,130,32,
16,0,0,0,0,0,
1,64,0,0,0,0,
128,63,62,0,0,1,
83,84,65,84,148,0,
0,0,32,0,0,0,
3,0,0,0,0,0,
0,0,2,0,0,0,
28,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,1,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
2,0,0,0,0,0,
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
0,0,0,0,0,0
};


static const uint32_t sVertexHash[] = 
{
0xbe54d74a,0x2a9be2e,0xf4fa4d9a,0xf30356d1,0xd82be227,0xf486894,
0x9e9fdb3,0x92138062
};


static const uint32_t sFragmentHash[] =
{
0xf0bbdf3e,0x93d6f70,0x14c402ee,0xc08b229b,0x65bca260,0xdf756929,
0x69a235b5,0x6d642ebe
};

}

namespace RetroArch
{
class MiscShadersAccessibility_modsShaderDef : public ShaderDef
{
public:
	MiscShadersAccessibility_modsShaderDef() : ShaderDef{}
	{
		Name = "accessibility_mods";
		VertexByteCode = RetroArchMiscShadersAccessibility_modsShaderDefs::sVertexByteCode;
		VertexLength = sizeof(RetroArchMiscShadersAccessibility_modsShaderDefs::sVertexByteCode);
		VertexHash = RetroArchMiscShadersAccessibility_modsShaderDefs::sVertexHash;
		FragmentByteCode = RetroArchMiscShadersAccessibility_modsShaderDefs::sFragmentByteCode;
		FragmentLength = sizeof(RetroArchMiscShadersAccessibility_modsShaderDefs::sFragmentByteCode);
		FragmentHash = RetroArchMiscShadersAccessibility_modsShaderDefs::sFragmentHash;
		Format = "";
		Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("SourceSize", -1, 0, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OriginalSize", -1, 16, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OutputSize", -1, 32, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("FrameCount", -1, 48, 4, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("Protanopia", -1, 52, 4, 0.000000f, 1.000000f, 0.000000f, 1.000000f, "Protanopia Correction Toggle"));
		Params.push_back(ShaderParam("Deuteranopia", -1, 56, 4, 0.000000f, 1.000000f, 0.000000f, 1.000000f, "Deuteranopia Correction Toggle"));
		Params.push_back(ShaderParam("Tritanopia", -1, 60, 4, 0.000000f, 1.000000f, 0.000000f, 1.000000f, "Tritanopia Correction Toggle"));
		Params.push_back(ShaderParam("D_factor", -1, 64, 4, 0.000000f, 1.000000f, 0.500000f, 0.050000f, "Accessibility Adjustment Strength"));
		Params.push_back(ShaderParam("D_contrast", -1, 68, 4, 0.000000f, 1.000000f, 0.000000f, 0.050000f, "Contrast Adjustment"));
		Params.push_back(ShaderParam("D_brightness", -1, 72, 4, -1.000000f, 1.000000f, 0.000000f, 0.050000f, "Brightness Adjustment"));
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
