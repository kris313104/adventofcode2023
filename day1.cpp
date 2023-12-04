#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <map>

int solve1(const std::string &input);
int solve2(const std::string &input);

int main(int argc, char const *argv[])
{
    std::cout << solve2("input/day1.txt") << std::endl;
    return 0;
}

int solve1(const std::string& fileName)
{
    int result = 0;
    std::string resultString;
    
    std::ifstream file(fileName);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            for (unsigned char character : line)
            {
                if (isdigit(character))
                {
                    resultString += character;
                    break;
                }
            }

            for (int i = line.length() - 1; i >= 0; i--)
            {
                unsigned char character = line[i];
                if (isdigit(character))
                {
                    resultString += character;
                    break;
                }
            }
            // int temp = std::stoi(resultString);
            result += std::stoi(resultString);
            resultString.clear();
        }

        file.close();
    }
    else
    {
        std::cerr << "Could not open file" << std::endl;
    }
    
    return result;
}


int solve2(const std::string& fileName)
{
    int result = 0;
    // std::string resultString;
    
    std::ifstream file(fileName);
    std::array<std::string, 9> stringDigits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    

    if (file.is_open())
    {
        
        std::string line;
        while (std::getline(file, line))
        {
            size_t frontDigitPosition = std::string::npos;
            size_t backDigitPosition = 0;
            int frontDigit = 0;
            int backDigit = 0;
            for (int i = 0; i < line.size(); i++) 
            {
                if (isdigit(line[i]))
                {
                    frontDigitPosition = i;
                    frontDigit = line[i] - '0';
                    break;
                }
            }

            for (int i = line.size(); i >= 0; --i)
            {
                if (isdigit(line[i]))
                {
                    backDigitPosition = i;
                    backDigit = line[i] - '0';
                    break;
                }
            }

            for (int i = 0; i < stringDigits.size(); i++) 
            {
                size_t tempFrontPos = line.find(stringDigits[i]);
                size_t tempBackPos = line.rfind(stringDigits[i]);

                if (tempFrontPos <= frontDigitPosition)
                {
                    frontDigitPosition = tempFrontPos;
                    frontDigit = i + 1;
                }

                if (tempBackPos >= backDigitPosition && tempBackPos != std::string::npos)
                {
                    backDigitPosition = tempBackPos;
                    backDigit = i + 1;
                }
            }
            
            result += (frontDigit * 10 + backDigit);
            std::cout << line << " -> " << frontDigit << backDigit << " -> " << result << std::endl;

        }

        file.close();
    }
    else
    {
        std::cerr << "Could not open file" << std::endl;
    }
    
    return result;
}