#include <iostream>
#include <string>

class Convert
{
    public:
        // Convert t to std::string.
        template <typename T>
        static std::string T_to_sring(T const &val);

        // Convert std::string to T.
        template <typename T>
        static T string_to_T(std::string const &val);

       void exitWithError(const std::string&);
};

class ConfigFile
{
    private:
	    std::map<std::string, std::string> contents;
	    std::string fName;

        void removeComment(std::string&) const;
        bool onlyWhitespace(const std::string&) const;
        bool validLine(const std::string&) const;
        void extractKey(std::string&, size_t const&, const std::string&) const;
        void extractValue(std::string&, size_t const&, const std::string&) const;
        void extractContents(const std::string&);
        void ExtractKeys();

    public:
        ConfigFile(const std::string&);
        bool keyExists(const std::string&);
        template <typename ValueType>
        ValueType getValueOfKey(const std::string&, ValueType const&) const;
};