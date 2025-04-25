#pragma once

#ifndef DICE_ROLLER_HPP
#define DICE_ROLLER_HPP

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

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH
#include "DiceMath.hpp"
#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE
#include "DiceMathStore.hpp"
#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_ROLL_CMD
#include "RollCmd.hpp"
#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_ROLL_CMD

#include "d100Combined.hpp"
#include "DiceBase.hpp"
#include "DiceRollerVersion.hpp"
#include "Dices.hpp"
#include "DiceType.hpp"
#include "Roller.hpp"
#include "Types.hpp"

/**
 * @brief Show the Dice Roller Library version
 * @param showBuild Show the build compilation number
 * @return Return the Dice Roller Library version string
 */
inline std::string diceRollerVersion(bool showBuild = false)
{
	std::string version;

	version = std::to_string(DICE_ROLLER_LIB_VERSION_MAJOR_VERSION) + "." + std::to_string(DICE_ROLLER_LIB_VERSION_MINOR_VERSION) + "." + std::to_string(DICE_ROLLER_LIB_VERSION_PATCH_VERSION) + "-" + DICE_ROLLER_LIB_VERSION_BUILD_TYPE;

	if (DICE_ROLLER_LIB_VERSION_BUILD_TYPE_NUMBER > 0)
	{
		version += "." + std::to_string(DICE_ROLLER_LIB_VERSION_BUILD_TYPE_NUMBER);
	}

	if (showBuild)
	{
		version += " build " + std::to_string(DICE_ROLLER_LIB_VERSION_BUILD_NUMBER);
	}

	return version;
}

#endif // !DICE_ROLLER_HPP