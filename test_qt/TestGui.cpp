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

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=MIN(A1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("23"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=MEAN(A1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("46.5"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM(A1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("186"));

    // modifica cella A2
    QTest::keyClick(view->viewport(), Qt::Key_Up);
    QTest::qWait(100);
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "2");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("2"));
    QTest::keyClick(view->viewport(), Qt::Key_Down);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("114"));

    // modifica cella A2
    QTest::keyClick(view->viewport(), Qt::Key_Up);
    QTest::qWait(100);
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "string");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("string"));
    QTest::keyClick(view->viewport(), Qt::Key_Down);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("112"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=max(a1:b2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("65"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(b2:a1)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("112"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=max(a1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("65"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum()");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1;B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1:)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(?1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1:!2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1;B2:C2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1:B2:C2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=15");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=(15");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=15)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=(15)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM15");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM(15");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM(15)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=A1:B2");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=(A1:B2");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=A1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=(A1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM(A1:B2");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUMA1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=15]");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=[15]");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM15");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM[15");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM15]");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM[15]");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=[A1:B2");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=A1:B2]");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=[A1:B2]");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUMA1:B2");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM[A1:B2");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUMA1:B2]");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM[A1:B2]");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM((A1:B2");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUMA1:B2))");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=SUM((A1:B2))");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("112"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=max((A1:B2)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("65"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1:B2))");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("112"));

    // modifica formula cella A3
    QTest::mouseClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::mouseDClick(view->viewport(), Qt::LeftButton, Qt::NoModifier, view->visualRect(view->currentIndex()).center());
    QTest::qWait(100);
    QTest::keyClicks(view->viewport()->focusWidget(), "=sum(A1:A4)");
    QTest::qWait(100);
    QTest::keyClick(view->viewport()->focusWidget(), Qt::Key_Enter);
    QTest::qWait(100);
    QCOMPARE(model->itemFromIndex(view->currentIndex())->text(), QString("#NOME?"));

    delete view;
    delete controller;
    delete model;
}

QTEST_MAIN(TestGui)
#include "TestGui.moc"