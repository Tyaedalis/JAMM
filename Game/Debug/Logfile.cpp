#include "Logfile.h"

_log::_log(char* filename)
{
    std::cout << "Creating log file " << filename << "...\n\n";

    fileStream.open(filename, ios_base::out|ios_base::trunc);
    if (fileStream.fail())
        Log << "Error: Unable to open log file.";
}

_log::~_log()
{
     fileStream.close();
}

_log Log("log.txt");