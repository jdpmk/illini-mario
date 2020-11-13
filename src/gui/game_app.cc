#include <gui/game_app.h>

namespace game {

namespace gui {

GameApp::GameApp() {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void GameApp::draw() {
  ci::Color8u background_color(0, 0, 0);
  ci::gl::clear(background_color);

  ci::gl::drawStringCentered(
          "Sample Text",
          glm::vec2(kWindowSize / 2, kWindowSize / 2), ci::Color("white"));
}

}

}