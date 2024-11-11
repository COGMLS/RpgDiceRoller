###########################################################
#
# CMakeLists: RpgConsole
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

# Define if is Windows Environment:

if(WIN32)
	add_compile_definitions(WIN32)
	add_compile_definitions(_CONSOLE)
endif()

if (DebugSolution AND NOT DebugRpgConsole)
	set(DebugRpgConsole True)
endif()

if(DebugRpgConsole)
	add_compile_definitions(DEBUG)
endif()

add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

# Defined the project:
project(
			RpgConsole
			VERSION 1.0.0
			DESCRIPTION "DiceRoller Console to test the Settings Library."
		)

###########################################################
#
# Project components settings:
#
###########################################################

# Include libraries directories source codes:
#include_directories("${ReposRoot}/Projects/libs/<lib>")
#include_directories("${VersionLibReposRoot}/VersionLib")
include_directories("${ProjectsRoot}/libs/DiceRoller")

# Define the executable properties:
add_executable(
					RpgConsole
					"main.cpp"
				)

# Define manual library link:
set(UseManualTargetLinkLibs False)
				
# Link the VersionLib:
if(UseManualTargetLinkLibs)
	if (WIN32)
		if(DebugRpgConsole)
			#target_link_libraries(RpgConsole ${ReposRoot}/build/VersionLib/Libs/<lib>/Debug/VersionLib.lib)
		else()
			#target_link_libraries(RpgConsole ${ReposRoot}/build/VersionLib/Libs/<lib>/Release/VersionLib.lib)
		endif()
	else()
		#target_link_libraries(RpgConsole ${ReposRoot}/build/bin/libVersionLib.so)
	endif()
else()
	#target_link_libraries(RpgConsole VersionLib)
	target_link_libraries(RpgConsole DiceRoller)
endif()