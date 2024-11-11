#pragma once

#ifndef DICE_BASE_HPP
#define DICE_BASE_HPP

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

class DICE_ROLLER_LIB_API Dice
{
	protected:

		DiceType dice;
		RollerType type;
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

		virtual RollerType getType();

		virtual void mkRoll();

		virtual bool operator== (const Dice& other);

		virtual bool operator!= (const Dice& other);
};

#endif // !DICE_BASE_HPP