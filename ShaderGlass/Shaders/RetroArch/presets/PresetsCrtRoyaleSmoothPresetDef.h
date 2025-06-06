/*
ShaderGlass preset presets / crt-royale-smooth imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/presets/crt-royale-smooth.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsCrtRoyaleSmoothPresetDef : public PresetDef
{
public:
	PresetsCrtRoyaleSmoothPresetDef() : PresetDef{}
	{
		Name = "crt-royale-smooth";
		Category = "presets";
	}

	virtual void Build() {
         	ShaderDefs.push_back(StockStockShaderDef()
.Param("alias", "refpass")
.Param("filter_linear", "false")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingScalefxShadersScalefxPass0ShaderDef()
.Param("alias", "scalefx_pass0")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingScalefxShadersScalefxPass1ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingScalefxShadersScalefxPass2ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingScalefxShadersScalefxPass3ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingScalefxShadersScalefxPass4ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "3.000000")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(InterpolationShadersBSpline4TapsShaderDef()
.Param("filter_linear", "true")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "0.333333")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_edge"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleFirstPassLinearizeCrtGammaBobFieldsShaderDef()
.Param("alias", "ORIG_LINEARIZED")
.Param("filter_linear", "false")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleScanlinesVerticalInterlacingShaderDef()
.Param("alias", "VERTICAL_SCANLINES")
.Param("filter_linear", "true")
.Param("float_framebuffer", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "viewport")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleBloomApproxShaderDef()
.Param("alias", "BLOOM_APPROX")
.Param("filter_linear", "true")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "320")
.Param("scale_y", "240")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BlursShadersRoyaleBlur9fastVerticalShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BlursShadersRoyaleBlur9fastHorizontalShaderDef()
.Param("alias", "HALATION_BLUR")
.Param("filter_linear", "true")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleMaskResizeVerticalShaderDef()
.Param("filter_linear", "true")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "viewport")
.Param("scale_x", "64")
.Param("scale_y", "0.062500")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleMaskResizeHorizontalShaderDef()
.Param("alias", "MASK_RESIZE")
.Param("filter_linear", "false")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "0.062500")
.Param("scale_y", "1.000000")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleScanlinesHorizontalApplyMaskShaderDef()
.Param("alias", "MASKED_SCANLINES")
.Param("filter_linear", "true")
.Param("scale", "1.000000")
.Param("scale_type", "viewport")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleBrightpassShaderDef()
.Param("alias", "BRIGHTPASS")
.Param("filter_linear", "true")
.Param("scale", "1.000000")
.Param("scale_type", "viewport")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleBloomVerticalShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleBloomHorizontalReconstituteShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.000000")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleGeometryAaLastPassShaderDef()
.Param("filter_linear", "true")
.Param("mipmap_input", "true")
.Param("scale", "1.000000")
.Param("scale_type", "viewport")
.Param("wrap_mode", "clamp_to_border"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearApertureGrille15Wide8And5d5SpacingResizeTo64TextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "mask_grille_texture_small")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearApertureGrille15Wide8And5d5SpacingTextureDef()
.Param("linear", "true")
.Param("mipmap", "true")
.Param("name", "mask_grille_texture_large")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearSlotMaskTall15Wide9And4d5Horizontal9d14VerticalSpacingResizeTo64TextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "mask_slot_texture_small")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearSlotMaskTall15Wide9And4d5Horizontal9d14VerticalSpacingTextureDef()
.Param("linear", "true")
.Param("mipmap", "true")
.Param("name", "mask_slot_texture_large")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearShadowMaskEDPResizeTo64TextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "mask_shadow_texture_small")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearShadowMaskEDPTextureDef()
.Param("linear", "true")
.Param("mipmap", "true")
.Param("name", "mask_shadow_texture_large")
.Param("wrap_mode", "repeat"));
            OverrideParam("SFX_CLR", (float)0.500000);
            OverrideParam("SFX_SAA", (float)0.000000);
            OverrideParam("SFX_SCN", (float)0.000000);
            OverrideParam("beam_max_sigma", (float)0.285000);
            OverrideParam("beam_min_sigma", (float)0.115000);
            OverrideParam("beam_spot_power", (float)0.010000);
            OverrideParam("border_compress", (float)3.000000);
            OverrideParam("border_darkness", (float)0.750000);
            OverrideParam("border_size", (float)0.000000);
            OverrideParam("crt_gamma", (float)2.400000);
            OverrideParam("diffusion_weight", (float)0.000000);
            OverrideParam("feedback_pass", (float)0.000000);
            OverrideParam("interlace_detect_toggle", (float)0.000000);
            OverrideParam("mask_type", (float)0.000000);
	}
};
}
