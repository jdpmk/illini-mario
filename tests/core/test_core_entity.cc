#include <catch2/catch.hpp>

#include <core/player.h>
#include <core/platform.h>

TEST_CASE("Construct Core Entities") {
  SECTION("Platform Initialization") {
    game::core::Platform platform("Platform", glm::dvec2(10, 10), glm::dvec2(0, -1), 20, 10);
    REQUIRE(platform.GetName() == "Platform");
    REQUIRE(platform.GetPosition() == glm::dvec2(10, 10));
    REQUIRE(platform.GetVelocity() == glm::dvec2(0, -1));
    SECTION("Verify Boundary Calculations") {
      REQUIRE(platform.GetTopLeftCorner() == glm::dvec2(0, 15));
      REQUIRE(platform.GetBottomRightCorner() == glm::dvec2(20, 5));
    }
  }

  SECTION("Player Initialization") {
    game::core::Player player("Player", glm::dvec2(50, 50), glm::dvec2(1, 0), glm::dvec2(0, -1), 20, 30);
    REQUIRE(player.GetName() == "Player");
    REQUIRE(player.GetPosition() == glm::dvec2(50, 50));
    REQUIRE(player.GetVelocity() == glm::dvec2(1, 0));
    SECTION("Verify Boundary Calculations") {
      REQUIRE(player.GetTopLeftCorner() == glm::dvec2(40, 65));
      REQUIRE(player.GetTopRightCorner() == glm::dvec2(60, 65));
      REQUIRE(player.GetBottomLeftCorner() == glm::dvec2(40, 35));
      REQUIRE(player.GetBottomRightCorner() == glm::dvec2(60, 35));
    }
  }
}