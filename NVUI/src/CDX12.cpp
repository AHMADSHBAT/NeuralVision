#include "CDX12.h"
#include "CGDIScreenCapture.h"
#include "CImGui.h"
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")  // Sometimes needed for older SDKs

// Constructor: Initialize the window and DX12.
CDX12::CDX12(HINSTANCE hInstance, int nCmdShow, int width, int height)
    : m_hWnd(nullptr), m_width(width), m_height(height)
{
    InitWindow(hInstance, nCmdShow);
    InitD3D();
}

// Destructor: Clean up resources if necessary.
CDX12::~CDX12()
{
    // Cleanup DirectX resources here if needed.
}

// Initializes the application window.
void CDX12::InitWindow(HINSTANCE hInstance, int nCmdShow)
{
    // Define and register the window class.
    WNDCLASSEX wc = { sizeof(WNDCLASSEX) };
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = DX12WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = L"DX12WindowClass";

    if (!RegisterClassEx(&wc))
        throw std::runtime_error("Failed to register window class");

    // Create the window.
    m_hWnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        L"DX12 ImGui Screenshot App",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        m_width, m_height,
        nullptr,
        nullptr,
        hInstance,
        nullptr);

    if (!m_hWnd)
        throw std::runtime_error("Failed to create window");

    ShowWindow(m_hWnd, nCmdShow);
}

// Initializes a basic DirectX 12 device.
void CDX12::InitD3D()
{
    HRESULT hr = D3D12CreateDevice(
        nullptr, // default adapter
        D3D_FEATURE_LEVEL_11_0,
        IID_PPV_ARGS(&m_device)
    );

    if (FAILED(hr))
        throw std::runtime_error("Failed to create D3D12 device.");

    // Additional DX12 initialization (command queue, swap chain, etc.)
    // would be implemented here.
}

// Runs the main message loop.
int CDX12::Run()
{
    //static bool b = false;

    MSG msg = {};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        // Render calls and updates would go here.
        //CImGui::CImGui(ID3D12Device * device, HWND hwnd, int numFramesInFlight, DXGI_FORMAT rtvFormat)
        CImGui* InitImGui = new CImGui(m_device.Get(), m_hWnd, 3, DXGI_FORMAT_420_OPAQUE);
        InitImGui->RenderImGui(nullptr);
    }
    return static_cast<int>(msg.wParam);
}

// Basic window procedure.
LRESULT CALLBACK DX12WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (message == WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
