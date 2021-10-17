/*
ShaderGlass preset nes_raw_palette / pal-r57shell-raw imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/nes_raw_palette/pal-r57shell-raw.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class Nes_raw_palettePalR57shellRawPresetDef : public PresetDef
{
public:
	Nes_raw_palettePalR57shellRawPresetDef() : PresetDef{}
	{
		Name = "pal-r57shell-raw";
		Category = "nes_raw_palette";
	}

	virtual void Build() {
         	ShaderDefs.push_back(PalShadersPalR57shellShaderDef()
.Param("alias", "ORIG_LINEARIZED")
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false"));
            TextureDefs.push_back(PalResourcesNes_lutTextureDef()
.Param("linear", "false")
.Param("mipmap", "false")
.Param("name", "nes_lut")
.Param("wrap_mode", "repeat"));
	}
};
}
