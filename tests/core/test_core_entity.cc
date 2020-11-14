#include <catch2/catch.hpp>

#include <core/player.h>
#include <core/platform.h>

TEST_CASE("Construct Core Entities") {
  SECTION("Platform Initialization") {
    game::core::Platform platform("Platform", glm::dvec2(10, 10), glm::dvec2(0, -1), 20, 10);
    REQUIRE(platform.GetName() == "Platform");
    REQUIRE(platform.GetPosition() == glm::dvec2(10, 10));
    REQUIRE(platform.GetVelocity() == glm::dvec2(0, -1));
    REQUIRE(platform.GetTopLeftCorner() == glm::dvec2(0, 15));
    REQUIRE(platform.GetBottomRightCorner() == glm::dvec2(20, 5));
  }

  SECTION("Player Initialization") {
    game::core::Player player("Player", glm::dvec2(1, 2), glm::dvec2(3, 4), glm::dvec2(1, -1));
    REQUIRE(player.GetName() == "Player");
    REQUIRE(player.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(player.GetVelocity() == glm::dvec2(3, 4));
    REQUIRE(player.GetAcceleration() == glm::dvec2(1, -1));
  }
}