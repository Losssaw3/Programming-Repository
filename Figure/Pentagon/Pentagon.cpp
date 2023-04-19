#include "Pentagon.h"
#include <sstream>

using namespace PentagonClass;
Pentagon::Pentagon(const double edge, const Point centre)
	: edge(edge) , centre(centre)
{
	if (!isCorrect(this->edge))
	{
		throw std::out_of_range("Ребро не может быть отрицательным!");
	}
	this->radius = abs(edge / (2 * cos(alpha * M_PI / 180)));
	for (size_t i = 0; i < pentagonEdges; i++)
	{
		double  angleOfRotation = (90 + (phi * i)) * M_PI / 180;
		Point point = calculateCoordinate(angleOfRotation, radius);
		pentagonPoints[i] = point;
	}
	pentagonPoints[pentagonEdges] = (pentagonPoints[0]);
}

const double Pentagon::distance(Point first, Point second) const
{
	return sqrt((pow(second.abscissa - first.abscissa, 2) + pow(second.ordinate - first.ordinate, 2)));
}

void Pentagon::movePentagon(const double abscissaStep, const double ordinateStep)
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
		perimeter += (distance(pentagonPoints[i], pentagonPoints[i + 1]));
	}
	return perimeter;

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

std::string PentagonClass::Pentagon::ToString()
{
	std::string pentagonString;
	for (auto point : pentagonPoints)
	{
		pentagonString += '(' + std::to_string(int(point.abscissa)) + ',' + std::to_string(int(point.ordinate)) + ')';
	}
	return pentagonString;
}

bool Pentagon::operator!=(const Pentagon& p2)
{
	return !(*this == p2);
}

Point Pentagon::calculateCoordinate(const double angle, const double radius)
{
	double x = round((radius * cos(angle) + centre.abscissa) * 100) / 100;
	double y = round((radius * sin(angle) + centre.ordinate) * 100) / 100;
	return Point(x , y);
}

std::ostream& PentagonClass::operator<< (std::ostream& out, const Pentagon& pentagon)
{
	for (std::vector<Point>::const_iterator out_it = pentagon.pentagonPoints.cbegin(); out_it < pentagon.pentagonPoints.cend() - 1; ++out_it)
	{
		out << *out_it << "\n";
	}
	return out;
}