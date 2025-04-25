#pragma once

#ifndef DICE_MATH_HPP
#define DICE_MATH_HPP

#ifdef WIN32
	#ifdef DICE_ROLLER_LIB_EXPORTS
		#define DICE_ROLLER_LIB_API __declspec(dllexport)
	#else
		#define DICE_ROLLER_LIB_API __declspec(dllimport)
	#endif //!DICE_ROLLER_LIB_EXPORTS

	#pragma warning (disable : 4251)
	#pragma warning (disable : 4273)
#else
	#if __GNUC__ >= 4
		#ifdef DICE_ROLLER_LIB_EXPORTS
			#define DICE_ROLLER_LIB_API __attribute__((visibility("default")))
		#else
			#define DICE_ROLLER_LIB_API __attribute__((visibility("default")))
		#endif //!DICE_ROLLER_LIB_EXPORTS
	#else
		#ifdef DICE_ROLLER_LIB_EXPORTS
			#define DICE_ROLLER_LIB_API
		#else
			#define DICE_ROLLER_LIB_API
		#endif //!DICE_ROLLER_LIB_EXPORTS
	#endif
#endif // !WIN32

#include "ExperimentalFeatures.hpp"

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH

#include <vector>
#include <memory>
#include <list>
#include <string>
#include <cstring>
#include <cmath>

#include "Types.hpp"
#include "DiceBase.hpp"
#include "Dices.hpp"
#include "d100Combined.hpp"

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE
#include "DiceMathStore.hpp"
#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE

/**
 * @brief Dice Mathematical Command base class to provide a inherence to DiceMathAttr, DiceMathDiceObj, DiceMathOp and DiceMathGroup
 */
class DiceMathBase
{
	protected:

		DiceMathType type;
		DiceMathStore data;

	public:

		DiceMathBase();

		DiceMathBase (const DiceMathBase& other);
		DiceMathBase (DiceMathBase&& other) noexcept;
		
		~DiceMathBase();

		DiceMathBase& operator= (const DiceMathBase& other);
		DiceMathBase& operator= (DiceMathBase&& other) noexcept;

		virtual int getValue();
		virtual DiceMathType getType();
		virtual size_t getSize();
};

/**
 * @brief Dice Mathematical component for Dice objects
 */
class DiceMathDiceObj : public DiceMathBase
{
	public:
	
		DiceMathDiceObj (Dice dice);
		
		DiceMathDiceObj (std::vector<Dice> dices);

		DiceMathDiceObj (DiceType dice, unsigned int nDices);
		
		DiceMathDiceObj (const DiceMathDiceObj& other);
		
		DiceMathDiceObj (DiceMathDiceObj&& other) noexcept;
		
		~DiceMathDiceObj();

		DiceMathDiceObj& operator= (const DiceMathDiceObj& other);
		DiceMathDiceObj& operator= (DiceMathDiceObj&& other) noexcept;
		
		int getValue();

		DiceMathType getType();
};

/**
 * @brief Dice Mathematical Attributes or Bonus holding integers
 */
class DiceMathAttr : public DiceMathBase
{
	public:
	
		DiceMathAttr (int value);

		DiceMathAttr (const DiceMathAttr& other);

		DiceMathAttr (DiceMathAttr&& other) noexcept;

		~DiceMathAttr();

		DiceMathAttr& operator= (const DiceMathAttr& other);
		DiceMathAttr& operator= (DiceMathAttr&& other) noexcept;

		int getValue();

		DiceMathType getType();
};

/**
 * @brief Dice Mathematical Group to support groups that must be treated first before interacts with other Dice Mathematical components
 */
class DiceMathGroup : public DiceMathBase
{
	protected:

	std::vector<DiceMathBase> cmds;

	public:

		DiceMathGroup();

		DiceMathGroup (std::vector<DiceMathBase> cmds);

		~DiceMathGroup();

		DiceMathGroup& operator= (const DiceMathGroup& other);
		DiceMathGroup& operator= (DiceMathGroup&& other) noexcept;

		size_t getSize();

		int getValue();

		DiceMathType getType();
};

/**
 * @brief Dice Mathematical Operator to create the relations between DiceMathAttr or DiceMathDiceObj. The relation is with last operator's value stored applied the mathematical operation between the current operator data stored.
 */
class DiceMathOp : public DiceMathBase
{
	private:

		char op;
		bool hasCmd;
		DiceMathBase rCmd;
	
	public:

		DiceMathOp (char op);

		DiceMathOp (char op, DiceMathAttr attr);

		DiceMathOp (char op, DiceMathDiceObj dice);

		DiceMathOp (const DiceMathOp& other);

		DiceMathOp (DiceMathOp&& other) noexcept;

		~DiceMathOp();

		DiceMathOp& operator= (const DiceMathOp& other);
		DiceMathOp& operator= (DiceMathOp&& other) noexcept;

		int getValue();
		
		bool hasMathCmd();
		
		char getOperator();

		DiceMathType getType();
};

class DiceMath
{
	private:
	
		std::vector<DiceMathOp> op;
		std::list<DiceMathOp> list;	// Doubly linked list of DiceMathOp creating the relationship between the math operators and attributes and dice objects

	public:

		DiceMath();

		//DiceMath (std::string cli);

		~DiceMath();

		DiceMathOp& front();

		DiceMathOp& back();

		void insert (char op, int attr);

		void insert (char op, Dice dice);

		void insert (char op, std::vector<Dice> dices);

		void insert (char op, DiceType dice, unsigned int nDices);

		DiceMathOp* getOp (size_t pos);

		size_t size();

		int calc();
};

/**
 * @brief Calculate the dice cmd, using the last operator value with the correct mathematical relation with current operator's value and return a DiceMathAttr to replace the current operator's value with new attribute. If the last operator is nullptr or current operator does not hold a DiceMathBase, the function will return the current operator's value.
 * @param lastOp Last operator pointer
 * @param op Current operator pointer
 * @return Calculated value between lastOp and op values as a DiceMathAttr.
 */
DiceMathAttr calcDiceCmd (DiceMathOp* lastOp, DiceMathOp* op);

#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH

#endif // !DICE_MATH_HPP