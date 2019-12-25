// UnmanagedComClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



#include <Windows.h>
#include <iostream>
#include "CStringTests.h"

int main()
{
    HRESULT hr = ::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if(FAILED(hr))
    {
        std::cout << "Failed to initialize COM";
    }

    CStringTests stringTests;
    stringTests.RunAllTests();


    ::CoUninitialize();
    _CrtDumpMemoryLeaks();
}