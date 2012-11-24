#include "Logfile.h"

_log::_log(wchar_t* filename)
{
    std::wcout << L"Creating log file " << filename << L"...\n\n";

    fileStream.open(filename, std::ios_base::out|std::ios_base::trunc);
    if (fileStream.fail())
        Log << L"Error: Unable to open log file.";
}

_log::~_log()
{
     fileStream.close();
}

_log Log(L"log.txt");