#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <core/game.h>

namespace game {

namespace gui {

class GameApp : public ci::app::App {
 public:
  GameApp();
  void draw() override;
  void update() override;
  void mouseMove(ci::app::MouseEvent event) override;
  void mouseDown(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  const double kWindowSize = 875;
  const double kWindowMargin = 200;
  const double game_timestep_ = 0.5;
  const std::string kTextColor = "white";
  const std::string kPlatformBodyColor = "gray";
  const std::string kPlatformBorderColor = "white";
  const std::string kPlayerBodyColor = "orange";
  const std::string kPlayerBorderColor = "white";
  const std::string kPlayerEyeColor = "white";
  const size_t kPlayerEyeRadius = 4;
  const double kBorderWidth = 2;
  const std::string kGameTitle = "CS 126 Final Project";
  const std::string kGamePlayInstructions = "Move with the mouse - Click to jump";
  const std::string kGameStartInstructions = "Press Enter to Start";
  const std::string kGameResumeInstructions = "Press Space to Resume";
  const std::string kGameOverText = "Game Over!";
  const std::string kGameOverScoreText = "Your Score: ";
  const std::string kTextFont = "Roboto";
  const size_t kSmallTextSize = 16;
  const size_t kMediumTextSize = 24;
  const size_t kLargeTextSize = 30;
 private:
  /**
   * Helper function to draw the game, based on its status.
   */
  void DrawGame() const;
  /**
   * Helper function to draw the start screen.
   */
  void DrawStartScreen() const;
  /**
   * Helper function to draw the game while it is in progress.
   */
  void DrawGameInProgress() const;
  /**
   * Helper function to draw the game paused screen.
   */
  void DrawGamePaused() const;
  /**
   * Helper function to draw the game over screen.
   */
  void DrawGameOverScreen() const;
  /**
   * Helper function to draw a platform.
   *
   * @param platform The platform to draw
   */
  void DrawPlatform(const game::core::Platform& platform) const;
  /**
   * Helper function to draw a player.
   *
   * @param player The player to draw
   */
  void DrawPlayer(const game::core::Player& player) const;

  game::core::Game game_;
};

}

}