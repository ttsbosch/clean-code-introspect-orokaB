#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
int StringCalculator::add(std::string& numbers){
  if (numbers.empty()) {
        return 0;
    }

    std::stringstream ss(numbers);
    std::string item;
    int sum = 0;

    while (std::getline(ss, item, ',')) {
        sum += std::stoi(item);
    }

    return sum;
}
