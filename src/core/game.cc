#include <core/game.h>
#include <core/core_constants.cc>
#include <physics/interactions.h>

using namespace game::core::constants;

namespace game {

namespace core {

Game::Game(size_t screen_dimension) {
  screen_dimension_ = screen_dimension;
  game_status_ = GameStatus::START_SCREEN;

  player_ = Player(kPlayerName, kPlayerStartPosition, kPlayerStartVelocity,
                   kPlayerAcceleration, kPlayerWidth, kPlayerHeight);
  platforms_.emplace_back(kInitialPlatformPosition, kInitialPlatformVelocity,
                          kPlatformAcceleration, kPlatformWidth,
                          kPlatformHeight);
}

GameStatus Game::GetGameStatus() const {
  return game_status_;
}

Player Game::GetPlayer() const {
  return player_;
}

std::list<Platform> Game::GetPlatforms() const {
  return platforms_;
}

void Game::SetGameStatus(GameStatus game_status) {
  game_status_ = game_status;
}

void Game::UpdateState(double dt) {
  if (game_status_ == IN_PROGRESS) {
    ScrollScreenDown();
    CollidePlayerWithPlatforms(dt);
    GenerateNewPlatforms();
    RemoveOldPlatforms();
    CheckGameOver();
  }
}

void Game::MovePlayer(size_t desired_location) {
  double new_x_velocity = (desired_location - player_.GetPosition().x) /
                          kPointerToVelocityScale;
  new_x_velocity = abs(new_x_velocity) > kMaxPlayerXVelocity
                   ? kMaxPlayerXVelocity * (new_x_velocity < 0 ? -1 : 1)
                   : new_x_velocity;
  player_.SetVelocity(
          glm::dvec2(
                  new_x_velocity,
                  player_.GetVelocity().y));
}

void Game::PlayerJump(size_t desired_location) {
  if (!player_.IsJumping()) {
    player_.SetJumping(true);
    double new_x_velocity = (desired_location - player_.GetPosition().x) /
                            kPointerToVelocityScale;
    new_x_velocity = abs(new_x_velocity) > kMaxPlayerXVelocity
                     ? kMaxPlayerXVelocity * (new_x_velocity < 0 ? -1 : 1)
                     : new_x_velocity;
    player_.SetVelocity(
            glm::dvec2(
                    new_x_velocity,
                    player_.GetVelocity().y +
                    kJumpBoostVelocity * player_.GetHeight()));
  }
}

void Game::ScrollScreenDown() {
  if (!scrolling_) {
    if (player_.GetPosition().y > kBeginScrollThreshold * screen_dimension_) {
      platform_old_velocity_ = platforms_.back().GetVelocity();
      std::for_each(platforms_.begin(), platforms_.end(),
        [] (Platform& p) { p.SetVelocity(kPlatformScrollingVelocity); }
      );
      scrolling_ = true;
    }
  } else {
    if (player_.GetPosition().y <= kStopScrollThreshold * screen_dimension_) {
      std::for_each(platforms_.begin(), platforms_.end(),
        [this] (Platform& p) { p.SetVelocity(platform_old_velocity_); }
      );
      scrolling_ = false;
    }
  }
}


void Game::CollidePlayerWithPlatforms(double dt) {
  glm::dvec2 new_position = player_.GetPosition();
  for (Platform& platform : platforms_) {
    switch (physics::interactions::DetermineCollision(player_, platform, dt)) {
      case physics::interactions::CollisionType::NoCollision:
        player_.SetOnGround(false);
        break;
      case physics::interactions::CollisionType::PlayerOnPlatform:
        player_.SetJumping(false);
        player_.SetOnGround(true);
        new_position.y = platform.GetPosition().y +
                         (platform.GetHeight() / 2) +
                         (player_.GetHeight() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(player_.GetVelocity().x,
                                       platform.GetVelocity().y));
        if (!platform.GetVisited()) {
          player_.IncrementScore();
          platform.SetVisited(true);
        }
        break;
      case physics::interactions::CollisionType::PlayerUnderPlatform:
        new_position.y = platform.GetPosition().y -
                         (platform.GetHeight() / 2) -
                         (player_.GetHeight() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(player_.GetVelocity().x,
                                       -player_.GetVelocity().y));
        break;
      case physics::interactions::CollisionType::PlayerOnLeftOfPlatform:
        new_position.x = platform.GetPosition().x -
                         (platform.GetWidth() / 2) -
                         (player_.GetWidth() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(0, player_.GetVelocity().y));
        break;
      case physics::interactions::CollisionType::PlayerOnRightOfPlatform:
        new_position.x = platform.GetPosition().x +
                         (platform.GetWidth() / 2) +
                         (player_.GetWidth() / 2);
        player_.SetPosition(new_position);
        player_.SetVelocity(glm::dvec2(0, player_.GetVelocity().y));
        break;
    }
    platform.UpdateState(dt);
  }
  player_.UpdateState(dt);
}

void Game::CheckGameOver() {
  if (player_.GetBottomRightCorner().y <= 0) {
    game_status_ = GAME_OVER_SCREEN;
  }
}

void Game::GenerateNewPlatforms() {
  while (!PlatformGoingAboveScreen(platforms_.back(), screen_dimension_)) {
    glm::dvec2 new_position(0, 0);
    int delta_height = rand() % (kMaxPlatformDeltaHeight - kMinPlatformDeltaHeight + 1) + kMinPlatformDeltaHeight;
    int delta_width = rand() % (kMaxPlatformDeltaWidth - kMinPlatformDeltaWidth + 1) + kMinPlatformDeltaWidth;
    platforms_.emplace_back(
            platforms_.back().GetPosition() + glm::dvec2(platform_spawn_direction_ * delta_width, delta_height),
            platforms_.back().GetVelocity(),
            platforms_.back().GetAcceleration(),
            100,
            10);
    platform_spawn_direction_ *= -1;
  }
}

void Game::RemoveOldPlatforms() {
  while (PlatformGoingUnderScreen(platforms_.front())) {
    platforms_.pop_front();
  }
}

bool Game::PlatformGoingUnderScreen(const Platform& platform) {
  return platform.GetBottomRightCorner().y <= 0;
}


bool Game::PlatformGoingAboveScreen(const Platform& platform,
                                    size_t screen_height) {
  return platform.GetBottomRightCorner().y >= screen_height;
}

}

}