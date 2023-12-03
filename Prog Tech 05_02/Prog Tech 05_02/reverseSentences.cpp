#include "reverseSentences.h"

std::string reverseSentences()
{
	std::ifstream file("file.txt");
	std::string line, text = "", reversedText = "", word, sentence;

	if (!file.is_open())
	{
		throw std::exception("Failed to open file!\n");
	}

	while (!(file.eof()))
	{
		std::getline(file, line);

		text.append(line);
	}

	std::stringstream stringStream(text);

	while (std::getline(stringStream, sentence, '.'))
	{
		reversedText.insert(0, ".");
		reversedText.insert(0, sentence);
	}

	return reversedText;
}