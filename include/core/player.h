#pragma once

#include "physics/accelerated_entity.h"

namespace game {

namespace core {

class Player : public physics::AcceleratedEntity {
 public:
  Player() = default;
  Player(const std::string& name, const glm::dvec2& position, const glm::dvec2& velocity, const glm::dvec2& acceleration, size_t width, size_t height);
  size_t GetScore() const;
  bool IsOnGround() const;
  void SetOnGround(bool on_ground);
  void UpdateState(double dt) override;
 private:
  std::string name_;
  size_t score_;
  bool on_ground_;
};

}

}