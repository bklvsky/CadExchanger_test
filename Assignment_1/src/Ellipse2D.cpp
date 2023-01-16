#include "Ellipse2D.hpp"

Ellipse2D::Ellipse2D(): radX(1.), radY(1.) {}

Ellipse2D::Ellipse2D(double radX, double radY): radX(radX), radY(radY)
{
	if (radX <= 0. || radY <= 0) {
		throw std::logic_error("Ellipse radius less than or equal to 0");
	}
}

Ellipse2D::Ellipse2D(const Ellipse2D& other): ACurve2D(other)
{
	*this = other;
}

Ellipse2D::~Ellipse2D() {}

Ellipse2D& Ellipse2D::operator=(const Ellipse2D& other)
{
	this->radX = other.getRadX();
	this->radY = other.getRadY();
	return *this;
}

/*
	Returns the length of the semi-axis of the ellipse along the axis X
*/
double Ellipse2D::getRadX() const
{
	return this->radX;
}

/*
	Returns semi-axis of the ellipse along the axis Y
*/
double Ellipse2D::getRadY() const
{
	return this->radY;
}

/*
	Calculates the coordinate of a point on the ellipse per parameter t.
*/
Point2D Ellipse2D::getPoint(double t) const
{
	double x = radX * cos(t);
	double y = radY * sin(t);
	return Point2D(x, y);
}

/*
	Calculates the slope of the tangent vector of the ellipse per parameter t.
	Two dimensional vector in the form of (delta_x, delta_y).
	Returns std::vector<float>, where:
	- the first element is the X increment;
	- the second element is the Y increment.
*/
std::vector<double> Ellipse2D::derivative(double t) const
{
	std::vector<double> ret;
	double delta_x = -radX * sin(t);
	double delta_y = radY * cos(t);
	ret.push_back(delta_x);
	ret.push_back(delta_y);
	return ret;
}

void Ellipse2D::log() const
{
	std::cout << "Ellipse"
		"(" << this->getRadX() << ", " << this->getRadY() << ")" 
		<< std::endl;
}
