#include <iostream>
#include <string>

using namespace std;

class ocean {
protected:
	string name, location;
	int depth, square;
public:
	ocean();
	ocean(string oc);
	ocean(string n, string l, int d, int s);
	friend ostream& operator<< (ostream& stream, ocean o);
	friend istream& operator>> (istream& stream, ocean& o);
}
