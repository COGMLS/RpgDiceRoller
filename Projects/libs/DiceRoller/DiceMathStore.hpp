#pragma once

#ifndef DICE_MATH_STORE_HPP
#define DICE_MATH_STORE_HPP

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

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE

#include <memory>
#include <vector>

#include "Types.hpp"
#include "DiceBase.hpp"
#include "Dices.hpp"
#include "d100Combined.hpp"

/**
 * @brief Dice Math data store to hold bonus/attributes or dices
 */
class DiceMathStore
{
	private:

		DiceMathType type;
		std::unique_ptr<int> attr;
		std::unique_ptr<std::vector<Dice>> dices;
		
	public:
		
		DiceMathStore();
		
		DiceMathStore (int attr);
		
		DiceMathStore (Dice dice);
		
		DiceMathStore (std::vector<Dice> dices);
		
		DiceMathStore (DiceType dice, unsigned int nDices);
		
		DiceMathStore (const DiceMathStore& other);
		
		DiceMathStore (DiceMathStore&& other) noexcept;
		
		~DiceMathStore();
		
		DiceMathStore& operator= (const DiceMathStore& other);
		DiceMathStore& operator= (DiceMathStore&& other) noexcept;
		
		void clear();
		
		int* getAttr();
		
		std::vector<Dice>* getDiceObj();
		
		DiceMathType getType();
};

#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE

#endif // !DICE_MATH_STORE_HPP