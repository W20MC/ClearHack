#include "Includes/Hacks.hpp"
#include <Geode/modify/CCScheduler.hpp>

FMOD::ChannelGroup* masterGroup;

void Modules::speedHack() {
	ImGui::SetNextWindowSize(ImVec2(202, 110), ImGuiCond_Once);
	ImGui::SetNextWindowPos(ImVec2(215, 60), ImGuiCond_Once);

	ImGui::Begin("Speedhack");

	UltraHack::get().createCheckbox("Enable", "speedhack");
	UltraHack::get().createCheckbox("Speedhack Music", "speedhack-music");
	UltraHack::get().createInputFloat("Value", "speedhack-value");

	ImGui::End();
}

class $modify(CCScheduler) {
	virtual void update(float dt) {
		if (!masterGroup) {
			FMODAudioEngine::sharedEngine()->m_system->getMasterChannelGroup(&masterGroup);
		}

		if (Mod::get()->getSavedValue<bool>("speedhack")) {
			if (Mod::get()->getSavedValue<float>("speedhack-value") <= 0.0f) {
				Mod::get()->setSavedValue<float>("set", "speedhack-value", 1.0f);
			}
			else {
				dt = dt * UltraHack::get().idAccessor<float>("get", "speedhack-value");
				if (Mod::get()->getSavedValue<bool>("speedhack-music")) {
					masterGroup->setPitch(Mod::get()->getSavedValue<float>("get", "speedhack-value"));
				}
				else {
					masterGroup->setPitch(1);
				}
			}
		}
		else {
			masterGroup->setPitch(1);
		}
		CCScheduler::update(dt);
	}
};
