#include "Geode/cocos/CCScheduler.h"
#include "Includes/Hacks.hpp"
#include <Geode/modify/CCScheduler.hpp>

FMOD::ChannelGroup* masterGroup;

float speedHack(float dt) {
	if (!masterGroup) {
		FMODAudioEngine::sharedEngine()->m_system->getMasterChannelGroup(&masterGroup);
	}

		if (Mod::get()->getSavedValue<bool>("speedhack")) {
			if (Mod::get()->getSavedValue<float>("speedhack-value") <= 0.0f) {
				Mod::get()->setSavedValue<float>("speedhack-value", 1.0f);
			}
			else {
				dt = dt * Mod::get()->getSavedValue<float>("speedhack-value");
				if (Mod::get()->getSavedValue<bool>("speedhack-music")) {
					masterGroup->setPitch(Mod::get()->getSavedValue<float>("speedhack-value"));
				}
				else {
					masterGroup->setPitch(1);
				}
			}
		}
		else {
			masterGroup->setPitch(1);
		}
	
	return dt;
}

void Modules::speedHack() {
	ImGui::SetNextWindowSize(ImVec2(202, 110), ImGuiCond_Once);
	ImGui::SetNextWindowPos(ImVec2(215, 60), ImGuiCond_Once);

	ImGui::Begin("Speedhack");

	ClearHack::get().createCheckbox("Enable", "speedhack");
	ClearHack::get().createCheckbox("Speedhack Music", "speedhack-music");
	ClearHack::get().createInputFloat("Value", "speedhack-value");

	ImGui::End();
}

class $modify(CCScheduler) {
	virtual void update(float dt) {
		dt = speedHack(dt);
		CCScheduler::update(dt);
	}
};
