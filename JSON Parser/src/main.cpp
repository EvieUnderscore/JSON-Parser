#include <iostream>
#include <fstream>
#include <string>

#include "json/JSONParser.h"

JSONParser testParser;

int main() {
    testParser.Parse("test/keyvaltest.json");

}