#include <iostream>

using namespace std;

class cone {
protected:
	double x, y, z;
	double r, h;
public:
	cone();
	cone(double _r, double _h);
	cone(double _x, double _y, double _z, double _r, double _h);
	void set(double _x, double _y, double _z, double _r, double _h);
	double area();
	double volume();
	friend ostream& operator<< (ostream& stream, cone obj);
	friend istream& operator>> (istream& stream, cone& obj);
}
