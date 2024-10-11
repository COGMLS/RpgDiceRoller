###########################################################
#
# CMakeLists: RpgDiceRollerSolution
#
###########################################################

cmake_minimum_required(VERSION 3.28)

###########################################################
#
# Define the general solution settings
#
###########################################################

# Define if will set the project debug definition:
set(DebugSolution True)

if(DebugSolution)
	add_compile_definitions(DEBUG)
endif()

# Define final location for binary files output:
set(ReposRoot ${CMAKE_CURRENT_LIST_DIR})
set(FinalBinDir "${ReposRoot}/build/bin")

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${FinalBinDir})

if (NOT WIN32)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${FinalBinDir})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${FinalBinDir})

# Project:

project(
			RpgDiceRollerSolution
			VERSION 0.0.1
			DESCRIPTION "Complete solution for this repository"
		)

###########################################################
#
# Sub projects:
#
###########################################################

add_subdirectory("Projects")