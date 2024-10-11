#include "Roller.hpp"

int RollDice(DiceType type)
{
	int diceMaxVal = DiceMaxVal(type);
	int diceMinVal = 1;
	int value = 0;

	std::random_device rd;

	std::mt19937 gen(rd());
	std::uniform_real_distribution<int> dist(diceMinVal, diceMaxVal);
	value = dist(rd);

    return value;
}
