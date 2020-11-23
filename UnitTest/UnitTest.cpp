#include "pch.h"
#include "CppUnitTest.h"
#include "../Program/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(met_min_)
		{
			const int mass[5] = { 4, 1, 2, 3, 0 };
			Assert::AreEqual(min_(mass, 5), 4);
		}
	};
}
