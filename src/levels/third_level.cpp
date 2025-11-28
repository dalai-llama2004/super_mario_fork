#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* ThirdLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 25}, 40, 5);
	ui_factory->create_ship({60, 20}, 7, 6);
	ui_factory->create_ship({80, 25}, 30, 4);
	ui_factory->create_ship({120, 20}, 20, 7);
	ui_factory->create_ship({150, 25}, 35, 4);
	ui_factory->create_ship({210, 20}, 10, 7);
}
