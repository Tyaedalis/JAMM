#include "config.h"

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

void Convert::exitWithError(const std::string &error)
{
	std::cout << error;
	std::cin.ignore();
	std::cin.get();

	exit(EXIT_FAILURE);
}

void ConfigFile::removeComment(std::string &line) const
{
	if (line.find(';') != line.npos)
		line.erase(line.find(';'));
}

bool ConfigFile::onlyWhitespace(std::string &line) const
{
	return (line.find_first_not_of(' ') == line.npos);
}

bool ConfigFile::validLine(const std::string &line) const
{
	std::string temp = line;
	temp.erase(0, temp.find_first_not_of("\t "));
	if (temp[0] == '=')
		return false;

	for (size_t i = temp.find('=') + 1; i < temp.length(); i++)
		if (temp[i] != ' ')
			return true;

	return false;
}

void ConfigFile::extractKey(std::string &key, size_t const &sepPos, const std::string &line) const
{

}