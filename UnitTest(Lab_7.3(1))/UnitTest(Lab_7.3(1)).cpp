﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3(1)/Lab_7.3(1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab731
{
	TEST_CLASS(UnitTestLab731)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int const line = 3;
			int const column = 3;
			int** matriz = new int* [line];
			for (int index = 0; index < line; index++)
				matriz[index] = new int[column];
			matriz[0][0] = -9; matriz[0][1] = 1;matriz[0][2] = 2;matriz[1][0] = 3;matriz[1][1] = 4;matriz[1][2] = 5;matriz[2][0] = 6;matriz[2][1] = 7;matriz[2][2] = 8;
			int suma = matriz_sum(matriz, line, column);
			Assert::AreEqual(suma, -6);
			delete[] matriz;
		}
	};
}
