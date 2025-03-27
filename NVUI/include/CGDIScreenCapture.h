#pragma once

#include <windows.h>
#include <string>
#include <vector>

class CGDIScreenCapture {
public:
    static bool CaptureScreen(const std::wstring& filename, int x, int y, int width, int height);
    static bool CaptureScreen(unsigned char* lpbitmap, int x, int y, int width, int height);
    static std::vector<unsigned char> LoadImageToMemoryFromFile(const std::wstring& filename, int& width, int& height);
    static std::vector<unsigned char> LoadImageFromClipboard(int& width, int& height);
};

