//
// Created by lucaberto on 05/12/24.
//

#include "CellRange.h"

CellRange::CellRange() : startColumn(0), startRow(0), endColumn(0), endRow(0) {
}

void CellRange::setRange(const std::string &range) {
    std::size_t found = range.find(':');
    if (found == std::string::npos) {
        throw std::invalid_argument("Intervallo non valido");
    }

    std::string starCell = range.substr(0, found);
    std::string endCell = range.substr(found + 1);
    startColumn = columnToIndex(starCell[0]);
    startRow = std::stoi(starCell.substr(1)) - 1;
    endColumn = columnToIndex(endCell[0]);
    endRow = std::stoi(endCell.substr(1)) - 1;
}

int CellRange::columnToIndex(char column) {
    return column - 'A';
}
