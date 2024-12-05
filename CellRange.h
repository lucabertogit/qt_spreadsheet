//
// Created by lucaberto on 05/12/24.
//

#ifndef CELLRANGE_H
#define CELLRANGE_H

#include <string>

struct CellRange {
    int startColumn;
    int startRow;
    int endColumn;
    int endRow;
};

inline int columnToIndex(char column) {
    return column - 'A';
}

inline CellRange convertRange(const std::string &range) {
    CellRange result;

    std::size_t found = range.find(':');
    if (found == std::string::npos) {
        throw std::invalid_argument("Intervallo non valido");
    }

    std::string starCell = range.substr(0, found);
    std::string endCell = range.substr(found + 1);
    result.startColumn = columnToIndex(starCell[0]);
    result.startRow = std::stoi(starCell.substr(1)) - 1;
    result.endColumn = columnToIndex(endCell[0]);
    result.endRow = std::stoi(endCell.substr(1)) - 1;
    return result;
}

#endif //CELLRANGE_H
