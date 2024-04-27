#pragma once

#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
#include <misc/cpp/imgui_stdlib.h>

using namespace geode::prelude;

class UltraHack {
private:
	bool m_toggleHacks = false;
public:
	static UltraHack& get();

	void toggle();
	void setup();

	template <typename T>
	T idAccessor(const std::string& type, const std::string& id, T value = T());

	void createCheckbox(const std::string& content, const std::string& id);
	void createInputFloat(const std::string& content, const std::string& id);
	void createInputString(const std::string& content, const std::string& id);
	void createButton(const std::string& content, std::function<void()> onClick);
};