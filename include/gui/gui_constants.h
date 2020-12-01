#pragma once

#include <string>

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

namespace game {

namespace gui {

namespace constants {

/**
 * Window Constants
 */
const size_t kWindowSize = 875;
const size_t kWindowMargin = 200;
const double kGameTimestep = 0.5;

/**
 * Graphics Constants
 */
const size_t kBackgroundR = 100;
const size_t kBackgroundG = 100;
const size_t kBackgroundB = 100;
const glm::dvec2 kScorePosition = glm::dvec2(825, 25);
const double kPauseScreenOpacity = 0.75;
const std::string kPauseScreenBorderColor = "white";
const std::string kPlatformBorderColor = "brown";
const size_t kBorderWidth = 5;
// Source: https://i.imgur.com/onEunqF.png
const std::string kBackgroundAssetFile = "bg_edited.png";
const std::string kBlockAssetFile = "block.png";
const std::string kCharGroundRightAssetFile = "illini_mario_standing_right.png";
const std::string kCharGroundLeftAssetFile = "illini_mario_standing_left.png";
const std::string kCharJumpRightAssetFile = "illini_mario_jumping_right.png";
const std::string kCharJumpLeftAssetFile = "illini_mario_jumping_left.png";

/**
 * Game Text Constants
 */
const std::string kTextColor = "white";
const size_t kSmallTextSize = 16;
const size_t kMediumTextSize = 28;
const size_t kLargeTextSize = 42;
const std::string kGameTitle = "CS 126 Final Project";
const std::string kGamePlayInstructions = "Move with the mouse - Click to jump";
const std::string kGameStartInstructions = "Press Enter to Start";
const std::string kGameResumeInstructions = "Space to Resume";
const std::string kGameOverText = "Game Over";
const std::string kGameOverScoreText = "Your Score: ";
const std::string kTextFont = "Pixel NES";

}

}

}