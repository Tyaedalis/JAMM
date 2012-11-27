/*
	config.h
	Header file for config file handler. Contains class ConfigFile.
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm> 
#include <functional> 
#include <map>

#include "Game\GlobalConstants.h"
#include "Game\Debug\Debug.h"

/*
==========================
template <class T> T StringToValue(std::wstring &str)
Helper function, converts the contents of a wide string to a value type
==========================
*/
template <class T>
T StringToValue(std::wstring &str)
{
    T value;
    std::wistringstream (str) >> value;

    return value;
}

namespace JAMM
{
    /*
    ==========================
    class ConfigFile
    Handles the loading and parsing of configuration files
    ==========================
    */
	class ConfigFile
	{
	    private:
		    mutable std::map<std::wstring, std::wstring> _configData; // map of string pairs
		    mutable std::wstring _configFileName;

            bool _createDefaultConfig();
		    void _parseLine(const std::wstring&);

            // Prevent compiler from generating default copy constructor\copy assignment operator code
            ConfigFile(const ConfigFile&);
            ConfigFile& operator=(const ConfigFile&);
        public:
		    ConfigFile(const std::wstring&);

		    void ReloadFile();
        
            template <class T>
            T GetValue(const std::wstring &key, const T &defValue = NULL) const
            {
                if (_configData[key] != L"")
                    return StringToValue<T>(_configData[key]);

                _configData[key] = defValue;
                return defValue;
            }
	};

    /*
    ==========================
    ConfigFile& Configuration();
    Function declared in namespace scope that returns a global static instance of the default ConfigFile
    ==========================
    */
    const ConfigFile& gConfiguration();
}