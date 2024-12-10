//
// Created by lucaberto on 10/12/24.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <algorithm>

inline void toUpper(std::string &text) {
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
}

#endif //UTILITY_H
