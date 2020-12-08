#include "catch2/catch.hpp"
#include "physics/entity.h"

TEST_CASE("Construct Entities") {
  SECTION("Basic Entity Initialization") {
    physics::Entity entity(glm::dvec2(1, 2), glm::dvec2(3, 4), glm::dvec2(0, 1), 1, 1);
    REQUIRE(entity.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 4));
    REQUIRE(entity.GetAcceleration() == glm::dvec2(0, 1));
  }
}

TEST_CASE("Update Entities") {
  SECTION("Check Entity Position Updates") {
    physics::Entity entity(glm::dvec2(1, 2), glm::dvec2(3, 4), glm::dvec2(0, 1), 1, 1);
    REQUIRE(entity.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 4));
    REQUIRE(entity.GetAcceleration() == glm::dvec2(0, 1));
    entity.UpdateState(1);
    REQUIRE(entity.GetPosition() == glm::dvec2(4, 7));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 5));
    REQUIRE(entity.GetAcceleration() == glm::dvec2(0, 1));
    entity.UpdateState(1);
    REQUIRE(entity.GetPosition() == glm::dvec2(7, 13));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 6));
    REQUIRE(entity.GetAcceleration() == glm::dvec2(0, 1));
  }
}