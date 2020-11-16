#include <gui/game_app.h>

namespace game {

namespace gui {

GameApp::GameApp() {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void GameApp::draw() {
  ci::Color8u background_color(181, 181, 181);
  ci::gl::clear(background_color);

  DrawGame();
}

void GameApp::update() {
  game_.UpdateState(game_timestep_);
}

void GameApp::DrawGame() const {
  DrawPlayer(game_.GetPlayer());
  for (const game::core::Platform& platform : game_.GetPlatforms())
    DrawPlatform(platform);
}

void GameApp::DrawPlatform(const game::core::Platform& platform) const {
  ci::gl::color(ci::Color("blue"));
  ci::gl::drawSolidRect(
          ci::Rectf(platform.GetTopLeftCorner().x,
                    kWindowSize - platform.GetTopLeftCorner().y,
                    platform.GetBottomRightCorner().x,
                    kWindowSize - platform.GetBottomRightCorner().y));
}
void GameApp::DrawPlayer(const game::core::Player& player) const {
  ci::gl::color(ci::Color("green"));
  ci::gl::drawSolidRect(
          ci::Rectf(player.GetTopLeftCorner().x,
                    kWindowSize - player.GetTopLeftCorner().y,
                    player.GetBottomRightCorner().x,
                    kWindowSize - player.GetBottomRightCorner().y));
};

}

}