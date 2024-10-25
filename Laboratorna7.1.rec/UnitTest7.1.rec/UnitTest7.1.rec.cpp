#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna7.1.rec/Laboratorna7.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71rec
{
	TEST_CLASS(UnitTest71rec)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int sum = 0;
            int count = 0;
            int** T = new int* [rowCount];

            for (int i = 0; i < rowCount; i++)
                T[i] = new int[colCount];

            T[0][0] = 5; T[0][1] = -2; T[0][2] = 8;
            T[1][0] = 7; T[1][1] = -4; T[1][2] = 3;
            T[2][0] = -6; T[2][1] = 1; T[2][2] = 4;

            Calc(T, rowCount, colCount, sum, count, 0, 0);

            Assert::AreEqual(0, sum);
            Assert::AreEqual(5, count);

            for (int i = 0; i < rowCount; i++)
                delete[] T[i];
            delete[] T;
        }
	};
}
