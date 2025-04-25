#include "DiceMath.hpp"

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH

//
// DiceMathBase:
//

DiceMathBase::DiceMathBase()
{
	this->type = DiceMathType::NOT_DEFINED;
}

DiceMathBase::DiceMathBase(const DiceMathBase &other)
{
	this->type = other.type;
	this->data = other.data;
}

DiceMathBase::DiceMathBase(DiceMathBase &&other) noexcept
{
	this->type = std::move(other.type);
	this->data = std::move(other.data);
}

DiceMathBase::~DiceMathBase()
{
	
}

DiceMathBase &DiceMathBase::operator=(const DiceMathBase &other)
{
	this->type = other.type;
	this->data = other.data;
	return *this;
}

DiceMathBase &DiceMathBase::operator=(DiceMathBase &&other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	
	this->type = std::move(other.type);
	this->data = std::move(other.data);
	return *this;
}

int DiceMathBase::getValue()
{
	return 0;
}

DiceMathType DiceMathBase::getType()
{
	return DiceMathType::NOT_DEFINED;
}

size_t DiceMathBase::getSize()
{
    return 0;
}

//
// DiceMathDiceObj:
//

DiceMathDiceObj::DiceMathDiceObj(Dice dice)
{
	this->type = DiceMathType::DICE_MATH;
	this->data = DiceMathStore(dice);
}

DiceMathDiceObj::DiceMathDiceObj(std::vector<Dice> dices)
{
	this->type = DiceMathType::DICE_MATH;
	this->data = DiceMathStore(dices);
}

DiceMathDiceObj::DiceMathDiceObj(DiceType dice, unsigned int nDices)
{
	this->type = DiceMathType::DICE_MATH;
	this->data = DiceMathStore(dice, nDices);
}

DiceMathDiceObj::DiceMathDiceObj(const DiceMathDiceObj &other)
{
	this->data = other.data;
	this->type = other.type;
}

DiceMathDiceObj::DiceMathDiceObj(DiceMathDiceObj &&other) noexcept
{
	this->data = std::move(other.data);
	this->type = std::move(other.type);
}

DiceMathDiceObj::~DiceMathDiceObj()
{
}

DiceMathDiceObj &DiceMathDiceObj::operator=(const DiceMathDiceObj &other)
{
    this->data = other.data;
	this->type = other.type;
	return *this;
}

DiceMathDiceObj &DiceMathDiceObj::operator=(DiceMathDiceObj &&other) noexcept
{
    if (this == &other)
	{
		return *this;
	}

	this->data = std::move(other.data);
	this->type = std::move(other.type);
	return *this;
}

int DiceMathDiceObj::getValue()
{
	int val = 0;
	if (this->data.getDiceObj() != nullptr)
	{
		for (size_t i = 0; i < this->data.getDiceObj()->size(); i++)
		{
			val += this->data.getDiceObj()->at(i).getValue();
		}
	}
    return val;
}

DiceMathType DiceMathDiceObj::getType()
{
    return this->type;
}

//
// DiceMathAttr:
//

DiceMathAttr::DiceMathAttr(int value)
{
	this->data = DiceMathStore(value);
	this->type = DiceMathType::NUMBER_TYPE;
}

DiceMathAttr::DiceMathAttr(const DiceMathAttr &other)
{
	this->data = other.data;
	this->type = other.type;
}

DiceMathAttr::DiceMathAttr(DiceMathAttr &&other) noexcept
{
	this->data = std::move(other.data);
	this->type = std::move(other.type);
}

DiceMathAttr::~DiceMathAttr()
{
}

DiceMathAttr &DiceMathAttr::operator=(const DiceMathAttr &other)
{
    this->data = other.data;
	this->type = other.type;
	return *this;
}

DiceMathAttr &DiceMathAttr::operator=(DiceMathAttr &&other) noexcept
{
    if (this == &other)
	{
		return *this;
	}

	this->data = std::move(other.data);
	this->type = std::move(other.type);
	return *this;
}

int DiceMathAttr::getValue()
{
    if (this->data.getAttr() == nullptr)
	{
		return 0;
	}

	return *this->data.getAttr();
}

DiceMathType DiceMathAttr::getType()
{
    return this->type;
}

//
// DiceMathOp:
//

DiceMathOp::DiceMathOp(char op)
{
	this->op = op;
	this->type = DiceMathType::MATH_OPERATOR;
	this->hasCmd = false;
}

DiceMathOp::DiceMathOp(char op, DiceMathAttr attr)
{
	this->op = op;
	this->type = DiceMathType::MATH_OPERATOR;
	this->hasCmd = true;
	this->rCmd = attr;
}

