#pragma once

#include <core/player.h>
#include <core/platform.h>
#include <physics/interactions.h>

namespace game {

namespace core {

enum GameStatus {
  MAIN_SCREEN,
  END_SCREEN
};

enum GameEvent {
  PLAYER_MOVE_UP,
  PLAYER_MOVE_DOWN,
  PLAYER_MOVE_LEFT,
  PLAYER_MOVE_RIGHT
};

class Game {
 public:
  Game();
  Player GetPlayer() const;
  std::vector<Platform> GetPlatforms() const;
  Player GenerateDefaultPlayer();
  void UpdateState(double dt);
 private:
  Player player_;
  std::vector<Platform> platforms_;
  const std::string kPlayerDefaultName = "Player";
  const glm::dvec2 kPlayerDefaultPosition = glm::dvec2(100, 100);
  const glm::dvec2 kPlayerDefaultVelocity = glm::dvec2(0, 0);
  const glm::dvec2 kPlayerDefaultAcceleration = glm::dvec2(0, -0.1);
  const size_t kPlayerDefaultWidth = 10;
  const size_t kPlayerDefaultHeight = 30;
};

}

}
