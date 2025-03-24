#pragma once

#include "imgui.h"
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <stdexcept>

// Include the ImGui backends headers (do not include the .cpp files here)
#include "backends/imgui_impl_dx12.h"
#include "backends/imgui_impl_win32.h"

using namespace Microsoft::WRL;

class CImGui
{
public:
    // Constructor: Pass in your DX12 device, window handle, number of frames in flight, and the swap chain render target format.
    CImGui(ID3D12Device* device, HWND hwnd, int numFramesInFlight, DXGI_FORMAT rtvFormat);
    ~CImGui();

    // Call this each frame to render ImGui.
    void RenderImGui(ID3D12GraphicsCommandList* cmdList);

private:
    void CreateImGuiDescriptorHeap();
    void InitImGui(HWND hwnd, int numFramesInFlight, DXGI_FORMAT rtvFormat);

    // DX12 objects used by ImGui
    ComPtr<ID3D12Device> m_device;
    ComPtr<ID3D12DescriptorHeap> m_srvDescHeap; // Descriptor heap for ImGui font texture, etc.
};
