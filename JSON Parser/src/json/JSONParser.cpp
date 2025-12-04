#include "JSONParser.h"

JSONParser::JSONParser()
{

}


bool readingString = false;

bool readingKey = true;
bool readingValue = false;

std::string key = "";
std::any value;

void JSONParser::detectThing() {
    for (int i = 1; i < parsedJsonFull.size(); i++)
    {
        //loop through lines
        std::string line = parsedJsonFull[i - 1];
        
        // iterator stuff
        int readLineLength = 0;
        int readStringLength = 0;


        for (char c : line) {
            readLineLength++;

            if (c == '"') {
                if (readingString == true) {
                    //string end

                    if (readingKey)
                    {
                        if (key == "") {
                            key = line.substr(readLineLength - readStringLength, readStringLength - 1);
                        }
                    }

                    if (readingValue)
                    {
                        if (!value.has_value()) {
                            value = line.substr(readLineLength - readStringLength, readStringLength - 1);

                            parsedKeyValues[key].type = JSONValue::JSONValueType::VAL_STRING;
                            parsedKeyValues[key].value = value;

                        }

                    }

                    readingString = false;
                }
                else {
                    //string start

                    readingString = true;
                    readStringLength = 0;
                    value.reset();
                }
            }
            if (c == ':') {
                //thingy that identifies difference between key and value i think

                if (readingKey)
                {
                    readingKey = false;
                    readingValue = true;
                }
            }

            if (readingValue) {
                if (line.substr(readLineLength, 4) == "true")
                {
                    parsedKeyValues[key].type = JSONValue::JSONValueType::VAL_BOOL;
                    parsedKeyValues[key].value = true;
                }
                if (line.substr(readLineLength, 5) == "false")
                {
                    parsedKeyValues[key].type = JSONValue::JSONValueType::VAL_BOOL;
                    parsedKeyValues[key].value = false;
                }
                if (line.substr(readLineLength, 4) == "null")
                {
                    parsedKeyValues[key].type = JSONValue::JSONValueType::VAL_NULL;
                    parsedKeyValues[key].value = nullptr;
                }
            }

            if (c == ',') {
                //thingy that identifies when to move to a new key|value pair i believe so

                if (readingValue)
                {
                    readingKey = true;
                    readingValue = false;
                }

                key = "";
                value.reset();
            }

            if (c == '{') {
                //object start
            }
            if (c == '}') {
                //object end
            }
            if (c == '[') {
                //array start
            }
            if (c == ']') {
                //array end
            }


            if (readingString == true) {
                readStringLength++;
            }
        }
    }

}

bool JSONParser::Parse(std::string filePath)
{
    const std::string prefix = "jsons/";

    std::string fullPath = prefix + filePath;

    std::ifstream inputFile(fullPath);
    if (inputFile.is_open()) {
        std::string line;
        

        while (std::getline(inputFile, line)) {
            parsedJsonFull.push_back(line);
        }
        inputFile.close();
    }
    else {
        return 1;
    }

    detectThing();

    return 0;
}