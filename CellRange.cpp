//
// Created by lucaberto on 05/12/24.
//

#include "CellRange.h"

CellRange::CellRange() : startColumn(0), startRow(0), endColumn(0), endRow(0) {
}

void CellRange::setRange(const std::string &range) {
    if (range.empty())
        throw std::invalid_argument("Intervallo non valido");

    std::size_t found = range.find(':');
    if (found == std::string::npos) {
        throw std::invalid_argument("Intervallo non valido");
    }

    std::string startCell = range.substr(0, found);
    std::transform(startCell.begin(), startCell.end(), startCell.begin(), ::toupper);
    if (startCell.empty())
        throw std::invalid_argument("Intervallo non valido");

    std::string endCell = range.substr(found + 1);
    std::transform(endCell.begin(), endCell.end(), endCell.begin(), ::toupper);
    if (endCell.empty())
        throw std::invalid_argument("Intervallo non valido");

    startColumn = columnToIndex(startCell[0]);
    startRow = std::stoi(startCell.substr(1)) - 1;
    endColumn = columnToIndex(endCell[0]);
    endRow = std::stoi(endCell.substr(1)) - 1;
    sortRange();
}

int CellRange::columnToIndex(char column) {
    if (column < 'A' || column > 'Z')
        throw std::invalid_argument("Intervallo non valido");
    return column - 'A';
}

void CellRange::sortRange() {
    if (endColumn < startColumn) {
        int tmp = endColumn;
        endColumn = startColumn;
        startColumn = tmp;
    }
    if (endRow < startRow) {
        int tmp = endRow;
        endRow = startRow;
        startRow = tmp;
    }
}