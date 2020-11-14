#include <catch2/catch.hpp>

#include <core/player.h>
#include <core/platform.h>
#include <physics/interactions.h>

TEST_CASE("Check No Collision") {
  SECTION("Player Above Platform") {
    game::core::Player player("Player", glm::dvec2(400, 300), glm::dvec2(0, 0), glm::dvec2(0, 0), 20, 30);
    game::core::Platform platform("Platform", glm::dvec2(400, 50), glm::dvec2(0, 0), 200, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Above and Right of Platform") {
    game::core::Player player("Player", glm::dvec2(600, 300), glm::dvec2(0, 0), glm::dvec2(0, 0), 20, 30);
    game::core::Platform platform("Platform", glm::dvec2(400, 50), glm::dvec2(0, 0), 200, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Above and Left of Platform") {
    game::core::Player player("Player", glm::dvec2(200, 300), glm::dvec2(0, 0), glm::dvec2(0, 0), 20, 30);
    game::core::Platform platform("Platform", glm::dvec2(400, 50), glm::dvec2(0, 0), 200, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Directly Right of Platform") {
    game::core::Player player("Player", glm::dvec2(600, 50), glm::dvec2(0, 0), glm::dvec2(0, 0), 20, 30);
    game::core::Platform platform("Platform", glm::dvec2(400, 50), glm::dvec2(0, 0), 200, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Directly Left of Platform") {
    game::core::Player player("Player", glm::dvec2(200, 50), glm::dvec2(0, 0), glm::dvec2(0, 0), 20, 30);
    game::core::Platform platform("Platform", glm::dvec2(400, 50), glm::dvec2(0, 0), 200, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Below Platform") {
    game::core::Player player("Player", glm::dvec2(400, 75), glm::dvec2(0, 0), glm::dvec2(0, 0), 20, 30);
    game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Below and Right of Platform") {
    game::core::Player player("Player", glm::dvec2(600, 75), glm::dvec2(0, 0), glm::dvec2(0, 0), 20, 30);
    game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Below and Left of Platform") {
    game::core::Player player("Player", glm::dvec2(200, 75), glm::dvec2(0, 0), glm::dvec2(0, 0), 20, 30);
    game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
}

TEST_CASE("Player and Platform Collision") {
  SECTION("Player Lands On Platform") {
    SECTION("Player Directly Above Platform") {
      game::core::Player player("Player", glm::dvec2(5, 12), glm::dvec2(0, -1), glm::dvec2(0, 0), 2, 2);
      game::core::Platform platform("Platform", glm::dvec2(5, 5), glm::dvec2(0, 0), 10, 10);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
      player.UpdateState(1);
      platform.UpdateState(1);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnPlatform);
      player.UpdateState(1);
      platform.UpdateState(1);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnPlatform);
    }
  }
  SECTION("Player Hitting Bottom Of Platform") {
    game::core::Player player("Player", glm::dvec2(5, 8), glm::dvec2(0, 1), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform("Platform", glm::dvec2(5, 15), glm::dvec2(0, 0), 10, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
    player.UpdateState(1);
    platform.UpdateState(1);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerUnderPlatform);
    player.UpdateState(1);
    platform.UpdateState(1);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Hits Left Of Platform") {
    game::core::Player player("Player", glm::dvec2(3, 10), glm::dvec2(1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform("Platform", glm::dvec2(10, 15), glm::dvec2(0, 0), 10, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
    player.UpdateState(1);
    platform.UpdateState(1);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnLeftOfPlatform);
    player.UpdateState(1);
    platform.UpdateState(1);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnLeftOfPlatform);
  }
  SECTION("Player Hits Right Of Platform") {
    game::core::Player player("Player", glm::dvec2(17, 10), glm::dvec2(-1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform("Platform", glm::dvec2(10, 15), glm::dvec2(0, 0), 10, 10);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
    player.UpdateState(1);
    platform.UpdateState(1);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnRightOfPlatform);
    player.UpdateState(1);
    platform.UpdateState(1);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnRightOfPlatform);
  }
}