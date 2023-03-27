#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Point.h"
#include <vector>

using namespace PointClass;
namespace PentagonClass
{
	class Pentagon
	{
	public:
		/*
		@brief Initializes a new instance of the 'Pentagon' class
		@param edge edge of pentagon
		@param centre centre of pentagon
		*/
		Pentagon(const double edge = 10, const Point centre = { 0 , 0 });

		/*
		@brief function which calculates a lenght of vector by its end and beginning
		@param first beginning of the vector
		@param second end of the vector
		*/
		const double absVector(Point first, Point second);

		/*
		@brief function which calculates pentagon peremeter
		@return value of pentagon perimeter
		*/
		const double getPerimeter();

		/*
		@brief function which calculates pentagon area
		@return area value of pentagon area
		*/
		double getArea() const;

		/*
		@brief function which move pentagon
		@param abscissaStep value of horizontal move
		@param ordinateStep value of vertical move
		@return a new pentagon with changed points
		*/
		Pentagon movePentagon(const int abscissaStep, const int ordinateStep);

		/*
		@brief overloading the comparison operator by comparing pentagon areas
		@param p2 second pentagon to compare
		@return true, if areas are equal and false, if areas are not equal
		*/
		bool operator ==(Pentagon& p2);

		/*
		@brief function, which overload the comparison operator by comparing pentagon areas
		@param p2 second pentagon to compare
		@return false, if areas are equal and true, if areas are not equal
		*/
		bool operator!=(Pentagon& p2);

		/*
		@brief function, which overload the output stream operator
		@param out output stream
		@param pentagon the pentagon whose point values should be output to the output stream
		@return out the pentagon point values in output stream
		*/
		friend ostream& operator<< (ostream& out, const Pentagon& pentagon);

	private:
		const size_t pentagonEdges = 5;

		Point centre = { 0 , 0 };

		double edge = 10;

		const int alpha = 54;

		const int phi = 360 / pentagonEdges;

		/*
		@brief function, which check the value of pentagon edge
		@param edge pentagon edge which value need to be checked
		@return true, if edge value > 0 and false, if < 0
		*/
		bool isCorrect(double edge);

		double radius = abs(edge / (2 * cos(alpha)));

		vector <Point> pentagonPoints;
	};
}