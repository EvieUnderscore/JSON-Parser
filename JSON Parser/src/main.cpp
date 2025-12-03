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
        for (const auto& pair : testParser.parsedKeyValues) {
            if (pair.second.type == JSONValue::JSONValueType::VAL_STRING) {
                std::cout << std::any_cast<std::string>(pair.second.value) << std::endl;
            }
        }
    }
}