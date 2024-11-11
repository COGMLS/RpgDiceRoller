#include "DiceBase.hpp"

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

RollerType Dice::getType()
{
    return this->type;
}

void Dice::mkRoll()
{
}

bool Dice::operator==(const Dice &other)
{
    return this->type == other.type && this->value == other.value;
}

bool Dice::operator!=(const Dice &other)
{
    return !(this->type == other.type && this->value == other.value);
}