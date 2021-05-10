#include "pch.h"
#include "CppUnitTest.h"
#include "../Project_opp_6.4/Array.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestopp64
{
	TEST_CLASS(UnitTestopp64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array<int> V(5);
			for (int i = 0; i < 5; i++)
				V[i] = 0;
			V[2] = -1;
			Assert::AreEqual(V.MyTask(), true);
		}
	};
}
