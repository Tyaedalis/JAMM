#include <iostream>
using std::cout;
using std::string;

#include "config.h"
using namespace JAMM;

ConfigFile::ConfigFile() // Default constructor
{
	configFileName = "DefaultConfig.x"; // Default filename
}

void ConfigFile::parseFile() // Loops through the file and adds contents to data map
{
	// Variables
	std::ifstream configFile;
	string line;

	// load the file
	configFile.open(configFileName);

	// The problem occurs somewhere around here.

	if (!configFile.good())
	{
		cout << "Error: Could not load configuration file.\n";
	}

	while (!configFile.eof())
	{
		getline(configFile, line);
		parseLine(line);
	}
}

bool ConfigFile::parseLine(const string &line)
{
	// Depends on config file with complete integrity; no errors can be present.
	// Needs to be refined.

	// Variables
	size_t pos; // to be used by string.find()
	string key, value; // data to be pushed to data map

	pos = line.find("=");
	if (!pos) // If it can't find the = then it must be a bad file.
	{
		cout << "Error: Invalid configuration file.\n";
		return false;
	}
	
	key = line.substr(0, pos-2);
	value = line.substr(pos+2);

	data[key] = value;
}