#pragma once
//Forward declaration of tlb generated interface
class IStringTests;
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
	void GetBstrFromComServer();
	void ReverseBstr();

private:
	IStringTests* stringTests;
};

