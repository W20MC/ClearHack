#include "Hacks/Includes/Hacks.hpp"

ClearHack& ClearHack::get() {
    static ClearHack inst;
    return inst;
}

void ClearHack::toggle() {
    m_toggleHacks = !m_toggleHacks;
    ImGuiCocos::get().setVisible(m_toggleHacks);
    if (auto* playLayer = PlayLayer::get()) {
        bool cursorToggle = playLayer->m_isPaused ||
            playLayer->m_hasCompletedLevel ||
            GameManager::sharedState()->getGameVariable("0024") ||
            m_toggleHacks;

        if (cursorToggle == true) {
            PlatformToolbox::showCursor();
        } else {
            PlatformToolbox::hideCursor();
        }
    }
}

void ClearHack::setup() {
    ImGuiCocos::get().setup([] {
        ImGuiIO& io = ImGui::GetIO();

        auto* font = io.Fonts->AddFontFromFileTTF(
            (Mod::get()->getResourcesDir() / "PTSans-Regular.ttf").string().c_str(), 
            16.0f
        );

        io.FontDefault = font;

        ImVec4* colors = ImGui::GetStyle().Colors;
        colors[ImGuiCol_TitleBg] = ImVec4(1.00f, 0.14f, 0.14f, 1.00f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(1.00f, 0.14f, 0.14f, 1.00f);
    }).draw([this] {
        ImGui::Begin("ClearHack");
        
        createCheckbox("Noclip", "noclip");
        createCheckbox("Practice Music Sync", "practice-sync");
        createCheckbox("Copy Hack", "copy-hack");
        createCheckbox("Auto Song Download", "song-download");

        ImGui::End();

        Modules::get().speedHack();
    });

    ImGuiCocos::get().setVisible(false);
}

void ClearHack::createCheckbox(const std::string& content, const std::string& id) {
    bool idVal = Mod::get()->getSavedValue<bool>(id);

    if (ImGui::Checkbox(content.c_str(), &idVal)) {
        Mod::get()->setSavedValue<bool>(id, idVal);
    }
}

void ClearHack::createInputFloat(const std::string& content, const std::string& id) {
    float idVal = Mod::get()->getSavedValue<float>(id);

    if (ImGui::InputFloat(content.c_str(), &idVal)) {
        Mod::get()->setSavedValue<float>(id, idVal);
    }
}

void ClearHack::createInputString(const std::string& content, const std::string& id) {
    std::string idVal = Mod::get()->getSavedValue<std::string>(id);

    if (ImGui::InputText(content.c_str(), &idVal)) {
        Mod::get()->setSavedValue<std::string>(id, idVal);
    }
}

void ClearHack::createButton(const std::string& content, std::function<void()> onClick) {
    if (ImGui::Button(content.c_str())) {
        onClick();
    }
}
