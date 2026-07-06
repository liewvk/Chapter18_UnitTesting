#include "Utils.h"
#include <cctype>
#include <stdexcept>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
    {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    return a / b;
}

bool isEven(int number)
{
    return number % 2 == 0;
}

bool isPositive(int number)
{
    return number > 0;
}

std::string toUpperCase(const std::string& text)
{
    std::string result = text;

    for (char& ch : result)
    {
        ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    }

    return result;
}

bool isValidUsername(const std::string& username)
{
    if (username.length() < 3)
    {
        return false;
    }

    for (char ch : username)
    {
        if (!std::isalnum(static_cast<unsigned char>(ch)))
        {
            return false;
        }
    }

    return true;
}

