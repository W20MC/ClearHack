#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "ClearHack.hpp"

using namespace geode::prelude;

#ifdef GEODE_IS_WINDOWS
#include <geode.custom-keybinds/include/Keybinds.hpp>
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
#endif

class $modify(CCKeyboardDispatcher) {
    bool dispatchKeyMSG(enumKeyCodes key, bool down, bool repeat) {
        if (key == KEY_L) {
            ClearHack::get().toggle();
        }

        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, repeat);
    }
};

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        ClearHack::get().setup();
        return true;
    }
};
