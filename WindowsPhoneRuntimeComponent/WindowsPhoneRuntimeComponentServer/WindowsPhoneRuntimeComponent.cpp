// WindowsPhoneRuntimeComponent.cpp
#include "pch.h"
#include "WindowsPhoneRuntimeComponent.h"

using namespace WindowsPhoneRuntimeComponent;
using namespace Platform;

WindowsPhoneRuntimeComponentClass::WindowsPhoneRuntimeComponentClass()
{
}

int WindowsPhoneRuntimeComponentClass::SumOfTwoInteger(int numberOne, int numberTwo)
{
    return numberOne + numberTwo;
}

int WindowsPhoneRuntimeComponentClass::SubtractionOfTwoInteger(int numberOne, int numberTwo)
{
    return numberOne - numberTwo;
}
