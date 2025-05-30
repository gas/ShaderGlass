# Shader Graphics Compiler (`/ShaderGC/`)

This directory contains the **Shader Graphics Compiler (ShaderGC)** module for ShaderGlass. Its primary responsibility is to take shader source code written in Slang (RetroArch's GLSL-based shader language), compile it through a multi-stage pipeline, and produce HLSL bytecode that can be executed by DirectX 11. It also handles shader caching to improve performance for previously compiled shaders.

## Overview

The ShaderGC module is a crucial backend component that enables ShaderGlass to support a wide range of shaders, especially those from the RetroArch ecosystem, and custom user-provided shaders. It abstracts the complexities of the shader compilation toolchain, which involves `glslang` for Slang/GLSL parsing and SPIR-V generation, `SPIRV-Cross` for SPIR-V to HLSL transpilation, and the DirectX shader compiler (`fxc.exe` or equivalent D3DCompile API) for HLSL to bytecode compilation.

The module defines structures for shader definitions (`ShaderDef`), preset definitions (`PresetDef`), and texture definitions (`TextureDef`), which are used to describe the properties and components of shaders and shader presets.

## Key Files and Classes

* **`ShaderGC.h` / `ShaderGC.cpp`**
    * **Class/Namespace:** `ShaderGC`
    * **Purpose:** This is the main interface and orchestrator for the shader compilation process within this module. It likely exposes functions to compile entire shader presets (`.slangp`) or individual shader files (`.slang`).
    * **Key Responsibilities & Methods:**
        * `Initialize()`: (Inferred) Would initialize the underlying compiler utilities like `glslang` and `SPIRV-Cross`.
        * `CompilePreset(const std::filesystem::path& path, std::ofstream& log, bool& warn, const ShaderCache& cache)`: This static method appears to be the primary entry point for compiling a shader preset file (`.slangp`). It parses the preset, processes each shader pass, handles textures, and manages the compilation pipeline. It interacts with the `ShaderCache` to potentially retrieve already compiled shaders.
        * It likely uses helper classes/functions within `GLSL.cpp`, `SPIRV.cpp`, and `HLSL.cpp` to perform the specific steps of the compilation.
        * Manages include paths for shaders and resolves `#include` directives within shader code.
        * Parses preset parameters, texture definitions, and pass-specific settings from `.slangp` files (which use a pseudo-JSON format).

* **`GLSL.h` / `GLSL.cpp`**
    * **Namespace:** `GLSL`
    * **Purpose:** Handles the initial stage of shader processing, specifically parsing Slang/GLSL source code and compiling it to SPIR-V using the `glslang` library.
    * **Key Functions:**
        * `Initialize()`: Initializes the `glslang` library.
        * `Parse(const std::string& source, const std::string& fileName, const std::string& entryPoint, const std::string& profile, std::vector<std::uint32_t>& spirv, std::string& error, const std::vector<std::string>& includes)`: Takes GLSL/Slang source code, entry point, profile, and include paths, then compiles it to SPIR-V, returning errors if any.
        * `Finalize()`: Finalizes the `glslang` library usage.

* **`SPIRV.h` / `SPIRV.cpp`**
    * **Namespace:** `SPIRV`
    * **Purpose:** Handles the cross-compilation of SPIR-V bytecode to HLSL source code using the `SPIRV-Cross` library. It also performs reflection on the SPIR-V to extract metadata about shader parameters and resources.
    * **Key Functions:**
        * `Parse(const std::vector<std::uint32_t>& spirv, ShaderDef& shaderDef, std::string& error)`: Takes SPIR-V bytecode, populates a `ShaderDef` structure with reflected information (parameters, textures, samplers), and transpiles the SPIR-V to HLSL source code, storing it in `shaderDef.Source`.

* **`HLSL.h` / `HLSL.cpp`**
    * **Namespace:** `HLSL`
    * **Purpose:** Handles the final stage of compiling HLSL source code (generated by `SPIRV-Cross`) into DirectX 11 compatible bytecode using `D3DCompile`.
    * **Key Functions:**
        * `Compile(const std::string& source, const std::string& fileName, const std::string& entryPoint, const std::string& profile, std::vector<BYTE>& byteCode, std::string& error)`: Takes HLSL source code and compilation parameters, and produces shader bytecode.

* **`ShaderCache.h` / `ShaderCache.cpp`**
    * **Class:** `ShaderCache`
    * **Purpose:** Implements a caching mechanism for compiled shader bytecode. This avoids recompiling shaders that haven't changed, significantly speeding up shader loading, especially for the large built-in RetroArch library.
    * **Key Responsibilities & Methods:**
        * The cache likely uses a hash of the shader source and its compilation parameters (like defines) as a key.
        * `Get(const std::string& source, const std::string& defines, const std::string& profile)`: Attempts to retrieve compiled bytecode from the cache.
        * `Set(const std::string& source, const std::string& defines, const std::string& profile, const std::vector<BYTE>& byteCode)`: Stores newly compiled bytecode into the cache.
        * It seems to use SHA256 hashing (from `sha256.h/.cpp`) for generating cache keys from shader source and defines.
        * The cache can be pre-populated (e.g., with RetroArch shaders that are converted to `CachedShader` structs) and also stores dynamically compiled shaders.

* **`ShaderDef.h`, `PresetDef.h`, `TextureDef.h`, `SourceDefs.h`**
    * **Purpose:** These headers define the C++ structures used to represent shaders, presets, textures, and source file references at various stages of parsing and compilation.
        * `ShaderParam`: Defines a shader parameter (uniform) including its name, type, offset, default value, min/max values, and step.
        * `SamplerParam`: Defines a sampler used by a shader, including its name and binding point.
        * `ShaderDef`: Contains the definition for a single shader pass, including its source code, compiled bytecode, entry points, parameters, samplers, and preset parameters affecting its behavior (like scale, format, filtering).
        * `TextureDef`: Defines a texture, including its path, name (alias), and properties like whether it's an sRGB texture, uses linear filtering, or mipmapping.
        * `PresetDef`: Defines a shader preset, including its name, category, a list of `ShaderDef` objects (passes), a list of `TextureDef` objects, and parameter overrides for the preset. It also includes methods to parse these definitions from a file path.
        * `SourceFile`, `SourceShader`: Structures likely used internally by `ShaderGen` or `ShaderGC` to manage source code before it's embedded into `ShaderDef` or `TextureDef`.

* **`framework.h`, `pch.h`, `pch.cpp`**: Standard precompiled header and framework include files for the module.
* **`sha256.h`, `sha256.cpp`**: Implementation of the SHA256 hashing algorithm, used by `ShaderCache`.

## Shader Compilation Pipeline (Conceptual)

1.  A `.slangp` preset file is loaded by `ShaderGC::CompilePreset`.
2.  The preset file is parsed to identify individual shader passes, textures, and parameters.
3.  For each shader pass:
    a.  The Slang/GLSL source code is retrieved (either from a file or embedded).
    b.  Includes are resolved.
    c.  A hash is generated for caching purposes (source + defines).
    d.  `ShaderCache::Get()` is called. If bytecode exists, it's used.
    e.  If not cached:
        i.  `GLSL::Parse()` compiles the Slang/GLSL to SPIR-V.
        ii. `SPIRV::Parse()` reflects on the SPIR-V (extracting parameter and resource info) and transpiles it to HLSL source.
        iii. `HLSL::Compile()` compiles the HLSL source to DirectX 11 bytecode.
        iv. The resulting bytecode is stored in the `ShaderCache` via `ShaderCache::Set()`.
4.  Texture definitions are processed, and parameter overrides are applied.
5.  A `PresetDef` object, populated with compiled `ShaderDef`s and `TextureDef`s, is returned.

This module is critical for enabling ShaderGlass's core feature of applying a wide variety of complex, multi-pass shaders.
