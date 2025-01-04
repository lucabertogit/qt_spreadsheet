#include <QTest>
#include "../src/Model.h"
#include "../src/Controller.h"
#include "../src/View.h"

class TestGui : public QObject {
    Q_OBJECT
private slots:
    void testGui();
};

void TestGui::testGui() {
    Model *model = new Model;
    Controller *controller = new Controller(model);
    View *view = new View(model, controller);

    // cella A1
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "23");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("23"));

    // cella A2
    QTest::keyClick(view->viewport(), Qt::Key_Down);
    QTest::qWait(100);
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "74");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("74"));

    // cella B1
    QTest::keyClick(view->viewport(), Qt::Key_Right);
    QTest::qWait(100);
    QTest::keyClick(view->viewport(), Qt::Key_Up);
    QTest::qWait(100);
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "65");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("65"));

    // cella B2
    QTest::keyClick(view->viewport(), Qt::Key_Down);
    QTest::qWait(100);
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "24");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("24"));

    // cella A3
    QTest::keyClick(view->viewport(), Qt::Key_Down);
    QTest::qWait(100);
    QTest::keyClick(view->viewport(), Qt::Key_Left);
    QTest::qWait(100);
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=MAX(A1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("74"));

    delete view;
    delete controller;
    delete model;
}

QTEST_MAIN(TestGui)
#include "TestGui.moc"