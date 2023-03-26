#include "bay.h"

ocean::ocean() {
	name = location = "Empty";
	depth = square = 0;
}

ocean::ocean(string oc) {
	name = oc;
	location = "Empty ocean";
	depth = square = 0;
}

ocean::ocean(string n, string l, int d, int s) {
	name = n;
	location = l;
	depth = d;
	square = s;
}

ostream& operator<< (ostream& stream, ocean o) {
	stream << "Ocean: " << o.name << "\nLocation: " << o.location << "\nDepth " << o.depth << "\nSquare " << o.square << endl;
	return stream;
}

istream& operator>> (istream& stream, ocean& o) {
	stream >> o.name >> o.location >> o.depth >> o.square;
	return stream;
}

sea::sea() : ocean() {
	sname = "Empty sea";
	sdepth = ssquare = cline = 0;
}

sea::sea(string n, string sn) : ocean(n) {
	sname = sn;
	sdepth = ssquare = cline = 0;
}

sea::sea(string oc, string n, int d, int s, int l) : ocean(oc) {
	sname = n;
	sdepth = d;
	ssquare = s;
	cline = l;
}

istream& operator>> (istream& stream, sea& s) {
	stream >> s.name >> s.sname >> s.sdepth >> s.ssquare >> s.cline >> s.name;
	return stream;
}

ostream& operator<< (ostream& stream, sea s) {
	stream << "Ocean: " << s.name << "\nSea: " << s.sname << "\nDepth: " << s.sdepth << "\nSquare: " << s.ssquare << "\nCoastline: " << s.cline << endl;
	return stream;
}

bay::bay() : sea() {
	bname = "Empty bay";
	length = height = 0;
}

bay::bay(string n, string sn, string bn, int l, int h) : sea(n, sn) {
	bname = bn;
	length = l;
	height = h;
}

istream& operator>> (istream& stream, bay& s) {
	stream >> s.name >> s.sname >> s.bname >> s.length >> s.height;
	return stream;
}

ostream& operator<< (ostream& stream, bay s) {
	stream << "Ocean: " << s.name << "\nSea: " << s.sname << "\nBay: " << s.bname << "\nLength: " << s.length << "\nHeight: " << s.height;
	return stream;
}
