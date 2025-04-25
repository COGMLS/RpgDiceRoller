#pragma once

#ifndef DICE_ROLLER_LIBRARY_EXPERIMENTAL_FEATURES_CONTROL_HPP
#define DICE_ROLLER_LIBRARY_EXPERIMENTAL_FEATURES_CONTROL_HPP

#include "DiceRollerVersion.hpp"

//
// Alpha Features:
//

#ifdef DICE_ROLLER_LIB_BUILD_TYPE_ALPHA
	// Enable Dice Math experimental feature
	#define DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH

	// Enable Dice Math Store experimental feature
	#define DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE

	// Enable Roll Command experimental feature
	#define DICE_ROLLER_ENABLE_EXPERIMENTAL_ROLL_CMD
#endif // !DICE_ROLLER_LIB_BUILD_TYPE_ALPHA is Alpha

//
// Beta Features:
//

#ifdef DICE_ROLLER_LIB_BUILD_TYPE_BETA
	
#endif // !DICE_ROLLER_LIB_BUILD_TYPE_BETA is Beta

//
// Release Candidate Features:
//

#ifdef DICE_ROLLER_LIB_BUILD_TYPE_RELEASE_CANDIDATE
	
#endif // !DICE_ROLLER_LIB_BUILD_TYPE_RELEASE_CANDIDATE is Release Candidate

//
// Experimental Features for Release version:
//

#ifdef DICE_ROLLER_LIB_BUILD_TYPE_RELEASE
	
#endif // !DICE_ROLLER_LIB_BUILD_TYPE_RELEASE is Release

#endif // !DICE_ROLLER_LIBRARY_EXPERIMENTAL_FEATURES_CONTROL_HPP