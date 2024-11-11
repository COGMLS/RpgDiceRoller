#pragma once

#ifndef DICE_100_COMBINED_HPP
#define DICE_100_COMBINED_HPP

#ifdef WIN32
	#ifdef DICE_ROLLER_LIB_EXPORTS
		#define DICE_ROLLER_LIB_API __declspec(dllexport)
	#else
		#define DICE_ROLLER_LIB_API __declspec(dllimport)
	#endif //!DICE_ROLLER_LIB_EXPORTS

	#pragma warning (disable : 4251)
	#pragma warning (disable : 4273)
#else
	#if __GNUC__ >= 4
		#ifdef DICE_ROLLER_LIB_EXPORTS
			#define DICE_ROLLER_LIB_API __attribute__((visibility("default")))
		#else
			#define DICE_ROLLER_LIB_API __attribute__((visibility("default")))
		#endif //!DICE_ROLLER_LIB_EXPORTS
	#else
		#ifdef DICE_ROLLER_LIB_EXPORTS
			#define DICE_ROLLER_LIB_API
		#else
			#define DICE_ROLLER_LIB_API
		#endif //!DICE_ROLLER_LIB_EXPORTS
	#endif
#endif // !WIN32

#include <ostream>

#include "Types.hpp"
#include "DiceType.hpp"
#include "Roller.hpp"
#include "DiceBase.hpp"
#include "Dices.hpp"

class DICE_ROLLER_LIB_API d100Comb : public Dice
{
	private:

		d100 dice_100;
		d10 dice_10;

	public:

		d100Comb (RollerType type = RollerType::UNIFORM);

		d100Comb (const d100Comb& other);

		d100Comb (d100Comb&& other) noexcept;

		~d100Comb();

		int getValue();

		DiceType getDice();

		RollerType getType();

		void mkRoll();

		bool operator== (const d100Comb& other);

		bool operator!= (const d100Comb& other);

		d100Comb& operator= (const d100Comb& other);

		d100Comb& operator= (d100Comb&& other) noexcept;
};

#endif // !DICE_100_COMBINED_HPP