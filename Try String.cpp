#include <iostream>
#include <string>
#include <stdexcept>

std::string ConvertNumberToOtherFormat(const std::string& number);


int main() 
{
    std::string input_number;
    std::cout << "Enter a phone number in one of the following formats: +7(111)111-11-11 or 71111111111: ";
    std::cin >> input_number;

    try 
    {
        std::string new_number = ConvertNumberToOtherFormat(input_number);
        std::cout << "Converted number: " << new_number << std::endl;
    }
    catch (const std::string& error) 
    {
        std::cerr << "Error: " << error << std::endl;
    }

    return 0;
}

std::string ConvertNumberToOtherFormat(const std::string& number)
{
    if (number.size() == 16)
    {
        if (number[0] == '+' && number[1] == '7' && number[2] == '(' && number[6] == ')' && number[10] == '-' && number[13] == '-')
        {
            std::string new_number = number.substr(1, 1) + number.substr(3, 3) + number.substr(7, 3) + number.substr(11, 2) + number.substr(14, 2);
            return new_number;
        }
        else
            throw std::string("Invalid format, expected: +7(111)111-11-11");

    }
    else if (number.size() == 11)
    {
        std::string new_number = "+7 (" + number.substr(0, 3) + ") " + number.substr(3, 3) + "-" + number.substr(6, 2) + "-" + number.substr(8, 2);
        return new_number;
    }
    else
        throw std::string("Invalid number length, expected: +7(111)111-11-11 or 71111111111");

}
