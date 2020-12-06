#pragma once

#include <list>

#include "core/core_constants.h"
#include "core/platform.h"
#include "core/player.h"
#include "physics/interactions.h"

namespace game {

namespace core {

/**
 * An enum that represents the current status of the game.
 */
enum GameStatus {
  START_SCREEN,
  IN_PROGRESS,
  PAUSED,
  GAME_OVER
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
  bool PlayerJump(size_t desired_location);

 private:
  /**
   * Helper function to scroll the screen down when the player approaches the
   * top of the screen. This ensures that the player does not go off-screen.
   */
  void ScrollScreenDown();
  /**
   * Resolves potential collisions between player and platforms, given
   * a timestep.
   *
   * @param dt The timestep
   */
  void CollidePlayerWithPlatforms(double dt);
  /**
   * Determines whether the game has reached Game Over status and updates
   * the game status accordingly.
   */
  void CheckGameOver();
  /**
   * Generates new platforms to fill the portion of the screen visible to
   * the player. Checks whether the last platform generated has a position
   * above the visible portion of the screen, meaning that platform generation
   * may now stop.
   */
  void GenerateNewPlatforms();
  /**
   * Removes old platforms that will not be used in play anymore. Checks
   * whether the first platform in the list of platforms has a position
   * under the visible portion of the screen, meaning that the platform should
   * be removed.
   */
  void RemoveOldPlatforms();
  /**
   * Check whether a platform is going under the visible portion of the screen.
   *
   * @param platform The platform
   * @return true if the platform is under the screen; false otherwise
   */
  bool PlatformGoingUnderScreen(const Platform& platform);
  /**
   * Check whether a platform is going above the visible portion of the screen.
   *
   * @param platform
   * @param screen_height
   * @return
   */
  bool PlatformGoingAboveScreen(const Platform& platform, size_t screen_height);

  GameStatus game_status_;
  Player player_;
  std::list<Platform> platforms_;
  size_t screen_dimension_;
  /**
   * Scalar to keep track if whether the next platform should spawn to the left
   * or right. Alternates between platform generation loops.
   */
  int platform_spawn_direction_ = 1;
  /**
   * Boolean to check whether the screen is scrolling up. While this value is
   * true, the platforms will be scrolled up at a faster speed to ensure the
   * player stays on-screen.
   */
  bool scrolling_;
  /**
   * Temporary vector to store the old platform velocity. This velocity is
   * used once the screen stops scrolling to restore the platforms to their
   * velocity before scrolling started.
   */
  glm::dvec2 platform_old_velocity_;
};

}

}