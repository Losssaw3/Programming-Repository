#include "pch.h"
#include "..//Pentagon/Point.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PointClass;

namespace PointTest
{
	TEST_CLASS(PointTest)
	{
	public:
		TEST_METHOD(DefaultConstrucorTest_ValidData_Success)
		{
			//Arrange , Act
			Point defaultPoint;
			Point point1(4, 6);

			//Assert
			Assert::AreEqual(defaultPoint.abscissa, 0.0);
			Assert::AreEqual(defaultPoint.ordinate, 0.0);

		}
		TEST_METHOD(ParametersConstrucorTest_ValidData_Success)
		{
			//Arrange , Act
			Point point1(4, 6);

			//Assert
			Assert::AreEqual(point1.abscissa, 4.0);
			Assert::AreEqual(point1.ordinate, 6.0);
		}
	};
}
