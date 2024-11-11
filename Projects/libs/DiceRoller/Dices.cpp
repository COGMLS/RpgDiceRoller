#include "Dices.hpp"

d4::d4 (RollerType type)
{
	this->dice = DiceType::D4;
	this->type = type;
    this->mkRoll();
}

d4::d4 (const d4 &other)
{
    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
}

d4::d4 (d4 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
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

RollerType d4::getType()
{
    return this->type;
}

void d4::mkRoll()
{
    this->value = RollDice_UniformRoll(this->dice);
}

bool d4::operator==(const d4 &other)
{
    return this->type == other.type && this->value == other.value;
}

bool d4::operator!=(const d4 &other)
{
    return !(this->type == other.type && this->value == other.value);
}

d4 &d4::operator=(const d4 &other)
{
    if (*this == other)
    {
        return *this;
    }

    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;

    return *this;
}

d4 &d4::operator=(d4 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);

    return *this;
}

d6::d6 (RollerType type)
{
	this->dice = DiceType::D6;
	this->type = type;
    this->mkRoll();
}

d6::d6 (const d6 &other)
{
    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
}

d6::d6 (d6 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
}

d6::~d6()
{
}

int d6::getValue()
{
    return this->value;
}

DiceType d6::getDice()
{
    return this->dice;
}

RollerType d6::getType()
{
    return this->type;
}

void d6::mkRoll()
{
    this->value = RollDice_UniformRoll(this->dice);
}

bool d6::operator==(const d6 &other)
{
    return this->type == other.type && this->value == other.value;
}

bool d6::operator!=(const d6 &other)
{
    return !(this->type == other.type && this->value == other.value);
}

d6 &d6::operator=(const d6 &other)
{
    if (*this == other)
    {
        return *this;
    }

    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;

    return *this;
}

d6 &d6::operator=(d6 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);

    return *this;
}

d8::d8 (RollerType type)
{
	this->dice = DiceType::D8;
	this->type = type;
    this->mkRoll();
}

d8::d8 (const d8 &other)
{
    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
}

d8::d8 (d8 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
}

d8::~d8()
{
}

int d8::getValue()
{
    return this->value;
}

DiceType d8::getDice()
{
    return this->dice;
}

RollerType d8::getType()
{
    return this->type;
}

void d8::mkRoll()
{
    this->value = RollDice_UniformRoll(this->dice);
}

bool d8::operator==(const d8 &other)
{
    return this->type == other.type && this->value == other.value;
}

bool d8::operator!=(const d8 &other)
{
    return !(this->type == other.type && this->value == other.value);
}

d8 &d8::operator=(const d8 &other)
{
    if (*this == other)
    {
        return *this;
    }

    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;

    return *this;
}

d8 &d8::operator=(d8 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);

    return *this;
}

d10::d10 (RollerType type)
{
	this->dice = DiceType::D10;
	this->type = type;
    this->mkRoll();
}

d10::d10 (const d10 &other)
{
    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
}

d10::d10 (d10 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
}

d10::~d10()
{
}

int d10::getValue()
{
    return this->value;
}

DiceType d10::getDice()
{
    return this->dice;
}

RollerType d10::getType()
{
    return this->type;
}

void d10::mkRoll()
{
    this->value = RollDice_UniformRoll(this->dice);
}

bool d10::operator==(const d10 &other)
{
    return this->type == other.type && this->value == other.value;
}

bool d10::operator!=(const d10 &other)
{
    return !(this->type == other.type && this->value == other.value);
}

d10 &d10::operator=(const d10 &other)
{
    if (*this == other)
    {
        return *this;
    }

    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;

    return *this;
}

d10 &d10::operator=(d10 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);

    return *this;
}

d12::d12 (RollerType type)
{
	this->dice = DiceType::D12;
	this->type = type;
    this->mkRoll();
}

d12::d12 (const d12 &other)
{
    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
}

d12::d12 (d12 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
}

d12::~d12()
{
}

int d12::getValue()
{
    return this->value;
}

DiceType d12::getDice()
{
    return this->dice;
}

RollerType d12::getType()
{
    return this->type;
}

void d12::mkRoll()
{
    this->value = RollDice_UniformRoll(this->dice);
}

bool d12::operator==(const d12 &other)
{
    return this->type == other.type && this->value == other.value;
}

bool d12::operator!=(const d12 &other)
{
    return !(this->type == other.type && this->value == other.value);
}

d12 &d12::operator=(const d12 &other)
{
    if (*this == other)
    {
        return *this;
    }

    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;

    return *this;
}

d12 &d12::operator=(d12 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);

    return *this;
}

d20::d20 (RollerType type)
{
	this->dice = DiceType::D20;
	this->type = type;
    this->mkRoll();
}

d20::d20 (const d20 &other)
{
    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
}

d20::d20 (d20 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
}

d20::~d20()
{
}

int d20::getValue()
{
    return this->value;
}

DiceType d20::getDice()
{
    return this->dice;
}

RollerType d20::getType()
{
    return this->type;
}

void d20::mkRoll()
{
    this->value = RollDice_UniformRoll(this->dice);
}

bool d20::operator==(const d20 &other)
{
    return this->type == other.type && this->value == other.value;
}

bool d20::operator!=(const d20 &other)
{
    return !(this->type == other.type && this->value == other.value);
}

d20 &d20::operator=(const d20 &other)
{
    if (*this == other)
    {
        return *this;
    }

    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;

    return *this;
}

d20 &d20::operator=(d20 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);

    return *this;
}

d100::d100 (RollerType type)
{
	this->dice = DiceType::D100;
	this->type = type;
    this->mkRoll();
}

d100::d100 (const d100 &other)
{
    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;
}

d100::d100 (d100 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);
}

d100::~d100()
{
}

int d100::getValue()
{
    return this->value;
}

DiceType d100::getDice()
{
    return this->dice;
}

RollerType d100::getType()
{
    return this->type;
}

void d100::mkRoll()
{
    this->value = RollDice_UniformRoll(this->dice);
}

bool d100::operator==(const d100 &other)
{
    return this->type == other.type && this->value == other.value;
}

bool d100::operator!=(const d100 &other)
{
    return !(this->type == other.type && this->value == other.value);
}

d100 &d100::operator=(const d100 &other)
{
    if (*this == other)
    {
        return *this;
    }

    this->dice = other.dice;
    this->type = other.type;
    this->value = other.value;

    return *this;
}

d100 &d100::operator=(d100 &&other) noexcept
{
    this->dice = std::move(other.dice);
    this->type = std::move(other.type);
    this->value = std::move(other.value);

    return *this;
}