#pragma once
#include <cmath>
class Point2D
{
private:
	double mX = 0;
	double mY = 0;
public: 
	Point2D() = default;
	Point2D(double x, double y) : mX{ x }, mY{ y }{};

	double X() const { return mX; };
	double Y() const { return mY; };

	double Length() const {
		return std::hypot(mX, mY);
	}
};

