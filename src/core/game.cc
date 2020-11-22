#include <core/game.h>

#include <physics/interactions.h>

namespace game {

namespace core {

Game::Game() {
  game_status_ = GameStatus::START_SCREEN;

  // These are hardcoded entities for Week 1 demo purposes.
  player_ = Player("Player", glm::dvec2(400, 100), glm::dvec2(1, 0),
                   glm::dvec2(1, -0.5), 40, 40);
  platforms_.emplace_back(glm::dvec2(400, 20), glm::dvec2(0, -0.25), 400, 10);
  platforms_.emplace_back(glm::dvec2(400, 100), glm::dvec2(0, -0.5), 300, 10);
  platforms_.emplace_back(glm::dvec2(400, 200), glm::dvec2(0, -0.5), 200, 10);
  platforms_.emplace_back(glm::dvec2(400, 260), glm::dvec2(0, -0.5), 100, 10);
}

GameStatus Game::GetGameStatus() const {
  return game_status_;
}

Player Game::GetPlayer() const {
  return player_;
}

std::list<Platform> Game::GetPlatforms() const {
  return platforms_;
}

void Game::SetGameStatus(GameStatus game_status) {
  game_status_ = game_status;
}

void Game::UpdateState(double dt) {
  if (game_status_ == IN_PROGRESS) {
    CollidePlayerWithPlatforms(dt);
    GenerateNewPlatforms();
    RemoveOldPlatforms();
    CheckGameOver();
  }
}

void Game::MovePlayer(size_t desired_location) {
  double new_x_velocity = (desired_location - player_.GetPosition().x) /
                          kPointerToVelocityScale;
  new_x_velocity = abs(new_x_velocity) > kMaxPlayerXVelocity
                   ? kMaxPlayerXVelocity * (new_x_velocity < 0 ? -1 : 1)
                   : new_x_velocity;
  player_.SetVelocity(
          glm::dvec2(
                  new_x_velocity,
                  player_.GetVelocity().y));
}

void Game::PlayerJump(size_t desired_location) {
  if (!player_.IsJumping()) {
    player_.SetJumping(true);
    double new_x_velocity = (desired_location - player_.GetPosition().x) /
                            kPointerToVelocityScale;
    new_x_velocity = abs(new_x_velocity) > kMaxPlayerXVelocity
                     ? kMaxPlayerXVelocity * (new_x_velocity < 0 ? -1 : 1)
                     : new_x_velocity;
    player_.SetVelocity(
            glm::dvec2(
                    new_x_velocity,
                    player_.GetVelocity().y +
                    kJumpBoostVelocity * player_.GetHeight()));
  }
}

void Game::CollidePlayerWithPlatforms(double dt) {
  glm::dvec2 new_position = player_.GetPosition();
  for (Platform& platform : platforms_) {
    switch (physics::interactions::DetermineCollision(player_, platform, dt)) {
      case physics::interactions::CollisionType::NoCollision:
        player_.SetOnGround(false);
        break;
      case physics::interactions::CollisionType::PlayerOnPlatform:
        player_.SetJumping(false);
        player_.SetOnGround(true);
        new_position.y = platform.GetPosition().y +
                         (platform.GetHeight() / 2) +
                         (player_.GetHeight() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(player_.GetVelocity().x,
                                       platform.GetVelocity().y));
        break;
      case physics::interactions::CollisionType::PlayerUnderPlatform:
        new_position.y = platform.GetPosition().y -
                         (platform.GetHeight() / 2) -
                         (player_.GetHeight() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(player_.GetVelocity().x,
                                       -player_.GetVelocity().y));
        break;
      case physics::interactions::CollisionType::PlayerOnLeftOfPlatform:
        new_position.x = platform.GetPosition().x -
                         (platform.GetWidth() / 2) -
                         (player_.GetWidth() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(0, player_.GetVelocity().y));
        break;
      case physics::interactions::CollisionType::PlayerOnRightOfPlatform:
        new_position.x = platform.GetPosition().x +
                         (platform.GetWidth() / 2) +
                         (player_.GetWidth() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(0, player_.GetVelocity().y));
        break;
    }
    platform.UpdateState(dt);
  }
  player_.UpdateState(dt);
}

void Game::CheckGameOver() {
  if (player_.GetBottomRightCorner().y <= 0) {
    game_status_ = GAME_OVER_SCREEN;
  }
}

void Game::GenerateNewPlatforms() {
  while (!PlatformGoingAboveScreen(platforms_.back())) {
    glm::dvec2 new_position(0, 0);
    int delta_height = rand() % (kMaxPlatformDeltaHeight - kMinPlatformDeltaHeight + 1) + kMinPlatformDeltaHeight;
    int delta_width = rand() % (kMaxPlatformDeltaWidth - kMinPlatformDeltaWidth + 1) + kMinPlatformDeltaWidth;
    platforms_.emplace_back(
            platforms_.back().GetPosition() + glm::dvec2(direction * delta_width, delta_height),
            platforms_.back().GetVelocity(),
            100,
            10);
    direction *= -1;
  }
}

void Game::RemoveOldPlatforms() {
  while (PlatformGoingUnderScreen(platforms_.front())) {
    platforms_.pop_front();
  }
}

bool Game::PlatformGoingUnderScreen(const Platform& platform) {
  return platform.GetBottomRightCorner().y <= 0;
}


bool Game::PlatformGoingAboveScreen(const Platform& platform) {
  return platform.GetBottomRightCorner().y >= 875;
}

}

}