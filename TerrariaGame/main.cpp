#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Terraria Game");
    SetTargetFPS(60);
    rlImGuiSetup(true); // Initialize rlImGui with default settings

    while (!WindowShouldClose()) {
        BeginDrawing();
        // 清理背景颜色为白色
        ClearBackground(RAYWHITE);
        DrawText("Hello, Terraria Game!", 10, 10, 20, DARKGRAY);

        // ImGui 内容必须放在 rlImGuiBegin() / rlImGuiEnd() 之间
        rlImGuiBegin();
        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("This is a simple ImGui window.");
        if (ImGui::Button("Click Me")) {
            std::cout << "Button clicked!" << std::endl;
        }










        ImGui::End();
        rlImGuiEnd();

        EndDrawing();
    }

    // 退出前释放 ImGui 资源
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}