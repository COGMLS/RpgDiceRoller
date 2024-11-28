#pragma once

#ifndef DICES_HPP
#define DICES_HPP

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

/**
 * @brief Class for dice d4
 */
class DICE_ROLLER_LIB_API d4 : public Dice
{
	public:

		//
		// Constructors:
		//

		d4 (RollerType type = RollerType::UNIFORM);

		d4 (const d4& other);

		d4 (d4&& other) noexcept;

		//
		// Destructor:
		//

		~d4();

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

		bool operator== (const d4& other);

		bool operator!= (const d4& other);

		d4& operator= (const d4& other);

		d4& operator= (d4&& other) noexcept;
};

/**
 * @brief Class for dice d6
 */
class DICE_ROLLER_LIB_API d6 : public Dice
{
	public:

		//
		// Constructors:
		//

		d6 (RollerType type = RollerType::UNIFORM);

		d6 (const d6& other);

		d6 (d6&& other) noexcept;

		//
		// Destructor:
		//

		~d6();

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

		bool operator== (const d6& other);

		bool operator!= (const d6& other);

		d6& operator= (const d6& other);

		d6& operator= (d6&& other) noexcept;
};

/**
 * @brief Class for dice d8
 */
class DICE_ROLLER_LIB_API d8 : public Dice
{
	public:

		//
		// Constructors:
		//

		d8 (RollerType type = RollerType::UNIFORM);

		d8 (const d8& other);

		d8 (d8&& other) noexcept;

		//
		// Destructor:
		//

		~d8();

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

		bool operator== (const d8& other);

		bool operator!= (const d8& other);

		d8& operator= (const d8& other);

		d8& operator= (d8&& other) noexcept;
};

/**
 * @brief Class for dice d10
 */
class DICE_ROLLER_LIB_API d10 : public Dice
{
	public:

		//
		// Constructors:
		//

		d10 (RollerType type = RollerType::UNIFORM);

		d10 (const d10& other);

		d10 (d10&& other) noexcept;

		//
		// Destructors:
		//

		~d10();

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

		bool operator== (const d10& other);

		bool operator!= (const d10& other);

		d10& operator= (const d10& other);

		d10& operator= (d10&& other) noexcept;
};

/**
 * @brief Class for dice d12
 */
class DICE_ROLLER_LIB_API d12 : public Dice
{
	public:

		//
		// Constructors:
		//

		d12 (RollerType type = RollerType::UNIFORM);

		d12 (const d12& other);

		d12 (d12&& other) noexcept;

		//
		// Destructor:
		//

		~d12();

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

		bool operator== (const d12& other);

		bool operator!= (const d12& other);

		d12& operator= (const d12& other);

		d12& operator= (d12&& other) noexcept;
};

/**
 * @brief Class for dice d20
 */
class DICE_ROLLER_LIB_API d20 : public Dice
{
	public:

		//
		// Constructors:
		//

		d20 (RollerType type = RollerType::UNIFORM);

		d20 (const d20& other);

		d20 (d20&& other) noexcept;

		//
		// Destructor:
		//

		~d20();

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

		bool operator== (const d20& other);

		bool operator!= (const d20& other);

		d20& operator= (const d20& other);

		d20& operator= (d20&& other) noexcept;
};

/**
 * @brief Class for dice d100
 */
class DICE_ROLLER_LIB_API d100 : public Dice
{
	public:

		//
		// Constructors:
		//

		d100 (RollerType type = RollerType::UNIFORM);

		d100 (const d100& other);

		d100 (d100&& other) noexcept;

		//
		// Destructor:
		//

		~d100();

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

		bool operator== (const d100& other);

		bool operator!= (const d100& other);

		d100& operator= (const d100& other);

		d100& operator= (d100&& other) noexcept;
};

#endif // !DICES_HPP