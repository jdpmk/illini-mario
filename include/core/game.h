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
 private:
  Player player_;
  std::vector<Platform> platforms_;
};

}

}