#include "catch2/catch.hpp"
#include "core/game.h"
#include "core/core_constants.h"

using namespace game::core::constants;

TEST_CASE("Random Platform Generation Functionality") {
  game::core::Game game(kDefaultWindowSize);

  SECTION("Ensure initial platform setup is correct") {
    SECTION("Only one initial platform") {
      REQUIRE(game.GetPlatforms().size() == 1);
    }

    SECTION("Check platform location and size") {
      game::core::Platform platform = game.GetPlatforms().front();
      REQUIRE(platform.GetPosition() == kInitialPlatformPosition);
      REQUIRE(platform.GetWidth() == kPlatformWidth);
      REQUIRE(platform.GetHeight() == kPlatformHeight);
    }
  }

  SECTION("Simulate platform generation") {
    game.SetGameStatus(game::core::GameStatus::IN_PROGRESS);
    game.UpdateState(1);

    SECTION("Check that new platforms have been generated") {
      REQUIRE(game.GetPlatforms().size() > 1);
    }

    SECTION("Check that all newly generated platforms spawned within bounds") {
      bool platforms_generated_in_bounds = true;
      std::list<game::core::Platform> platforms = game.GetPlatforms();
      for (auto it = std::next(platforms.begin()); it != platforms.end(); ++it) {
        if (it != game.GetPlatforms().begin()) {
          game::core::Platform curr = *it;
          game::core::Platform prev = *std::prev(it);
          if (abs(prev.GetPosition().x - curr.GetPosition().x) < kMinPlatformDeltaWidth ||
              abs(prev.GetPosition().x - curr.GetPosition().x) > kMaxPlatformDeltaWidth ||
              abs(prev.GetPosition().y - curr.GetPosition().y) < kMinPlatformDeltaHeight ||
              abs(prev.GetPosition().y - curr.GetPosition().y) > kMaxPlatformDeltaWidth) {
            platforms_generated_in_bounds = false;
            break;
          }
        }
      }

      REQUIRE(platforms_generated_in_bounds);
    }
  }
}