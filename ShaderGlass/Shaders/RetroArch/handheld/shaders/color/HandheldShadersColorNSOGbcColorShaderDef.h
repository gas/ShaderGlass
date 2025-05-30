/*
ShaderGlass shader handheld/shaders/color\NSO-gbc-color imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/handheld/shaders/color/NSO-gbc-color.slang
See original file for full credits and usage license with excerpts below. 
This file is auto-generated, do not modify directly.

// Shader that replicates the Nintendo Switch Online's GBC color filter --
// (Experimental WIP shader. Due to how complex the NSO GBC filter used (using different gamma ramps and greyscale temperatures), it couldn't be replicated to a shader as of now completely, so a side effect of using correct color metrics for RGB, is warm greyscales. This is not an issue with NSO GBA Filter which was easy to replicate. If you want an actual NSO GBC replication, use Reshade NSO-GBC shader pack instead that uses Reshade LUT shader)
// bring out our stored luminance value
// our adjustments need to happen in linear gamma

*/

#pragma once

namespace RetroArchHandheldShadersColorNSOGbcColorShaderDefs
{
static const BYTE sVertexByteCode[] =
{
68,88,66,67,76,87,
98,134,249,27,124,187,
60,215,206,32,183,249,
126,245,1,0,0,0,
160,6,0,0,5,0,
0,0,52,0,0,0,
120,2,0,0,196,2,
0,0,124,3,0,0,
4,6,0,0,82,68,
69,70,60,2,0,0,
1,0,0,0,96,0,
0,0,1,0,0,0,
60,0,0,0,0,5,
254,255,0,129,0,0,
20,2,0,0,82,68,
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
92,0,0,0,5,0,
0,0,120,0,0,0,
128,0,0,0,0,0,
0,0,0,0,0,0,
64,1,0,0,0,0,
0,0,64,0,0,0,
2,0,0,0,84,1,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,120,1,
0,0,64,0,0,0,
16,0,0,0,0,0,
0,0,148,1,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,184,1,0,0,
80,0,0,0,16,0,
0,0,0,0,0,0,
148,1,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
204,1,0,0,96,0,
0,0,16,0,0,0,
0,0,0,0,148,1,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,222,1,
0,0,112,0,0,0,
4,0,0,0,2,0,
0,0,240,1,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,103,108,111,98,
97,108,95,77,86,80,
0,102,108,111,97,116,
52,120,52,0,2,0,
3,0,4,0,4,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
75,1,0,0,103,108,
111,98,97,108,95,79,
117,116,112,117,116,83,
105,122,101,0,102,108,
111,97,116,52,0,171,
171,171,1,0,3,0,
1,0,4,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,138,1,
0,0,103,108,111,98,
97,108,95,79,114,105,
103,105,110,97,108,83,
105,122,101,0,103,108,
111,98,97,108,95,83,
111,117,114,99,101,83,
105,122,101,0,103,108,
111,98,97,108,95,109,
111,100,101,0,102,108,
111,97,116,0,0,0,
3,0,1,0,1,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
234,1,0,0,77,105,
99,114,111,115,111,102,
116,32,40,82,41,32,
72,76,83,76,32,83,
104,97,100,101,114,32,
67,111,109,112,105,108,
101,114,32,49,48,46,
49,0,73,83,71,78,
68,0,0,0,2,0,
0,0,8,0,0,0,
56,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,15,15,0,0,
56,0,0,0,1,0,
0,0,0,0,0,0,
3,0,0,0,1,0,
0,0,3,3,0,0,
84,69,88,67,79,79,
82,68,0,171,171,171,
79,83,71,78,176,0,
0,0,6,0,0,0,
8,0,0,0,152,0,
0,0,0,0,0,0,
0,0,0,0,3,0,
0,0,0,0,0,0,
3,12,0,0,152,0,
0,0,1,0,0,0,
0,0,0,0,3,0,
0,0,1,0,0,0,
15,0,0,0,152,0,
0,0,2,0,0,0,
0,0,0,0,3,0,
0,0,2,0,0,0,
15,0,0,0,152,0,
0,0,3,0,0,0,
0,0,0,0,3,0,
0,0,3,0,0,0,
15,0,0,0,152,0,
0,0,4,0,0,0,
0,0,0,0,3,0,
0,0,4,0,0,0,
15,0,0,0,161,0,
0,0,0,0,0,0,
1,0,0,0,3,0,
0,0,5,0,0,0,
15,0,0,0,84,69,
88,67,79,79,82,68,
0,83,86,95,80,111,
115,105,116,105,111,110,
0,171,171,171,83,72,
69,88,128,2,0,0,
80,0,1,0,160,0,
0,0,106,8,0,1,
89,0,0,4,70,142,
32,0,0,0,0,0,
8,0,0,0,95,0,
0,3,242,16,16,0,
0,0,0,0,95,0,
0,3,50,16,16,0,
1,0,0,0,101,0,
0,3,50,32,16,0,
0,0,0,0,101,0,
0,3,242,32,16,0,
1,0,0,0,101,0,
0,3,242,32,16,0,
2,0,0,0,101,0,
0,3,242,32,16,0,
3,0,0,0,101,0,
0,3,242,32,16,0,
4,0,0,0,103,0,
0,4,242,32,16,0,
5,0,0,0,1,0,
0,0,104,0,0,2,
2,0,0,0,54,0,
0,5,50,32,16,0,
0,0,0,0,70,16,
16,0,1,0,0,0,
27,0,0,6,18,0,
16,0,0,0,0,0,
10,128,32,0,0,0,
0,0,7,0,0,0,
32,0,0,10,114,0,
16,0,0,0,0,0,
6,0,16,0,0,0,
0,0,2,64,0,0,
1,0,0,0,2,0,
0,0,3,0,0,0,
0,0,0,0,60,0,
0,7,34,0,16,0,
0,0,0,0,26,0,
16,0,0,0,0,0,
42,0,16,0,0,0,
0,0,60,0,0,7,
66,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,26,0,
16,0,0,0,0,0,
1,0,0,10,242,0,
16,0,1,0,0,0,
86,5,16,0,0,0,
0,0,2,64,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,128,63,55,0,
0,12,242,32,16,0,
4,0,0,0,6,0,
16,0,0,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,154,153,
89,63,70,14,16,0,
1,0,0,0,1,0,
0,10,242,32,16,0,
1,0,0,0,166,10,
16,0,0,0,0,0,
2,64,0,0,61,10,
87,63,20,174,135,62,
0,0,0,0,51,51,
51,62,1,0,0,10,
242,32,16,0,2,0,
0,0,166,10,16,0,
0,0,0,0,2,64,
0,0,61,10,215,61,
31,133,43,63,143,194,
117,62,236,81,56,62,
1,0,0,10,242,32,
16,0,3,0,0,0,
166,10,16,0,0,0,
0,0,2,64,0,0,
154,153,25,62,154,153,
153,62,102,102,6,63,
236,81,56,62,56,0,
0,8,242,0,16,0,
0,0,0,0,86,21,
16,0,0,0,0,0,
70,142,32,0,0,0,
0,0,1,0,0,0,
50,0,0,10,242,0,
16,0,0,0,0,0,
6,16,16,0,0,0,
0,0,70,142,32,0,
0,0,0,0,0,0,
0,0,70,14,16,0,
0,0,0,0,50,0,
0,10,242,0,16,0,
0,0,0,0,166,26,
16,0,0,0,0,0,
70,142,32,0,0,0,
0,0,2,0,0,0,
70,14,16,0,0,0,
0,0,50,0,0,10,
242,32,16,0,5,0,
0,0,246,31,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
3,0,0,0,70,14,
16,0,0,0,0,0,
62,0,0,1,83,84,
65,84,148,0,0,0,
15,0,0,0,2,0,
0,0,0,0,0,0,
8,0,0,0,4,0,
0,0,1,0,0,0,
6,0,0,0,1,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,1,0,
0,0,1,0,0,0,
1,0,0,0,0,0,
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


static const BYTE sFragmentByteCode[] =
{
68,88,66,67,105,233,
161,165,234,174,29,74,
194,110,47,59,179,103,
138,241,1,0,0,0,
232,3,0,0,5,0,
0,0,52,0,0,0,
248,0,0,0,140,1,
0,0,192,1,0,0,
76,3,0,0,82,68,
69,70,188,0,0,0,
0,0,0,0,0,0,
0,0,2,0,0,0,
60,0,0,0,0,5,
255,255,0,129,0,0,
147,0,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
124,0,0,0,3,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,2,0,0,0,
1,0,0,0,1,0,
0,0,140,0,0,0,
2,0,0,0,5,0,
0,0,4,0,0,0,
255,255,255,255,2,0,
0,0,1,0,0,0,
13,0,0,0,95,83,
111,117,114,99,101,95,
115,97,109,112,108,101,
114,0,83,111,117,114,
99,101,0,77,105,99,
114,111,115,111,102,116,
32,40,82,41,32,72,
76,83,76,32,83,104,
97,100,101,114,32,67,
111,109,112,105,108,101,
114,32,49,48,46,49,
0,171,73,83,71,78,
140,0,0,0,5,0,
0,0,8,0,0,0,
128,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,3,3,0,0,
128,0,0,0,1,0,
0,0,0,0,0,0,
3,0,0,0,1,0,
0,0,15,15,0,0,
128,0,0,0,2,0,
0,0,0,0,0,0,
3,0,0,0,2,0,
0,0,15,15,0,0,
128,0,0,0,3,0,
0,0,0,0,0,0,
3,0,0,0,3,0,
0,0,15,15,0,0,
128,0,0,0,4,0,
0,0,0,0,0,0,
3,0,0,0,4,0,
0,0,15,15,0,0,
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
69,88,132,1,0,0,
80,0,0,0,97,0,
0,0,106,8,0,1,
90,0,0,3,0,96,
16,0,2,0,0,0,
88,24,0,4,0,112,
16,0,2,0,0,0,
85,85,0,0,98,16,
0,3,50,16,16,0,
0,0,0,0,98,16,
0,3,242,16,16,0,
1,0,0,0,98,16,
0,3,242,16,16,0,
2,0,0,0,98,16,
0,3,242,16,16,0,
3,0,0,0,98,16,
0,3,242,16,16,0,
4,0,0,0,101,0,
0,3,242,32,16,0,
0,0,0,0,104,0,
0,2,1,0,0,0,
69,0,0,139,194,0,
0,128,67,85,21,0,
242,0,16,0,0,0,
0,0,70,16,16,0,
0,0,0,0,70,126,
16,0,2,0,0,0,
0,96,16,0,2,0,
0,0,47,0,0,5,
242,0,16,0,0,0,
0,0,70,14,16,0,
0,0,0,0,56,0,
0,10,242,0,16,0,
0,0,0,0,70,14,
16,0,0,0,0,0,
2,64,0,0,82,184,
158,63,205,204,76,63,
51,51,51,63,0,0,
128,63,25,0,0,5,
242,0,16,0,0,0,
0,0,70,14,16,0,
0,0,0,0,56,32,
0,7,242,0,16,0,
0,0,0,0,70,14,
16,0,0,0,0,0,
246,31,16,0,4,0,
0,0,17,0,0,7,
18,32,16,0,0,0,
0,0,70,14,16,0,
0,0,0,0,70,30,
16,0,1,0,0,0,
17,0,0,7,34,32,
16,0,0,0,0,0,
70,14,16,0,0,0,
0,0,70,30,16,0,
2,0,0,0,17,0,
0,7,66,32,16,0,
0,0,0,0,70,14,
16,0,0,0,0,0,
70,30,16,0,3,0,
0,0,17,0,0,7,
130,32,16,0,0,0,
0,0,70,14,16,0,
0,0,0,0,70,30,
16,0,4,0,0,0,
62,0,0,1,83,84,
65,84,148,0,0,0,
10,0,0,0,1,0,
0,0,0,0,0,0,
6,0,0,0,8,0,
0,0,0,0,0,0,
0,0,0,0,1,0,
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
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0
};


static const uint32_t sVertexHash[] = 
{
0x1ef1a078,0xbb0bb9f5,0x5493f38c,0x8651eb4f,0xc70ad5db,0x220ad762,
0xeb57cf5a,0x5575365c
};


static const uint32_t sFragmentHash[] =
{
0x8e52430e,0x45d25831,0x86711418,0x5b3af51f,0x2a64f64d,0xdfba42a9,
0x7ef4d220,0x17cbba7c
};

}

namespace RetroArch
{
class HandheldShadersColorNSOGbcColorShaderDef : public ShaderDef
{
public:
	HandheldShadersColorNSOGbcColorShaderDef() : ShaderDef{}
	{
		Name = "NSO-gbc-color";
		VertexByteCode = RetroArchHandheldShadersColorNSOGbcColorShaderDefs::sVertexByteCode;
		VertexLength = sizeof(RetroArchHandheldShadersColorNSOGbcColorShaderDefs::sVertexByteCode);
		VertexHash = RetroArchHandheldShadersColorNSOGbcColorShaderDefs::sVertexHash;
		FragmentByteCode = RetroArchHandheldShadersColorNSOGbcColorShaderDefs::sFragmentByteCode;
		FragmentLength = sizeof(RetroArchHandheldShadersColorNSOGbcColorShaderDefs::sFragmentByteCode);
		FragmentHash = RetroArchHandheldShadersColorNSOGbcColorShaderDefs::sFragmentHash;
		Format = "";
		Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OutputSize", 0, 64, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OriginalSize", 0, 80, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("SourceSize", 0, 96, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("mode", 0, 112, 4, 1.000000f, 3.000000f, 1.000000f, 1.000000f, "Color Profile (1=sRGB, 2=DCI, 3=Rec2020)"));
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
