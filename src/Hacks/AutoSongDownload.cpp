#include "Includes/Hacks.hpp"
#include <Geode/modify/CustomSongWidget.hpp>

class $modify(CustomSongWidget) {
    bool init(SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk) {
        if (!CustomSongWidget::init(songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk)) {
            return false;
        }

        if (Mod::get()->getSavedValue<bool>("song-download") == true) {
            if (m_downloadBtn->isVisible()) {
                m_downloadBtn->activate();
            }
        }

        return true;
    }
};
