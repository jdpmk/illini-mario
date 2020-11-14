#include <catch2/catch.hpp>

#include <core/player.h>
#include <core/platform.h>

TEST_CASE("Construct Core Entities") {
  SECTION("Platform Initialization") {
    game::core::Platform platform("Platform", glm::dvec2(1, 2), glm::dvec2(3, 4), glm::dvec2(10, 20), glm::dvec2(20, 15));
    REQUIRE(platform.GetName() == "Platform");
    REQUIRE(platform.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(platform.GetVelocity() == glm::dvec2(3, 4));
    REQUIRE(platform.GetTopLeftCorner() == glm::dvec2(10, 20));
    REQUIRE(platform.GetBottomRightCorner() == glm::dvec2(20, 15));
  }

  SECTION("Player Initialization") {
    game::core::Player player("Player", glm::dvec2(1, 2), glm::dvec2(3, 4), glm::dvec2(1, -1));
    REQUIRE(player.GetName() == "Player");
    REQUIRE(player.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(player.GetVelocity() == glm::dvec2(3, 4));
    REQUIRE(player.GetAcceleration() == glm::dvec2(1, -1));
  }
}