#pragma once

#include <iostream>
#include <vector>
#include "stb_image.h" 

class CImage2RawConv {
public:
    CImage2RawConv(const std::string& imagePath) {
        LoadImage(imagePath);
    }

    std::vector<float> getRawData() const {
        return rawData;
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getChannels() const { return channels; }

    ~CImage2RawConv() {
        if (imageData) {
            stbi_image_free(imageData);
        }
    }

private:
    std::vector<float> rawData;
    int width = 0, height = 0, channels = 0;
    unsigned char* imageData = nullptr;

    void LoadImage(const std::string& imagePath);
};
