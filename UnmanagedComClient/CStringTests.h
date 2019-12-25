#pragma once
//Forward declaration of tlb generated interface
interface IStringTests;
class CStringTests
{
public:
	CStringTests();
	~CStringTests();

	//Attempt to run all of the tests below
	void RunAllTests();

	//Automatically called by RunAllTests.
	//To run specific tests this must be called.
	bool InitializeComPointer();
	void PassInBstr();
	void PassInLPStr();
	void PassInLPWStr();
	void PassInLPUTF8Str();
	void PassInBstrByRef();
	void PassInLPStrByRef();
	void PassInLPWStrByRef();
	void PassInLPUTF8StrByRef();
	void GetBstrFromComServer();
	void GetLPStrFromComServer();
	void GetLPWStrFromComServer();
	void GetLPUTF8StrFromComServer();
	void ReverseBstr();
	void ReverseLPStr();
	void ReverseLPWStr();
	void ReverseLPUTF8Str();


private:
	IStringTests* stringTests;
};

