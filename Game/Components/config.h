/*
	config.h
	Header file for config file handler. Contains class ConfigFile.
*/

#pragma once

#include <fstream>
#include <string>
#include <map>

namespace JAMM
{
	typedef std::map<std::string, std::string> ConfigType;

	class ConfigFile
	{
	private:
		ConfigType data; // map of string pairs
		std::string configFileName;

		// Member functions
		bool parseLine(const std::string&);

	public:
		// Constructors
		ConfigFile();
		//ConfigFile(const std::string&); // for non-deefault filenames

		// Member functions
		void parseFile();
	};
}