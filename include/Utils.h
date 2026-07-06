#ifndef UTILS_H
#define UTILS_H

#include <string>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);

bool isEven(int number);
bool isPositive(int number);

std::string toUpperCase(const std::string& text);
bool isValidUsername(const std::string& username);

#endif
