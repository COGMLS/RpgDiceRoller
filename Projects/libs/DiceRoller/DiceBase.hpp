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

#include "ExperimentalFeatures.hpp"

#include <ostream>

#include "Types.hpp"
#include "DiceType.hpp"
#include "Roller.hpp"

/**
 * @brief Class base for dice classes
 */
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

		/**
		 * @brief Get the dice value
		 */
		virtual int getValue();

		/**
		 * @brief Get the DiceType enumerator value
		 */
		virtual DiceType getDice();

		/**
		 * @brief Get the RollerType used to configure the dice value distribution
		 */
		virtual RollerType getType();

		/**
		 * @brief Make a dice roll.
		 * @note This method is already called when a dice is created. Call this method to reuse (reroll) the dice again.
		 */
		virtual void mkRoll();

		virtual bool operator== (const Dice& other);

		virtual bool operator!= (const Dice& other);
};

#endif // !DICE_BASE_HPP