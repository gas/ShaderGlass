#pragma once

#include "ShaderGlass.h"

class CaptureSession
{
public:
    CaptureSession(winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device,
                   winrt::Windows::Graphics::Capture::GraphicsCaptureItem const&         item,
                   winrt::Windows::Graphics::DirectX::DirectXPixelFormat                 pixelFormat,
                   ShaderGlass&                                                          shaderGlass);

    CaptureSession(winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device,
                   winrt::com_ptr<ID3D11Texture2D>                                       inputImage,
                   ShaderGlass&                                                          shaderGlass);

    void OnFrameArrived(winrt::Windows::Graphics::Capture::Direct3D11CaptureFramePool const& sender,
                        winrt::Windows::Foundation::IInspectable const&                      args);

    void Stop();

    void UpdateCursor(bool captureCursor);

    void ProcessInput();

private:

    winrt::Windows::Graphics::Capture::GraphicsCaptureItem         m_item {nullptr};
    winrt::Windows::Graphics::Capture::Direct3D11CaptureFramePool  m_framePool {nullptr};
    winrt::Windows::Graphics::Capture::GraphicsCaptureSession      m_session {nullptr};
    winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice m_device {nullptr};
    winrt::com_ptr<ID3D11Texture2D>                                m_inputImage {nullptr};

    ShaderGlass& m_shaderGlass;
};
