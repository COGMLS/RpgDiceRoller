# RPG Dice Roller

## About:

The RPG Dice Roller is a tool for RPG board games, allowing the players to use features like: roll history, dice math, dice math with attributes and use dice composition, like the traditional D100 roll, a combined roll of the dices D10 and D100 and sum their results. Other less traditional dices are not present in this tool. The RPG Dice Roller is composed by the library `Dice Roller`, and is managed by the `Rpg Console`. The library contains all features to allow a possible GUI implementation in the future.

> In the actual moment, the `Rpg Console` it's been used to test the library.

> **IMPORTANT:** This project is under development and the features listed here may not be fully implemented.

> **NOTE FROM DEVELOPER:** This project it's been developed using my free time. The implementation of the new features and bug correction may take some time.

### Features:

Dices available: The `Dice Roller` library contains the dices `d4`, `d6`, `d8`, `d10`, `d20` and `d100`. An special d100, called `d100Comb` is design to make easier the roll of a d10 and d100 in only one dice object.

> All dices are inherited from the base class `Dice`, allowing the all dices types to be inserted in the same history container and simplify the dice math implementation.

| Feature | Type | Name | Status | Notes |
| ------- | ---- | ---- | ------ | ----- |
| Dice | Base Class | `Dice` | ✅ | |
| Dice 4 | Class | `d4` | ✅ | |
| Dice 6 | Class | `d6` | ✅ | |
| Dice 8 | Class | `d8` | ✅ | |
| Dice 10 | Class | `d10` | ✅ | |
| Dice 20 | Class | `d20` | ✅ | |
| Dice 100 | Class | `d100` | ✅ | |
| Combined D10 and D100 | Class | `d100Comb` | ✅ | |
| Uniform Dice Roll | Function | `RollDice_UniformRoll` | ✅ | This method is called internally by the dices constructors |
| Dice Value Tools | Functions | `DiceMaxVal`, `DiceMaxVal` and `DiceType2Str` | ✅ | Methods to give the correct values (minimum and maximum) based on dice to provide the correct value distribution. `DiceType2Str` is a method design to convert the dice identification to a `std::string` type. |
| Dice Roll Type | Enumerator | `RollerType` | ✅📌 | This enumerator is destined to define the type of distribution of the dice value, **by default the UNIFORM distribution is used all the time**. Other values are not recommended to use. |

> 📌 The `RollerType` values are not fully implemented. The non-UNIFORM roll type was created to simulate vicious dices and should not be used.

# License

MIT License

Copyright (c) 2024 Matheus L. Silvati

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.