#include <gui/game_app.h>

namespace game {

namespace gui {

GameApp::GameApp() {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void GameApp::draw() {
  ci::Color8u background_color(kBackgroundR, kBackgroundG, kBackgroundB);
  ci::gl::clear(background_color);

  DrawGame();
}

void GameApp::update() {
  game_.UpdateState(kGameTimestep);
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
  ci::gl::draw(kBackgroundTex);
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
  ci::gl::drawStringCentered(
          std::to_string(game_.GetPlayer().GetScore()),
          kScorePosition,
          ci::Color(kTextColor.c_str()),
          ci::Font(kTextFont, kLargeTextSize));
  DrawPlayer(game_.GetPlayer());
  for (const game::core::Platform& platform : game_.GetPlatforms())
    DrawPlatform(platform);
}

void GameApp::DrawGamePaused() const {
  ci::gl::color(ci::ColorA(0, 0, 0, kPauseScreenOpacity));
  ci::gl::drawSolidRect(
          ci::Rectf(
                  kWindowMargin,
                  kWindowMargin,
                  kWindowSize - kWindowMargin,
                  kWindowSize - kWindowMargin));
  ci::gl::color(ci::Color(kPauseScreenBorderColor.c_str()));
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
          ci::Font(kTextFont, kMediumTextSize));
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
          ci::Font(kTextFont, kMediumTextSize));
}

void GameApp::DrawPlatform(const game::core::Platform& platform) const {
  size_t top_left_x = platform.GetTopLeftCorner().x;
  size_t top_left_y = platform.GetTopLeftCorner().y;
  size_t bottom_right_x = platform.GetTopLeftCorner().x + kPlatformHeight;
  size_t bottom_right_y = platform.GetBottomRightCorner().y;

  while (top_left_x < platform.GetTopRightCorner().x) {
    if (top_left_y < kWindowSize) {
      ci::gl::draw(kBlockTex,
                   ci::Rectf(top_left_x,
                             kWindowSize - top_left_y,
                             bottom_right_x,
                             kWindowSize - bottom_right_y));
    }
    top_left_x += kPlatformHeight;
    bottom_right_x += kPlatformHeight;
  }
}

void GameApp::DrawPlayer(const game::core::Player& player) const {
  ci::gl::draw(
          player.IsJumping()
            ? player.IsFacingRight()
              ? kCharRightJumpTex
              : kCharLeftJumpTex
            : player.IsFacingRight()
              ? kCharRightGroundTex
              : kCharLeftGroundTex,
          ci::Rectf(
                  player.GetTopLeftCorner().x,
                  kWindowSize - player.GetTopLeftCorner().y,
                  player.GetBottomRightCorner().x,
                  kWindowSize - player.GetBottomRightCorner().y));
}

}

}