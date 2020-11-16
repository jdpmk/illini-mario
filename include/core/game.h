#pragma once

#include <core/platform.h>
#include <core/player.h>
#include <physics/interactions.h>

namespace game {

namespace core {

enum GameStatus {
  START_SCREEN,
  IN_PROGRESS,
  PAUSED,
  GAME_OVER_SCREEN
};

class Game {
 public:
  Game();
  GameStatus GetGameStatus() const;
  Player GetPlayer() const;
  std::vector<Platform> GetPlatforms() const;
  Platform GetGroundPlatform() const;
  void SetGameStatus(GameStatus game_status);
  void UpdateState(double dt);
  void MovePlayer(size_t desired_location);
  void PlayerJump(size_t desired_location);
 private:
  GameStatus game_status_;
  Player player_;
  std::vector<Platform> platforms_;
  Platform ground_platform_;
  const size_t kMaxPlayerXVelocity = 50;
  const size_t kPointerToVelocityScale = 50;
  const double kJumpBoostVelocity = 0.375;
};

}

}