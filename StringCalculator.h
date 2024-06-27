// StringCalculator.h
#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::vector<int> parseNumbers(const std::string& numbers);
    void checkForNegatives(const std::vector<int>& numbers);
    int sumNumbers(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H
