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

class DICE_ROLLER_LIB_API d4 : public Dice
{
	public:

		d4 (RollerType type = RollerType::UNIFORM);

		d4 (const d4& other);

		d4 (d4&& other) noexcept;

		~d4();

		int getValue();

		DiceType getDice();

		RollerType getType();

		void mkRoll();

		bool operator== (const d4& other);

		bool operator!= (const d4& other);

		d4& operator= (const d4& other);

		d4& operator= (d4&& other) noexcept;
};

class DICE_ROLLER_LIB_API d6 : public Dice
{
	public:

		d6 (RollerType type = RollerType::UNIFORM);

		d6 (const d6& other);

		d6 (d6&& other) noexcept;

		~d6();

		int getValue();

		DiceType getDice();

		RollerType getType();

		void mkRoll();

		bool operator== (const d6& other);

		bool operator!= (const d6& other);

		d6& operator= (const d6& other);

		d6& operator= (d6&& other) noexcept;
};

class DICE_ROLLER_LIB_API d8 : public Dice
{
	public:

		d8 (RollerType type = RollerType::UNIFORM);

		d8 (const d8& other);

		d8 (d8&& other) noexcept;

		~d8();

		int getValue();

		DiceType getDice();

		RollerType getType();

		void mkRoll();

		bool operator== (const d8& other);

		bool operator!= (const d8& other);

		d8& operator= (const d8& other);

		d8& operator= (d8&& other) noexcept;
};

class DICE_ROLLER_LIB_API d10 : public Dice
{
	public:

		d10 (RollerType type = RollerType::UNIFORM);

		d10 (const d10& other);

		d10 (d10&& other) noexcept;

		~d10();

		int getValue();

		DiceType getDice();

		RollerType getType();

		void mkRoll();

		bool operator== (const d10& other);

		bool operator!= (const d10& other);

		d10& operator= (const d10& other);

		d10& operator= (d10&& other) noexcept;
};

class DICE_ROLLER_LIB_API d12 : public Dice
{
	public:

		d12 (RollerType type = RollerType::UNIFORM);

		d12 (const d12& other);

		d12 (d12&& other) noexcept;

		~d12();

		int getValue();

		DiceType getDice();

		RollerType getType();

		void mkRoll();

		bool operator== (const d12& other);

		bool operator!= (const d12& other);

		d12& operator= (const d12& other);

		d12& operator= (d12&& other) noexcept;
};

class DICE_ROLLER_LIB_API d20 : public Dice
{
	public:

		d20 (RollerType type = RollerType::UNIFORM);

		d20 (const d20& other);

		d20 (d20&& other) noexcept;

		~d20();

		int getValue();

		DiceType getDice();

		RollerType getType();

		void mkRoll();

		bool operator== (const d20& other);

		bool operator!= (const d20& other);

		d20& operator= (const d20& other);

		d20& operator= (d20&& other) noexcept;
};

class DICE_ROLLER_LIB_API d100 : public Dice
{
	public:

		d100 (RollerType type = RollerType::UNIFORM);

		d100 (const d100& other);

		d100 (d100&& other) noexcept;

		~d100();

		int getValue();

		DiceType getDice();

		RollerType getType();

		void mkRoll();

		bool operator== (const d100& other);

		bool operator!= (const d100& other);

		d100& operator= (const d100& other);

		d100& operator= (d100&& other) noexcept;
};

#endif // !DICES_HPP