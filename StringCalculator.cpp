#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <vector>

int StringCalculator::add(std::string& numbers){
  if (numbers.empty()) {
        return 0;
    }

    std::stringstream ss(numbers);
    std::string item;
    int sum = 0;
    std::vector<int> negatives;
  
    while (std::getline(ss, item, ',')) {
        int number = std::stoi(item);
        if (number < 0) {
            negatives.push_back(number);
        } else {
            sum += number;
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
   

    return sum;
}
