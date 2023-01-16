#include "ACurve2D.hpp"

ACurve2D::ACurve2D() {}


ACurve2D::ACurve2D(const ACurve2D & other)
{
	*this = other;
}

ACurve2D::~ACurve2D() {}

ACurve2D & ACurve2D::operator=(const ACurve2D & other)
{
	(void)other;
	return *this;
}