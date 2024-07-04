#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <imgui-cocos.hpp>
#include <vector>
#include "utils.hpp"
using namespace geode::prelude;

ImVec2 windowPos = ImVec2(1500, 500); 

class $modify(LevelEditorLayer) { 
bool init(GJGameLevel* playerlayer, bool p1) {
        LevelEditorLayer::init(playerlayer,p1);
        return true;
}
};

$on_mod(Loaded) {
    ImGuiCocos::get().setup([] {
        // This runs after ImGui has been setup,
        // It's a callback as ImGui will be re-initialized when toggling fullscreen,
        // so use this to setup any themes and/or fonts!
    }).draw([] {
        if (!LevelEditorLayer::get()) {
            ImGui::End();
            return;
        };
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;

        ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);
        ImGui::Begin("My awesome window", nullptr, window_flags);
        ImGui::SetWindowSize(ImVec2(220, 300));
        CelesteUI::ToggleButton(CelesteUI::whitelist("loeneditor.Tiles",std::vector<CelesteUI::togglebutton> {
            {"All","loeneditor.all", true},
            {"Foreground Tiles","loeneditor.ForegroundTiles", false},
            {"Background Tiles","loeneditor.all", false},
            {"Enitites","loeneditor.Enitites", false},
            {"Triggers","loeneditor.Triggers", false},
            {"Foreground Decals","loeneditor.ForegroundDecals", false},
            {"Background Decals","loeneditor.BackgroundDecals", false}
        }));
        ImGui::ShowDemoWindow();

        ImGui::End();
    });
}
