#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

/*
\brief Point class 
*/
class Point {
private:
	double abscise;
	double ordinate;
public:	
	/*
	\brief constructor with parametras
	\param x - abscise
	\param y - ordinate
	*/
	Point(const double x ,const double y);
	/*
	\brief default constructor
	*/
	Point();
	/*
	\brief destructor
	*/
	~Point();
	/*
	\brief a function that calculates the length of a vector by two given points
	\param second the end of the vector
	\return a square length of vector
	*/
	const double absVector(Point second); // в скобках конец вектора
	/*
	\brief a function that returns abscise
	\return returns abcsice
	*/
	double GetAbscise() const;
	/*
	\brief a function that returns ordinate
	\return return ordinate
	*/
	double GetOrdinate() const;
	/*
	\brief a functions that sets abscise
	*/
	void SetAbscise(const double x);
	/*
	\brief  a functions that sets ordinate
	*/
	void SetOrdinate(const double y);
	/*
	\brief copy constructor
	\param other other point refence
	*/
	Point(const Point& other);
	/*
	\brief function overriding the output stream
	\param out outstream
	\param point point
	\return returns point
	*/
	friend std::ostream& operator<< (std::ostream& out, const Point& point);

};