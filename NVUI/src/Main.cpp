#include "CDX12.h"




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    try {
        // Create the DX12 application instance.
        CDX12 dx12App(hInstance, nCmdShow);

        // Run the main message loop.
        return dx12App.Run();
    }
    catch (const std::runtime_error& e)
    {
        MessageBoxA(nullptr, e.what(), "Initialization Error", MB_OK);
        return -1;
    }
}
