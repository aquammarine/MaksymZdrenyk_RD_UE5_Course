#pragma once
struct Stats {
	int intelligence;
	int strength;
	int agility;
	int speed;

	Stats(int str = 0, int intel = 0, int agi = 0, int spd = 0)
		: strength(str), intelligence(intel), agility(agi), speed(spd) { }
};