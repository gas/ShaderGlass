/*
ShaderGlass: shader effect overlay
Copyright (C) 2021-2025 mausimus (mausimus.net)
https://github.com/mausimus/ShaderGlass
GNU General Public License v3.0
*/

#pragma once

namespace PassthroughShaderDefs
{
const BYTE sVertexByteCode[] = {
    68,  88,  66,  67,  110, 239, 1,   38,  44,  138, 120, 137, 121, 214, 212, 137, 93,  170, 129, 5,   1,   0,   0,   0,   140, 3,   0,   0,   5,   0,   0,   0,   52,  0,  0,
    0,   60,  1,   0,   0,   136, 1,   0,   0,   224, 1,   0,   0,   240, 2,   0,   0,   82,  68,  69,  70,  0,   1,   0,   0,   1,   0,   0,   0,   96,  0,   0,   0,   1,  0,
    0,   0,   60,  0,   0,   0,   0,   5,   254, 255, 0,   129, 0,   0,   216, 0,   0,   0,   82,  68,  49,  49,  60,  0,   0,   0,   24,  0,   0,   0,   32,  0,   0,   0,  40,
    0,   0,   0,   36,  0,   0,   0,   12,  0,   0,   0,   0,   0,   0,   0,   92,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,
    0,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   85,  66,  79,  0,   92,  0,   0,   0,   1,   0,   0,   0,   120, 0,   0,   0,   64,  0,   0,   0,   0,   0,  0,
    0,   0,   0,   0,   0,   160, 0,   0,   0,   0,   0,   0,   0,   64,  0,   0,   0,   2,   0,   0,   0,   180, 0,   0,   0,   0,   0,   0,   0,   255, 255, 255, 255, 0,  0,
    0,   0,   255, 255, 255, 255, 0,   0,   0,   0,   103, 108, 111, 98,  97,  108, 95,  77,  86,  80,  0,   102, 108, 111, 97,  116, 52,  120, 52,  0,   2,   0,   3,   0,  4,
    0,   4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   171, 0,   0,   0,   77,  105, 99, 114,
    111, 115, 111, 102, 116, 32,  40,  82,  41,  32,  72,  76,  83,  76,  32,  83,  104, 97,  100, 101, 114, 32,  67,  111, 109, 112, 105, 108, 101, 114, 32,  49,  48,  46, 49,
    0,   73,  83,  71,  78,  68,  0,   0,   0,   2,   0,   0,   0,   8,   0,   0,   0,   56,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,   0,   0,   0,   0,  0,
    0,   0,   15,  15,  0,   0,   56,  0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   3,   0,   0,   0,   1,   0,   0,   0,   3,   3,   0,   0,   84,  69,  88,  67, 79,
    79,  82,  68,  0,   171, 171, 171, 79,  83,  71,  78,  80,  0,   0,   0,   2,   0,   0,   0,   8,   0,   0,   0,   56,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,
    3,   0,   0,   0,   0,   0,   0,   0,   3,   12,  0,   0,   65,  0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   3,   0,   0,   0,   1,   0,   0,   0,   15,  0,  0,
    0,   84,  69,  88,  67,  79,  79,  82,  68,  0,   83,  86,  95,  80,  111, 115, 105, 116, 105, 111, 110, 0,   171, 171, 171, 83,  72,  69,  88,  8,   1,   0,   0,   80, 0,
    1,   0,   66,  0,   0,   0,   106, 8,   0,   1,   89,  0,   0,   4,   70,  142, 32,  0,   0,   0,   0,   0,   4,   0,   0,   0,   95,  0,   0,   3,   242, 16,  16,  0,  0,
    0,   0,   0,   95,  0,   0,   3,   50,  16,  16,  0,   1,   0,   0,   0,   101, 0,   0,   3,   50,  32,  16,  0,   0,   0,   0,   0,   103, 0,   0,   4,   242, 32,  16, 0,
    1,   0,   0,   0,   1,   0,   0,   0,   104, 0,   0,   2,   1,   0,   0,   0,   54,  0,   0,   5,   50,  32,  16,  0,   0,   0,   0,   0,   70,  16,  16,  0,   1,   0,  0,
    0,   56,  0,   0,   8,   242, 0,   16,  0,   0,   0,   0,   0,   86,  21,  16,  0,   0,   0,   0,   0,   70,  142, 32,  0,   0,   0,   0,   0,   1,   0,   0,   0,   50, 0,
    0,   10,  242, 0,   16,  0,   0,   0,   0,   0,   6,   16,  16,  0,   0,   0,   0,   0,   70,  142, 32,  0,   0,   0,   0,   0,   0,   0,   0,   0,   70,  14,  16,  0,  0,
    0,   0,   0,   50,  0,   0,   10,  242, 0,   16,  0,   0,   0,   0,   0,   166, 26,  16,  0,   0,   0,   0,   0,   70,  142, 32,  0,   0,   0,   0,   0,   2,   0,   0,  0,
    70,  14,  16,  0,   0,   0,   0,   0,   50,  0,   0,   10,  242, 32,  16,  0,   1,   0,   0,   0,   246, 31,  16,  0,   0,   0,   0,   0,   70,  142, 32,  0,   0,   0,  0,
    0,   3,   0,   0,   0,   70,  14,  16,  0,   0,   0,   0,   0,   62,  0,   0,   1,   83,  84,  65,  84,  148, 0,   0,   0,   6,   0,   0,   0,   1,   0,   0,   0,   0,  0,
    0,   0,   4,   0,   0,   0,   4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,  0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0};

const BYTE sFragmentByteCode[] = {
    68,  88, 66, 67,  97,  81, 192, 56,  239, 170, 66,  202, 243, 198, 88,  159, 214, 132, 196, 110, 1,   0,   0,   0,   164, 2,   0,   0,   5,   0,   0,   0,   52,  0,   0,   0,
    248, 0,  0,  0,   44,  1,  0,   0,   96,  1,   0,   0,   8,   2,   0,   0,   82,  68,  69,  70,  188, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,
    60,  0,  0,  0,   0,   5,  255, 255, 0,   129, 0,   0,   147, 0,   0,   0,   82,  68,  49,  49,  60,  0,   0,   0,   24,  0,   0,   0,   32,  0,   0,   0,   40,  0,   0,   0,
    36,  0,  0,  0,   12,  0,  0,   0,   0,   0,   0,   0,   124, 0,   0,   0,   3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,
    1,   0,  0,  0,   1,   0,  0,   0,   140, 0,   0,   0,   2,   0,   0,   0,   5,   0,   0,   0,   4,   0,   0,   0,   255, 255, 255, 255, 2,   0,   0,   0,   1,   0,   0,   0,
    13,  0,  0,  0,   95,  83, 111, 117, 114, 99,  101, 95,  115, 97,  109, 112, 108, 101, 114, 0,   83,  111, 117, 114, 99,  101, 0,   77,  105, 99,  114, 111, 115, 111, 102, 116,
    32,  40, 82, 41,  32,  72, 76,  83,  76,  32,  83,  104, 97,  100, 101, 114, 32,  67,  111, 109, 112, 105, 108, 101, 114, 32,  49,  48,  46,  49,  0,   171, 73,  83,  71,  78,
    44,  0,  0,  0,   1,   0,  0,   0,   8,   0,   0,   0,   32,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,   0,   0,   0,   0,   0,   0,   0,   3,   3,   0,   0,
    84,  69, 88, 67,  79,  79, 82,  68,  0,   171, 171, 171, 79,  83,  71,  78,  44,  0,   0,   0,   1,   0,   0,   0,   8,   0,   0,   0,   32,  0,   0,   0,   0,   0,   0,   0,
    0,   0,  0,  0,   3,   0,  0,   0,   0,   0,   0,   0,   15,  0,   0,   0,   83,  86,  95,  84,  97,  114, 103, 101, 116, 0,   171, 171, 83,  72,  69,  88,  160, 0,   0,   0,
    80,  0,  0,  0,   40,  0,  0,   0,   106, 8,   0,   1,   90,  0,   0,   3,   0,   96,  16,  0,   2,   0,   0,   0,   88,  24,  0,   4,   0,   112, 16,  0,   2,   0,   0,   0,
    85,  85, 0,  0,   98,  16, 0,   3,   50,  16,  16,  0,   0,   0,   0,   0,   101, 0,   0,   3,   242, 32,  16,  0,   0,   0,   0,   0,   104, 0,   0,   2,   1,   0,   0,   0,
    69,  0,  0,  139, 194, 0,  0,   128, 67,  85,  21,  0,   114, 0,   16,  0,   0,   0,   0,   0,   70,  16,  16,  0,   0,   0,   0,   0,   70,  126, 16,  0,   2,   0,   0,   0,
    0,   96, 16, 0,   2,   0,  0,   0,   54,  0,   0,   5,   114, 32,  16,  0,   0,   0,   0,   0,   70,  2,   16,  0,   0,   0,   0,   0,   54,  0,   0,   5,   130, 32,  16,  0,
    0,   0,  0,  0,   1,   64, 0,   0,   0,   0,   128, 63,  62,  0,   0,   1,   83,  84,  65,  84,  148, 0,   0,   0,   4,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,
    2,   0,  0,  0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,  0,  0,   0,   0,  0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,
    0,   0,  0,  0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,  0,  0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0};

} // namespace PassthroughShaderDefs

