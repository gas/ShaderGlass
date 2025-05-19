# ShaderGen Include Files (`/ShaderGen/include/`)

This directory contains header files for third-party libraries that the `ShaderGen` command-line tool depends on for its shader compilation and conversion pipeline. These are essential for `ShaderGen` to interface with the underlying shader processing tools.

## Overview

The `ShaderGen` tool's primary function is to convert Slang shaders into C++ header files. To achieve this, it needs to parse the original shader code, compile it to intermediate representations, and finally to HLSL bytecode. This directory provides the necessary C++ API headers for the libraries that perform these tasks.

The structure and content of this directory are very similar to `/ShaderGC/include/`, as both modules leverage the same core shader compilation libraries.

## Key Contents

* **`glslang/` (subdirectory):**
    * **Purpose:** Contains the public C and C++ header files for the **glslang** library.
    * **Role:** `glslang` is used by `ShaderGen` to parse Slang and GLSL shader source code and compile it into SPIR-V (Standard Portable Intermediate Representation).
    * **Key Headers (examples):**
        * `glslang/Public/ShaderLang.h`: Core C++ interface for glslang compilation.
        * `glslang/Public/ResourceLimits.h`: Defines resource limits for the compiler.
        * (See `ShaderGen/include/glslang/README.md` for more details on the `glslang` headers).

* **SPIRV-Cross Headers (e.g., `spirv_hlsl.hpp`, `spirv_cross.hpp`, `spirv_common.hpp`, etc.):**
    * **Purpose:** These are the header files for the **SPIRV-Cross** library.
    * **Role:** After `glslang` produces SPIR-V, `SPIRV-Cross` is used by `ShaderGen` to transpile this SPIR-V bytecode into HLSL source code. `SPIRV-Cross` also enables reflection on the SPIR-V to extract metadata about shader parameters and resources, which `ShaderGen` then embeds into the generated C++ headers.
    * **Key Headers (examples):**
        * `spirv_cross.hpp`: Core C++ API for SPIRV-Cross.
        * `spirv_hlsl.hpp`: HLSL-specific backend for SPIRV-Cross.
        * `spirv_reflect.hpp`: API for reflection capabilities.

* **`GLSL.std.450.h`**:
    * **Purpose:** A standard header defining GLSL extended instruction set opcodes, often used in conjunction with SPIR-V generation.

These include files allow `ShaderGen` to programmatically control the shader compilation and transpilation processes necessary for its operation.
