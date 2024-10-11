###########################################################
#
# CMakeLists: Templates Solution
#
###########################################################

cmake_minimum_required(VERSION 3.28)

###########################################################
#
# Define the general solution settings
#
###########################################################

# Define current project base working directory location:
set(ProjectsRoot ${CMAKE_CURRENT_LIST_DIR})

# Define the project solution:
#project(
#			ReposProjects
#			VERSION 0.0.1
#			DESCRIPTION "Complete solution for Templates Solution repository."
#		)

###########################################################
#
# Sub projects:
#
###########################################################

add_subdirectory("libs")
add_subdirectory("RpgConsole")