DiceMathOp::DiceMathOp(char op, DiceMathDiceObj dice)
{
	this->op = op;
	this->type = DiceMathType::MATH_OPERATOR;
	this->hasCmd = true;
	this->rCmd = dice;
}

DiceMathOp::DiceMathOp(const DiceMathOp &other)
{
	this->op = other.op;
	this->type = other.type;
	this->hasCmd = other.hasCmd;
	if (other.hasCmd)
	{
		this->rCmd = other.rCmd;
	}
}

DiceMathOp::DiceMathOp(DiceMathOp &&other) noexcept
{
	this->op = std::move(other.op);
	this->type = std::move(other.type);
	this->hasCmd = std::move(other.hasCmd);
	this->rCmd = std::move(other.rCmd);
}

DiceMathOp::~DiceMathOp()
{

}

DiceMathOp &DiceMathOp::operator=(const DiceMathOp &other)
{
    this->op = other.op;
	this->type = other.type;
	this->hasCmd = other.hasCmd;
	if (other.hasCmd)
	{
		this->rCmd = other.rCmd;
	}
	return *this;
}

DiceMathOp &DiceMathOp::operator=(DiceMathOp &&other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	this->op = std::move(other.op);
	this->type = std::move(other.type);
	this->hasCmd = std::move(other.hasCmd);
	this->rCmd = std::move(other.rCmd);
	return *this;
}

int DiceMathOp::getValue()
{
	if (!this->hasMathCmd())
	{
		return 0;
	}

	return this->rCmd.getValue();
}

bool DiceMathOp::hasMathCmd()
{
    return this->hasCmd;
}

char DiceMathOp::getOperator()
{
    return this->op;
}

DiceMathType DiceMathOp::getType()
{
    return DiceMathType::MATH_OPERATOR;
}

DiceMath::DiceMath()
{
	this->op.push_back(DiceMathOp('+', d20()));
	this->op.push_back(DiceMathOp('+', 15));
	this->op.push_back(DiceMathOp('-', d10()));
	this->op.push_back(DiceMathOp('+', 5));

	for (size_t i = 0; i < this->op.size(); i++)
	{
		this->list.push_back(this->op[i]);
	}
}

DiceMath::~DiceMath()
{
	
}

DiceMathOp &DiceMath::front()
{
	return this->list.front();
}

DiceMathOp &DiceMath::back()
{
    return this->list.back();
}

void DiceMath::insert(char op, int attr)
{
	this->list.push_back(DiceMathOp(op, DiceMathAttr(attr)));
}

void DiceMath::insert(char op, Dice dice)
{
	this->list.push_back(DiceMathOp(op, DiceMathDiceObj(dice)));
}

void DiceMath::insert(char op, std::vector<Dice> dices)
{
	this->list.push_back(DiceMathOp(op, DiceMathDiceObj(dices)));
}

void DiceMath::insert(char op, DiceType dice, unsigned int nDices)
{
	this->list.push_back(DiceMathOp(op, DiceMathDiceObj(dice, nDices)));
}

DiceMathOp *DiceMath::getOp(size_t pos)
{
	if (pos >= this->list.size() || this->list.empty())
	{
		return nullptr;
	}

	return (&this->list.front() + pos);
}

size_t DiceMath::size()
{
    return this->list.size();
}

int DiceMath::calc()
{
	int val = 0;

	size_t i = 0;

	DiceMathOp* cmd = nullptr;
	DiceMathOp* last = nullptr;

	for (i; i < this->list.size(); i++)
	{
		cmd = this->getOp(i);

		if (i != 0)
		{
			last = this->getOp(i - 1);
		}

		DiceMathAttr x = calcDiceCmd(last, cmd);

		val = x.getValue();

		this->list.assign(i, DiceMathOp(cmd->getOperator(), x));
	}

    return val;
}

DiceMathAttr calcDiceCmd(DiceMathOp *lastOp, DiceMathOp *op)
{
    int val = 0;
	
	if (op != nullptr)
	{
		if (lastOp == nullptr || !op->hasMathCmd())
		{
			return DiceMathAttr(op->getValue());
		}
		
		int lval = 0;
		int rval = 0;

		lval = lastOp->getValue();
		rval = op->getValue();

		switch (op->getOperator())
		{
			case '+':
			{
				val = lval + rval;
				break;
			}
			case '-':
			{
				val = lval - rval;
				break;
			}
			default:
			{
				break;
			}
		}
	}
	
	return DiceMathAttr(val);
}

#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH