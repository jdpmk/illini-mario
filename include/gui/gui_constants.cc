#include <string>

namespace game {

namespace gui {

namespace constants {

/**
 * Window Constants
 */
const double kWindowSize = 875;
const double kWindowMargin = 200;
const double kGameTimestep = 0.5;

/**
 * Graphics Size Constatns
 */
const size_t kPlayerEyeRadius = 4;
const double kBorderWidth = 2;

/**
 * Color Constants
 */
const size_t kBackgroundR = 100;
const size_t kBackgroundG = 100;
const size_t kBackgroundB = 100;
const std::string kTextColor = "white";
const std::string kPlatformBodyColor = "gray";
const std::string kPlatformBorderColor = "white";
const std::string kPlayerBodyColor = "orange";
const std::string kPlayerBorderColor = "white";
const std::string kPlayerEyeColor = "white";

/**
 * Game Text Constants
 */
const size_t kSmallTextSize = 16;
const size_t kMediumTextSize = 24;
const size_t kLargeTextSize = 30;
const std::string kGameTitle = "CS 126 Final Project";
const std::string kGamePlayInstructions = "Move with the mouse - Click to jump";
const std::string kGameStartInstructions = "Press Enter to Start";
const std::string kGameResumeInstructions = "Press Space to Resume";
const std::string kGameOverText = "Game Over!";
const std::string kGameOverScoreText = "Your Score: ";
const std::string kTextFont = "Roboto";
}

}

}