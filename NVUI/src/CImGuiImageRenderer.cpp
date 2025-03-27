#include "CImGuiImageRenderer.h"
#include "CGDIScreenCapture.h"
#include "CLogger.h"
#include "imgui.h"
#include "imgui_impl_dx12.h"

void CImGuiImageRenderer::ShowImageWorkspace(const std::vector<unsigned char>&)
{
	LOG(INFO, "ShowImageWorkspace");
    //CaptureScreen(char* lpbitmap, int x, int y, int width, int height)
    m_imageData = nullptr;
    m_imageLoaded = false;
    if (!m_imageLoaded) {
        CGDIScreenCapture::CaptureScreen(m_imageData, 0, 0, imgWidth, imgHeight);
        if (m_imageData == nullptr) {
            LOG(ERR, "LoadImage is NULL");
            return;
        }
    }

    ImGui::Begin("Image Workspace");
    if (m_imageLoaded) {
        ImGui::Text("Width: %d, Height: %d", imgWidth, imgHeight);
        // Assuming m_imageData is a texture ID, cast it to ImTextureID
        ImGui::Image((ImTextureID)m_imageData, ImVec2((float)imgWidth, (float)imgHeight));
    }
    else {
        ImGui::Text("No image loaded.");
    }
    ImGui::End();
}
