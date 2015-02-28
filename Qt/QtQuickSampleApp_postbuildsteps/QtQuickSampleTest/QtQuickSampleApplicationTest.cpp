#include "QtQuickSampleApplicationTest.h"
#include <QtTest/QTest>
#include <QSignalSpy>
#include "MyCalculatorViewModel.h"
#include "MyCalculatorViewModelTest.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QtQuickSampleApplicationTest::QtQuickSampleApplicationTest(QObject *parent) :
    QObject(parent)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelUserInputDefaultValuesTest()
{
    // Setup the test
    MyCalculatorViewModel model;

    // Test
    QVERIFY2( model.getUserInput() == 0, "Expect the user input to be zero by default");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelGetUserInputTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QCOMPARE( model.getUserInput(), 0 ); //Expect the user input to be zero by default
    int expect( 100 );
    model.injectUserInput( expect );

    // Test
    int actual = model.getUserInput();

    QVERIFY2( actual == expect,
              QString("Expect the user input to be [%1] but actually got [%2] instead.").arg(expect).arg(actual).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelSetUserInputTest()
{
    // Setup the test
    MyCalculatorViewModel model;
    QSignalSpy spy( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spy.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( model.getUserInput(), 0 ); //Expect the user input to be zero by default

    // TEST
    int expect( 100 );
    model.setUserInput( expect );

    QVERIFY2( spy.count() == 1,
              QString( "Expecting the userInputChanged() signal to have be emitted. actual [%1], expected [%2]").arg(spy.count()).arg(1).toStdString().c_str() );

    int actual = model.getUserInput();
    QVERIFY2( actual == expect,
              QString("Expect the user input to be [%1] but actually got [%2] instead.").arg(expect).arg(actual).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelMyResultDefaultValuesTest()
{
    // Setup the test
    MyCalculatorViewModel model;

    // Test
    QVERIFY2( model.getMyResult() == 0, "Expect the result value to be zero by default");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelGetMyResultTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QCOMPARE( model.getMyResult(), 0 ); //Expect the result value to be zero by default
    int expect( 100 );
    model.injectMyResult( expect );

    // Test
    int actual = model.getMyResult();
    QVERIFY2( actual == expect,
              QString("Expect the result value to be [%1] but actually got [%2] instead.").arg(expect).arg(actual).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelSetMyResultTest()
{
    // Setup the test
    MyCalculatorViewModel model;
    QSignalSpy spy( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QCOMPARE( spy.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( model.getMyResult(), 0 ); //Expect the result value to be zero by default

    // Test
    int expect( 100 );
    model.setMyResult( expect );
    QVERIFY2( spy.count() == 1,
              QString( "Expecting the myResultChanged() signal to have be emitted. actual [%1], expected [%2]").arg(spy.count()).arg(1).toStdString().c_str() );

    int actual = model.getMyResult();
    QVERIFY2( actual == expect,
              QString("Expect the result value to be [%1] but actually got [%2] instead.").arg(expect).arg(actual).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelOperationDefaultValuesTest()
{
    // Setup the test
    MyCalculatorViewModel model;

    // Test
    QVERIFY2( model.getOperation() == 0, "Expect the operation to be 'None' by default");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelOperationTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;

    QCOMPARE( model.getOperation(), 0 ); //Expect the operation to be 'None' by default
    MyCalculatorViewModel::MyCalculator_Operation expect( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Addition );
    model.injectOperation( expect );

    // Test - we're actually testing both the set and get method here, not as isolated as I would like but ok for what it is.
    int actual = model.getOperation();

    QVERIFY2( actual == (int)expect,
              QString("Expect the result value to be [%1] but actually got [%2] instead.").arg(expect).arg(actual).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelAddTest()
{
    MyCalculatorViewModelTest model;

    int actual;
    actual = model.addTest( 0, 0);
    QVERIFY2( actual == 0,
              QString("Expect 0 + 0 = 0 but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.addTest( 10, 10);
    QVERIFY2( actual == 20,
              QString("Expect 10 + 10 = 20 but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.addTest( 10, -5);
    QVERIFY2( actual == 5,
              QString("Expect 10 + (-5) = 5 but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.addTest( -10, 5);
    QVERIFY2( actual == -5,
              QString("Expect (-10) + 5 = -5 but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.addTest( -10, -5);
    QVERIFY2( actual == -15,
              QString("Expect (-10) + (-5) = -15 but got [%1] instead.").arg(actual).toStdString().c_str());

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelSubtractTest()
{
    MyCalculatorViewModelTest model;

    int actual;
    actual = model.subtractTest(0, 0);
    QVERIFY2( actual == 0,
              QString("Expect 0 - 0 = 0 but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.subtractTest( 10, 10);
    QVERIFY2( actual == 0,
              QString("Expect 10 - 10 = 0 but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.subtractTest( 10, 5);
    QVERIFY2( actual == 5,
              QString("Expect 10 - 5 = 5 but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.subtractTest( 10, -5);
    QVERIFY2( actual == 15,
              QString("Expect 10 - (-5) = 15 but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.subtractTest( -10, 5);
    QVERIFY2( actual == -15,
              QString("Expect (-10) - 5 = (-15) but got [%1] instead.").arg(actual).toStdString().c_str());

    actual = model.subtractTest( -10, -5);
    QVERIFY2( actual == -5,
              QString("Expect (-10) - (-5) = -5 but got [%1] instead.").arg(actual).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelHandleClearTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QSignalSpy spyResult( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QSignalSpy spyInput( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spyResult.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( spyInput.count(), 0 ); // Expect the signal to have not been thrown yet.

    model.injectUserInput( 100 );
    model.injectMyResult( 200 );
    model.injectOperation( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Addition);

    // TEST
    model.handelClear();

    int actualUserInput = model.getUserInput();
    int actualResult = model.getMyResult();
    int actualOperation = model.getOperation();

    QVERIFY2( actualUserInput == 0,
              QString("UserInput: Expect [0] but got [%1] instead.").arg(actualUserInput).toStdString().c_str());
    QVERIFY2( actualResult == 0,
              QString("MyResult: Expect [0] but got [%1] instead.").arg(actualResult).toStdString().c_str());
    QVERIFY2( actualOperation == (int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None,
              QString("Operation: Expect [%1] but got [%2] instead.").arg((int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None).arg(actualOperation).toStdString().c_str());
    QVERIFY2( spyResult.count() == 1,
              QString("Expected the myResultChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyResult.count()).toStdString().c_str());
    QVERIFY2( spyInput.count() == 1,
              QString("Expected the userInputChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyInput.count()).toStdString().c_str());


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelHandleSubtractionNoOperatorTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QSignalSpy spyResult( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QSignalSpy spyInput( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spyResult.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( spyInput.count(), 0 ); // Expect the signal to have not been thrown yet.

    int expectedResult( 100 );
    model.injectUserInput( expectedResult );
    model.injectMyResult( 200 );
    model.injectOperation( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None);

    // TEST
    model.handleSubtraction();

    int actualUserInput = model.getUserInput();
    int actualResult = model.getMyResult();
    int actualOperation = model.getOperation();

    QVERIFY2( actualUserInput == 0,
              QString("UserInput: Expect [0] but got [%1] instead.").arg(actualUserInput).toStdString().c_str());
    QVERIFY2( actualResult == expectedResult,
              QString("MyResult: Expect [%1] but got [%2] instead.").arg(expectedResult).arg(actualResult).toStdString().c_str());
    QVERIFY2( actualOperation == (int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Subtration,
              QString("Operation: Expect [%1] but got [%2] instead.").arg((int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Subtration).arg(actualOperation).toStdString().c_str());
    QVERIFY2( spyResult.count() == 1,
              QString("Expected the myResultChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyResult.count()).toStdString().c_str());
    QVERIFY2( spyInput.count() == 1,
              QString("Expected the userInputChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyInput.count()).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelHandleSubtractionSubtractOperatorTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QSignalSpy spyResult( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QSignalSpy spyInput( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spyResult.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( spyInput.count(), 0 ); // Expect the signal to have not been thrown yet.

    int expectedResult( 200 );
    model.injectUserInput( 100 );
    model.injectMyResult( 300 );
    model.injectOperation( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Subtration);

    // TEST
    model.handleSubtraction();

    int actualUserInput = model.getUserInput();
    int actualResult = model.getMyResult();
    int actualOperation = model.getOperation();

    QVERIFY2( actualUserInput == 0,
              QString("UserInput: Expect [0] but got [%1] instead.").arg(actualUserInput).toStdString().c_str());
    QVERIFY2( actualResult == expectedResult,
              QString("MyResult: Expect [%1] but got [%2] instead.").arg(expectedResult).arg(actualResult).toStdString().c_str());
    QVERIFY2( actualOperation == (int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Subtration,
              QString("Operation: Expect [%1] but got [%2] instead.").arg((int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Subtration).arg(actualOperation).toStdString().c_str());
    QVERIFY2( spyResult.count() == 1,
              QString("Expected the myResultChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyResult.count()).toStdString().c_str());
    QVERIFY2( spyInput.count() == 1,
              QString("Expected the userInputChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyInput.count()).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelHandleAdditionNoOperatorTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QSignalSpy spyResult( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QSignalSpy spyInput( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spyResult.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( spyInput.count(), 0 ); // Expect the signal to have not been thrown yet.

    int expectedResult( 100 );
    model.injectUserInput( expectedResult );
    model.injectMyResult( 200 );
    model.injectOperation( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None);

    // TEST
    model.handleAddition();

    int actualUserInput = model.getUserInput();
    int actualResult = model.getMyResult();
    int actualOperation = model.getOperation();

    QVERIFY2( actualUserInput == 0,
              QString("UserInput: Expect [0] but got [%1] instead.").arg(actualUserInput).toStdString().c_str());
    QVERIFY2( actualResult == expectedResult,
              QString("MyResult: Expect [%1] but got [%2] instead.").arg(expectedResult).arg(actualResult).toStdString().c_str());
    QVERIFY2( actualOperation == (int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Addition,
              QString("Operation: Expect [%1] but got [%2] instead.").arg((int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Addition).arg(actualOperation).toStdString().c_str());
    QVERIFY2( spyResult.count() == 1,
              QString("Expected the myResultChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyResult.count()).toStdString().c_str());
    QVERIFY2( spyInput.count() == 1,
              QString("Expected the userInputChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyInput.count()).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelHandleAdditionOperatorTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QSignalSpy spyResult( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QSignalSpy spyInput( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spyResult.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( spyInput.count(), 0 ); // Expect the signal to have not been thrown yet.

    int expectedResult( 400 );
    model.injectUserInput( 100 );
    model.injectMyResult( 300 );
    model.injectOperation( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Addition);

    // TEST
    model.handleAddition();

    int actualUserInput = model.getUserInput();
    int actualResult = model.getMyResult();
    int actualOperation = model.getOperation();

    QVERIFY2( actualUserInput == 0,
              QString("UserInput: Expect [0] but got [%1] instead.").arg(actualUserInput).toStdString().c_str());
    QVERIFY2( actualResult == expectedResult,
              QString("MyResult: Expect [%1] but got [%2] instead.").arg(expectedResult).arg(actualResult).toStdString().c_str());
    QVERIFY2( actualOperation == (int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Addition,
              QString("Operation: Expect [%1] but got [%2] instead.").arg((int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Addition).arg(actualOperation).toStdString().c_str());
    QVERIFY2( spyResult.count() == 1,
              QString("Expected the myResultChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyResult.count()).toStdString().c_str());
    QVERIFY2( spyInput.count() == 1,
              QString("Expected the userInputChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyInput.count()).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelHandleEqualsNoOperatorTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QSignalSpy spyResult( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QSignalSpy spyInput( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spyResult.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( spyInput.count(), 0 ); // Expect the signal to have not been thrown yet.

    int expectedResult( 100 );
    model.injectUserInput( expectedResult );
    model.injectMyResult( 200 );
    model.injectOperation( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None);

    // TEST
    model.handleEquals();

    int actualUserInput = model.getUserInput();
    int actualResult = model.getMyResult();
    int actualOperation = model.getOperation();

    QVERIFY2( actualUserInput == 0,
              QString("UserInput: Expect [0] but got [%1] instead.").arg(actualUserInput).toStdString().c_str());
    QVERIFY2( actualResult == expectedResult,
              QString("MyResult: Expect [%1] but got [%2] instead.").arg(expectedResult).arg(actualResult).toStdString().c_str());
    QVERIFY2( actualOperation == (int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None,
              QString("Operation: Expect [%1] but got [%2] instead.").arg((int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None).arg(actualOperation).toStdString().c_str());
    QVERIFY2( spyResult.count() == 1,
              QString("Expected the myResultChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyResult.count()).toStdString().c_str());
    QVERIFY2( spyInput.count() == 1,
              QString("Expected the userInputChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyInput.count()).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelHandleEqualsAdditionOperatorTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QSignalSpy spyResult( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QSignalSpy spyInput( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spyResult.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( spyInput.count(), 0 ); // Expect the signal to have not been thrown yet.

    int expectedResult( 400 );
    model.injectUserInput( 100 );
    model.injectMyResult( 300 );
    model.injectOperation( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Addition);

    // TEST
    model.handleEquals();

    int actualUserInput = model.getUserInput();
    int actualResult = model.getMyResult();
    int actualOperation = model.getOperation();

    QVERIFY2( actualUserInput == 0,
              QString("UserInput: Expect [0] but got [%1] instead.").arg(actualUserInput).toStdString().c_str());
    QVERIFY2( actualResult == expectedResult,
              QString("MyResult: Expect [%1] but got [%2] instead.").arg(expectedResult).arg(actualResult).toStdString().c_str());
    QVERIFY2( actualOperation == (int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None,
              QString("Operation: Expect [%1] but got [%2] instead.").arg((int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None).arg(actualOperation).toStdString().c_str());
    QVERIFY2( spyResult.count() == 1,
              QString("Expected the myResultChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyResult.count()).toStdString().c_str());
    QVERIFY2( spyInput.count() == 1,
              QString("Expected the userInputChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyInput.count()).toStdString().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void QtQuickSampleApplicationTest::myCalculatorViewModelHandleEqualsSubtractionOperatorTest()
{
    // Setup the test
    MyCalculatorViewModelTest model;
    QSignalSpy spyResult( &model, SIGNAL(myResultChanged()) ); // monitor for the myResultChanged() signal
    QSignalSpy spyInput( &model, SIGNAL(userInputChanged()) ); // monitor for the userInputChanged() signal

    QCOMPARE( spyResult.count(), 0 ); // Expect the signal to have not been thrown yet.
    QCOMPARE( spyInput.count(), 0 ); // Expect the signal to have not been thrown yet.

    int expectedResult( 200 );
    model.injectUserInput( 100 );
    model.injectMyResult( 300 );
    model.injectOperation( MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_Subtration);

    // TEST
    model.handleEquals();

    int actualUserInput = model.getUserInput();
    int actualResult = model.getMyResult();
    int actualOperation = model.getOperation();

    QVERIFY2( actualUserInput == 0,
              QString("UserInput: Expect [0] but got [%1] instead.").arg(actualUserInput).toStdString().c_str());
    QVERIFY2( actualResult == expectedResult,
              QString("MyResult: Expect [%1] but got [%2] instead.").arg(expectedResult).arg(actualResult).toStdString().c_str());
    QVERIFY2( actualOperation == (int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None,
              QString("Operation: Expect [%1] but got [%2] instead.").arg((int)MyCalculatorViewModel::MyCalculator_Operation::MyCalculator_Operation_None).arg(actualOperation).toStdString().c_str());
    QVERIFY2( spyResult.count() == 1,
              QString("Expected the myResultChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyResult.count()).toStdString().c_str());
    QVERIFY2( spyInput.count() == 1,
              QString("Expected the userInputChanged() signal to have been fired: Expect [1] but got [%1] instead.").arg(spyInput.count()).toStdString().c_str());
}
