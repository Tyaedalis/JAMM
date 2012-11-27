/*
==========================
Logfile.cpp
Header file for the LogFile class
==========================
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Game\AtomicTypes.h"

namespace JAMM
{
    class LogFile
    {
        private:
            mutable std::wofstream fileStream;

            // Prevent compiler from generating default copy constructor\copy assignment operator code
            LogFile(const LogFile&);
            LogFile& operator=(const LogFile&);
        public:
            LogFile(wchar_t* filename);
            ~LogFile();

            template<class t>
            friend LogFile &operator<<(LogFile &left, const t& right)
            {
                std::wcout << right;
                left.fileStream << right;
                left.fileStream.flush();
                return left;  
            }

            template<class t>
            friend LogFile &operator<<(LogFile &left, const t* right)
            {
                std::wcout << right;
                left.fileStream << right;
                left.fileStream.flush();
                return left;  
            }
    };

    /*
    ==========================
    extern LogFile Log;
    Global variable declaration of the _log class, allows output of messages to the log file and console simultaneously.
    Initialization is in Logfile.cpp
    ==========================
    */
    extern LogFile Log;
}