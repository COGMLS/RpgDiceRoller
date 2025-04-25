#include "DiceMathStore.hpp"

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE

DiceMathStore::DiceMathStore()
{
	this->attr.reset(nullptr);
	this->dices.reset(nullptr);
	this->type = DiceMathType::NOT_DEFINED;
}

DiceMathStore::DiceMathStore(int attr)
{
	this->attr.reset(new int);
	*this->attr.get() = attr;
	this->dices.reset(nullptr);
	this->type = DiceMathType::NUMBER_TYPE;
}

DiceMathStore::DiceMathStore(Dice dice)
{
	this->attr.reset(nullptr);
	this->dices.reset(new std::vector<Dice>);
	this->dices->push_back(dice);
	this->type = DiceMathType::DICE_MATH;
}

DiceMathStore::DiceMathStore(std::vector<Dice> dices)
{
	this->attr.reset(nullptr);
	this->dices.reset(new std::vector<Dice>(dices));
	this->type = DiceMathType::DICE_MATH;
}

DiceMathStore::DiceMathStore(DiceType dice, unsigned int nDices)
{
	this->attr.reset(nullptr);
	this->dices.reset(new std::vector<Dice>);
	this->type = DiceMathType::DICE_MATH;
	for (unsigned int i = 0; i < nDices; i++)
	{
		switch (dice)
		{
			case DiceType::D4:
			{
				this->dices->push_back(d4());
				break;
			}
			case DiceType::D6:
			{
				this->dices->push_back(d6());
				break;
			}
			case DiceType::D8:
			{
				this->dices->push_back(d8());
				break;
			}
			case DiceType::D10:
			{
				this->dices->push_back(d10());
				break;
			}
			case DiceType::D12:
			{
				this->dices->push_back(d12());
				break;
			}
			case DiceType::D20:
			{
				this->dices->push_back(d20());
				break;
			}
			case DiceType::D100:
			{
				this->dices->push_back(d100Comb());
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

DiceMathStore::DiceMathStore(const DiceMathStore &other)
{
	this->type = other.type;

	this->attr.reset(nullptr);
	this->dices.reset(nullptr);
	
	if (other.attr)
	{
		this->attr.reset(new int);
		*this->attr.get() = *other.attr.get();
	}

	if (other.dices)
	{
		this->dices.reset(new std::vector<Dice>(*other.dices));
	}
}

DiceMathStore::DiceMathStore(DiceMathStore &&other) noexcept
{
	this->type = other.type;

	this->attr.reset(nullptr);
	this->dices.reset(nullptr);

	if (this->attr)
	{
		this->attr = std::move(other.attr);
	}

	if (this->dices)
	{
		this->dices = std::move(other.dices);
	}
}

DiceMathStore::~DiceMathStore()
{
	this->clear();
}

DiceMathStore &DiceMathStore::operator=(const DiceMathStore &other)
{
	this->type = other.type;

    this->attr.reset(nullptr);
	this->dices.reset(nullptr);
	
	if (other.attr)
	{
		this->attr.reset(new int);
		*this->attr.get() = *other.attr.get();
	}

	if (other.dices)
	{
		this->dices.reset(new std::vector<Dice>(*other.dices));
	}

	return *this;
}

DiceMathStore &DiceMathStore::operator=(DiceMathStore &&other) noexcept
{
	this->type = other.type;

    if (this == &other)
	{
		return *this;
	}

	this->attr.reset(nullptr);
	this->dices.reset(nullptr);

	if (this->attr)
	{
		this->attr = std::move(other.attr);
	}

	if (this->dices)
	{
		this->dices = std::move(other.dices);
	}

	return *this;
}

void DiceMathStore::clear()
{
	if (this->attr)
	{
		this->attr.reset(nullptr);
	}

	if (this->dices)
	{
		this->dices.reset(nullptr);
	}

	this->type = DiceMathType::NOT_DEFINED;
}

int *DiceMathStore::getAttr()
{
    return this->attr.get();
}

std::vector<Dice> *DiceMathStore::getDiceObj()
{
    return this->dices.get();
}

DiceMathType DiceMathStore::getType()
{
	return this->type;
}

#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE