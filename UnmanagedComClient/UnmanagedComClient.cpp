// UnmanagedComClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include "CStringTests.h"

int main()
{
    HRESULT hr = ::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if(FAILED(hr))
    {
        std::cout << "ComClient: Failed to initialize COM";
    }

    CStringTests stringTests;
    stringTests.RunAllTests();

    ::CoUninitialize();
}