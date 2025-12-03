#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <variant>
#include <vector>
#include <map>
#include <any>

#include "parsing/JSONValue.h"

class JSONParser
{
public:
	JSONParser();

	bool Parse(std::string filePath);

	std::vector<std::string> parsedJsonFull;
	std::map<std::string, std::any> parsedKeyValues;

	void detectThing();

};

