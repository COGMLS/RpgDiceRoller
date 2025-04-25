#pragma once

#ifndef TYPES_HPP
#define TYPES_HPP

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

/**
 * @brief Determinate the dice type (d4, d6, d8, d10, d12, d20, d100)
 */
enum DiceType : int
{
	D4,		// Dice 4
	D6,		// Dice 6
	D8,		// Dice 8
	D10,	// Dice 10
	D12,	// Dice 12
	D20,	// Dice 20
	D100	// Dice 100
};

/**
 * @brief Dice roller method type
 */
enum RollerType
{
	UNIFORM,
	BINOMIAL,
	POISSON,
	NORMAL
};

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH
/**
 * @brief Dice math type
 */
enum DiceMathType
{
	FAIL_TO_DETERMINATE = -1,
	NOT_DEFINED,
	DICE_MATH,
	NUMBER_TYPE,
	MATH_OPERATOR,
	MATH_GROUP
};
#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH

#endif // !TYPES_HPP