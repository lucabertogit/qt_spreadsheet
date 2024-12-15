//
// Created by lucaberto on 14/12/24.
//

#include "Controller.h"

Controller::Controller(Model *m) : model(m), prevItem(nullptr) {
}

Controller::~Controller() {
    if (!prevItem)
        delete prevItem;
}

void Controller::setPrevContent(const QModelIndex &index) {
    prevItem = model->itemFromIndex(index)->clone();
}
