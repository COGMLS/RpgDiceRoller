###########################################################
#
# CMakeLists: DiceRoller Library
#
###########################################################

cmake_minimum_required(VERSION 3.28)

###########################################################
#
# Define the general solution settings
#
###########################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define local Settings Library project root var:
set(DiceRollerRoot ${CMAKE_CURRENT_LIST_DIR})

# Define if is Windows Environment:

if(WIN32)
	add_compile_definitions(WIN32)
	add_compile_definitions(_WINDOWS)
	add_compile_definitions(_USRDLL)
	add_compile_definitions(_WINDLL)
endif()

if (DebugSolution AND NOT DebugDiceRoller)
	set(DebugDiceRoller True)
endif()

if(DebugDiceRoller)
	add_compile_definitions(DEBUG)
endif()

add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

# Defined the project:
project(
			DiceRoller
			VERSION 0.0.1
			DESCRIPTION "RPG Dice Roller Library."
		)

###########################################################
#
# Project components settings:
#
###########################################################

# Include libraries directories source codes:
#include_directories("${ReposRoot}/Libraries/<lib>")

# Global definitions:
add_compile_definitions(RPG_DICE_ROLLER_LIB_EXPORTS)
add_compile_definitions(VERSION_LIB_EXPORTS)

# Define to export the library methods if is Windows:
if(WIN32)
	# Add the export here
endif()

# Define the library build properties:
if (WIN32)
	add_library(
					DiceRoller
					SHARED
					# Windows specific headers:
					"dllmain.hpp"					"dllmain.cpp"
					# Dice Roller Main Library:
					"DiceRoller.hpp"
					# Dice Roller Headers:
					"d100Combined.hpp"				"d100Combined.cpp"
					"DiceBase.hpp"					"DiceBase.cpp"
					"DiceMath.hpp"					"DiceMath.cpp"
					"DiceMathStore.hpp"				"DiceMathStore.cpp"
					"Dices.hpp"						"Dices.cpp"
					"DiceType.hpp"					"DiceType.cpp"
					"ExperimentalFeature.hpp"
					"RollCmd.hpp"					"RollCmd.cpp"
					"Roller.hpp"					"Roller.cpp"
					"Types.hpp"
				)
else()
	add_library(
					DiceRoller
					SHARED
					"d100Combined.hpp" "d100Combined.cpp"
					"DiceBase.hpp" "DiceBase.cpp"
					"DiceMath.hpp" "DiceMath.cpp"
					"DiceMathStore.hpp" "DiceMathStore.cpp"
					"DiceRoller.hpp"
					"Dices.hpp" "Dices.cpp"
					"DiceType.hpp" "DiceType.cpp"
					"Roller.hpp" "Roller.cpp"
					"Types.hpp"
				)
endif()

###########################################################
# WARNING: About the linking libraries:
# --------------------------------------------------------
# For some reason, the methods in the libraries are not
# recognized directly, resulting in LINK2019 with MSVC or
# "undefined reference to" in GCC, but the methods are generated
# and exported. To mitigate this problem, set as "True" the
# CMake variable "UseManualTargetLinkLibs" to link then manually.
###########################################################

set(UseManualTargetLinkLibs False)

if(UseManualTargetLinkLibs)
	if (WIN32)
		if(DebugDiceRoller)
			#target_link_libraries(DiceRoller ${ReposRoot}/build/DiceRoller/Libs/<lib>/Debug/<libfile>.lib)
		else()
			#target_link_libraries(DiceRoller ${ReposRoot}/build/DiceRoller/Libs/<lib>/Release/<libfile>.lib)
		endif()
	else()
		#target_link_libraries(DiceRoller ${ReposRoot}/build/bin/lib<libName>.so)
	endif()
else()
	#target_link_libraries(DiceRoller <librojectName>)
endif()