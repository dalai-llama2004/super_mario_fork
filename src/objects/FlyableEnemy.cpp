#include "FlyableEnemy.hpp"

#include "map_movable.hpp"

using biv::FlyableEnemy;

FlyableEnemy::FlyableEnemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
	base_y = top_left.y - FLIGHT_HEIGHT;
	this->top_left.y = base_y;
}

biv::Rect FlyableEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed FlyableEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void FlyableEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void FlyableEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void FlyableEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	// Проверка: не свалился ли враг с корабля. 
	// Т.е., если он на краю, то он должен разверуться 
	// и побежать в обратную сторону.
	// Для летающего врага проверяем на уровне базовой платформы
	float saved_y = top_left.y;
	top_left.y = base_y + FLIGHT_HEIGHT;
	top_left.x += hspeed;
	
	bool has_platform = has_collision(obj);
	
	top_left.x -= hspeed;
	top_left.y = saved_y;
	
	if (!has_platform) {
		process_horizontal_static_collision(obj);
	}
}

