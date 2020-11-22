#pragma once

#include <list>

#include <core/platform.h>
#include <core/player.h>
#include <physics/interactions.h>

namespace game {

namespace core {

/**
 * An enum that represents the current status of the game.
 */
enum GameStatus {
  START_SCREEN,
  IN_PROGRESS,
  PAUSED,
  GAME_OVER_SCREEN
};

/**
 * A class that represents an instance of the game.
 */
class Game {
 public:
  Game();
  GameStatus GetGameStatus() const;
  Player GetPlayer() const;
  std::list<Platform> GetPlatforms() const;
  Platform GetGroundPlatform() const;
  void SetGameStatus(GameStatus game_status);

  /**
   * Updates the state of the entities in the game, given a timestep.
   *
   * @param dt The timestep
   */
  void UpdateState(double dt);

  /**
   * Makes the player move towards a given desired pixel location based on
   * mouse pointer location.
   *
   * @param desired_location The desired horizontal pixel location
   */
  void MovePlayer(size_t desired_location);

  /**
   * Makes the player jump vertically. Adjusts the player's horizontal position
   * based on mouse pointer location.
   *
   * @param desired_location The desired horizontal pixel location
   */
  void PlayerJump(size_t desired_location);

 private:
  void CollidePlayerWithPlatforms(double dt);
  void CheckGameOver(double dt);
  void GenerateNextPlatform();
  void RemoveOldPlatform();
  bool PlatformGoingOffScreen(const Platform& platform);
  GameStatus game_status_;
  Player player_;
  std::list<Platform> platforms_;
  Platform ground_platform_;
  const size_t kMaxPlayerXVelocity = 50;
  const size_t kPointerToVelocityScale = 50;
  const double kJumpBoostVelocity = 0.375;
};

}

}