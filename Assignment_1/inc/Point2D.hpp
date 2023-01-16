#pragma once
#include <iostream>

class Point2D
{
	public:
		Point2D();
		Point2D(double x, double y);
		Point2D(const Point2D& other);

		virtual ~Point2D();
		virtual Point2D& operator=(const Point2D& other);

		double getX() const;
		double getY() const;

	private:
		double x;
		double y;
};

std::ostream& operator<<(std::ostream& stream, const Point2D & rhs);
