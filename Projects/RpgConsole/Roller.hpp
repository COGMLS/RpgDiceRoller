#pragma once

#ifndef ROLLER_HPP
#define ROLLER_HPP

#include <random>

#include "DiceType.hpp"

enum RollerType
{
	UNIFORM,
	BINOMIAL,
	POISSON,
	NORMAL
};

int RollDice (DiceType type);

#endif // !ROLLER_HPP