/*
==========================
Logfile.cpp
Implementation file for the LogFile class
==========================
*/

#include "Game\Debug\Logfile.h"

using namespace JAMM;

/*
==========================
LogFile::LogFile(wchar_t* filename)
Constructor for LogFile class, takes 'filename' arg for the log file path
==========================
*/
LogFile::LogFile(wchar_t* filename)
{
    std::wcout << L"Creating log file " << filename << L"...\n\n";

    fileStream.open(filename, std::ios_base::out|std::ios_base::trunc);
    if (fileStream.fail())
        Log << L"Error: Unable to open log file.";
}

/*
==========================
LogFile::~LogFile()
Donstructor for LogFile class, closes the log filestream
==========================
*/
LogFile::~LogFile()
{
     fileStream.close();
}

/*
==========================
LogFile JAMM::Log(L"log.txt");
Global variable of the LogFile class, allows output of messages to the log file and console simultaneously
==========================
*/
LogFile JAMM::Log(L"log.txt");