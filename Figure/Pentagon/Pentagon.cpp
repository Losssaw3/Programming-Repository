#include "Pentagon.h"
using namespace PentagonClass;

Pentagon::Pentagon(const double edge, const Point centre)
	: centre(centre), edge(edge) 
{
	if (!isCorrect(this->edge))
	{
		throw("Ребро не может быть отрицательным!");
	}
	else
	{
		this->radius = abs(edge / (2 * cos(alpha)));
		for (size_t i = 0; i < pentagonEdges; i++)
		{
			double  angleOfRotation = ((90 + phi * i) * M_PI) / 180;
			Point point = calculateCoordinate(angleOfRotation, radius);
			pentagonPoints[i] = point;
		}
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
	return (edge > 0);
}

double Pentagon::getPerimeter() const
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
	double precision = 0.01;
	return(abs(getArea() - p2.getArea()) < precision);
}

bool Pentagon::operator!=(const Pentagon& p2)
{
	double precision = 0.01;
	return(!(abs(getArea() - p2.getArea()) < precision));
}

Point PentagonClass::Pentagon::calculateCoordinate(const double angle, const double radius)
{
	double x = round((radius * cos(angle) + centre.abscissa) * 100) / 100;
	double y = round((radius * sin(angle) + centre.ordinate) * 100) / 100;
	return Point(x , y);
}

ostream& PentagonClass::operator<< (ostream& out, const Pentagon& pentagon)
{
	for (int i = 0; i < pentagon.pentagonEdges; i++)
	{
		out << pentagon.pentagonPoints[i] << "\n";
	}
	return out;
}