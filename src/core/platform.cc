#include <core/platform.h>

namespace game {

namespace core {

Platform::Platform(std::string name, glm::dvec2 position, glm::dvec2 velocity, size_t width, size_t height)
        : physics::Entity(name, position, velocity) {
  width_ = width;
  height_ = height;
}

size_t Platform::GetWidth() const {
  return width_;
}

size_t Platform::GetHeight() const {
  return height_;
}

glm::dvec2 Platform::GetTopLeftCorner() const {
  return glm::dvec2(position_.x - width_ / 2, position_.y + height_ / 2);
}

glm::dvec2 Platform::GetBottomRightCorner() const {
  return glm::dvec2(position_.x + width_ / 2, position_.y - height_ / 2);
}

}

}