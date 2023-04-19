#include "pch.h"
#include <string>
#include "..//Pentagon/Pentagon.h"
#include "CppUnitTest.h"
#include "..//MathModules/Math.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PentagonClass;

namespace PentagonTest
{
    TEST_CLASS(PentagonTest)
    {
    public:
        TEST_METHOD(ConstructorTest_InvalidData_ExpectedException)
        {
            //Arrange, Act, Assert
            Assert::ExpectException<std::out_of_range>([]() {auto wrongPentagon = Pentagon(-10, { 0 , 0 }); });
        }
        TEST_METHOD(GetPerimeterTest_ValidData_Success)
        {
            //Arrange
            Pentagon defaultPentagon;
            auto expected = 50.0;
            auto precision = 0.1;
            // Act
            auto perimeter = defaultPentagon.getPerimeter();

            // Assert
            Assert::IsTrue(areSameDouble(perimeter, expected, precision));
        }
        TEST_METHOD(GetAreaTest_ValidData_Success)
        {
            //Arrange
            Pentagon defaultPentagon;
            auto expected = 212.0;
            double precision = 1;

            // Act
            auto area = defaultPentagon.getArea();

            // Assert
            Assert::IsTrue(areSameDouble(area, expected, precision));
        }
        TEST_METHOD(CalculateCoordinateTest_ValidData_Success)
        {
            //Arrange
            Pentagon defaultPentagon;
            int angle = 0;
            double radius = 10.0;
            Point expected{ 10 , 0 };

            // Act
            Point point1 = defaultPentagon.calculateCoordinate(angle, radius);

            // Assert
            Assert::AreEqual(expected.abscissa, point1.abscissa);
            Assert::AreEqual(expected.ordinate, point1.ordinate);
        }
        TEST_METHOD(DistanceTest_ValidData_Success)
        {
            //Arrange
            Pentagon defaultPentagon;
            Point begin{ 2 , 6 };
            Point end{ 5 , 10 };
            double expected = 5.0;
            double precision = 0.1;

            // Act
            double distance = defaultPentagon.distance(begin, end);

            // Assert
            Assert::IsTrue(areSameDouble(distance, expected, precision));

        }
        TEST_METHOD(MovePentagonTest_ValidData_Success)
        {
            //Arrange
            Pentagon defaultPentagon;
            std::string expected;
            expected = "(3,11)(-5,5)(-2,-3)(8,-3)(11,5)(0,8)";

            //Act
            Pentagon moved = defaultPentagon;
            moved.movePentagon(3, 3);
            std::string movedString = moved.ToString();

            //Assert
            Assert::AreEqual(movedString, expected);
        }
        TEST_METHOD(EqualOperatorTest_ValidData_Success)
        {
            //Arrange , Act
            Pentagon Pentagon1{ 10 , {0, 0} };
            Pentagon Pentagon2{ 10 , {7 , 9} };

            //Assert
            Assert::IsTrue(Pentagon1 == Pentagon2);
        }
        TEST_METHOD(NotEqualOperatorTest_ValidData_Success)
        {
            //Arrange , Act
            Pentagon Pentagon1{ 10 , {0 , 0} };
            Pentagon Pentagon2{ 9 , {0 , 0} };

            //Assert
            Assert::IsTrue(Pentagon1 != Pentagon2);
        }
    };
}
