// StringCalculator.cpp
#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::vector<int> parsedNumbers = parseNumbers(numbers);
    checkForNegatives(parsedNumbers);
    return sumNumbers(parsedNumbers);
}

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers) {
    std::string modifiedNumbers = numbers;
    std::replace(modifiedNumbers.begin(), modifiedNumbers.end(), '\n', ',');
    std::stringstream ss(modifiedNumbers);
    std::string item;
    std::vector<int> parsedNumbers;

    while (std::getline(ss, item, ',')) {
        if (!item.empty()) {
            parsedNumbers.push_back(std::stoi(item));
        }
    }

    return parsedNumbers;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(negatives), [](int number) {
        return number < 0;
    });

    if (!negatives.empty()) {
        throw std::runtime_error(buildErrorMessage(negatives));
    }
}

std::string StringCalculator::buildErrorMessage(const std::vector<int>& negatives) {
    std::string errorMessage = "negatives not allowed: ";
    for (size_t i = 0; i < negatives.size(); ++i) {
        errorMessage += std::to_string(negatives[i]);
        if (i < negatives.size() - 1) {
            errorMessage += ", ";
        }
    }
    return errorMessage;
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}
