#pragma once

#ifndef ROLL_COMMAND_HPP
#define ROLL_COMMAND_HPP

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

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_ROLL_CMD

#include <vector>
#include <memory>
#include <list>
#include <string>
#include <cstring>

#include "Types.hpp"
#include "DiceBase.hpp"
#include "Dices.hpp"
#include "d100Combined.hpp"

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH
#include "DiceMath.hpp"
#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH

class DICE_ROLLER_LIB_API RollCmd
{
	private:

		std::vector<DiceMathCmd> mathCmds;

	public:

		RollCmd();

		RollCmd (std::string cli);

		RollCmd (const RollCmd& other);

		RollCmd (RollCmd&& other);

		~RollCmd();

		//
		//
		//

		std::vector<std::string> getCmdComponentsStr();

		std::vector<DiceMathCmd> getCmdComponents();

		int getCmdFinalVal();
};

#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_ROLL_CMD

#endif // !ROLL_COMMAND_HPP