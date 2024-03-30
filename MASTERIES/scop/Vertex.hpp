#pragma once


class Vertex3
{
private:

public:
	float x, y, z;
	Vertex3();
	Vertex3(float x, float y, float z);
	Vertex3(const Vertex3 &rhs) { *this = rhs; }
	~Vertex3();
    Vertex3 cross(const Vertex3& other) const;
    Vertex3 normalize() const;
	Vertex3 &operator=(const Vertex3 &rhs);
	Vertex3 operator+(const Vertex3 &rhs);
	Vertex3 operator-(const Vertex3 &rhs);
};