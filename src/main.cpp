#include <iostream>
#include "Utils.h"

int main()
{
    std::cout << "========== Utility Function Demo ==========" << std::endl;

    std::cout << "add(2, 3) = " << add(2, 3) << std::endl;
    std::cout << "subtract(10, 4) = " << subtract(10, 4) << std::endl;
    std::cout << "multiply(3, 4) = " << multiply(3, 4) << std::endl;

    try
    {
        std::cout << "divide(10, 2) = " << divide(10, 2) << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    std::cout << "isEven(8) = " << (isEven(8) ? "true" : "false") << std::endl;
    std::cout << "isPositive(-5) = " << (isPositive(-5) ? "true" : "false") << std::endl;
    std::cout << "toUpperCase(\"hello\") = " << toUpperCase("hello") << std::endl;
    std::cout << "isValidUsername(\"alice123\") = "
        << (isValidUsername("alice123") ? "true" : "false")
        << std::endl;

    return 0;
}
