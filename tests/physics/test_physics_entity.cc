#include <catch2/catch.hpp>

#include <physics/entity.h>
#include <physics/accelerated_entity.h>

TEST_CASE("Construct Entities") {
  SECTION("Basic Entity Initialization") {
    physics::Entity entity("Entity", glm::dvec2(1, 2), glm::dvec2(3, 4));
    REQUIRE(entity.GetName() == "Entity");
    REQUIRE(entity.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 4));
  }

  SECTION("Accelerated Entity Initialization") {
    physics::AcceleratedEntity entity("Entity", glm::dvec2(1, 2), glm::dvec2(3, 4), glm::dvec2(1, -1));
    REQUIRE(entity.GetName() == "Entity");
    REQUIRE(entity.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 4));
    REQUIRE(entity.GetAcceleration() == glm::dvec2(1, -1));
  }
}

TEST_CASE("Update Entities") {
  SECTION("Check Entity Position Updates") {
    physics::Entity entity("Entity", glm::dvec2(1, 2), glm::dvec2(3, 4));
    REQUIRE(entity.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 4));
    entity.UpdateState(1);
    REQUIRE(entity.GetPosition() == glm::dvec2(4, 6));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 4));
    entity.UpdateState(1);
    REQUIRE(entity.GetPosition() == glm::dvec2(7, 10));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 4));
  }

  SECTION("Check Accelerated Entity Position Updates") {
    physics::AcceleratedEntity entity("Entity", glm::dvec2(1, 2), glm::dvec2(3, 4), glm::dvec2(1, -1));
    REQUIRE(entity.GetPosition() == glm::dvec2(1, 2));
    REQUIRE(entity.GetVelocity() == glm::dvec2(3, 4));
    REQUIRE(entity.GetAcceleration() == glm::dvec2(1, -1));
    entity.UpdateState(1);
    REQUIRE(entity.GetPosition() == glm::dvec2(5, 5));
    REQUIRE(entity.GetVelocity() == glm::dvec2(4, 3));
    REQUIRE(entity.GetAcceleration() == glm::dvec2(1, -1));
    entity.UpdateState(1);
    REQUIRE(entity.GetPosition() == glm::dvec2(10, 7));
    REQUIRE(entity.GetVelocity() == glm::dvec2(5, 2));
    REQUIRE(entity.GetAcceleration() == glm::dvec2(1, -1));
  }
}