#include <QtWidgets/QApplication>
#include "src/MainWindow.h"
#include "src/View.h"
#include "src/Model.h"
#include "src/Controller.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);

    Model model(10, 10);
    Controller controller(&model);
    View view(&model, &controller);
    MainWindow window(&view);


    window.show();

    return a.exec();
}