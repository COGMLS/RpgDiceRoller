#pragma once

#ifndef DICE_HPP
#define DICE_HPP

#include <ostream>

#include "DiceType.hpp"
#include "Roller.hpp"

class Dice
{
	private:

		DiceType dice;
		RollerType roll;
		int value;

	public:

		//
		// Constructors:
		//

		Dice();

		//
		// Destructor:
		//

		virtual ~Dice();

		//
		// Methods:
		//

		virtual int getValue();

		virtual DiceType getDice();

		virtual RollerType getRollType();
};

class d4 : Dice
{
	protected:

		DiceType dice;
		RollerType roll;
		int value;

	public:

		d4(RollerType roll = RollerType::UNIFORM);

		~d4();

		int getValue();

		DiceType getDice();

		RollerType getRollType();
};

#endif // !DICE_HPP