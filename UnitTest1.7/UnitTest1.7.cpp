#include "pch.h"
#include "CppUnitTest.h"
#include "../1.07/Account.h"
#include "../1.07/Account.cpp"
#include "../1.07/Date.h"
#include "../1.07/Date.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest17
{
	TEST_CLASS(UnitTest17)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Account a;
			Date d;
			d.Init("2024.05.05");
			a.Init("a", "123", d, 15, 12000);
			a.withdraw(10000);
			double result = 2000;
			Assert::AreEqual(result, a.getMoney());
		}
	};
}
