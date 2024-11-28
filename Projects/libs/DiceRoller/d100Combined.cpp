#include "d100Combined.hpp"

d100Comb::d100Comb (RollerType type)
{
	this->dice = DiceType::D100;
	this->type = type;
    
    this->dice_10 = d10(this->type);
    this->dice_100 = d100(this->type);

    this->mkRoll();
}

d100Comb::d100Comb(const d10 &D10, const d100 &D100, RollerType type)
{
    this->dice = DiceType::D100;
    this->type = type;
    this->dice_10 = D10;
    this->dice_100 = D100;

    if (this->dice_10.getType() != this->type)
    {
        this->dice_10 = d10(this->type);
    }

    if (this->dice_100.getType() != this->type)
    {
        this->dice_100 = d100(this->type);
    }
}

d100Comb::d100Comb (const d100Comb &other)
{
    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
    this->dice_10 = other.dice_10;
    this->dice_100 = other.dice_100;
}

d100Comb::d100Comb (d100Comb &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
    this->dice_10 = std::move(other.dice_10);
    this->dice_100 = std::move(other.dice_100);
}

d100Comb::~d100Comb()
{
}

int d100Comb::getValue()
{
    return this->value;
}

DiceType d100Comb::getDice()
{
    return this->dice;
}

RollerType d100Comb::getType()
{
    return this->type;
}

void d100Comb::mkRoll()
{
    this->dice_10.mkRoll();
    this->dice_100.mkRoll();

    this->value = (dice_100.getValue() * 10) + dice_10.getValue();
}

bool d100Comb::operator==(const d100Comb &other)
{
    return this->type == other.type && this->value == other.value;
}

bool d100Comb::operator!=(const d100Comb &other)
{
    return !(this->type == other.type && this->value == other.value);
}

d100Comb &d100Comb::operator=(const d100Comb &other)
{
    if (*this == other)
    {
        return *this;
    }

    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
    this->dice_10 = other.dice_10;
    this->dice_100 = other.dice_100;

    return *this;
}

d100Comb &d100Comb::operator=(d100Comb &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
    this->dice_10 = std::move(other.dice_10);
    this->dice_100 = std::move(other.dice_100);

    return *this;
}
