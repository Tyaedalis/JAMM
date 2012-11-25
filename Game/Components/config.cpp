/*
	config.cpp
	Implementaion file for config file handler. Contains class ConfigFile.
*/
#include "config.h"

using namespace JAMM;

// Forward function declaration, implementation is below
bool StringSplit(const std::wstring &input, wchar_t delimiter, std::wstring &result1, std::wstring &result2);

// ================ ConfigFile class members ================

ConfigFile::ConfigFile(const std::wstring& fileName) // Default constructor
    : configFileName(fileName)
{
}

void ConfigFile::parseFile() // Loops through the file and adds contents to data map
{
	// Variables
	std::wifstream configFile;
	std::wstring line;

	// load the file
	configFile.open(configFileName);

	if (!configFile.good())
	{
		Log << L"\nError: Could not load configuration file.\n\n";
        return;
	}

	while (!configFile.eof())
	{
        Log << line << L"\n"; // Print the contents of the config file to the console

		getline(configFile, line);
		parseLine(line);
	}

    configFile.close();
}

void ConfigFile::parseLine(const std::wstring &line)
{
    // Break out of function if line is blank
    if (line.length() == 0)
        return;

	// Variables
	std::wstring key(L""), value(L""); // data to be pushed to data map, intialized with empty strings

    // Attempt to split the line
	if (!StringSplit(line, L'=', key, value))
	{
		Log << L"Config file load Error, while parsing line: " + line;
        return;
	}

    //  ==================== IMPORTANT ====================
    //  It is important to strip the whitespace characters from the key and value pair!
    //  So that should be done Here before adding the pair to the map.
    //  ===================================================

	data[key] = value;
	return;
}

// ================ Helper Functions ================

// If you can't find a standard library function, do it yourself!
// Notice that this function isn't part of the "ConfigFile" class, and that's okay! It's just local to this file.
// We might want to move this later to a "StringTools.cpp" file if we find the need for this function elsewhere in the game,
// or write additional helper functions.
//
// Anyway, this will take the "input" string, split it at the "delimiter" character, and put the 2 halves in "result1" and 
// "result2", or return false if something goes wrong
bool StringSplit(const std::wstring &input, wchar_t delimiter, std::wstring &result1, std::wstring &result2)
{
    // Set both result1 and result2 to blank strings
    result1 = result2 = L"";

    // Check to make sure input is at least 1 character using "input.length()". If check fails, return false


    // Loop through each charactor in "input", using "input[index]", and if the character is not equal to 'delimiter'
    // then add the character to the end of "result1" via "result1.push_back(input[index])". If the character equals 
    // 'delimiter', then skip that character, then continue adding the rest of the characters to 'result2' until you hit
    // the end of the string.

    return true;
}