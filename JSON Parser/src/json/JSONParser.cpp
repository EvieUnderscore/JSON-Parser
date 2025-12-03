#include "JSONParser.h"

JSONParser::JSONParser()
{

}

void detectThing(std::vector<std::string> json) {
    for (int i = 1; i < json.size(); i++)
    {
        //loop through lines
        std::string line = json[i - 1];
        
        //iterator bools
        bool readingString = false;

        for (int j = 0; j < line.size(); j++)
        {
            //loop through characters
            std::string letter = line.substr(j);

           
            if (letter == "{") {
                std::cout << "object start (line " << i << " char " << j << ")" << std::endl;
            }
            if (letter == "}") {
                std::cout << "object end (line " << i << " char " << j << ")" << std::endl;
            }
            if (letter == "[") {
                std::cout << "array start (line " << i << " char " << j << ")" << std::endl;
            }
            if (letter == "]") {
                std::cout << "array end (line " << i << " char " << j << ")" << std::endl;
            }
            if (letter == "\"") {
                if (readingString == false)
                {
                    std::cout << "string start (line " << i << " char " << j << ")" << std::endl;
                    readingString = true;
                }
                else
                {
                    std::cout << "string end (line " << i << " char " << j << ")" << std::endl;
                    readingString = false;
                }
            }

        }

        //std::cout << line << std::endl;
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

    detectThing(parsedJsonFull);

    return 0;
}