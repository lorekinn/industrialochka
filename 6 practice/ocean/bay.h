#include "sea.h"

class bay : public sea {
	string bname;
	int length, height;
public:
	bay();
	bay(string n, string sn, string bn, int l, int h);
	friend ostream& operator<< (ostream& stream, bay s);
	friend istream& operator>> (istream& stream, bay& s);
}
