#include "CImGui.h"

CImGui::CImGui(ID3D12Device* device, HWND hwnd, int numFramesInFlight, DXGI_FORMAT rtvFormat)
{
    // Store the DX12 device
    m_device = device;

    // Create a descriptor heap for ImGui's shader-visible resources.
    CreateImGuiDescriptorHeap();

    // Initialize ImGui with Win32 and DX12 backends.
    InitImGui(hwnd, numFramesInFlight, rtvFormat);
}

CImGui::~CImGui()
{
    // Shutdown the backends and destroy the ImGui context.
    ImGui_ImplDX12_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}

void CImGui::CreateImGuiDescriptorHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC desc = {};
    desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    desc.NumDescriptors = 1; // Only one descriptor is needed for the ImGui font texture.
    desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    if (FAILED(m_device->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&m_srvDescHeap))))
        throw std::runtime_error("Failed to create ImGui descriptor heap.");
}

void CImGui::InitImGui(HWND hwnd, int numFramesInFlight, DXGI_FORMAT rtvFormat)
{
    // Create the ImGui context and set up default options.
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;  // Suppress unused variable warning if needed

    // Set a default style (dark theme)
    ImGui::StyleColorsDark();

    // Initialize the Win32 backend.
    if (!ImGui_ImplWin32_Init(hwnd))
        throw std::runtime_error("Failed to initialize ImGui Win32 backend.");

    // Initialize the DX12 backend.
    if (!ImGui_ImplDX12_Init(
        m_device.Get(),
        numFramesInFlight,
        rtvFormat,
        m_srvDescHeap.Get(),
        m_srvDescHeap->GetCPUDescriptorHandleForHeapStart(),
        m_srvDescHeap->GetGPUDescriptorHandleForHeapStart()))
    {
        throw std::runtime_error("Failed to initialize ImGui DX12 backend.");
    }
}

void CImGui::RenderImGui(ID3D12GraphicsCommandList* cmdList)
{
    // Start a new ImGui frame.
    ImGui_ImplDX12_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    // Create a demo window (you can replace this with your custom UI).
    ImGui::Begin("Hello, ImGui!");
    ImGui::Text("This is an integrated ImGui window!");
    ImGui::End();

    // Finalize the frame.
    ImGui::Render();

    // Set the descriptor heap required for ImGui's rendering.
    ID3D12DescriptorHeap* descriptorHeaps[] = { m_srvDescHeap.Get() };
    cmdList->SetDescriptorHeaps(_countof(descriptorHeaps), descriptorHeaps);

    // Render the ImGui draw data using the provided command list.
    ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), cmdList);
}
