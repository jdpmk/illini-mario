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

  void DrawGame() const;
  void DrawPlatform(const game::core::Platform& platform) const;
  void DrawPlayer(const game::core::Player& player) const;

  const double kWindowSize = 875;
  const double game_timestep_ = 0.5;
 private:
  game::core::Game game_;
};

}

}