#pragma once
#include <Geode/Geode.hpp>

#include <imgui-cocos.hpp>
#include <vector>
#include <string>
#include <unordered_map>

namespace CelesteUI {
    struct togglebutton {
        std::string name;
        std::string id;
        bool isChecked;
    };
    struct SaveFileToggleButton {
        std::vector<togglebutton> tb;
        std::string id;
    };
    class Save {
    public:
        static std::unordered_map<std::string, std::vector<togglebutton>> toggleMap;
    };
    std::unordered_map<std::string, std::vector<togglebutton>> Save::toggleMap;

    SaveFileToggleButton whitelist(const std::string& id, std::vector<togglebutton> togg) {
        if (Save::toggleMap.find(id) != Save::toggleMap.end()) {
            SaveFileToggleButton vec = {Save::toggleMap[id],id};
            return vec;
        } else {
            SaveFileToggleButton vec = {togg,id};
            Save::toggleMap[id] = togg;
            return vec;
        }
    }

    void ToggleButton(CelesteUI::SaveFileToggleButton togs) {
    float maxButtonWidth = 0.0f;
    std::vector<CelesteUI::togglebutton> tog = togs.tb;
    std::string id = togs.id;
        for (size_t i = 0; i < tog.size(); ++i) {
            ImVec2 textSize = ImGui::CalcTextSize(tog[i].name.c_str());
            float buttonWidth = textSize.x + ImGui::GetStyle().FramePadding.x * 2;
            if (buttonWidth > maxButtonWidth) {
                maxButtonWidth = buttonWidth;
         }
    }
    ImVec2 defaultPadding = ImGui::GetStyle().FramePadding; // no change please
    ImGui::GetStyle().FramePadding.x = 0.0f;
        for (size_t i = 0; i < tog.size(); ++i) {
            ImVec4 buttonColor = tog[i].isChecked ? ImVec4(0.06f, 0.53f, 0.98f, 1.00f) : ImVec4(0.00f, 0.00f, 0.00f, 0.40f);
            ImVec4 buttonHoveredColor = tog[i].isChecked ? ImVec4(0.06f, 0.53f, 0.98f, 1.00f) : ImVec4(1.00f, 1.00f, 1.00f, 0.36f);
            ImVec4 buttonActiveColor = tog[i].isChecked ? ImVec4(0.06f, 0.53f, 0.98f, 1.00f) : ImVec4(0.00f, 0.00f, 0.00f, 0.40f);
            ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, buttonHoveredColor);
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, buttonActiveColor);
            ImGui::SetNextItemWidth(maxButtonWidth);
            ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(defaultPadding.x, defaultPadding.y));
            if (ImGui::Button(tog[i].name.c_str(), ImVec2(maxButtonWidth, 0.0f))) {
                for (size_t j = 0; j < tog.size(); ++j) {
                    tog[j].isChecked = (i == j);
                }
            }
            ImGui::PopStyleColor(3);
        }

        if (Save::toggleMap.find(id) != Save::toggleMap.end()) {
            Save::toggleMap[id] = tog;
        }
        
        ImGui::GetStyle().FramePadding = defaultPadding;

};

}
