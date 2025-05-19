# ShaderGlass Utilities (`ShaderGlass/Util/`)

This directory contains various utility header files that provide helper functions, macros, and interoperability functionalities used throughout the ShaderGlass application, particularly for interacting with Windows APIs, DirectX, and WinRT.

## Overview

The files in `ShaderGlass/Util/` are designed to simplify common tasks, provide wrappers for API calls, and define structures or enums that are broadly used. They help in making the main application code cleaner and more focused on its core logic by abstracting some lower-level details.

## Key Files and Their Purpose

* **`capture.desktop.interop.h`**
    * **Purpose:** Provides interoperability functions for desktop capture using the Windows Graphics Capture API.
    * **Key Functions:**
        * `CreateCaptureItemForWindow(HWND hwnd)`: Creates a `GraphicsCaptureItem` for a specific window (HWND).
        * `CreateCaptureItemForMonitor(HMONITOR hmonitor)`: Creates a `GraphicsCaptureItem` for a specific monitor (HMONITOR).
        * These are essential for initiating screen or window captures.

* **`capture.h`**
    * **Purpose:** Defines common structures and possibly helper functions related to graphics capture that might be shared between different capture mechanisms or modules.
    * **Note:** Based on the provided file list, the full content of `capture.h` was not explicitly detailed earlier, but its name suggests a role in defining capture-related types or utilities. *(If specific content is needed, it would require fetching)*.

* **`d3dHelpers.h`**
    * **Purpose:** Contains helper functions for Direct3D 11 operations, simplifying common tasks like device creation and resource management.
    * **Key Functions:**
        * `CreateD3DDevice()`: Creates a D3D11 device, attempting to use a hardware device first and falling back to WARP if necessary.
        * `CreateD3DDevice(D3D_DRIVER_TYPE const type, winrt::com_ptr<ID3D11Device>& device)`: A more specific version for device creation with a given driver type.
        * `GetDXGIAdapter(winrt::com_ptr<ID3D11Device> const& device)`: Retrieves the DXGI adapter associated with a D3D11 device.

* **`direct3d11.interop.h`**
    * **Purpose:** Provides interoperability functions for working with Direct3D 11 and WinRT's `IDirect3DDevice`. This is crucial for integrating modern Windows API features (like Graphics Capture) with traditional DirectX rendering.
    * **Key Functions:**
        * `CreateDirect3DDevice(IDXGIDevice* dxgiDevice)`: Creates an `IDirect3DDevice` from an `IDXGIDevice`.
        * `GetDXGIInterfaceFromObject<IDXGIInterface>(winrt::Windows::Foundation::IInspectable const& object)`: A template function to retrieve a DXGI interface from a WinRT `IInspectable` object. This is particularly useful for getting the underlying DirectX texture from a `Direct3D11CaptureFrame`.

* **`enum.h`**
    * **Purpose:** Likely defines various enumerations used across the application for representing states, types, or options.
    * **Note:** The specific enums would be visible by fetching the file content. For example, it might define enums for shader parameter types, UI states, or error codes.

* **`winrtMatchers.h`**
    * **Purpose:** Provides custom matchers for use with testing frameworks (specifically Google Test, as indicated by `gmock/gmock.h` inclusion), facilitating unit testing of WinRT interop code.
    * **Key Features:**
        * `PointerAddressMatcher`: A matcher to compare pointer addresses.
        * `IsValidHandleMatcher` and `IsNullHandleMatcher`: Matchers for `HANDLE` validity.
        * `IsValidPointerMatcher` and `IsNullPointerMatcher`: Matchers for general pointer validity.

* **`wic.h`**
    * **Purpose:** Contains helper functions and utilities related to the Windows Imaging Component (WIC). WIC is used for image loading, saving, and format conversion.
    * **Key Functions:**
        * `CreateWICFactory(IWICImagingFactory2** ppFactory)`: Creates an instance of the WIC imaging factory.
        * Functions for saving textures to files, likely involving WIC for encoding (e.g., `SaveWICTextureToFile` which is part of DirectXTex but this header might contain related helpers or wrappers).

These utility files abstract complex or repetitive Windows API interactions, making other parts of the ShaderGlass codebase cleaner and easier to manage.
