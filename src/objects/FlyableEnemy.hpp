#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class FlyableEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
		private:
			static constexpr float FLIGHT_HEIGHT = 6.0f;
			static constexpr float MIN_Y = 0.0f;  // Top boundary of the map
			static constexpr float MAX_Y = 37.0f; // Bottom boundary (40 - 3 for water area)
			float base_y;
			
		public:
			FlyableEnemy(const Coord& top_left, const int width, const int height);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
			
			void move_vertically() noexcept override;
	};
}
