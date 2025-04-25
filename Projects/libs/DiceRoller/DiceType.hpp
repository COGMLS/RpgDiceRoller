#pragma once

#ifndef DICE_TYPE_HPP
#define DICE_TYPE_HPP

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

#include <string>

#include "Types.hpp"

/**
 * @brief Define the maximum value for dice
 * @param type Dice type
 */
int DiceMaxVal (DiceType type);

/**
 * @brief Define the minimum value for dice
 * @param type Dice type
 */
int DiceMinVal (DiceType type);

/**
 * @brief Convert the DiceType to string
 * @param type DiceType
 * @return Return the DiceType string
 */
std::string DiceType2Str (DiceType type);

#endif // !DICE_TYPE_HPP