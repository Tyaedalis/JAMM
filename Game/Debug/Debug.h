#pragma once

#include "Game\Debug\Logfile.h"

inline void _reportAssertionFailure(const char* expr, const char* comment, const char* file, int32 line)
{
    Log << "\n=======================================\n"
        << "Debug assertion failed!\n"
        << "Expression: " << expr << "\n"
        << "Comment...: " << comment << "\n"
        << "File......: " << file << "\n"
        << "Line......: " << line << "\n"
        << "=======================================\n\n";
}

inline void _fatalErrorExit(const char* msg, const char* file = "", int32 line = 0)
{
    #ifdef DEBUG
        Log << "\n=======================================\n"
            << "A fatal error has occured!\n"
            << "Message: " << msg << "\n"
            << "File...: " << file << "\n"
            << "Line...: " << line << "\n"
            << "=======================================\n\n";
    #else
        Log << "\n=======================================\n"
            << "A fatal error has occured!\n"
            << "Message: " << msg << "\n"
            << "=======================================\n\n";
    #endif

    std::cout << "Press any key to exit the game.";

    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    exit(0);
}

// Enables debug features if program is ran with DEBUG preprocessor directive
#ifdef DEBUG
    #ifdef _MSC_VER
        #define DEBUG_BREAK __debugbreak()
    #else
        #define DEBUG_BREAK()
    #endif

    #define ASSERT(expr, comment) \
        if (expr) { } \
        else \
        { \
        _reportAssertionFailure(#expr, #comment, __FILE__, __LINE__); \
            DEBUG_BREAK; \
        }

    #define ExitWithError(msg) _fatalErrorExit(msg, __FILE__, __LINE__);
#else
    #define DEBUG_BREAK
    #define ASSERT(expr, comment)
    #define ExitWithError(msg) _fatalErrorExit(msg);
#endif

// #define cout Log