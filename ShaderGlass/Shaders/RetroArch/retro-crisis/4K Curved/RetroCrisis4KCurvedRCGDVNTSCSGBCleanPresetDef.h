/*
ShaderGlass preset retro-crisis/4K-Curved / RC GDV-NTSC - SGB - Clean imported from RetroCrisis:
https://github.com/RetroCrisis/Retro-Crisis-GDV-NTSC
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class RetroCrisis4KCurvedRCGDVNTSCSGBCleanPresetDef : public PresetDef
{
public:
	RetroCrisis4KCurvedRCGDVNTSCSGBCleanPresetDef() : PresetDef{}
	{
		Name = "RC GDV-NTSC - SGB - Clean";
		Category = "retro-crisis/4K-Curved";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersGuestAdvancedStockShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedStockShaderDef()
.Param("alias", "StockPass")
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedAfterglow0ShaderDef()
.Param("alias", "AfterglowPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedPreShadersAfterglowShaderDef()
.Param("alias", "PrePass0")
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedNtscNtscPass1ShaderDef()
.Param("alias", "NPass1")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "4.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedNtscNtscPass2ShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "0.500000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedNtscNtscPass3ShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedCustomFastSharpenShaderDef()
.Param("alias", "NtscPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedStockShaderDef()
.Param("alias", "PrePass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "true")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedAvgLumNtscShaderDef()
.Param("alias", "AvgLumPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "true")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedLinearizeNtscShaderDef()
.Param("alias", "LinearizePass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedCrtGuestAdvancedNtscPass1ShaderDef()
.Param("alias", "Pass1")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedGaussian_horizontalShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "source")
.Param("scale_x", "800")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedGaussian_verticalShaderDef()
.Param("alias", "GlowPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "800")
.Param("scale_y", "600")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedBloom_horizontalShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "800")
.Param("scale_y", "600")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedBloom_verticalShaderDef()
.Param("alias", "BloomPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "800")
.Param("scale_y", "600")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedCrtGuestAdvancedNtscPass2ShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "viewport")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersGuestAdvancedDeconvergenceNtscShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "viewport")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
            TextureDefs.push_back(CrtShadersGuestAdvancedLutTrinitronLutTextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "SamplerLUT1")
.Param("wrap_mode", "clamp_to_border"));
            TextureDefs.push_back(CrtShadersGuestAdvancedLutInvTrinitronLutTextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "SamplerLUT2")
.Param("wrap_mode", "clamp_to_border"));
            TextureDefs.push_back(CrtShadersGuestAdvancedLutNecLutTextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "SamplerLUT3")
.Param("wrap_mode", "clamp_to_border"));
            TextureDefs.push_back(CrtShadersGuestAdvancedLutNtscLutTextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "SamplerLUT4")
.Param("wrap_mode", "clamp_to_border"));
            OverrideParam("beam_min", (float)1.999999);
            OverrideParam("bloom", (float)0.500000);
            OverrideParam("bsize1", (float)0.010000);
            OverrideParam("c_shape", (float)0.050000);
            OverrideParam("csize", (float)0.010000);
            OverrideParam("cust_artifacting", (float)0.000000);
            OverrideParam("cust_fringing", (float)0.000000);
            OverrideParam("double_slot", (float)3.000000);
            OverrideParam("gsl", (float)2.000000);
            OverrideParam("halation", (float)0.100000);
            OverrideParam("m_glow", (float)1.000000);
            OverrideParam("mask_bloom", (float)0.500000);
            OverrideParam("mask_zoom", (float)-5.000000);
            OverrideParam("maskboost", (float)2.000000);
            OverrideParam("masksize", (float)2.000000);
            OverrideParam("maskstr", (float)1.000000);
            OverrideParam("mcut", (float)2.000000);
            OverrideParam("ntsc_cscale", (float)2.250000);
            OverrideParam("ntsc_fields", (float)1.000000);
            OverrideParam("ntsc_phase", (float)4.000000);
            OverrideParam("ntsc_sat", (float)1.200000);
            OverrideParam("ntsc_scale", (float)2.500000);
            OverrideParam("sborder", (float)0.250000);
            OverrideParam("scan_falloff", (float)0.100000);
            OverrideParam("scangamma", (float)5.000000);
            OverrideParam("scanline1", (float)10.000000);
            OverrideParam("scanline2", (float)10.000000);
            OverrideParam("shadowMask", (float)13.000000);
            OverrideParam("slotmask", (float)1.000000);
            OverrideParam("slotmask1", (float)1.000000);
            OverrideParam("tds", (float)1.000000);
            OverrideParam("warpX", (float)0.030000);
            OverrideParam("warpY", (float)0.040000);
	}
};
}
