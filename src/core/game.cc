#include <core/game.h>

#include <physics/interactions.h>

namespace game {

namespace core {

Game::Game() {
  player_ = Player("Player", glm::dvec2(540, 51), glm::dvec2(-3, 0), glm::dvec2(1, -0.1), 10, 10);
  platforms_.emplace_back(glm::dvec2(400, 50), glm::dvec2(0, 0), 200, 20);
}

Player Game::GetPlayer() const {
  return player_;
}

std::vector<Platform> Game::GetPlatforms() const {
  return platforms_;
}

void Game::UpdateState(double dt) {
  player_.UpdateState(dt);
  for (Platform& platform : platforms_) {
    switch (physics::interactions::DetermineCollision(player_, platform, dt / 10)) {
      case physics::interactions::CollisionType::NoCollision:
        player_.SetOnGround(false);
        break;
      case physics::interactions::CollisionType::PlayerOnPlatform:
        player_.SetOnGround(true);
        player_.SetVelocity(glm::dvec2());
        break;
      case physics::interactions::CollisionType::PlayerOnLeftOfPlatform:
        player_.SetOnGround(false);
        player_.SetVelocity(glm::dvec2());
        break;
      case physics::interactions::CollisionType::PlayerOnRightOfPlatform:
        player_.SetOnGround(false);
        player_.SetVelocity(glm::dvec2());
        break;
    }
    platform.UpdateState(dt);
  }
}

}

}