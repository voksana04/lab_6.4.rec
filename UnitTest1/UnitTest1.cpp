#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Project_6.4.rec\Project_6.4.rec\lab_6.4.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestSumNegativeElements)
        {
            double arr[] = { -3.0, 2.5, -1.5, 4.0, -2.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            double sumNeg = sumNegativeElements(arr, n);
            Assert::AreEqual(-6.5, sumNeg, 0.01); 
        }

        TEST_METHOD(TestFindMaxIndex)
        {
            double arr[] = { -3.0, 2.5, 1.5, 4.0, -2.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            int maxIndex = findMaxIndex(arr, n);
            Assert::AreEqual(3, maxIndex); 
        }

        TEST_METHOD(TestFindMinIndex)
        {
            double arr[] = { -3.0, 2.5, 1.5, 4.0, -2.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            int minIndex = findMinIndex(arr, n);
            Assert::AreEqual(0, minIndex); 
        }

        TEST_METHOD(TestProductBetweenMinMax)
        {
            double arr[] = { -3.0, 2.5, 1.5, 4.0, -2.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            int minIndex = findMinIndex(arr, n);
            int maxIndex = findMaxIndex(arr, n);
            if (minIndex > maxIndex) swap(minIndex, maxIndex);
            double product = productBetweenMinMax(arr, minIndex, maxIndex, minIndex + 1);
            Assert::AreEqual(3.75, product, 0.01); 
        }

        TEST_METHOD(TestSortEvenElements)
        {
            double arr[] = { 4.0, 3.5, 2.0, 1.0, 6.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            sortEvenElements(arr, n);
            double expectedArr[] = { 2.0, 3.5, 4.0, 1.0, 6.0 }; 
            for (int i = 0; i < n; i++) {
                Assert::AreEqual(expectedArr[i], arr[i]);
            }
        }
    };
}

