#pragma once

#include <core/platform.h>
#include <core/player.h>
#include <physics/interactions.h>

namespace game {

namespace core {

class Game {
 public:
  Game();
  Player GetPlayer() const;
  std::vector<Platform> GetPlatforms() const;
  void UpdateState(double dt);
  void MovePlayer(size_t desired_location);
  void PlayerJump(size_t desired_location);
 private:
  Player player_;
  std::vector<Platform> platforms_;
  const size_t kMaxPlayerXVelocity = 50;
  const size_t kPointerToVelocityScale = 50;
};

}

}