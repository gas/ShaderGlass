# ShaderGC Include Files (`/ShaderGC/include/`)

This directory contains header files for third-party libraries that the `ShaderGC` (Shader Graphics Compiler) module depends on for its shader compilation and processing pipeline.

## Overview

The `ShaderGC` module needs to interface with external tools to handle the complex process of parsing Slang/GLSL, converting to SPIR-V, and then transpiling to HLSL for DirectX 11. The header files for these tools are primarily located here, allowing the `ShaderGC` C++ code to call into these libraries.

## Key Contents

* **`glslang/` (subdirectory):**
    * **Purpose:** Contains the public C and C++ header files for the **glslang** library.
    * **Role:** `glslang` is used to parse Slang and GLSL shader source code and compile it into SPIR-V (Standard Portable Intermediate Representation). This is the first major step in the shader compilation pipeline within ShaderGlass.
    * **Key Headers (examples):**
        * `glslang/Public/ShaderLang.h`: Core C++ interface for glslang compilation.
        * `glslang/Public/ResourceLimits.h`: Defines resource limits for the compiler.
        * `glslang/Include/intermediate.h`: Definitions for the intermediate representation used by glslang.

* **SPIRV-Cross Headers (e.g., `spirv_hlsl.hpp`, `spirv_cross.hpp`, `spirv_common.hpp`, etc.):**
    * **Purpose:** These are the header files for the **SPIRV-Cross** library.
    * **Role:** After `glslang` produces SPIR-V, `SPIRV-Cross` is used to transpile this SPIR-V bytecode into HLSL (High-Level Shading Language), which is the shader language compatible with ShaderGlass's DirectX 11 backend. SPIRV-Cross also provides reflection capabilities to inspect the SPIR-V for resources like uniforms, textures, and samplers.
    * **Key Headers (examples):**
        * `spirv_cross.hpp`: Core C++ API for SPIRV-Cross.
        * `spirv_hlsl.hpp`: HLSL-specific backend for SPIRV-Cross.
        * `spirv_reflect.hpp`: API for reflection capabilities.

* **`json.hpp`:**
    * **Purpose:** This is the header for the **nlohmann/json** library, a popular single-header C++ library for JSON manipulation.
    * **Role:** Used within `ShaderGC` (specifically observed in `ShaderGC.cpp`) for parsing `.slangp` preset files, which, while not strictly JSON, use a JSON-like syntax for defining shader passes, parameters, and textures.

These include files are essential for building the `ShaderGC` module and linking it against the necessary shader compilation libraries. They are typically not modified as part of ShaderGlass development unless upgrading the external libraries themselves.
