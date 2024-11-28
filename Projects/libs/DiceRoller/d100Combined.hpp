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

/**
 * @brief Class for combined dices d100 and d10
 */
class DICE_ROLLER_LIB_API d100Comb : public Dice
{
	private:

		d100 dice_100;
		d10 dice_10;

	public:

		//
		// Constructors:
		//

		/**
		 * @brief Create an D100 combined dice roll (D100 and D10)
		 * @param type Dice value distribution
		 */
		d100Comb (RollerType type = RollerType::UNIFORM);

		/**
		 * @brief Create an D100 combined roll based on D100 and D10 already created
		 * @param D10 Dice d10
		 * @param D100 Dice d100
		 * @param type Dice value distribution
		 * @note If a dice is not maching with the roller type, the dice will be rerolled with the roller type value for this object creation
		 */
		d100Comb (const d10& D10, const d100& D100, RollerType type = RollerType::UNIFORM);

		d100Comb (const d100Comb& other);

		d100Comb (d100Comb&& other) noexcept;

		//
		// Destructor:
		//

		~d100Comb();

		//
		// Methods:
		//

		/**
		 * @brief Get the dice value
		 */
		int getValue();

		/**
		 * @brief Get the DiceType enumerator value
		 */
		DiceType getDice();

		/**
		 * @brief Get the RollerType used to configure the dice value distribution
		 */
		RollerType getType();

		/**
		 * @brief Make a dice roll.
		 * @note This method is already called when a dice is created. Call this method to reuse (reroll) the dice again.
		 */
		void mkRoll();

		bool operator== (const d100Comb& other);

		bool operator!= (const d100Comb& other);

		d100Comb& operator= (const d100Comb& other);

		d100Comb& operator= (d100Comb&& other) noexcept;
};

#endif // !DICE_100_COMBINED_HPP