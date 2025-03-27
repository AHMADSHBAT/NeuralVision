#include "CDX12.h"
#include <iostream>
#include "CLogger.h"


void AttachConsoleToApp()
{
    if (AllocConsole())  // Ensure a console is created
    {
        FILE* fDummy;
        freopen_s(&fDummy, "CONOUT$", "w", stdout);
        freopen_s(&fDummy, "CONOUT$", "w", stderr);
        freopen_s(&fDummy, "CONIN$", "r", stdin);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    AttachConsoleToApp();
    LOG(INFO, "Hello, World!");
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
