#pragma once

#include <iostream>
#include <fstream>

#include "AtomicTypes.h"

using namespace std;

class _log
{
    public:
        std::ofstream fileStream;

        _log(char*filename);
        ~_log();

        template<class t>
        friend _log &operator<<(_log &left, const t& right)
        {
            std::cout << right;
            left.fileStream << right;
            left.fileStream.flush();
            return left;  
        }

        template<class t>
        friend _log &operator<<(_log &left, const t* right)
        {
            std::cout << right;
            left.fileStream << right;
            left.fileStream.flush();
            return left;  
        }
};

extern _log Log;