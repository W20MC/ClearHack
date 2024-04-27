#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "UltraHack.hpp"

using namespace geode::prelude;

$execute {
    using namespace keybinds;

    BindManager::get()->registerBindable({
        "launch"_spr,
        "Launch UltraHack",
        "",
        { Keybind::create(KEY_L, Modifier::None) },
        "Hacks"
    });

    new EventListener([=](InvokeBindEvent* event) {
        if (event->isDown()) {
            UltraHack::get().toggle();
        }
        return ListenerResult::Propagate;
    }, InvokeBindFilter(nullptr, "launch"_spr));
}

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        UltraHack::get().setup();
        return true;
    }
};