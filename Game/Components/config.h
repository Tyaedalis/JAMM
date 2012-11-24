/*
	config.h
	Header file for config file handler. Contains class ConfigFile.
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "Debug\Debug.h"

namespace JAMM
{
	typedef std::map<std::wstring, std::wstring> strMap;

	class ConfigFile
	{
	private:
		strMap data; // map of string pairs
		std::wstring configFileName;

		// Member functions
		void parseLine(const std::wstring&);

	public:
		// Constructors
		//ConfigFile();

		ConfigFile(const std::wstring&); // for non-default filenames

		// Member functions
		void parseFile();
	};
}