#include "Includes/Hacks.hpp"
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* p0, GameObject* p1) {
        if (UltraHack::get().idAccessor<bool>("get", "noclip") == true);
        else {
            PlayLayer::destroyPlayer(p0, p1);
        }
    }
};