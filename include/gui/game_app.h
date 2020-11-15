#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace game {

namespace gui {

class GameApp : public ci::app::App {
 public:
  GameApp();
  void draw() override;
  void update() override;

  const double kWindowSize = 875;
};

}

}