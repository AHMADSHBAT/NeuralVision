#include "CGDIScreenCapture.h"
#include <fstream>
#include "CLogger.h"


bool CGDIScreenCapture::CaptureScreen(const std::wstring& filename, int x, int y, int width, int height)
{
    HDC hScreen = GetDC(nullptr);
    HDC hDC = CreateCompatibleDC(hScreen);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, width, height);
    SelectObject(hDC, hBitmap);

    BitBlt(hDC, 0, 0, width, height, hScreen, x, y, SRCCOPY);

    BITMAPFILEHEADER bmfHeader;
    BITMAPINFOHEADER bi;
    BITMAP bmp;
    GetObject(hBitmap, sizeof(BITMAP), &bmp);

    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = bmp.bmWidth;
    bi.biHeight = -bmp.bmHeight;  // Negative ensures correct orientation
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    DWORD dwBmpSize = ((bmp.bmWidth * bi.biBitCount + 31) / 32) * 4 * bmp.bmHeight;
    char* lpbitmap = new char[dwBmpSize];
    GetDIBits(hDC, hBitmap, 0, bmp.bmHeight, lpbitmap, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    HANDLE hFile = CreateFile(filename.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD dwSizeofDIB = dwBmpSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    bmfHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfHeader.bfSize = dwSizeofDIB;
    bmfHeader.bfType = 0x4D42;

    DWORD dwBytesWritten;
    WriteFile(hFile, &bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
    WriteFile(hFile, &bi, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
    WriteFile(hFile, lpbitmap, dwBmpSize, &dwBytesWritten, NULL);

    CloseHandle(hFile);
    delete[] lpbitmap;

    DeleteObject(hBitmap);
    DeleteDC(hDC);
    ReleaseDC(nullptr, hScreen);

    return true;
}



bool CGDIScreenCapture::CaptureScreen(unsigned char* lpbitmap, int x, int y, int width, int height)
{
    HDC hScreen = GetDC(nullptr);
    HDC hDC = CreateCompatibleDC(hScreen);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, width, height);
    SelectObject(hDC, hBitmap);

    BitBlt(hDC, 0, 0, width, height, hScreen, x, y, SRCCOPY);

    BITMAPFILEHEADER bmfHeader;
    BITMAPINFOHEADER bi;
    BITMAP bmp;
    GetObject(hBitmap, sizeof(BITMAP), &bmp);

    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = bmp.bmWidth;
    bi.biHeight = -bmp.bmHeight;  // Negative ensures correct orientation
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    DWORD dwBmpSize = ((bmp.bmWidth * bi.biBitCount + 31) / 32) * 4 * bmp.bmHeight;

    if (lpbitmap != nullptr)
    {
        LOG(ERR, "lpbitmap != nullptr");
        return false;
    }

    lpbitmap = new unsigned char[dwBmpSize];
    GetDIBits(hDC, hBitmap, 0, bmp.bmHeight, lpbitmap, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    LOG(INFO, "%s", lpbitmap);
    DeleteObject(hBitmap);
    DeleteDC(hDC);
    ReleaseDC(nullptr, hScreen);

    return true;
}



std::vector<unsigned char> CGDIScreenCapture::LoadImageToMemoryFromFile(const std::wstring& filename, int& width, int& height)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file) return {};

    BITMAPFILEHEADER bmfHeader;
    BITMAPINFOHEADER bi;
    file.read((char*)&bmfHeader, sizeof(BITMAPFILEHEADER));
    file.read((char*)&bi, sizeof(BITMAPINFOHEADER));

    width = bi.biWidth;
    height = abs(bi.biHeight);  // Ensure positive height

    std::vector<unsigned char> buffer(bi.biSizeImage);
    file.read((char*)buffer.data(), bi.biSizeImage);
    file.close();

    return buffer;
}


std::vector<unsigned char> CGDIScreenCapture::LoadImageFromClipboard(int& width, int& height)
{
    if (!IsClipboardFormatAvailable(CF_BITMAP)) return {};

    if (!OpenClipboard(nullptr)) return {};

    HBITMAP hBitmap = (HBITMAP)GetClipboardData(CF_BITMAP);
    if (!hBitmap) {
        CloseClipboard();
        return {};
    }

    BITMAP bmp;
    GetObject(hBitmap, sizeof(BITMAP), &bmp);

    width = bmp.bmWidth;
    height = bmp.bmHeight;

    // Convert HBITMAP to raw pixel data
    std::vector<unsigned char> buffer(width * height * 4); // 4 bytes per pixel (RGBA)

    HDC hdcScreen = GetDC(nullptr);
    HDC hdcMem = CreateCompatibleDC(hdcScreen);
    SelectObject(hdcMem, hBitmap);

    BITMAPINFOHEADER bi = {};
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height;  // Negative height for top-down DIB
    bi.biPlanes = 1;
    bi.biBitCount = 32; // RGBA
    bi.biCompression = BI_RGB;

    GetDIBits(hdcMem, hBitmap, 0, height, buffer.data(), (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    DeleteDC(hdcMem);
    ReleaseDC(nullptr, hdcScreen);
    CloseClipboard();

    return buffer;
}

