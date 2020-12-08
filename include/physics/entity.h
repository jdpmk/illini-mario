#pragma once

#include <string>

#include "cinder/gl/gl.h"

namespace physics {

/**
 * A class to represent an entity that has position, velocity, and acceleration
 * and occupies two-dimensional space.
 */
class Entity {
 public:
  Entity() = default;
  Entity(const glm::dvec2& position,
         const glm::dvec2& velocity,
         const glm::dvec2& acceleration,
         size_t width,
         size_t height);
  glm::dvec2 GetPosition() const;
  glm::dvec2 GetVelocity() const;
  glm::dvec2 GetAcceleration() const;
  size_t GetWidth() const;
  size_t GetHeight() const;
  glm::dvec2 GetTopLeftCorner() const;
  glm::dvec2 GetBottomLeftCorner() const;
  glm::dvec2 GetTopRightCorner() const;
  glm::dvec2 GetBottomRightCorner() const;
  void SetPosition(const glm::dvec2& position);
  void SetVelocity(const glm::dvec2& velocity);
  void SetAcceleration(const glm::dvec2& acceleration);

  /**
   * Updates the vectors associated with the entity given a timestep.
   *
   * @param dt The timestep
   */
  virtual void UpdateState(double dt);

 protected:
  glm::dvec2 position_;
  glm::dvec2 velocity_;
  glm::dvec2 acceleration_;
  size_t width_;
  size_t height_;
};

}
