#include "Includes/Hacks.hpp"
#include <Geode/modify/LevelInfoLayer.hpp>

class $modify(LevelInfoLayer) {
    bool init(GJGameLevel* p0, bool p1) {
        if (!LevelInfoLayer::init(p0, p1)) {
            return false;
        }

        auto oldBtn = m_cloneBtn;
        auto currentBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_duplicateBtn_001.png"), this, menu_selector(LevelInfoLayer::confirmClone));

        if (Mod::get()->getSavedValue<bool>("copy-hack") == true) {
            m_cloneBtn = currentBtn;
            m_cloneBtn->setPosition(oldBtn->getPosition());
            oldBtn->getParent()->addChild(m_cloneBtn);

            oldBtn->setVisible(false);
        } else {
            m_cloneBtn = oldBtn;
        }

        return true;
    }
};