#include "UltraHack.hpp"
#include "Hacks/Includes/Hacks.hpp"

UltraHack& UltraHack::get() {
    static UltraHack inst;
    return inst;
}

void UltraHack::toggle() {
    m_toggleHacks = !m_toggleHacks;
    ImGuiCocos::get().setVisible(m_toggleHacks);
}

void UltraHack::setup() {
    ImGuiCocos::get().setup([] {
        auto* font = ImGui::GetIO().Fonts->AddFontFromFileTTF(
            (Mod::get()->getResourcesDir() / "PTSans-Regular.ttf").string().c_str(), 
            16.0f
        );
        ImGui::GetIO().FontDefault = font;

        ImVec4* colors = ImGui::GetStyle().Colors;
        colors[ImGuiCol_TitleBg] = ImVec4(1.00f, 0.14f, 0.14f, 1.00f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(1.00f, 0.14f, 0.14f, 1.00f);
    }).draw([this] {
        ImGui::Begin("UltraHack");
        
        createCheckbox("Noclip", "noclip");
        createCheckbox("Practice Music Sync", "practice-sync");

        ImGui::End();

        Modules::get().speedHack();
    });

    ImGuiCocos::get().setVisible(false);
}

template <typename T>
T UltraHack::idAccessor(const std::string& type, const std::string& id, T value) {
    if (type == "set") {
        Mod::get()->setSavedValue<T>(id, value);
    }
    else if (type == "get") {
        return Mod::get()->getSavedValue<T>(id);
    }
}

void UltraHack::createCheckbox(const std::string& content, const std::string& id) {
    bool idVal = this->idAccessor<bool>("get", id);

    if (ImGui::Checkbox(content.c_str(), &idVal)) {
        this->idAccessor<bool>("set", id, idVal);
    }
}

void UltraHack::createInputFloat(const std::string& content, const std::string& id) {
    float idVal = this->idAccessor<float>("get", id);

    if (ImGui::InputFloat(content.c_str(), &idVal)) {
        this->idAccessor<float>("set", id, idVal);
    }
}

void UltraHack::createInputString(const std::string& content, const std::string& id) {
    std::string idVal = this->idAccessor<std::string>("get", id);

    if (ImGui::InputText(content.c_str(), &idVal)) {
        this->idAccessor<std::string>("set", id, idVal);
    }
}

void UltraHack::createButton(const std::string& content, std::function<void()> onClick) {
    if (ImGui::Button(content.c_str())) {
        onClick();
    }
}