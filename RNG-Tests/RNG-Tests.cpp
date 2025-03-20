#include "pch.h"
#include "CppUnitTest.h"

extern "C" int RNG(int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RNGTests
{
	TEST_CLASS(RNGTests)
	{
	public:
		
		TEST_METHOD(WithinRange) {	// tests weather RNG function stays within 0 and maxVal for n number of uses
			int maxVal = 80;
			int minVal = 40;
			int n = 1000;
			bool inRange = true;
			for (int i = 0; i < n; i++) {
				int tmp = RNG(maxVal, minVal);
				if (tmp < minVal || maxVal < tmp)
					inRange = false;
			}
			Assert::IsTrue(inRange);
		}
		TEST_METHOD(MaxVal) {	// tests weather RNG function max value is within range
			int maxVal = 20;
			int minVal = 0;
			int n = 1000;	// 1000 attempts makes it more likely to roll the lowest possible number
			bool test = false;
			for (int i = 0; i < n; i++) {
				int tmp = RNG(maxVal, minVal);
				if (tmp == maxVal)
					test = true;
			}
			Assert::IsTrue(test);
		}
		TEST_METHOD(MinVal) {	// tests weather RNG function Min value is 1
			int maxVal = 20;
			int minVal = 5;
			int n = 1000;	// 1000 attempts makes it more likely to roll the lowest possible number
			bool test = false;
			for (int i = 0; i < n; i++) {
				int tmp = RNG(maxVal, minVal);
				if (tmp == minVal)
					test = true;
			}
			Assert::IsTrue(test);
		}
	};

	TEST_CLASS(CombatTests) {
		TEST_METHOD(Combatloop - 01) 
	};
}
