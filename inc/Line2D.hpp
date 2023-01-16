#pragma once

#include "ACurve2D.hpp"
#include "Point2D.hpp"
#include <vector>

class Line2D: public ACurve2D
{
	/*
		Line is defined by its origin point O and direction D:
		C(t) = O + D*t.
	*/

	public:
		Line2D();
		Line2D(Point2D point, double d);
		Line2D(double x, double y, double d);
		Line2D(double point, double d);
		Line2D(const Line2D& other);

		virtual ~Line2D();
		virtual Line2D& operator=(const Line2D& other);

		// Point2D getOriginPoint() const;
		Point2D getOriginPoint() const;
		double getDir() const;

		virtual std::vector<double> derivative(double t) const;
		virtual Point2D getPoint(double t) const;

		virtual void log() const;

	private:
		Point2D point; // origin point
		double dir; // direction
};

