#include <iostream>
#include <fstream>
#include <string>

#include "json/JSONParser.h"

JSONParser testParser;

int main() {
    testParser.Parse("test/keyvaltest.json");

    std::cout << testParser.parsedKeyValues.size() << std::endl;

    if (testParser.parsedKeyValues.size() > 0)
    {
        std::cout << std::any_cast<std::string>(testParser.parsedKeyValues["key"]) << std::endl;
        std::cout << std::any_cast<std::string>(testParser.parsedKeyValues["key2"]) << std::endl;

    }
}