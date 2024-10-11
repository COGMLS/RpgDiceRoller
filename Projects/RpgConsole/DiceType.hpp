#pragma once

#ifndef VERSION_BUILD_TYPE_HPP
#define VERSION_BUILD_TYPE_HPP

enum DiceType : int
{
	d4,		// Dice 4
	d6,		// Dice 6
	d8,		// Dice 8
	d10,	// Dice 10
	d12,	// Dice 12
	d20,	// Dice 20
	d100	// Dice 100
};

int DiceMaxVal (DiceType type);

#endif // !VERSION_BUILD_TYPE_HPP