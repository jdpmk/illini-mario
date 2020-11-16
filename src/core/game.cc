#include <core/game.h>

#include <physics/interactions.h>

namespace game {

namespace core {

Game::Game() {
  player_ = Player("Player", glm::dvec2(400, 800), glm::dvec2(1, 0), glm::dvec2(1, -0.5), 20, 20);
  platforms_.emplace_back(glm::dvec2(400, 500), glm::dvec2(0, -0.2), 200, 10);
  platforms_.emplace_back(glm::dvec2(400, 580), glm::dvec2(0, -0.2), 100, 10);
  platforms_.emplace_back(glm::dvec2(400, 700), glm::dvec2(0, -0.2), 75, 10);
}

Player Game::GetPlayer() const {
  return player_;
}

std::vector<Platform> Game::GetPlatforms() const {
  return platforms_;
}

void Game::UpdateState(double dt) {
  glm::dvec2 new_position = player_.GetPosition();
  for (Platform& platform : platforms_) {
    physics::interactions::CollisionType collision_type = physics::interactions::DetermineCollision(player_, platform, dt);
    switch (collision_type) {
      case physics::interactions::CollisionType::NoCollision:
        player_.SetOnGround(false);
        break;
      case physics::interactions::CollisionType::PlayerOnPlatform:
        player_.SetJumping(false);
        player_.SetOnGround(true);
        new_position.y = platform.GetPosition().y + (platform.GetHeight() / 2) + (player_.GetHeight() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(player_.GetVelocity().x, platform.GetVelocity().y));
        break;
      case physics::interactions::CollisionType::PlayerUnderPlatform:
        new_position.y = platform.GetPosition().y - (platform.GetHeight() / 2) - (player_.GetHeight() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(player_.GetVelocity().x, -player_.GetVelocity().y));
        break;
      case physics::interactions::CollisionType::PlayerOnLeftOfPlatform:
        new_position.x = platform.GetPosition().x - (platform.GetWidth() / 2) - (player_.GetWidth() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(0, player_.GetVelocity().y));
        break;
      case physics::interactions::CollisionType::PlayerOnRightOfPlatform:
        new_position.x = platform.GetPosition().x + (platform.GetWidth() / 2) + (player_.GetWidth() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(0, player_.GetVelocity().y));
        break;
    }
    platform.UpdateState(dt);
  }
  player_.UpdateState(dt);
}

void Game::MovePlayer(size_t desired_location) {
  double new_x_velocity = (desired_location - player_.GetPosition().x) / kPointerToVelocityScale;
  if (abs(new_x_velocity) > kMaxPlayerXVelocity) {
    new_x_velocity = kMaxPlayerXVelocity * new_x_velocity < 0 ? -1 : 1;
  }
  player_.SetVelocity(
          glm::dvec2(
                  new_x_velocity,
                  player_.GetVelocity().y));
}

void Game::PlayerJump(size_t desired_location) {
  if (!player_.IsJumping()) {
    player_.SetJumping(true);
    double new_x_velocity = (desired_location - player_.GetPosition().x) / kPointerToVelocityScale;
    if (abs(new_x_velocity) > kMaxPlayerXVelocity) {
      new_x_velocity = kMaxPlayerXVelocity * new_x_velocity < 0 ? -1 : 1;
    }
    player_.SetVelocity(
            glm::dvec2(
                    new_x_velocity,
                    player_.GetVelocity().y + 3 * player_.GetHeight() / 4));
  }
}

}

}