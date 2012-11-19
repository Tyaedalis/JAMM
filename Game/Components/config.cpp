#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

#include "config.h"

//========================= Class Convert =========================

template <typename T>
static std::string Convert::T_to_sring(T const &val)
{
    std::ostringstream ostr;
    ostr << val;

    return ostr.str();
}

// Convert std::string to T.
template <typename T>
static T Convert::string_to_T(std::string const &val)
{
    std::istringstream istr(val);
    T returnVal;
    if (!(istr >> returnVal))
        exitWithError("CFG: Not a valid " +
        (std::string)typeid(T).name() + " received!\n");

    return returnVal;
}

void Convert::exitWithError(const std::string &error)
{
    std::cout << error;
    std::cin.ignore();
    std::cin.get();

    exit(EXIT_FAILURE);
}

//========================= Class ConfigFile =========================

void ConfigFile::removeComment(std::string &line) const
{
    if (line.find(';') != line.npos)
        line.erase(line.find(';'));
}

bool ConfigFile::onlyWhitespace(const std::string &line) const
{
    return (line.find_first_not_of(' ') == line.npos);
}

bool ConfigFile::validLine(const std::string &line) const
{
    std::string temp = line;
    temp.erase(0, temp.find_first_not_of("\t "));
    if (temp[0] == '=')
        return false;

    for (size_t i = temp.find('=') + 1; i < temp.length(); i++)
        if (temp[i] != ' ')
            return true;

    return false;
}

void ConfigFile::extractKey(std::string &key, size_t const &sepPos, const std::string &line) const
{

}