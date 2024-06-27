// StringCalculator.cpp
#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::vector<int> parsedNumbers = parseNumbers(numbers);
    checkForNegatives(parsedNumbers);
    return sumNumbers(parsedNumbers);
}

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers) {
    std::stringstream ss(numbers);
    std::string item;
    std::vector<int> parsedNumbers;

    while (std::getline(ss, item, ',')) {
        parsedNumbers.push_back(std::stoi(item));
    }

    return parsedNumbers;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int number : numbers) {
        if (number < 0) {
            negatives.push_back(number);
        }
    }

    if (!negatives.empty()) {
        std::string errorMessage = "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            errorMessage += std::to_string(negatives[i]);
            if (i < negatives.size() - 1) {
                errorMessage += ", ";
            }
        }
        throw std::runtime_error(errorMessage);
    }
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}
