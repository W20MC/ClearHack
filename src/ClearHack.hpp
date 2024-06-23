#pragma once

#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
#include <misc/cpp/imgui_stdlib.h>

using namespace geode::prelude;

class ClearHack {
private:
	bool m_toggleHacks = false;
public:
	static ClearHack& get();

	void toggle();
	void setup();

	void createCheckbox(const std::string& content, const std::string& id);
	void createInputFloat(const std::string& content, const std::string& id);
	void createInputString(const std::string& content, const std::string& id);
	void createButton(const std::string& content, std::function<void()> onClick);
};
