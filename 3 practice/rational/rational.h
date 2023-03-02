int nod(int a, int b);

class rational {
	int num;
	int den;
public:
	rational(int a, int b);
	rational();
	void set(int a, int b);
	void show();
	int get_num();
	int get_den();
	friend rational operator+ (rational& r1, rational& r2);
	friend rational operator- (rational& r1, rational& r2);
	friend rational operator++ (rational& r1, int);
	rational operator= (rational f2);
	friend bool operator== (rational& r1, rational& r2);
	friend bool operator> (rational& r1, rational& r2);
	friend bool operator< (rational& r1, rational& r2);
};	
