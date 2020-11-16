#include <core/game.h>

#include <physics/interactions.h>

namespace game {

namespace core {

Game::Game() {
  game_status_ = GameStatus::START_SCREEN;
  player_ = Player("Player", glm::dvec2(400, 100), glm::dvec2(1, 0), glm::dvec2(1, -0.5), 40, 40);
  platforms_.emplace_back(glm::dvec2(200, 100), glm::dvec2(0, -0.001), 50, 10);
  platforms_.emplace_back(glm::dvec2(600, 100), glm::dvec2(0, -0.001), 100, 10);
  platforms_.emplace_back(glm::dvec2(400, 150), glm::dvec2(0, -0.001), 100, 10);
  platforms_.emplace_back(glm::dvec2(400, 250), glm::dvec2(0, -0.001), 20, 60);
  platforms_.emplace_back(glm::dvec2(100, 100), glm::dvec2(0, 0.2), 50, 10);
  platforms_.emplace_back(glm::dvec2(200, 300), glm::dvec2(0, -0.001), 50, 10);
  platforms_.emplace_back(glm::dvec2(600, 300), glm::dvec2(0, -0.001), 100, 10);
  platforms_.emplace_back(glm::dvec2(400, 350), glm::dvec2(0, -0.001), 100, 10);
  platforms_.emplace_back(glm::dvec2(400, 450), glm::dvec2(0, -0.001), 20, 60);
  platforms_.emplace_back(glm::dvec2(400, 20), glm::dvec2(0, -0.001), 400, 10);
  ground_platform_ = Platform(glm::dvec2(437.5, 5), glm::dvec2(0, 0.001), 875, 10);
}

GameStatus Game::GetGameStatus() const {
  return game_status_;
}

Player Game::GetPlayer() const {
  return player_;
}

std::vector<Platform> Game::GetPlatforms() const {
  return platforms_;
}

Platform Game::GetGroundPlatform() const {
  return ground_platform_;
}

void Game::SetGameStatus(GameStatus game_status) {
  game_status_ = game_status;
}

void Game::UpdateState(double dt) {
  if (game_status_ == IN_PROGRESS) {
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
    if (physics::interactions::DetermineCollision(player_, ground_platform_, dt)
        != physics::interactions::NoCollision) {
      game_status_ = GAME_OVER_SCREEN;
    }
    ground_platform_.UpdateState(dt);
    player_.UpdateState(dt);
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

}

}