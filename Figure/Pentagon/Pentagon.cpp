#include "Pentagon.h"
using namespace PentagonClass;

Pentagon::Pentagon(const double edge, const Point centre)
{
	this->edge = edge;
	this->centre = centre;
	this->radius = abs(edge / (2 * cos(alpha)));
	if (isCorrect(edge))
	{
		for (size_t i = 0; i < pentagonEdges; i++)
		{
			double  angleOfRotation = ((90 + phi * i) * M_PI) / 180;
			double x = round((radius * cos(angleOfRotation) + centre.abscissa) * 100) / 100;
			double y = round((radius * sin(angleOfRotation) + centre.ordinate) * 100) / 100;
			Point a(x, y);
			pentagonPoints.push_back(a);
		}
	}
	else
	{
		throw "edge cant be negative";
	}
}

const double Pentagon::distance(Point first, Point second) const
{
	return pow(second.abscissa - first.ordinate, 2) + pow(second.abscissa - first.ordinate, 2);
}

void Pentagon::movePentagon(const int abscissaStep, const int ordinateStep)
{
	for (size_t i = 0; i < pentagonEdges; i++)
	{
		this->pentagonPoints[i].abscissa += abscissaStep;
		this->pentagonPoints[i].ordinate += ordinateStep;
	}
}

bool Pentagon::isCorrect(const double edge) const
{
	if (edge > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const double Pentagon::getPerimeter() const
{
	double perimeter = 0;
	for (size_t i = 0; i < pentagonEdges; i++)
	{
		perimeter += distance(pentagonPoints[i % pentagonEdges], pentagonPoints[(i + 1) % pentagonEdges]);
	}
	return sqrt(perimeter);
}

double Pentagon::getArea() const
{
	return (this->edge * this->radius) * 2.5;
}

bool Pentagon::operator==(const Pentagon& p2)
{
	if (getArea() == p2.getArea())
	{
		return true;
	}
	return false;
}

bool Pentagon::operator!=(const Pentagon& p2)
{
	if (getArea() != p2.getArea())
	{
		return true;
	}
	return false;
}

ostream& PentagonClass::operator<< (ostream& out, const Pentagon& pentagon)
{
	for (size_t i = 0; i < pentagon.pentagonEdges; i++)
	{
		out << pentagon.pentagonPoints[i] << "\n";
	}
	return out;
}