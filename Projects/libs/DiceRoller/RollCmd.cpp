#include "RollCmd.hpp"

#ifdef DICE_ROLLER_ENABLE_EXPERIMENTAL_ROLL_CMD

RollCmd::RollCmd()
{
}

RollCmd::RollCmd(std::string cli)
{
	std::vector<std::string> tokens;

	// Create tokens:

	char* input = nullptr;
	const char* delim = " ";
	char* cToken = std::strtok(input, delim);

	while (cToken)
	{
		cToken = std::strtok(nullptr, delim);
		tokens.push_back(cToken);
	}

	// Remove all possible empty spaces:
	for (size_t i = 0; i < tokens.size(); i++)
	{
		std::string tmp;
		for (size_t j = 0; j < tokens[i].size(); j++)
		{
			if (!std::isspace(tokens[i][j]))
			{
				tmp += tokens[i][j];
			}
		}
		tokens[i] = tmp;
	}

	// Analyze the tokens and determinate if they are dices, math operators or attribute bonus:
	for (size_t i = 0; i < tokens.size(); i++)
	{
		
	}
}

#endif // !DICE_ROLLER_ENABLE_EXPERIMENTAL_ROLL_CMD