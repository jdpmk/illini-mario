#include <gui/game_app.h>

namespace game {

namespace gui {

GameApp::GameApp() {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void GameApp::draw() {
  ci::Color8u background_color(100, 100, 100);
  ci::gl::clear(background_color);

  DrawGame();
}

void GameApp::update() {
  game_.UpdateState(game_timestep_);
}

void GameApp::mouseMove(ci::app::MouseEvent event) {
  game_.MovePlayer(event.getPos().x);
}

void GameApp::mouseDown(ci::app::MouseEvent event) {
  game_.PlayerJump(event.getPos().x);
}

void GameApp::DrawGame() const {
  DrawPlayer(game_.GetPlayer());
  for (const game::core::Platform& platform : game_.GetPlatforms())
    DrawPlatform(platform);
}

void GameApp::DrawPlatform(const game::core::Platform& platform) const {
  ci::gl::color(ci::Color("gray"));
  ci::gl::drawSolidRect(
          ci::Rectf(platform.GetTopLeftCorner().x,
                    kWindowSize - platform.GetTopLeftCorner().y,
                    platform.GetBottomRightCorner().x,
                    kWindowSize - platform.GetBottomRightCorner().y));

  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(
          ci::Rectf(platform.GetTopLeftCorner().x,
                    kWindowSize - platform.GetTopLeftCorner().y,
                    platform.GetBottomRightCorner().x,
                    kWindowSize - platform.GetBottomRightCorner().y));
}

void GameApp::DrawPlayer(const game::core::Player& player) const {
  bool player_facing_left = player.GetVelocity().x < 0;
  ci::gl::color(ci::Color("orange"));
  ci::gl::drawSolidRect(
          ci::Rectf(player.GetTopLeftCorner().x,
                    kWindowSize - player.GetTopLeftCorner().y,
                    player.GetBottomRightCorner().x,
                    kWindowSize - player.GetBottomRightCorner().y));

  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(
          ci::Rectf(player.GetTopLeftCorner().x,
                    kWindowSize - player.GetTopLeftCorner().y,
                    player.GetBottomRightCorner().x,
                    kWindowSize - player.GetBottomRightCorner().y));

  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidCircle(
          glm::dvec2(player.GetTopLeftCorner().x + (player_facing_left ? 1 : 3) * player.GetWidth() / 4,
                     kWindowSize - (player.GetTopLeftCorner().y - player.GetHeight() / 3)),
          2);
  ci::gl::drawSolidCircle(
          glm::dvec2(player.GetTopLeftCorner().x + 2 * player.GetWidth() / 4,
                     kWindowSize - (player.GetTopLeftCorner().y - player.GetHeight() / 3)),
          2);
};

}

}