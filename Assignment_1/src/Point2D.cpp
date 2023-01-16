#include "Point2D.hpp"

Point2D::Point2D(): x(0.), y(0.) {}

Point2D::Point2D(double x, double y): x(x), y(y) {}

Point2D::Point2D(const Point2D& other): x(other.getX()), y(other.getY()) {}

Point2D::~Point2D() {}

Point2D& Point2D::operator=(const Point2D& other)
{
	this->x = other.getX();
	this->y = other.getY();
	return *this;
}

double Point2D::getX() const
{
	return this->x;
}

double Point2D::getY() const
{
	return this->y;
}

std::ostream& operator<<(std::ostream& stream, const Point2D & rhs)
{
	stream << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return stream;
}
