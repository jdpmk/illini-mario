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

  DrawGame();
}

void GameApp::update() {
  game_.UpdateState(1);
}

void GameApp::DrawGame() const {
  DrawPlayer(game_.GetPlayer());
  for (const game::core::Platform& platform : game_.GetPlatforms())
    DrawPlatform(platform);
}

void GameApp::DrawPlayer(const game::core::Player& player) const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(
          ci::Rectf(player.GetTopLeftCorner().x,
                    kWindowSize - player.GetTopLeftCorner().y,
                    player.GetBottomRightCorner().x,
                    kWindowSize - player.GetBottomRightCorner().y));
}
void GameApp::DrawPlatform(const game::core::Platform& platform) const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(
          ci::Rectf(platform.GetTopLeftCorner().x,
                    kWindowSize - platform.GetTopLeftCorner().y,
                    platform.GetBottomRightCorner().x,
                    kWindowSize - platform.GetBottomRightCorner().y));
}

}

}