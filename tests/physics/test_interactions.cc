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
      game::core::Player player("Player", glm::dvec2(360, 205), glm::dvec2(0, -1), glm::dvec2(0, 0), 20, 30);
      game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnPlatform);
    }
    SECTION("Player Hanging Off Left Side Of Platform") {
      game::core::Player player("Player", glm::dvec2(305, 205), glm::dvec2(0, -1), glm::dvec2(0, 0), 20, 30);
      game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnPlatform);
    }
    SECTION("Player Hanging Off Right Side Of Platform") {
      game::core::Player player("Player", glm::dvec2(495, 205), glm::dvec2(0, -1), glm::dvec2(0, 0), 20, 30);
      game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnPlatform);
    }
  }
  SECTION("Player Hits Bottom Of Platform") {
    SECTION("Player Directly Under Platform") {
      game::core::Player player("Player", glm::dvec2(360, 205), glm::dvec2(0, 1), glm::dvec2(0, 0), 20, 30);
      game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerUnderPlatform);
    }
    SECTION("Player Hits Part Of Left Side Of Platform") {
      game::core::Player player("Player", glm::dvec2(305, 205), glm::dvec2(0, 1), glm::dvec2(0, 0), 20, 30);
      game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerUnderPlatform);
    }
    SECTION("Player Hits Part Of Right Side Of Platform") {
      game::core::Player player("Player", glm::dvec2(495, 205), glm::dvec2(0, 1), glm::dvec2(0, 0), 20, 30);
      game::core::Platform platform("Platform", glm::dvec2(400, 200), glm::dvec2(0, 0), 200, 10);
      REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerUnderPlatform);
    }
  }
}