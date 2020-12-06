#pragma once

#include <string>

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "core/game.h"

namespace game {

namespace gui {

namespace constants {

/**
 * Window Constants
 */
const size_t kWindowSize = 875;
const size_t kBuffer = 25;
const size_t kWindowMargin = 200;
const double kGameTimestep = 0.5;

/**
 * Multimedia Constants
 */
const size_t kBackgroundR = 100;
const size_t kBackgroundG = 100;
const size_t kBackgroundB = 100;
const double kPauseScreenOpacity = 0.75;
const std::string kPauseScreenBorderColor = "white";
const std::string kPlatformBorderColor = "brown";
const size_t kBorderWidth = 5;
// Source: https://i.imgur.com/onEunqF.png
const std::string kLogoAssetFile = "logo.png";
const std::string kBackgroundAssetFile = "background.png";
const std::string kBlockAssetFile = "block.png";
const std::string kCharGroundRightAssetFile = "illini_mario_standing_right.png";
const std::string kCharGroundLeftAssetFile = "illini_mario_standing_left.png";
const std::string kCharJumpRightAssetFile = "illini_mario_jumping_right.png";
const std::string kCharJumpLeftAssetFile = "illini_mario_jumping_left.png";
const std::string kJumpAudioFile = "jump.mp3";
const std::string kGameAudioFile = "game.mp3";
const std::string kMenuAudioFile = "menu.mp3";
const std::string kGameOverAudioFile = "game_over.mp3";

const ci::audio::VoiceRef kJumpAudio =
        ci::audio::Voice::create(
                ci::audio::load(ci::app::loadAsset(kJumpAudioFile)));
const ci::audio::VoiceRef kGameAudio =
        ci::audio::Voice::create(
                ci::audio::load(ci::app::loadAsset(kGameAudioFile)));
const ci::audio::VoiceRef kMenuAudio =
        ci::audio::Voice::create(
                ci::audio::load(ci::app::loadAsset(kMenuAudioFile)));
const ci::audio::VoiceRef kGameOverAudio =
        ci::audio::Voice::create(
                ci::audio::load(ci::app::loadAsset(kGameOverAudioFile)));

const std::map<game::core::GameStatus, ci::audio::VoiceRef> kAudioMap = {
        {game::core::GameStatus::IN_PROGRESS, kGameAudio},
        {game::core::GameStatus::START_SCREEN, kMenuAudio},
        {game::core::GameStatus::GAME_OVER, kGameOverAudio}
};

const glm::dvec2 kGameLogoPosition(kWindowSize / 2, kWindowSize / 4);
const size_t kGameLogoWidth = 300;
const size_t kGameLogoHeight = 300;

/**
 * Game Text Constants
 */
const std::string kTextColor = "white";
const size_t kTinyTextSize = 12;
const size_t kSmallTextSize = 16;
const size_t kMediumTextSize = 28;
const size_t kLargeTextSize = 42;
const std::string kGameTitle = "Illini Mario";
const std::string kGamePlayInstructions = "Move with the mouse - Click to jump";
const std::string kGameStartInstructions = "Press Enter to Start";
const std::string kGameResumeInstructions = "Space to Resume";
const std::string kGameOverText = "Game Over";
const std::string kGameOverScoreText = "Your Score: ";
const std::string kGameDeveloper = "Joydeep Mukherjee - UIUC CS 126 Fall 2020";
const std::string kTextFont = "Pixel NES";
const glm::dvec2 kScorePosition(kWindowSize - 2 * kBuffer, kBuffer);
const glm::dvec2 kGameDevPosition(kBuffer, kWindowSize - kBuffer);

}

}

}