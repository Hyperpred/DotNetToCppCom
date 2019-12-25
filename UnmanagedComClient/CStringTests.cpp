#include <Windows.h>
#include <iostream>
#include <tchar.h>
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
	if (stringTests) {
		stringTests->Release();
		stringTests = nullptr;
	}
}

void CStringTests::RunAllTests()
{
	if (!InitializeComPointer()) {
		return;
	}

	std::cout << "\nPassing a string to the COM Server \n";
	PassInBstr();
	PassInLPStr();
	PassInLPWStr();
	PassInLPUTF8Str();

	std::cout << "\nPassing a string by reference to the COM Server. Modifies the string. \n";
	PassInBstrByRef();
	PassInLPStrByRef();
	PassInLPWStrByRef();
	PassInLPUTF8StrByRef();

	std::cout << "\nGetting a string from the COM Server \n";
	GetBstrFromComServer();
	GetLPStrFromComServer();
	GetLPWStrFromComServer();
	GetLPUTF8StrFromComServer();

	std::cout << "\nPassing in a string to the COM server then getting its reversed result \n";
	ReverseBstr();
	ReverseLPStr();
	ReverseLPWStr();
	ReverseLPUTF8Str();
}

bool CStringTests::InitializeComPointer()
{

	if (!stringTests && FAILED(::CoCreateInstance(
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
	BSTR bStr = ::SysAllocString(L"Hello from the COM Client");
	if (FAILED(stringTests->PassInBstr(bStr))) {
		std::cout << "ComClient: Failed PassInBstr test \n";
	}

	::SysFreeString(bStr);
}

void CStringTests::PassInLPStr()
{
	std::string temp = "Hello from the COM Client";
	LPSTR lpstr = _strdup(temp.c_str());

	if (FAILED(stringTests->PassInLPStr(lpstr))) {
		std::cout << "ComClient: Failed PassInLPStr test \n";
	}

	free(lpstr);
}

void CStringTests::PassInLPWStr()
{
	std::wstring temp = L"Hello from the COM Client";
	LPWSTR lpwstr = _wcsdup(temp.c_str());
	if (FAILED(stringTests->PassInLPWStr(lpwstr))) {
		std::cout << "ComClient: Failed PassInLPWStr test '\n'";
	}

	free(lpwstr);
}

void CStringTests::PassInLPUTF8Str()
{
	std::string temp = "Hello from the COM Client";
	if (FAILED(stringTests->PassInLPUTF8Str(temp.c_str()))) {
		std::cout << "ComClient: Failed LPUTF8Str test '\n'";
	}
}

void CStringTests::PassInBstrByRef()
{
	BSTR bStr = ::SysAllocString(L"Hello from the COM Client");
	if (FAILED(stringTests->PassInByRefBstr(&bStr))) {
		std::cout << "ComClient: Failed PassInByRefBstr test \n";
	}

	std::wcout << "ComClient: Called PassInByRefBstr returned: " << bStr << '\n';
	::SysFreeString(bStr);
}

void CStringTests::PassInLPStrByRef()
{
	std::string temp = "Hello from the COM Client";
	size_t length = strlen(temp.c_str()) + 1;

	//We must use CoTaskMemAlloc in order for the COM server to modify an LPSTR
	LPSTR lpstr = static_cast<LPSTR>(::CoTaskMemAlloc(length));

	//Added to remove warning about ::CopyMemory
	if (lpstr) {
		::CopyMemory(lpstr, temp.c_str(), length);
	}

	if (FAILED(stringTests->PassInByRefLPStr(&lpstr))) {
		std::cout << "ComClient: Failed PassInByRefLPStr test \n";
	}

	std::cout << "ComClient: Called PassInByRefLPStr returned: " << lpstr << '\n';
	::CoTaskMemFree(lpstr);
}

void CStringTests::PassInLPWStrByRef()
{
	std::wstring temp = L"Hello from the COM Client";
	size_t length = wcslen(temp.c_str()) * 2 + 1;

	//We must use CoTaskMemAlloc in order for the COM server to modify an LPWSTR
	LPWSTR lpwstr = static_cast<LPWSTR>(::CoTaskMemAlloc(length));

	//Added to remove warning about ::CopyMemory
	if (lpwstr) {
		::CopyMemory(lpwstr, temp.c_str(), length);
	}

	if (FAILED(stringTests->PassInByRefLPWStr(&lpwstr))) {
		std::cout << "ComClient: Failed PassInByRefLPWStr test \n";
	}

	std::wcout << "ComClient: Called PassInByRefLPWStr returned: " << lpwstr << '\n';
	::CoTaskMemFree(lpwstr);
}

void CStringTests::PassInLPUTF8StrByRef()
{
	std::string temp = "Hello from the COM Client";
	size_t length = strlen(temp.c_str()) + 1;
	//We must use CoTaskMemAlloc in order for the COM server to modify an LPSTR
	LPSTR lpstr = static_cast<LPSTR>(::CoTaskMemAlloc(length));

	//Added to remove warning about ::CopyMemory
	if (lpstr) {
		::CopyMemory(lpstr, temp.c_str(), length);
	}

	if (FAILED(stringTests->PassInByRefLPUTF8Str(&lpstr))) {
		std::cout << "ComClient: Failed PassInByRefLPUTF8StrByRef test \n";
	}

	std::cout << "ComClient: Called PassInByRefLPUTF8StrByRef returned: " << lpstr << '\n';
	::CoTaskMemFree(lpstr);
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

void CStringTests::GetLPStrFromComServer()
{
	LPSTR lpstr;
	if (FAILED(stringTests->GetLPStrFromComServer(&lpstr))) {
		std::cout << "ComClient: Failed GetLPStrFromComServer '\n'";
		return;
	}

	std::cout << "ComClient: Called GetLPStrFromComServer returned: " << lpstr << '\n';
}

void CStringTests::GetLPWStrFromComServer()
{
	LPWSTR lpwstr;
	if (FAILED(stringTests->GetLPWStrFromComServer(&lpwstr))) {
		std::cout << "ComClient: Failed GetLPStrFromComServer '\n'";
		return;
	}

	std::wcout << "ComClient: Called GetLPWStrFromComServer returned: " << lpwstr << '\n';

}

void CStringTests::GetLPUTF8StrFromComServer()
{
	LPSTR lputf8str;
	if (FAILED(stringTests->GetLPUTF8StrFromComServer(&lputf8str))) {
		std::cout << "ComClient: Failed GetLPUTF8StrFromComServer '\n'";
		return;
	}

	std::cout << "ComClient: Called GetLPUTF8StrFromComServer returned: " << lputf8str << '\n';
}

void CStringTests::ReverseBstr()
{
	BSTR bStr = ::SysAllocString(L"Reverse this BSTR.");
	if (FAILED(stringTests->ReverseBstr(bStr, &bStr))) {
		std::wcout << "ComClient: ReverseBstr call failed. \n";
	}

	std::wcout << "ComClient: Called ReverseBstr returned: " << bStr << '\n';
	::SysFreeString(bStr);
}

void CStringTests::ReverseLPStr()
{
	std::string temp = "Reverse this LPSTR";
	LPSTR lpstr = _strdup(temp.c_str());
	LPSTR reversedLpstr;
	if (FAILED(stringTests->ReverseLPStr(lpstr, &reversedLpstr))) {
		std::cout << "ComClient: ReverseLPStr call failed. \n";
	}

	std::cout << "ComClient: Called ReverseLPStr returned: " << reversedLpstr << '\n';
	free(lpstr);
}

void CStringTests::ReverseLPWStr()
{
	std::wstring temp = L"Reverse this LPWSTR";
	LPWSTR lpwstr = _wcsdup(temp.c_str());
	LPWSTR reversedLpwstr;
	if (FAILED(stringTests->ReverseLPWStr(lpwstr, &reversedLpwstr))) {
		std::cout << "ComClient: ReverseLPStr call failed. \n";
	}

	std::wcout << "ComClient: Called ReverseLPStr returned: " << reversedLpwstr << '\n';
	free(lpwstr);
}

void CStringTests::ReverseLPUTF8Str()
{
	std::string temp = u8"Reverse this LPUTF8str";
	LPSTR lpstr = _strdup(temp.c_str());
	LPSTR reversedLpstr;
	if (FAILED(stringTests->ReverseLPUTF8Str(lpstr, &reversedLpstr))) {
		std::cout << "ComClient: ReverseLPUTF8str call failed. \n";
	}

	std::cout << "ComClient: Called ReverseLPUTF8str returned: " << reversedLpstr << '\n';
	free(lpstr);
}
