#include "MyModel.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MyModel::MyModel() :
    m_value("Hello World")
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString MyModel::getValue()
{
    return m_value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyModel::setValue( QString value )
{
    // This if statement prevents a runtime binding loop warning from occuring
    //           qrc:///main.qml:92:17: QML TextInput: Binding loop detected for property "text"
    // The issue is when we emit the valueChanged() signal we can cause a recursive loop on the text property
    // of the TextInput element which is bi-directionally binded.
    //
    // first the view model gets updated which emits the valueChanged() signal causing the TextInput element
    // to update, then the Binding element which createds the return binding between the ViewModel and TextInput
    // element gets triggered becasue the TextInput element's text property just updated which causes the
    // WRITE method (setValue() ) to be called on the myValue property which again emits the valueChanged()
    // signal... rinse, wash, repeat -- binding loop detected warning.

    if ( m_value != value )
    {
        m_value = value;
        emit valueChanged();
    }

    // Comment out the above and uncomment out the below to get the binding loop error
//    m_value = value;
//    emit valueChanged();
}


