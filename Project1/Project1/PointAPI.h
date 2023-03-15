#pragma once
#include <iostream>
using namespace std;
/*
@brief Point class 
*/
struct Point {

	double abscissa;
	double ordinate;
	/*
	@brief Initializes a new instance of the 'Point' class (abscissa , ordinate)
	@param x - abscissa
	@param y - ordinate
	*/
	Point(const double x ,const double y);

	/*
	@brief Initializes a new instance of the 'Point' class (0 , 0)
	*/
	Point();

	/*
	@brief function overriding the output stream
	@param out outstream
	@param point point
	@return returns point
	*/
	friend std::ostream& operator<< (std::ostream& out, const Point& point);

};