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
  Game(size_t screen_dimension);
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
  void CheckGameOver();
  void GenerateNewPlatforms();
  void RemoveOldPlatforms();
  bool PlatformGoingUnderScreen(const Platform& platform);
  bool PlatformGoingAboveScreen(const Platform& platform, size_t screen_height);
  GameStatus game_status_;
  Player player_;
  std::list<Platform> platforms_;
  size_t screen_dimension_;
  int platform_spawn_direction_ = 1;
};

}

}