#pragma once

#include "physics/accelerated_entity.h"

namespace game {

namespace core {

class Player : public physics::AcceleratedEntity {
 public:
  Player() = default;
  Player(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration);
  size_t GetScore();
 private:
  size_t score_;
};

}

}