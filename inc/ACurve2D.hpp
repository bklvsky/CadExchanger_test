#pragma once
#include "Point2D.hpp"
#include <vector>
#include <string>

class ACurve2D
{
	public:
		ACurve2D();
		ACurve2D(const ACurve2D & other);
		virtual ~ACurve2D();
		virtual ACurve2D & operator=(const ACurve2D & other); 

		virtual std::vector<double> derivative(double t) const = 0;
		virtual Point2D getPoint(double t) const = 0;
		virtual void log() const = 0;
};
