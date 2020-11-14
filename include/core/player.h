#pragma once

#include "physics/accelerated_entity.h"

namespace game {

namespace core {

class Player : public physics::AcceleratedEntity {
 public:
  Player() = default;
  Player(std::string name);
  size_t GetScore();
  std::string GetName();
 private:
  size_t score_;
  std::string name_;
};

}

}