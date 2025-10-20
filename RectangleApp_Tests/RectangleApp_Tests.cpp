#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
    // Function declarations
    int getPerimeter(int* length, int* width);
    int getArea(int* length, int* width);
    void setLength(int input, int* length);
    void setWidth(int input, int* width);

    // Function implementations
    int getPerimeter(int* length, int* width) {
        int perimeter = 2 * (*length + *width);
        return perimeter;
    }

    int getArea(int* length, int* width) {
        int area = *length * *width;
        return area;
    }

    void setLength(int input, int* length) {
        if (input >= 0 && input < 100) {
            *length = input;
        }
    }

    void setWidth(int input, int* width) {
        if (input > 0 && input <= 100) {
            *width = input;
        }
    }
}

namespace RectangleTests
{
    TEST_CLASS(RectangleUnitTests)
    {
    public:

        // ========== TASK 1 ==========

        TEST_METHOD(getPerimeter_Length5Width10_Returns30)
        {
            int length = 5;
            int width = 10;
            int expected = 30;

            int actual = getPerimeter(&length, &width);

            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(getArea_Length6Width8_Returns48)
        {
            int length = 6;
            int width = 8;
            int expected = 48;

            int actual = getArea(&length, &width);

            Assert::AreEqual(expected, actual);
        }

        // ========== TASK 2: setLength ==========

        TEST_METHOD(setLength_Input50_SetsLengthTo50)
        {
            int input = 50;
            int length = 0;

            setLength(input, &length);

            Assert::AreEqual(50, length);
        }

        TEST_METHOD(setLength_Input1_SetsLengthTo1)
        {
            int input = 1;
            int length = 0;

            setLength(input, &length);

            Assert::AreEqual(1, length);
        }

        TEST_METHOD(setLength_Input99_SetsLengthTo99)
        {
            int input = 99;
            int length = 0;

            setLength(input, &length);

            Assert::AreEqual(99, length);
        }

        // ========== TASK 2: setWidth ==========

        TEST_METHOD(setWidth_Input25_SetsWidthTo25)
        {
            int input = 25;
            int width = 0;

            setWidth(input, &width);

            Assert::AreEqual(25, width);
        }

        TEST_METHOD(setWidth_Input1_SetsWidthTo1)
        {
            int input = 1;
            int width = 0;

            setWidth(input, &width);

            Assert::AreEqual(1, width);
        }

        TEST_METHOD(setWidth_Input99_SetsWidthTo99)
        {
            int input = 99;
            int width = 0;

            setWidth(input, &width);

            Assert::AreEqual(99, width);
        }
    };
}