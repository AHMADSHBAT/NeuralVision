#pragma once

#include <windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <stdexcept>
#include <string>

using namespace Microsoft::WRL;

class CDX12
{
public:
    // Constructor initializes the window and DX12 device.
    // width and height are optional parameters (defaulting to 800x600).
    CDX12(HINSTANCE hInstance, int nCmdShow, int width = 800, int height = 600);
    ~CDX12();

    // Returns the DX12 device pointer for use by other classes.
    ID3D12Device* GetDevice() const { return m_device.Get(); }

    // Run the application's message loop.
    int Run();

    // Optionally, expose the HWND if needed.
    HWND GetHWND() const { return m_hWnd; }

private:
    // Helper methods for initialization.
    void InitWindow(HINSTANCE hInstance, int nCmdShow);
    void InitD3D();

    // Window parameters
    HWND m_hWnd;
    int m_width;
    int m_height;

    // DirectX 12 device pointer.
    ComPtr<ID3D12Device> m_device;

    // Additional members (e.g., command queue, swap chain, descriptor heaps)
    // can be added here as your project expands.
};

// Window procedure declaration.
LRESULT CALLBACK DX12WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
