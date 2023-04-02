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
		@brief function which calculates a distance between two points
		@param first point
		@param second point
		@return distance between two points 
		*/
		const double distance(Point first, Point second) const;

		/*
		@brief function which calculates pentagon peremeter
		@return value of pentagon perimeter
		*/
		double getPerimeter() const;

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
		void movePentagon(const int abscissaStep, const int ordinateStep );

		/*
		@brief overloading the comparison operator by compare two pentagons
		@param p2 second pentagon to compare
		@return true, if areas are equal and false, if areas are not equal
		*/
		bool operator ==(const Pentagon& p2);

		/*
		@brief function, which overload the comparison operator by comparing pentagon areas
		@param p2 second pentagon to compare
		@return false, if areas are equal and true, if areas are not equal
		*/
		bool operator!=(const Pentagon& p2);

		/*
		@brief function, which overload the output stream operator
		@param out output stream
		@param pentagon the pentagon whose point values should be output to the output stream
		@return out the pentagon point values in output stream
		*/
		friend ostream& operator<< (ostream& out, const Pentagon& pentagon);
		/*
		@brief function, which calculates a point coordinate
		@param angle angle of the point
		@param radius radius of the point
		@return Point's coordinates 
		*/
		Point calculateCoordinate(const double angle , const double radius);

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
		bool isCorrect(const double edge) const;

		double radius = abs(edge / (2 * cos(alpha)));

		vector<Point> pentagonPoints{0,0,0,0,0};
	};
}