/*
ShaderGlass preset reshade/handheld-color-LUTs / GBA_GBC-sRGB imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/reshade/handheld-color-LUTs/GBA_GBC-sRGB.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class ReshadeHandheldColorLUTsGBA_GBCSRGBPresetDef : public PresetDef
{
public:
	ReshadeHandheldColorLUTsGBA_GBCSRGBPresetDef() : PresetDef{}
	{
		Name = "GBA_GBC-sRGB";
		Category = "reshade/handheld-color-LUTs";
	}

	virtual void Build() {
         	ShaderDefs.push_back(ReshadeShadersLUTLUTShaderDef()
.Param("filter_linear", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000"));
            TextureDefs.push_back(ReshadeShadersLUTHandheldGBA_GBCSRGBTextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT"));
	}
};
}
