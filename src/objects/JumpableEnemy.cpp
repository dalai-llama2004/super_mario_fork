#include "JumpableEnemy.hpp"

#include "map_movable.hpp"

using biv::JumpableEnemy;

JumpableEnemy::JumpableEnemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0;
}

biv::Rect JumpableEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed JumpableEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void JumpableEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	// Прыгающий враг не двигается горизонтально
}

void JumpableEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void JumpableEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	// Особенность модели вертикального передвижения в игре.
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
		// Прыгаем снова
		jump();
	}
}
