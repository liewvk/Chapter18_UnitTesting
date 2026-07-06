#include <iostream>
#include <string>
#include <stdexcept>
#include "Utils.h"

struct TestStats
{
    int passed = 0;
    int failed = 0;
};

void check(bool condition, const std::string& testName, TestStats& stats)
{
    if (condition)
    {
        std::cout << "[PASS] " << testName << std::endl;
        stats.passed++;
    }
    else
    {
        std::cout << "[FAIL] " << testName << std::endl;
        stats.failed++;
    }
}

void testMathFunctions(TestStats& stats)
{
    check(add(2, 3) == 5, "add(2, 3) should return 5", stats);

    check(subtract(10, 4) == 6, "subtract(10, 4) should return 6", stats);

    check(multiply(3, 4) == 12, "multiply(3, 4) should return 12", stats);

    check(divide(10, 2) == 5.0, "divide(10, 2) should return 5.0", stats);
}

void testBooleanFunctions(TestStats& stats)
{
    check(isEven(8) == true, "isEven(8) should return true", stats);

    check(isEven(7) == false, "isEven(7) should return false", stats);

    check(isPositive(10) == true, "isPositive(10) should return true", stats);

    check(isPositive(-5) == false, "isPositive(-5) should return false", stats);

    check(isPositive(0) == false, "isPositive(0) should return false", stats);
}

void testStringFunctions(TestStats& stats)
{
    check(toUpperCase("hello") == "HELLO",
        "toUpperCase(\"hello\") should return \"HELLO\"", stats);

    check(toUpperCase("Cpp123") == "CPP123",
        "toUpperCase(\"Cpp123\") should return \"CPP123\"", stats);

    check(isValidUsername("alice123") == true,
        "isValidUsername(\"alice123\") should return true", stats);

    check(isValidUsername("ab") == false,
        "isValidUsername(\"ab\") should return false", stats);

    check(isValidUsername("john_doe") == false,
        "isValidUsername(\"john_doe\") should return false", stats);
}

void testDivisionByZero(TestStats& stats)
{
    bool exceptionThrown = false;

    try
    {
        divide(10, 0);
    }
    catch (const std::invalid_argument&)
    {
        exceptionThrown = true;
    }

    check(exceptionThrown == true,
        "divide(10, 0) should throw invalid_argument", stats);
}

void displayTestSummary(const TestStats& stats)
{
    int total = stats.passed + stats.failed;

    std::cout << std::endl;
    std::cout << "========== Test Summary ==========" << std::endl;
    std::cout << "Tests passed: " << stats.passed << std::endl;
    std::cout << "Tests failed: " << stats.failed << std::endl;
    std::cout << "Total tests : " << total << std::endl;

    if (stats.failed == 0)
    {
        std::cout << "Result      : All tests passed." << std::endl;
    }
    else
    {
        std::cout << "Result      : Some tests failed." << std::endl;
    }
}

int main()
{
    TestStats stats;

    std::cout << "========== Running Unit Tests ==========" << std::endl;
    std::cout << std::endl;

    testMathFunctions(stats);
    testBooleanFunctions(stats);
    testStringFunctions(stats);
    testDivisionByZero(stats);

    displayTestSummary(stats);

    return stats.failed == 0 ? 0 : 1;
}
