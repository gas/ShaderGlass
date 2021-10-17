/*
ShaderGlass preset crt / crt-geom-deluxe imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/crt/crt-geom-deluxe.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class CrtCrtGeomDeluxePresetDef : public PresetDef
{
public:
	CrtCrtGeomDeluxePresetDef() : PresetDef{}
	{
		Name = "crt-geom-deluxe";
		Category = "crt";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersGeomDeluxePhosphor_applyShaderDef()
.Param("alias", "internal1"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxePhosphor_updateShaderDef()
.Param("alias", "phosphor"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxeGaussxShaderDef()
.Param("alias", "internal2")
.Param("filter_linear", "true"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxeGaussyShaderDef()
.Param("alias", "blur_texture")
.Param("filter_linear", "true"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxeCrtGeomDeluxeShaderDef()
.Param("filter_linear", "true")
.Param("mipmap_input", "true"));
            TextureDefs.push_back(CrtShadersGeomDeluxeMasksAperture_2_4_rgbTextureDef()
.Param("name", "aperture"));
            TextureDefs.push_back(CrtShadersGeomDeluxeMasksSlot_2_5x4_bgrTextureDef()
.Param("name", "slot"));
            TextureDefs.push_back(CrtShadersGeomDeluxeMasksDelta_2_4x1_rgbTextureDef()
.Param("name", "delta"));
	}
};
}
