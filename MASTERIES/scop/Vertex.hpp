#pragma once


class Vec3
{
private:

public:
	float x, y, z;
	Vec3();
	Vec3(float x, float y, float z);
	Vec3(const Vec3 &rhs) { *this = rhs; }
	~Vec3();
    Vec3 cross(const Vec3& other) const;
    Vec3 normalize() const;
	Vec3 &operator=(const Vec3 &rhs);
	Vec3 operator+(const Vec3 &rhs);
	Vec3 operator-(const Vec3 &rhs);
};

class Vec2
{
	private:

	public:
	float x, y;
	Vec2();
	Vec2(float x, float y);
	Vec2(const Vec2 &rhs) { *this = rhs; }
	~Vec2();
	Vec2 &operator=(const Vec2 &rhs);
	Vec2 operator+(const Vec2 &rhs);
	Vec2 operator-(const Vec2 &rhs);
};
