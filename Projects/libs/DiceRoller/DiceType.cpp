#include "DiceType.hpp"

int DiceMaxVal (DiceType type)
{
	int diceMaxVal = 0;
    switch (type)
	{
		case DiceType::D4:
		{
			diceMaxVal = 4;
			break;
		}
		case DiceType::D6:
		{
			diceMaxVal = 6;
			break;
		}
		case DiceType::D8:
		{
			diceMaxVal = 8;
			break;
		}
		case DiceType::D10:
		{
			diceMaxVal = 10;
			break;
		}
		case DiceType::D12:
		{
			diceMaxVal = 12;
			break;
		}
		case DiceType::D20:
		{
			diceMaxVal = 20;
			break;
		}
		case DiceType::D100:
		{
			diceMaxVal = 9;
			break;
		}
		default:
		{
			diceMaxVal = 6;
			break;
		}
	}
	return diceMaxVal;
}

int DiceMinVal (DiceType type)
{
    int diceMaxVal = 0;
    switch (type)
	{
		case DiceType::D100:
		{
			diceMaxVal = 0;
			break;
		}
		default:
		{
			diceMaxVal = 1;
			break;
		}
	}
	return diceMaxVal;
}

std::string DiceType2Str(DiceType type)
{
	std::string diceTypeStr;

	switch (type)
	{
		case DiceType::D4:
		{
			diceTypeStr = "d4";
			break;
		}
		case DiceType::D6:
		{
			diceTypeStr = "d6";
			break;
		}
		case DiceType::D8:
		{
			diceTypeStr = "d8";
			break;
		}
		case DiceType::D10:
		{
			diceTypeStr = "d10";
			break;
		}
		case DiceType::D12:
		{
			diceTypeStr = "d12";
			break;
		}
		case DiceType::D20:
		{
			diceTypeStr = "d20";
			break;
		}
		case DiceType::D100:
		{
			diceTypeStr = "d100";
			break;
		}
		default:
		{
			break;
		}
	}

	return diceTypeStr;
}
