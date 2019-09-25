#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include "Shape.h"
#include <array>

using namespace std;

class SlotMachine
{
	array<unique_ptr<Shape>, 3> reel{};
	void make_shapes();
	void display();

	//game logic
	bool any_two_similar_in_shape();
	bool all_three_similar_in_shape();
	bool any_two_match_screen_areas();
	bool middle_more_left_right();
	bool left_right_similar_in_shape();

public:
	SlotMachine() = default;
	SlotMachine(const SlotMachine&) = delete;
	SlotMachine(SlotMachine&&) = delete;
	SlotMachine& operator=(const SlotMachine&) = delete;
	SlotMachine& operator=(SlotMachine&&) = delete;
	virtual ~SlotMachine() = default;

	void run();
};

#endif
