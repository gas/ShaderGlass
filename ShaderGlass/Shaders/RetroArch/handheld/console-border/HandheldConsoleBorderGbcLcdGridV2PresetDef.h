/*
ShaderGlass preset handheld/console-border / gbc-lcd-grid-v2 imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/handheld/console-border/gbc-lcd-grid-v2.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class HandheldConsoleBorderGbcLcdGridV2PresetDef : public PresetDef
{
public:
	HandheldConsoleBorderGbcLcdGridV2PresetDef() : PresetDef{}
	{
		Name = "gbc-lcd-grid-v2";
		Category = "handheld/console-border";
	}

	virtual void Build() {
         	ShaderDefs.push_back(MotionblurShadersResponseTimeShaderDef()
.Param("filter_linear", "false"));
         	ShaderDefs.push_back(HandheldConsoleBorderShaderFilesLcdCgwgLcdGridV2ShaderDef()
.Param("filter_linear", "false")
.Param("scale_type", "viewport"));
         	ShaderDefs.push_back(HandheldShadersColorGbcColorShaderDef()
.Param("filter_linear", "false"));
         	ShaderDefs.push_back(HandheldConsoleBorderShaderFilesGbPass5ShaderDef()
.Param("filter_linear", "true"));
            TextureDefs.push_back(HandheldConsoleBorderResourcesColorBorderSquare4xTextureDef()
.Param("linear", "true")
.Param("name", "BORDER"));
            OverrideParam("BGR", (float)0.000000);
            OverrideParam("BSUBPIX_B", (float)1.000000);
            OverrideParam("BSUBPIX_G", (float)0.000000);
            OverrideParam("BSUBPIX_R", (float)0.000000);
            OverrideParam("GSUBPIX_B", (float)0.000000);
            OverrideParam("GSUBPIX_G", (float)1.000000);
            OverrideParam("GSUBPIX_R", (float)0.000000);
            OverrideParam("RSUBPIX_B", (float)0.000000);
            OverrideParam("RSUBPIX_G", (float)0.000000);
            OverrideParam("RSUBPIX_R", (float)1.000000);
            OverrideParam("ambient", (float)0.000000);
            OverrideParam("blacklevel", (float)0.000000);
            OverrideParam("gain", (float)1.000000);
            OverrideParam("gamma", (float)1.600000);
            OverrideParam("lighten_screen", (float)0.000000);
            OverrideParam("video_scale", (float)4.000000);
	}
};
}
