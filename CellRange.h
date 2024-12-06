//
// Created by lucaberto on 05/12/24.
//

#ifndef CELLRANGE_H
#define CELLRANGE_H

#include <string>
#include <algorithm>
#include <stdexcept>

class CellRange {
public:
    CellRange();

    void setRange(const std::string &range);

    int getStartColumn() const {
        return startColumn;
    }

    void setStartColumn(int startColumn) {
        this->startColumn = startColumn;
    }

    int getStartRow() const {
        return startRow;
    }

    void setStartRow(int startRow) {
        this->startRow = startRow;
    }

    int getEndColumn() const {
        return endColumn;
    }

    void setEndColumn(int endColumn) {
        this->endColumn = endColumn;
    }

    int getEndRow() const {
        return endRow;
    }

    void setEndRow(int endRow) {
        this->endRow = endRow;
    }

private:
    int startColumn;
    int startRow;
    int endColumn;
    int endRow;

    int columnToIndex(char column);

    void sortRange();
};

#endif //CELLRANGE_H
