#pragma once

class Matrix
{
	private:
		/* data */
	public:
		float m[4][4];
		Matrix();
		Matrix(float m[4][4]);
		Matrix(float v);
		~Matrix();
		Matrix operator*(const Matrix &rhs);
		float *operator[](int i) { return m[i]; }
};
