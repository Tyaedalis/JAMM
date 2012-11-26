/*
	config.h
	Header file for config file handler. Contains class ConfigFile.
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "Debug\Debug.h"

template <class T>
T StringToValue(std::wstring &str)
{
    T value;
    std::wistringstream (str) >> value;

    return value;
}

namespace JAMM
{
	typedef std::map<std::wstring, std::wstring> strMap;

	class ConfigFile
	{
	private:
		strMap data; // map of string pairs
		std::wstring configFileName;

		// Member functions
        bool _createDefaultConfig();
		void _parseLine(const std::wstring&);
    public:
		// Constructors
		//ConfigFile();

		ConfigFile(const std::wstring&); // for non-default filenames

		// Member functions
		void parseFile();
        
        template <class T>
        T GetValue(const std::wstring &key, const T &defValue = NULL)
        {
            if (data[key] != L"")
                return StringToValue<T>(data[key]);

            data[key] = defValue;
            return defValue;
        }
	};

    ConfigFile& Configuration();
}