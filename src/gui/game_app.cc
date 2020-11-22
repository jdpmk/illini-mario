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

void GameApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RETURN:
      if (game_.GetGameStatus() == game::core::GameStatus::START_SCREEN)
        game_.SetGameStatus(game::core::GameStatus::IN_PROGRESS);
      break;
    case ci::app::KeyEvent::KEY_ESCAPE:
      if (game_.GetGameStatus() == game::core::GameStatus::IN_PROGRESS)
        game_.SetGameStatus(game::core::GameStatus::PAUSED);
      break;
    case ci::app::KeyEvent::KEY_SPACE:
      if (game_.GetGameStatus() == game::core::GameStatus::PAUSED)
        game_.SetGameStatus(game::core::GameStatus::IN_PROGRESS);
      break;
  }
}

void GameApp::DrawGame() const {
  if (game_.GetGameStatus() == game::core::GameStatus::START_SCREEN)
    DrawStartScreen();
  else if (game_.GetGameStatus() == game::core::GameStatus::GAME_OVER_SCREEN)
    DrawGameOverScreen();
  else {
    DrawGameInProgress();
    if (game_.GetGameStatus() == game::core::GameStatus::PAUSED) {
      DrawGamePaused();
    }
  }
}

void GameApp::DrawStartScreen() const {
  ci::gl::drawStringCentered(
          kGameTitle,
          glm::dvec2(kWindowSize / 2, kWindowSize / 2),
          ci::Color(kTextColor.c_str()),
          ci::Font(kTextFont, kLargeTextSize));
  ci::gl::drawStringCentered(
          kGameStartInstructions,
          glm::dvec2(kWindowSize / 2, 7 * kWindowSize / 12),
          ci::Color(kTextColor.c_str()),
          ci::Font(kTextFont, kMediumTextSize));
  ci::gl::drawStringCentered(
          kGamePlayInstructions,
          glm::dvec2(kWindowSize / 2, 2 * kWindowSize / 3),
          ci::Color(kTextColor.c_str()),
          ci::Font(kTextFont, kSmallTextSize));
}

void GameApp::DrawGameInProgress() const {
  DrawPlayer(game_.GetPlayer());
  for (const game::core::Platform& platform : game_.GetPlatforms())
    DrawPlatform(platform);
}

void GameApp::DrawGamePaused() const {
  ci::gl::color(ci::Color(kPlatformBodyColor.c_str()));
  ci::gl::drawSolidRect(
          ci::Rectf(
                  kWindowMargin,
                  kWindowMargin,
                  kWindowSize - kWindowMargin,
                  kWindowSize - kWindowMargin));
  ci::gl::color(ci::Color(kPlatformBorderColor.c_str()));
  ci::gl::drawStrokedRect(
          ci::Rectf(
                  kWindowMargin,
                  kWindowMargin,
                  kWindowSize - kWindowMargin,
                  kWindowSize - kWindowMargin));
  ci::gl::drawStringCentered(
          kGameResumeInstructions,
          glm::dvec2(kWindowSize / 2, kWindowSize / 2),
          ci::Color(kTextColor.c_str()),
          ci::Font(kTextFont, kLargeTextSize));
}

void GameApp::DrawGameOverScreen() const {
  ci::gl::drawStringCentered(
          kGameOverText,
          glm::dvec2(kWindowSize / 2, kWindowSize / 2),
          ci::Color(kTextColor.c_str()),
          ci::Font(kTextFont, kLargeTextSize));
  ci::gl::drawStringCentered(
          kGameOverScoreText + std::to_string(game_.GetPlayer().GetScore()),
          glm::dvec2(kWindowSize / 2, 2 * kWindowSize / 3),
          ci::Color(kTextColor.c_str()),
          ci::Font(kTextFont, kSmallTextSize));
}

void GameApp::DrawPlatform(const game::core::Platform& platform) const {
  ci::gl::color(ci::Color(kPlatformBodyColor.c_str()));
  ci::gl::drawSolidRect(
          ci::Rectf(platform.GetTopLeftCorner().x,
                    kWindowSize - platform.GetTopLeftCorner().y,
                    platform.GetBottomRightCorner().x,
                    kWindowSize - platform.GetBottomRightCorner().y));

  ci::gl::color(ci::Color(kPlatformBorderColor.c_str()));
  ci::gl::drawStrokedRect(
          ci::Rectf(platform.GetTopLeftCorner().x,
                    kWindowSize - platform.GetTopLeftCorner().y,
                    platform.GetBottomRightCorner().x,
                    kWindowSize - platform.GetBottomRightCorner().y),
          kBorderWidth);
}

void GameApp::DrawPlayer(const game::core::Player& player) const {
  bool player_facing_left = player.GetVelocity().x < 0;
  ci::gl::color(ci::Color(kPlayerBodyColor.c_str()));
  ci::gl::drawSolidRect(
          ci::Rectf(player.GetTopLeftCorner().x,
                    kWindowSize - player.GetTopLeftCorner().y,
                    player.GetBottomRightCorner().x,
                    kWindowSize - player.GetBottomRightCorner().y));

  ci::gl::color(ci::Color(kPlayerBorderColor.c_str()));
  ci::gl::drawStrokedRect(
          ci::Rectf(player.GetTopLeftCorner().x,
                    kWindowSize - player.GetTopLeftCorner().y,
                    player.GetBottomRightCorner().x,
                    kWindowSize - player.GetBottomRightCorner().y),
          kBorderWidth);

  ci::gl::color(ci::Color(kPlayerEyeColor.c_str()));
  ci::gl::drawSolidCircle(
          glm::dvec2(player.GetTopLeftCorner().x +
                     (player_facing_left ? 1 : 3) * player.GetWidth() / 4,
                     kWindowSize -
                     (player.GetTopLeftCorner().y - player.GetHeight() / 3)),
          kPlayerEyeRadius);
  ci::gl::drawSolidCircle(
          glm::dvec2(player.GetTopLeftCorner().x + 2 * player.GetWidth() / 4,
                     kWindowSize -
                     (player.GetTopLeftCorner().y - player.GetHeight() / 3)),
          kPlayerEyeRadius);
}

}

}