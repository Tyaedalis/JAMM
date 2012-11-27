#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Game\AtomicTypes.h"

class _log
{
    public:
        std::wofstream fileStream;

        _log(wchar_t* filename);
        ~_log();

        template<class t>
        friend _log &operator<<(_log &left, const t& right)
        {
            std::wcout << right;
            left.fileStream << right;
            left.fileStream.flush();
            return left;  
        }

        template<class t>
        friend _log &operator<<(_log &left, const t* right)
        {
            std::wcout << right;
            left.fileStream << right;
            left.fileStream.flush();
            return left;  
        }
};

extern _log Log;