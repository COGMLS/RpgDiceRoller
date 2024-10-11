#include "DiceType.hpp"

int DiceMaxVal(DiceType type)
{
	int diceMaxVal = 0;
    switch (type)
	{
		case DiceType::d4:
		{
			diceMaxVal = 4;
			break;
		}
		case DiceType::d6:
		{
			diceMaxVal = 6;
			break;
		}
		case DiceType::d8:
		{
			diceMaxVal = 8;
			break;
		}
		case DiceType::d10:
		{
			diceMaxVal = 10;
			break;
		}
		case DiceType::d12:
		{
			diceMaxVal = 12;
			break;
		}
		case DiceType::d20:
		{
			diceMaxVal = 20;
			break;
		}
		case DiceType::d100:
		{
			diceMaxVal = 10;
			break;
		}
	}
	return diceMaxVal;
}