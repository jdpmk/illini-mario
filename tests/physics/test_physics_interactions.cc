#include <catch2/catch.hpp>

#include <core/platform.h>
#include <core/player.h>
#include <physics/interactions.h>

TEST_CASE("Test Vertical Positioning") {
  SECTION("No Collision") {
    game::core::Player player("Player", glm::dvec2(10, 4), glm::dvec2(0, -1), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(5, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Directly On Top") {
    game::core::Player player("Player", glm::dvec2(5, 4), glm::dvec2(0, -1), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(5, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnPlatform);
  }
  SECTION("Player Hanging Off Left Edge") {
    game::core::Player player("Player", glm::dvec2(2, 4), glm::dvec2(0, -1), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(5, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnPlatform);
  }
  SECTION("Player Hanging Off Right Edge") {
    game::core::Player player("Player", glm::dvec2(8, 4), glm::dvec2(0, -1), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(5, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnPlatform);
  }
  SECTION("Player Directly Under") {
    game::core::Player player("Player", glm::dvec2(5, 3), glm::dvec2(0, 1), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(5, 5), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerUnderPlatform);
  }
  SECTION("Player Half Under Left Edge") {
    game::core::Player player("Player", glm::dvec2(2, 4), glm::dvec2(0, 1), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(5, 5), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerUnderPlatform);
  }
  SECTION("Player Half Under Right Edge") {
    game::core::Player player("Player", glm::dvec2(8, 4), glm::dvec2(0, 1), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(5, 5), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerUnderPlatform);
  }
}

TEST_CASE("Test Horizontal Positioning") {
  SECTION("No Collision") {
    game::core::Player player("Player", glm::dvec2(10, 4), glm::dvec2(-1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(5, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::NoCollision);
  }
  SECTION("Player Coming From Left") {
    game::core::Player player("Player", glm::dvec2(4, 2), glm::dvec2(1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(8, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnLeftOfPlatform);
  }
  SECTION("Player Coming From Left, Slightly Above") {
    game::core::Player player("Player", glm::dvec2(4, 3), glm::dvec2(1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(8, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnLeftOfPlatform);
  }
  SECTION("Player Coming From Left, Slightly Below") {
    game::core::Player player("Player", glm::dvec2(4, 1), glm::dvec2(1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(8, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnLeftOfPlatform);
  }
  SECTION("Player Coming From Right") {
    game::core::Player player("Player", glm::dvec2(12, 2), glm::dvec2(-1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(8, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnRightOfPlatform);
  }
  SECTION("Player Coming From Right, Slightly Above") {
    game::core::Player player("Player", glm::dvec2(12, 3), glm::dvec2(-1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(8, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnRightOfPlatform);
  }
  SECTION("Player Coming From Right, Slightly Below") {
    game::core::Player player("Player", glm::dvec2(12, 1), glm::dvec2(-1, 0), glm::dvec2(0, 0), 2, 2);
    game::core::Platform platform(glm::dvec2(8, 2), glm::dvec2(0, 0), 6, 2);
    REQUIRE(physics::interactions::DetermineCollision(player, platform) == physics::interactions::CollisionType::PlayerOnRightOfPlatform);
  }
}