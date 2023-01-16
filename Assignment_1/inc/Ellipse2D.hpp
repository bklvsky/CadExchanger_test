#pragma once
#include "Point2D.hpp"
#include "ACurve2D.hpp"
#include <iostream>
#include <math.h>
#include <vector>
#include <exception>

class Ellipse2D: public ACurve2D
{
	/*
		Ellipse is defined by its radii along X and Y axis,
		according to its canonical equation: (x / a) ^ 2 + (y / b) ^ 2 = 1,
		Where a - its semi-axis along X axis;
		b - its semi-axis along Y axis.

		Point and derivative calculation uses its parametrical equation:
		x = a * cos(t)
		y = b * sin(t)
	*/
	public:
		Ellipse2D();
		Ellipse2D(double radX, double radY);
		Ellipse2D(const Ellipse2D& other);

		virtual ~Ellipse2D();
		virtual Ellipse2D& operator=(const Ellipse2D& other);

		double getRadX() const;
		double getRadY() const;

		Point2D getPoint(double t) const;
		std::vector<double> derivative(double t) const;

		virtual void log() const;
	private:
		double radX;
		double radY;
};
