#include <Windows.h>
#include <iostream>
#include "CStringTests.h"

//These files are built by the midl.exe command in 
//the pre-build step
#include "ComServer.h"
#include "ComServer_i.c"

CStringTests::CStringTests() : stringTests(nullptr)
{	
}

CStringTests::~CStringTests()
{
	stringTests->Release();
}

void CStringTests::RunAllTests()
{
	if (!InitializeComPointer()) {
		return;
	}

	PassInBstr();
	GetBstrFromComServer();
	ReverseBstr();
}

bool CStringTests::InitializeComPointer()
{
	
	if(!stringTests && FAILED(::CoCreateInstance(
		CLSID_StringTests,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IStringTests,
		reinterpret_cast<LPVOID*>(&stringTests))))
	{
		std::cout << "ComClient: Failed to create instance for IStringTests \n";
		return false;
	}

	return true;
}

void CStringTests::PassInBstr()
{
	auto bStr = ::SysAllocString(L"Hello from the COM Client");
	if (FAILED(stringTests->PassInBstr(bStr))) {
		std::cout << "ComClient: Failed PassInBstr test \n";
	}

	::SysFreeString(bStr);
}

void CStringTests::GetBstrFromComServer()
{
	BSTR bStr;
	if (FAILED(stringTests->GetBstrFromComServer(&bStr))) {
		std::cout << "ComClient: Failed GetBstrFromComServer \n";
		return;
	}

	std::wcout << "ComClient: Called GetBstrFromComServer returned: " << bStr << '\n';
}

void CStringTests::ReverseBstr()
{
	auto bStr = ::SysAllocString(L"Reverse this string.");
	std::wcout << "ComClient: Calling ReverseBstr with " << bStr << "\n";
	if (FAILED(stringTests->ReverseBstr(bStr, &bStr))) {
		std::wcout << "ComClient: ReverseBstr call failed. \n";
	}

	std::wcout << "ComClient: Called ReverseBstr returned: " << bStr << '\n';
}