class PassthroughShaderDef : public ShaderDef
{
public:
    PassthroughShaderDef() : ShaderDef {}
    {
        Name             = "passthrough";
        VertexByteCode   = PassthroughShaderDefs::sVertexByteCode;
        VertexLength     = sizeof(PassthroughShaderDefs::sVertexByteCode);
        FragmentByteCode = PassthroughShaderDefs::sFragmentByteCode;
        FragmentLength   = sizeof(PassthroughShaderDefs::sFragmentByteCode);
        Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f));
        Params.push_back(ShaderParam("SourceSize", -1, 0, 16, 0.000000f, 0.000000f, 0.000000f));
        Params.push_back(ShaderParam("OriginalSize", -1, 16, 16, 0.000000f, 0.000000f, 0.000000f));
        Params.push_back(ShaderParam("OutputSize", -1, 32, 16, 0.000000f, 0.000000f, 0.000000f));
        Params.push_back(ShaderParam("FrameCount", -1, 48, 4, 0.000000f, 0.000000f, 0.000000f));
        Samplers.push_back(ShaderSampler("Source", 2));

        VertexSource = R"(
cbuffer UBO : register(b0)
{
    row_major float4x4 global_MVP : packoffset(c0);
};

cbuffer Push
{
    float4 params_SourceSize : packoffset(c0);
    float4 params_OriginalSize : packoffset(c1);
    float4 params_OutputSize : packoffset(c2);
    uint params_FrameCount : packoffset(c3);
};


