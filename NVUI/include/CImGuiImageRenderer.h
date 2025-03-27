#pragma once
#include <vector>



class CImGuiImageRenderer
{
public:

	void ShowImageWorkspace(const std::vector<unsigned char>&);

protected:
	unsigned char* m_imageData;
	int imgWidth;
	int imgHeight;
	bool m_imageLoaded;
};

