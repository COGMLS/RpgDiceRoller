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

		DiceMathType type;							// Define the data type is holding
		std::unique_ptr<int> attr;					// Numeric attribute
		std::unique_ptr<std::vector<Dice>> dices;	// Dice or dices, all of the same time
		
	public:
		
		DiceMathStore();
		
		/**
		 * @brief Create a DiceMathStore that holds a numeric attribute
		 * @param attr Numeric attribute
		 */
		DiceMathStore (int attr);
		
		/**
		 * @brief Create a DiceMathStore object that hold a dice object
		 * @param dice Dice object
		 */
		DiceMathStore (Dice dice);
		
		/**
		 * @brief Create a DiceMathStore object that holds various dices
		 * @param dices Dice vector
		 */
		DiceMathStore (std::vector<Dice> dices);
		
		/**
		 * @brief Create a DiceMathStore object that holds various dices of the same type
		 * @param dice Dice type
		 * @param nDices Number of dices that will be rolled
		 */
		DiceMathStore (DiceType dice, unsigned int nDices);
		
		DiceMathStore (const DiceMathStore& other);
		
		DiceMathStore (DiceMathStore&& other) noexcept;
		
		~DiceMathStore();
		
		DiceMathStore& operator= (const DiceMathStore& other);
		DiceMathStore& operator= (DiceMathStore&& other) noexcept;

		DiceMathStore& operator= (int attr);
		DiceMathStore& operator= (Dice dice);
		DiceMathStore& operator= (std::vector<Dice> dices);
		
		/**
		 * @brief Clear the DiceMathStore
		 */
		void clear();
		
		/**
		 * @brief Get the numeric attribute.
		 * @return If a numeric value exist, will return. Otherwise, it will return nullptr.
		 */
		int* getAttr();
		
		/**
		 * @brief Get the dice or dices available in the store
		 * @return Return a vector of dices if has a dice or dices stored. Otherwise, it will return nullptr.
		 */
		std::vector<Dice>* getDiceObj();
		
		/**
		 * @brief Get the type of component that is holding
		 */
		DiceMathType getType();
};

#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_DICE_MATH_STORE

#endif // !DICE_MATH_STORE_HPP