#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "MovableEnemy.hpp"

namespace biv {
	class ConsoleMovableEnemy : public MovableEnemy, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleMovableEnemy(const Coord& top_left, const int width, const int height);

			char get_brush() const noexcept override;
	};
}
