#include <core/game.h>
#include <core/player.h>

namespace game {

namespace core {

Game::Game() {
  player_ = GenerateDefaultPlayer();
  platforms_.emplace_back("Platform", glm::dvec2(100, 10), glm::dvec2(0, 0), 50, 10);
}

Player Game::GetPlayer() const {
  return player_;
}

std::vector<Platform> Game::GetPlatforms() const {
  return platforms_;
}

Player Game::GenerateDefaultPlayer() {
  return Player(kPlayerDefaultName, kPlayerDefaultPosition, kPlayerDefaultVelocity, kPlayerDefaultAcceleration, kPlayerDefaultWidth, kPlayerDefaultHeight);
}

void Game::UpdateState(double dt) {
  player_.UpdateState(dt);
  for (Platform& platform : platforms_) {
    physics::interactions::CollisionType collision_type = physics::interactions::DetermineCollision(player_, platform);
    switch (collision_type) {
      case physics::interactions::PlayerOnPlatform:
        player_.SetAcceleration(glm::dvec2());
        player_.SetVelocity(platform.GetVelocity());
    }
    platform.UpdateState(dt);
  }
}

}

}