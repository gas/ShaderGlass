# ShaderGlass WIC Utilities (`ShaderGlass/WIC/`)

This directory contains classes and functions specifically for handling image loading and saving operations using the Windows Imaging Component (WIC) and integrating them with DirectX 11 textures. These utilities are essential for features like loading an image file as a shader input or taking snapshots of the shader output.

## Overview

The primary role of the files in this directory is to bridge the gap between standard image file formats (like PNG, JPG) and DirectX 11 textures that can be used in the rendering pipeline. This involves decoding image files into raw pixel data and then creating D3D11 resources from this data, as well as the reverse process for saving textures.

The code in this directory is based on or adapted from Microsoft's DirectX Tool Kit (`DirectXTK`) for DX11, specifically for screen capture and texture loading functionalities.

## Key Files and Their Purpose

* **`ScreenGrab11.h` / `ScreenGrab11.cpp`**
    * **Purpose:** Provides functionality to capture a DirectX 11 texture (typically a back buffer or render target) and save it to an image file (e.g., PNG, BMP, JPG) using WIC for encoding.
    * **Key Functions (within `DirectX` namespace):**
        * `SaveWICTextureToFile(ID3D11DeviceContext* pContext, ID3D11Resource* pSource, REFGUID guidContainerFormat, const wchar_t* fileName, const GUID* targetFormat = nullptr, std::function<void(IPropertyBag2*)> setCustomProps = nullptr, bool forceSRGB = false)`: The core function that takes a D3D11 resource (texture), a target image container format (like `GUID_ContainerFormatPng`), and a filename, then saves the texture to disk. It handles various pixel format conversions and uses WIC encoders.

* **`WICTextureLoader11.h` / `WICTextureLoader11.cpp`**
    * **Purpose:** Provides functionality to load image files from disk or memory into DirectX 11 textures using WIC for decoding. This allows ShaderGlass to use images as inputs for shader processing.
    * **Key Functions (within `DirectX` namespace):**
        * `CreateWICTextureFromFileEx(ID3D11Device* d3dDevice, const wchar_t* fileName, size_t maxsize, D3D11_USAGE usage, unsigned int bindFlags, unsigned int cpuAccessFlags, unsigned int miscFlags, unsigned int loadFlags, ID3D11Resource** texture, ID3D11ShaderResourceView** textureView)`: Loads an image from a file, creates a D3D11 texture resource, and optionally a shader resource view for it. It supports various WIC-supported image formats and handles sRGB gamma correction if specified by `loadFlags`.
        * `CreateWICTextureFromMemoryEx(...)`: Similar to `CreateWICTextureFromFileEx`, but loads the image from a memory buffer instead of a file.

These components are vital for ShaderGlass's ability to:
-   Allow users to load their own images as input for shaders (via `WICTextureLoader11`).
-   Implement the "Take Snapshot" feature to save the current shader output to a file (via `ScreenGrab11`).
