#include <cmath>
#include <vector>

class Dot2D
{
	double x;
	double y;
	
	Dot2D()
	{
		x = 0.0;
		y = 0.0;
	}

	Dot2D(double xCoord, double yCoord)
	{
		x = xCoord;
		y = yCoord;
	}

	double peekX()
	{
		return x;
	}

	double peekY()
	{
		return y;
	}

	double distance(Dot2D dot1, Dot2D dot2);

	void move(double distanceX, double distanceY);

	void turn(double radians);
};

double Dot2D::distance(Dot2D dot1, Dot2D dot2)
{
	return sqrt(pow(dot1.peekX() - dot2.peekX(), 2) + pow(dot1.peekY() - dot2.peekY(), 2));
}

void Dot2D::move(double distanceX, double distanceY)
{
	x += distanceX;
	y += distanceY;
}

void Dot2D::turn(double radians)
{
	double tempX = x * cos(radians) - y * sin(radians);
	double tempY = x * sin(radians) + y * cos(radians);
	x = tempX;
	y = tempY;
}


class Cube
{
	std::vector<double> a;
	std::vector<double> b;
	std::vector<double> c;

	Cube()
	{
		a = { 0, 0, 0 };
		b = { 0, 0, 0 };
		c = { 0, 0, 0 };
	}

	Cube(std::vector<double> aToPut, std::vector<double> bToPut, std::vector<double> cToPut)
	{
		a = aToPut;
		b = bToPut;
		c = cToPut;
	}

	double diag();
};

double Cube::diag()
{
	std::vector<double> symm = { b[0] + c[0], b[1] + c[1], b[2] + c[2] };
	return sqrt(pow(symm[0], 2) + pow(symm[1], 2) + pow(symm[2], 2));
}