#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "ClearHack.hpp"

using namespace geode::prelude;

$execute {
    using namespace keybinds;

    BindManager::get()->registerBindable({
        "launch"_spr,
        "Launch ClearHack",
        "",
        { Keybind::create(KEY_L, Modifier::None) },
        "Hacks"
    });

    new EventListener([=](InvokeBindEvent* event) {
        if (event->isDown()) {
            ClearHack::get().toggle();
        }
        return ListenerResult::Propagate;
    }, InvokeBindFilter(nullptr, "launch"_spr));
}

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        ClearHack::get().setup();
        return true;
    }
};