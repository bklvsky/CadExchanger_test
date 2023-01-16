#include "Line2D.hpp"
#include "Point2D.hpp"
#include "Ellipse2D.hpp"
#include "ACurve2D.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>

double randomDouble(double lowerBound, double upperBound)
{
	double delta;
	delta = upperBound - lowerBound;
	return (lowerBound + delta * ((double)random() / RAND_MAX));
}

int getArgs(int argc, char **argv, int& curvesNum, double& maxT)
{
	if (argc != 3) {
		std::cout << "Usage:" << std::endl;
		std::cout << "./curves [number_of_curves_to_evaluate]" 
				<< " [max_size_of_t]." << std::endl;
		return -1;
	}
	curvesNum = atoi(argv[1]);
	maxT = atof(argv[2]);
	if (curvesNum <= 0 || maxT <= 0.) {
		std::cout << "[number_of_curves_to_evaluate] and "
				<< "[max_size_of_t]"
				<< "should be positive numbers." << std::endl;
		return -1;
	}
	return 0;
}

int main(int argc, char **argv) 
{
	int curvesNum;
	double maxT;

	if (getArgs(argc, argv, curvesNum, maxT) < 0) {
		return 1;
	}

	// Initialize vector of curves
	std::vector<ACurve2D *> vct;
	for (int i = 0; i < curvesNum; i++)
	{
		double param_1 = randomDouble(1., maxT);
		double param_2 = randomDouble(1., maxT);
		ACurve2D *curve;
		if (i % 2 == 0)
			curve = new Line2D(param_1, param_2);
		else
			curve = new Ellipse2D(param_1, param_2);
		vct.push_back(curve);
	}

	// print all points and derivatives at t = PI / 4
	for (size_t i = 0; i < vct.size(); i++)
	{
		std::cout << "[" << i + 1 << "] " << std::endl;
		vct[i]->log();
		std::cout << "point at the parameter t = PI / 4:" << std::endl;
		std::cout << vct[i]->getPoint(M_PI_4) << std::endl;
		std::cout << "derivative at the parameter t = PI / 4:" << std::endl;
		std::vector<double> der = vct[i]->derivative(M_PI_4);
		std::cout << "(" << der[0] << ", " << der[1] << ")" << std::endl;
		std::cout << std::endl;
		delete vct[i];
	}

	return 0;
}