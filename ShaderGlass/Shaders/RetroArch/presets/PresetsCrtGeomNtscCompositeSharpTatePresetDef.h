/*
ShaderGlass preset presets / crt-geom-ntsc-composite-sharp-tate imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/presets/crt-geom-ntsc-composite-sharp-tate.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsCrtGeomNtscCompositeSharpTatePresetDef : public PresetDef
{
public:
	PresetsCrtGeomNtscCompositeSharpTatePresetDef() : PresetDef{}
	{
		Name = "crt-geom-ntsc-composite-sharp-tate";
		Category = "presets";
	}

	virtual void Build() {
         	ShaderDefs.push_back(MiscNtscColorsShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false"));
         	ShaderDefs.push_back(NtscShadersNtscAdaptiveTateNtscTatePass1ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "4.000000")
.Param("srgb_framebuffer", "false"));
         	ShaderDefs.push_back(NtscShadersNtscAdaptiveTateNtscTatePass2ShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "0.500000")
.Param("srgb_framebuffer", "false"));
         	ShaderDefs.push_back(WarpShadersSmartMorphShaderDef()
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false"));
         	ShaderDefs.push_back(SharpenShadersFastSharpenShaderDef()
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false"));
         	ShaderDefs.push_back(CrtShadersCrtGeomShaderDef()
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "false"));
	}
};
}
