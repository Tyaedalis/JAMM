/*
	config.cpp
	Implementaion file for config file handler. Contains class ConfigFile.
*/

#include <iostream>
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

#include "config.h"
#include "GlobalConstants.h"

using namespace JAMM;

// Forward function declaration, implementation is below
static inline std::wstring &ltrim(std::wstring &s);
static inline std::wstring &rtrim(std::wstring &s);
static inline std::wstring &trim(std::wstring &s);

bool StringSplit(const std::wstring &input, wchar_t delimiter, std::wstring &result1, std::wstring &result2);

// ================ ConfigFile class members ================

ConfigFile::ConfigFile(const std::wstring& fileName) // Default constructor
    : data(),
      configFileName(fileName)
{
}

void ConfigFile::parseFile() // Loops through the file and adds contents to data map
{
	// Variables
	std::wifstream configFile;
	std::wstring line;

    while (1)
    {
	    // load the file
	    configFile.open(configFileName);

	    if (!configFile.good())
	    {
            Log << "No configuration file found, creating default file: " << configFileName << "\n\n";

            bool success = _createDefaultConfig();
            if (!success)
		        ExitWithError("Error: Could not load configuration file.");
	    }
        else
            break;
    }

    Log << "== Parsing " << configFileName << " ==\n";

	while (!configFile.eof())
	{
		getline(configFile, line);
		_parseLine(line);
	}

    Log << L"\nConfig file loaded, " << data.size() << " entries.\n\n";

    configFile.close();
}

void ConfigFile::_parseLine(const std::wstring &line)
{
    // Break out of function if line is blank
    if (line.length() == 0)
        return;

	// Variables
	std::wstring key(L""), value(L""); // data to be pushed to data map, intialized with empty strings

    // Attempt to split the line
	if (!StringSplit(line, L'=', key, value))
	{
		Log << L"Config file load Error, while parsing line: " << line;
        return;
	}

    key = trim(key);
    value = trim(value);

    Log << L"[" << key << L"] = \"" << value << "\"\n";
	data[key] = value;

	return;
}

bool ConfigFile::_createDefaultConfig()
{
    std::wofstream ofStr(configFileName, std::ios_base::out|std::ios_base::trunc);
    if (ofStr.fail())
        return false;

    ofStr << Config_Default;
    ofStr.flush();
    ofStr.close();

    return true;
}


// ================ Helper Functions ================
bool StringSplit(const std::wstring &input, wchar_t delimiter, std::wstring &result1, std::wstring &result2)
{
    // Set both result1 and result2 to blank strings
    result1 = result2 = L"";

    // Check to make sure input is at least 1 character
    if (input.length() < 1)
        return false;

    uint32 i = 0;
    std::wstring* strPtr(&result1);

    while (i < input.length())
    {
        if (input[i] != delimiter)
            strPtr->push_back(input[i]);
        else
            strPtr = &result2;

        i++;
    }

    return true;
}

// trim from start
static inline std::wstring &ltrim(std::wstring &s) 
{
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::wstring &rtrim(std::wstring &s) 
{
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::wstring &trim(std::wstring &s)
{
        return ltrim(rtrim(s));
}

ConfigFile& JAMM::Configuration()
{
    static ConfigFile config(Config_Filename);
    return config;
}