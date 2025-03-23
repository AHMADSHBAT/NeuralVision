#define STB_IMAGE_IMPLEMENTATION
#include "CImage2RawConv.h"



void CImage2RawConv::LoadImage(const std::string& imagePath) {
    imageData = stbi_load(imagePath.c_str(), &width, &height, &channels, 0);
    if (!imageData) {
        std::cerr << "Error: Could not load image!\n";
        return;
    }

    // Convert image data to float [0,1]
    rawData.resize(width * height * channels);
    for (int i = 0; i < width * height * channels; i++) {
        rawData[i] = imageData[i] / 255.0f;
    }

    std::cout << "Loaded Image: " << width << "x" << height << " Channels: " << channels << std::endl;
}
