#include <iostream>
#include <vector>

#include "DiceRoller.hpp"

int main (int argc, const char* argv[])
{
	std::vector<Dice> dices;

	for (int i = 0; i < 100; i++)
	{
		if (i <= 8)
		{
			dices.push_back(d4());
		}
		else if (i >= 9 && i <= 15)
		{
			dices.push_back(d6());
		}
		else if (i >= 16 && i <= 21)
		{
			dices.push_back(d8());
		}
		else if (i >= 22 && i <= 30)
		{
			dices.push_back(d10());
		}
		else if (i >= 31 && i <= 40)
		{
			dices.push_back(d12());
		}
		else if (i >= 41 && i <= 50)
		{
			dices.push_back(d20());
		}
		else if (i >= 51 && i <= 60)
		{
			dices.push_back(d100());
		}
		else
		{
			dices.push_back(d100Comb());
		}
	}

	std::cout << "d4, d6, d8, d10, d20, d100, d100Comb:\n" << std::endl;

	for (int i = 0; i < dices.size(); i++)
	{
		std::cout << "i: " << i << " Dice: " << DiceType2Str(dices[i].getDice()) << " Value: " << dices[i].getValue() << std::endl;
	}

	dices.clear();

	std::cout << "\nd100Comb:\n" << std::endl;

	for (size_t i = 0; i < 250; i++)
	{
		dices.push_back(d100Comb());
	}

	for (int i = 0; i < dices.size(); i++)
	{
		std::cout << "i: " << i << " Dice: " << DiceType2Str(dices[i].getDice()) << " Value: " << dices[i].getValue() << std::endl;
	}

	return 0;
}