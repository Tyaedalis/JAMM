/*
==========================
Logfile.cpp
Implementation file for the _log class
==========================
*/

#include "Game\Debug\Logfile.h"

/*
==========================
_log::_log(wchar_t* filename)
Constructor for _log class, takes 'filename' arg for the log file path
==========================
*/
_log::_log(wchar_t* filename)
{
    std::wcout << L"Creating log file " << filename << L"...\n\n";

    fileStream.open(filename, std::ios_base::out|std::ios_base::trunc);
    if (fileStream.fail())
        Log << L"Error: Unable to open log file.";
}

/*
==========================
_log::~_log()
Donstructor for _log class, closes the log filestream
==========================
*/
_log::~_log()
{
     fileStream.close();
}

/*
==========================
_log Log(L"log.txt");
Global variable of the _log class, allows output of messages to the log file and console simultaneously
==========================
*/
_log Log(L"log.txt");