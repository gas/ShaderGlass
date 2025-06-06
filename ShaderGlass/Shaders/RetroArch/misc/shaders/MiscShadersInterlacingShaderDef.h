/*
ShaderGlass shader misc/shaders\interlacing imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/misc/shaders/interlacing.slang
See original file for full credits and usage license with excerpts below. 
This file is auto-generated, do not modify directly.

// assume anything with a vertical resolution greater than 400 lines is interlaced

*/

#pragma once

namespace RetroArchMiscShadersInterlacingShaderDefs
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
68,88,66,67,47,119,
20,22,100,139,188,23,
172,201,24,27,224,54,
222,195,1,0,0,0,
156,6,0,0,5,0,
0,0,52,0,0,0,
100,3,0,0,152,3,
0,0,204,3,0,0,
0,6,0,0,82,68,
69,70,40,3,0,0,
1,0,0,0,184,0,
0,0,3,0,0,0,
60,0,0,0,0,5,
255,255,0,129,0,0,
0,3,0,0,82,68,
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
0,0,7,0,0,0,
208,0,0,0,64,0,
0,0,0,0,0,0,
0,0,0,0,232,1,
0,0,0,0,0,0,
16,0,0,0,0,0,
0,0,4,2,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,40,2,0,0,
16,0,0,0,16,0,
0,0,2,0,0,0,
4,2,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
63,2,0,0,32,0,
0,0,16,0,0,0,
2,0,0,0,4,2,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,84,2,
0,0,48,0,0,0,
4,0,0,0,2,0,
0,0,112,2,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,148,2,0,0,
52,0,0,0,4,0,
0,0,2,0,0,0,
172,2,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
208,2,0,0,56,0,
0,0,4,0,0,0,
2,0,0,0,172,2,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,230,2,
0,0,60,0,0,0,
4,0,0,0,2,0,
0,0,172,2,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,114,101,103,105,
115,116,101,114,115,95,
79,117,116,112,117,116,
83,105,122,101,0,102,
108,111,97,116,52,0,
1,0,3,0,1,0,
4,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,253,1,0,0,
114,101,103,105,115,116,
101,114,115,95,79,114,
105,103,105,110,97,108,
83,105,122,101,0,114,
101,103,105,115,116,101,
114,115,95,83,111,117,
114,99,101,83,105,122,
101,0,114,101,103,105,
115,116,101,114,115,95,
70,114,97,109,101,67,
111,117,110,116,0,100,
119,111,114,100,0,171,
0,0,19,0,1,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,105,2,0,0,
114,101,103,105,115,116,
101,114,115,95,112,101,
114,99,101,110,116,0,
102,108,111,97,116,0,
0,0,3,0,1,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,166,2,0,0,
114,101,103,105,115,116,
101,114,115,95,101,110,
97,98,108,101,95,52,
56,48,105,0,114,101,
103,105,115,116,101,114,
115,95,116,111,112,95,
102,105,101,108,100,95,
102,105,114,115,116,0,
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
83,72,69,88,44,2,
0,0,80,0,0,0,
139,0,0,0,106,8,
0,1,89,0,0,4,
70,142,32,0,1,0,
0,0,4,0,0,0,
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
86,0,0,6,18,0,
16,0,0,0,0,0,
10,128,32,0,1,0,
0,0,3,0,0,0,
56,0,0,8,34,0,
16,0,0,0,0,0,
26,16,16,0,0,0,
0,0,26,128,32,0,
1,0,0,0,2,0,
0,0,50,0,0,10,
18,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,42,128,
32,0,1,0,0,0,
3,0,0,0,26,0,
16,0,0,0,0,0,
50,0,0,10,34,0,
16,0,0,0,0,0,
26,0,16,0,0,0,
0,0,1,64,0,0,
4,0,0,64,58,128,
32,0,1,0,0,0,
3,0,0,0,0,0,
0,8,18,0,16,0,
0,0,0,0,10,0,
16,0,0,0,0,0,
58,128,32,0,1,0,
0,0,3,0,0,0,
49,0,0,8,66,0,
16,0,0,0,0,0,
1,64,0,0,0,0,
200,67,26,128,32,0,
1,0,0,0,1,0,
0,0,55,0,0,9,
18,0,16,0,0,0,
0,0,42,0,16,0,
0,0,0,0,10,0,
16,0,0,0,0,0,
26,0,16,0,0,0,
0,0,56,0,0,7,
34,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,1,64,
0,0,42,0,0,63,
65,0,0,5,34,0,
16,0,0,0,0,0,
26,0,16,0,0,0,
0,0,50,0,0,10,
18,0,16,0,0,0,
0,0,26,0,16,128,
65,0,0,0,0,0,
0,0,1,64,0,0,
172,255,255,63,10,0,
16,0,0,0,0,0,
49,0,0,7,18,0,
16,0,0,0,0,0,
1,64,0,0,88,255,
127,63,10,0,16,0,
0,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,242,0,
16,0,1,0,0,0,
70,16,16,0,0,0,
0,0,70,126,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
56,0,0,8,242,0,
16,0,2,0,0,0,
70,14,16,0,1,0,
0,0,86,133,32,0,
1,0,0,0,3,0,
0,0,55,0,0,9,
242,32,16,0,0,0,
0,0,6,0,16,0,
0,0,0,0,70,14,
16,0,1,0,0,0,
70,14,16,0,2,0,
0,0,62,0,0,1,
83,84,65,84,148,0,
0,0,15,0,0,0,
3,0,0,0,0,0,
0,0,2,0,0,0,
10,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,1,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,2,0,
0,0,2,0,0,0,
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
0xafd9c0f5,0x39da8177,0x5fb0de00,0x7a2b68a6,0xc43c0456,0x3984e857,
0xa97576f,0x73d45960
};


static const uint32_t sFragmentHash[] =
{
0xac77ee68,0x63c58e4a,0xd304a4ba,0xdee20ef6,0x286c1098,0x4b437b6d,
0x89656b66,0x9d9d0d10
};

}

namespace RetroArch
{
class MiscShadersInterlacingShaderDef : public ShaderDef
{
public:
	MiscShadersInterlacingShaderDef() : ShaderDef{}
	{
		Name = "interlacing";
		VertexByteCode = RetroArchMiscShadersInterlacingShaderDefs::sVertexByteCode;
		VertexLength = sizeof(RetroArchMiscShadersInterlacingShaderDefs::sVertexByteCode);
		VertexHash = RetroArchMiscShadersInterlacingShaderDefs::sVertexHash;
		FragmentByteCode = RetroArchMiscShadersInterlacingShaderDefs::sFragmentByteCode;
		FragmentLength = sizeof(RetroArchMiscShadersInterlacingShaderDefs::sFragmentByteCode);
		FragmentHash = RetroArchMiscShadersInterlacingShaderDefs::sFragmentHash;
		Format = "";
		Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OutputSize", -1, 0, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OriginalSize", -1, 16, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("SourceSize", -1, 32, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("FrameCount", -1, 48, 4, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("percent", -1, 52, 4, 0.000000f, 1.000000f, 0.000000f, 0.050000f, "Interlacing Scanline Bright %"));
		Params.push_back(ShaderParam("enable_480i", -1, 56, 4, 0.000000f, 1.000000f, 1.000000f, 1.000000f, "Enable 480i Mode"));
		Params.push_back(ShaderParam("top_field_first", -1, 60, 4, 0.000000f, 1.000000f, 0.000000f, 1.000000f, "Top Field First Enable"));
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
