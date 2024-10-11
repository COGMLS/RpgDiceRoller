#include "Dice.hpp"

Dice::Dice()
{

}

Dice::~Dice()
{
	
}

int Dice::getValue()
{
    return this->value;
}

DiceType Dice::getDice()
{
    return this->dice;
}

RollerType Dice::getRollType()
{
    return this->roll;
}

d4::d4(RollerType roll)
{
	this->dice = DiceType::d4;
	this->roll = roll;
}

d4::~d4()
{
}

int d4::getValue()
{
    return this->value;
}

DiceType d4::getDice()
{
    return this->dice;
}

RollerType d4::getRollType()
{
    return this->roll;
}
