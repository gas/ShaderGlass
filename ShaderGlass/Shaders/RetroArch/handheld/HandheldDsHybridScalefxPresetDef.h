/*
ShaderGlass preset handheld / ds-hybrid-scalefx imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/handheld/ds-hybrid-scalefx.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class HandheldDsHybridScalefxPresetDef : public PresetDef
{
public:
	HandheldDsHybridScalefxPresetDef() : PresetDef{}
	{
		Name = "ds-hybrid-scalefx";
		Category = "handheld";
	}

	virtual void Build() {
         	ShaderDefs.push_back(StockStockShaderDef()
.Param("alias", "refpass")
.Param("filter_linear", "false"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass0ShaderDef()
.Param("alias", "scalefx_pass0")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass1ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass2ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass3ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass4ShaderDef()
.Param("alias", "Ref")
.Param("filter_linear", "false")
.Param("scale", "3.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(HandheldShadersDsHybridViewShaderDef()
.Param("filter_linear", "true"));
	}
};
}