static float4 gl_Position;
static float4 Position;
static float2 vTexCoord;
static float2 TexCoord;

struct SPIRV_Cross_Input
{
    float4 Position : TEXCOORD0;
    float2 TexCoord : TEXCOORD1;
};

struct SPIRV_Cross_Output
{
    float2 vTexCoord : TEXCOORD0;
    float4 gl_Position : SV_Position;
};

void vert_main()
{
    gl_Position = mul(Position, global_MVP);
    vTexCoord = TexCoord;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    Position = stage_input.Position;
    TexCoord = stage_input.TexCoord;
    vert_main();
    SPIRV_Cross_Output stage_output;
    stage_output.gl_Position = gl_Position;
    stage_output.vTexCoord = vTexCoord;
    return stage_output;
}
)";

        FragmentSource = R"(
cbuffer UBO : register(b0)
{
    row_major float4x4 global_MVP : packoffset(c0);
};

cbuffer Push
{
    float4 params_SourceSize : packoffset(c0);
    float4 params_OriginalSize : packoffset(c1);
    float4 params_OutputSize : packoffset(c2);
    uint params_FrameCount : packoffset(c3);
};

Texture2D<float4> Source : register(t2);
SamplerState _Source_sampler : register(s2);

static float4 FragColor;
static float2 vTexCoord;

struct SPIRV_Cross_Input
{
    float2 vTexCoord : TEXCOORD0;
};

struct SPIRV_Cross_Output
{
    float4 FragColor : SV_Target0;
};

void frag_main()
{
    FragColor = float4(Source.Sample(_Source_sampler, vTexCoord).xyz, 1.0f);
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    vTexCoord = stage_input.vTexCoord;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.FragColor = FragColor;
    return stage_output;
}
)";
    }
};
