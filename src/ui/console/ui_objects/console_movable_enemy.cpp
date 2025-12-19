#include "console_movable_enemy.hpp"

using biv::ConsoleMovableEnemy;

ConsoleMovableEnemy::ConsoleMovableEnemy(const Coord& top_left, const int width, const int height) 
	: MovableEnemy(top_left, width, height) {}

char ConsoleMovableEnemy::get_brush() const noexcept {
	return 'e';
}
