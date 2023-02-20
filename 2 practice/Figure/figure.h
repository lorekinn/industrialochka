class Figure {
private:
	float x1, x2, x3, x4;
	float y1, y2, y3, y4;
	float S;
	float P;

public:
	Figure();
	Figure(float x_1, float x_2, float x_3, float x_4, float y_1, float y_2, float y_3, float y_4);
	void show();
	bool is_prug();
	bool is_square();
	bool is_romb();
	bool is_in_circle();
	bool is_out_circle();
};
