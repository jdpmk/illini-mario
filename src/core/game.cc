#include <core/game.h>

#include <physics/interactions.h>

namespace game {

namespace core {

Game::Game() {
  player_ = Player("Player", glm::dvec2(290, 300), glm::dvec2(1, 0), glm::dvec2(1, -0.1), 10, 10);
  platforms_.emplace_back(glm::dvec2(400, 50), glm::dvec2(0, -0.1), 200, 20);
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
//        player_.SetVelocity(glm::dvec2(player_.GetVelocity().x, platform.GetVelocity().y));
          player_.SetVelocity(platform.GetVelocity());
        break;
      case physics::interactions::CollisionType::PlayerUnderPlatform:
        break;
      case physics::interactions::CollisionType::PlayerOnLeftOfPlatform:
        break;
      case physics::interactions::CollisionType::PlayerOnRightOfPlatform:
        break;
    }
    platform.UpdateState(dt);
  }
  player_.UpdateState(dt);
}

}

}