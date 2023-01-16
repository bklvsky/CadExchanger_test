#include "Line2D.hpp"

Line2D::Line2D(): point(), dir(1) {}

/*
	Defines a line by its origin 2D point anf its direction. 
*/
Line2D::Line2D(Point2D point, double d): point(point), dir(d) {}

/*
	Defines a line by its canonical equation.

	According to the canonical equation of the line : y(x) = O + d * x, where:
	- O (point) is the Y-axis offset;
	- d is the slope of the line.
*/
Line2D::Line2D(double point, double d): point(0, point), dir(d) {}

Line2D::Line2D(const Line2D& other): ACurve2D(other)
{
	*this = other;
}

Line2D::~Line2D() {}

Line2D& Line2D::operator=(const Line2D& other)
{
	this->point = other.getOriginPoint();
	this->dir = other.getDir();
	return *this;
}

// Point2D Line::getOriginPoint() const
// {
// 	Point2D ret(this->point.getX(), this->point.getY());
// 	return ret;
// }

/*
	Returns the Y-axis offset
*/
Point2D Line2D::getOriginPoint() const
{
	return this->point;
}

/*
	Returs the slope of the line
*/
double Line2D::getDir() const
{
	return this->dir;
}

/*
	Calculates a derivative (a 2D Vector) of the Line per parameter t.
	Two dimensional vector in the form of (delta_x, delta_y).
	Returns std::vector<float>, where:
	- the first element is the X increment;
	- the second element is the Y increment.
*/
std::vector<double> Line2D::derivative(double t) const
{
	(void)t;
	std::vector<double> ret;
	ret.push_back(dir);
	ret.push_back(1);
	return ret;
}

/*
	Calculates a point of the line per parameter t
*/
Point2D Line2D::getPoint(double t) const
{
	return Point2D(this->point.getX() + t, this->point.getY() + this->dir * t);
}

void Line2D::log() const
{
	std::cout << "Line C(t) = " 
		<< this->getOriginPoint() << " + " 
		<< this->getDir() << " * t" 
		<< std::endl;
}
