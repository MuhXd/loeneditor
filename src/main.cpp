#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

#include <imgui-cocos.hpp>
#include <vector>
using namespace geode::prelude;

struct Button {
    std::string name;
    std::string id;
    bool isChecked;
};

std::vector<Button> buttonlist = {
    {"All","loeneditor.all", false},
    {"Foreground Tiles","loeneditor.ForegroundTiles", false},
    {"Background Tiles","loeneditor.all", false},
    {"Enitites","loeneditor.Enitites", false},
    {"Triggers","loeneditor.Triggers", false},
    {"Foreground Decals","loeneditor.ForegroundDecals", false},
    {"Background Decals","loeneditor.BackgroundDecals", false}
};

ImVec2 windowPos = ImVec2(1500, 500); 

$on_mod(Loaded) {
    ImGuiCocos::get().setup([] {
        // This runs after ImGui has been setup,
        // It's a callback as ImGui will be re-initialized when toggling fullscreen,
        // so use this to setup any themes and/or fonts!
    }).draw([] {
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;

        ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);
        ImGui::SetWindowSize(ImVec2(500, 500));

        ImGui::Begin("My awesome window", nullptr, window_flags);

        for (size_t i = 0; i < buttonlist.size(); ++i) {
            ImVec4 buttonColor = buttonlist[i].isChecked ? ImVec4(0.06f, 0.53f, 0.98f, 1.00f) : ImVec4(0.00f, 0.00f, 0.00f, 0.40f);
            ImVec4 buttonHoveredColor = buttonlist[i].isChecked ? ImVec4(0.06f, 0.53f, 0.98f, 1.00f) : ImVec4(1.00f, 1.00f, 1.00f, 0.36f);
            ImVec4 buttonActiveColor = buttonlist[i].isChecked ? ImVec4(0.06f, 0.53f, 0.98f, 1.00f) : ImVec4(0.00f, 0.00f, 0.00f, 0.40f);

            ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, buttonHoveredColor);
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, buttonActiveColor);

            if (ImGui::Button(buttonlist[i].name.c_str())) {
                for (size_t j = 0; j < buttonlist.size(); ++j) {
                    buttonlist[j].isChecked = (i == j);
                }
            }

            ImGui::PopStyleColor(3);
        }


        ImGui::ShowDemoWindow();

        ImGui::End();
    });
}
