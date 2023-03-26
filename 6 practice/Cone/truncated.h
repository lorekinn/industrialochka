#include "cone.h"

using namespace std;

class truncated : public cone {
protected:
	double h2;
	double r2;

public:
	truncated();
	truncated(double _r, double _r2, double _h2);
	double area();
	double volume();
	friend ostream& operator<< (ostream& stream, truncated obj);
	friend istream& operator>> (istream& stream, truncated& obj);
};
