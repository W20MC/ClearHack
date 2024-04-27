#include "Includes/Hacks.hpp"
#include <Geode/modify/CCScheduler.hpp>

void Modules::speedHack() {
	ImGui::SetNextWindowSize(ImVec2(202, 99));
	ImGui::SetNextWindowPos(ImVec2(215, 60));

	ImGui::Begin("Speedhack (WIP)");

	UltraHack::get().createCheckbox("Enable", "speedhack");
	UltraHack::get().createInputFloat("Value", "speedhack-value");

	ImGui::End();
}