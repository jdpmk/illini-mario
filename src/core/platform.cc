#include <core/platform.h>

namespace game {

namespace core {

Platform::Platform(std::string name, glm::dvec2 position, glm::dvec2 velocity, size_t width, size_t height) {
  name_ = name;
  position_ = position;
  velocity_ = velocity;
  width_ = width;
  height_ = height;
}

size_t Platform::GetWidth() {
  return width_;
}

size_t Platform::GetHeight() {
  return height_;
}

glm::dvec2 Platform::GetTopLeftCorner() {
  return glm::dvec2(position_.x - width_ / 2, position_.y + height_ / 2);
}

glm::dvec2 Platform::GetBottomRightCorner() {
  return glm::dvec2(position_.x + width_ / 2, position_.y - height_ / 2);
}

}

}