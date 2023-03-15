#pragma once
#include <iostream>
using namespace std;
/*
@brief Point class 
*/
class Point {
private:
	double abscissa;
	double ordinate;
public:	
	/*
	@brief constructor with parameters , create a point-class object with parameters (abscissa , ordinate)
	@param x - abscissa
	@param y - ordinate
	*/
	Point(const double x ,const double y);

	/*
	@brief default constructor, which create a point-class object with paremeters (0 , 0)
	*/
	Point();

	/*
	@brief a function that returns abscissa
	@return returns abcsissa value
	*/
	double GetAbscissa() const;

	/*
	@brief a function that returns ordinate
	@return return ordinate value
	*/
	double GetOrdinate() const;

	/*
	@brief a functions that sets abscissa
	*/
	void SetAbscissa(const double x);

	/*
	@brief  a functions that sets ordinate
	*/
	void SetOrdinate(const double y);

	/*
	@brief function overriding the output stream
	@param out outstream
	@param point point
	@return returns point
	*/
	friend std::ostream& operator<< (std::ostream& out, const Point& point);

};