#include "MyCalculatorViewModel.h"

//////////////////////////////////////////////////////////////////////////////////////
MyCalculatorViewModel::MyCalculatorViewModel() :
    m_userInput( 0 ),
    m_myResult( 0 ),
    m_currentOperation( MyCalculator_Operation_None )
{
}

//////////////////////////////////////////////////////////////////////////////////////
int MyCalculatorViewModel::getUserInput()
{
    return m_userInput;
}

//////////////////////////////////////////////////////////////////////////////////////
void MyCalculatorViewModel::setUserInput( int userInput )
{
    m_userInput = userInput;
    emit userInputChanged();
}

//////////////////////////////////////////////////////////////////////////////////////
int MyCalculatorViewModel::getMyResult()
{
    return m_myResult;
}

//////////////////////////////////////////////////////////////////////////////////////
void MyCalculatorViewModel::setMyResult( int myResult )
{
    m_myResult = myResult;
    emit myResultChanged();
}

//////////////////////////////////////////////////////////////////////////////////////
int MyCalculatorViewModel::getOperation()
{
    return (int)m_currentOperation;
}

//////////////////////////////////////////////////////////////////////////////////////
int MyCalculatorViewModel::add( int A, int B)
{
    return A + B;
}

//////////////////////////////////////////////////////////////////////////////////////
int MyCalculatorViewModel::subtract( int A, int B)
{
    return A - B;
}

//////////////////////////////////////////////////////////////////////////////////////
void MyCalculatorViewModel::handleEquals()
{
    int result;

    if ( m_currentOperation == MyCalculator_Operation_Addition )
    {
        result = add( m_myResult, m_userInput );
    }
    else if ( m_currentOperation == MyCalculator_Operation_Subtration )
    {
        result = subtract( m_myResult, m_userInput );
    }
    else
    {
        result = m_userInput;
    }

    m_myResult = result;
    m_userInput = 0;
    m_currentOperation = MyCalculator_Operation_None;
    emit myResultChanged();
    emit userInputChanged();
}

//////////////////////////////////////////////////////////////////////////////////////
void MyCalculatorViewModel::handleAddition()
{
    int result;
    if ( m_currentOperation == MyCalculator_Operation_None )
    {
        result = m_userInput;
    }
    else
    {
        result = add( m_myResult, m_userInput );
    }

    m_myResult = result;
    m_userInput = 0;
    m_currentOperation = MyCalculator_Operation_Addition;
    emit myResultChanged();
    emit userInputChanged();
}

//////////////////////////////////////////////////////////////////////////////////////
void MyCalculatorViewModel::handleSubtraction()
{
    int result;
    if ( m_currentOperation == MyCalculator_Operation_None )
    {
        result = m_userInput;
    }
    else
    {
        result = subtract( m_myResult, m_userInput );
    }

    m_myResult = result;
    m_userInput = 0;
    m_currentOperation = MyCalculator_Operation_Subtration;
    emit myResultChanged();
    emit userInputChanged();
}

//////////////////////////////////////////////////////////////////////////////////////
void MyCalculatorViewModel::handelClear()
{
    m_myResult = 0;
    m_userInput = 0;
    m_currentOperation = MyCalculator_Operation_None;
    emit myResultChanged();
    emit userInputChanged();
}
