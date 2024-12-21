#include <QtWidgets/QApplication>
#include "src/MainWindow.h"
#include "src/View.h"
#include "src/Model.h"
#include "src/Controller.h"

// TODO: migliorare gestione eccezioni anche creandone alcune specifiche
// TODO: il controller non deve impostare la view, ev. la view puo' richiamare direttamente il model
// TODO: cambiare nome variabile indexes in range
int main(int argc, char **argv) {
    QApplication a(argc, argv);

    Model model;
    Controller controller(&model);
    View view(&model, &controller);
    MainWindow window(&view);

    window.show();

    return a.exec();
}