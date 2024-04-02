#include "Vertex.hpp"
#include <cmath>

Vec3::Vec3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vec3::Vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3::~Vec3()
{
}

Vec3 Vec3::cross(const Vec3& other) const {
	return {this->y * other.z - this->z * other.y,
			this->z * other.x - this->x * other.z,
			this->x * other.y - this->y * other.x};
}

Vec3 Vec3::normalize() const {
	float length = std::sqrt(x * x + y * y + z * z);
	return {x / length, y / length, z / length};
}


Vec3 &Vec3::operator=(const Vec3 &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return *this;
}

Vec3 Vec3::operator+(const Vec3 &rhs)
{
	Vec3 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;
	return result;
}

Vec3 Vec3::operator-(const Vec3 &rhs)
{
	Vec3 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;
	return result;
}

Vec2::Vec2()
{
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec2::~Vec2()
{
}

Vec2 &Vec2::operator=(const Vec2 &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

Vec2 Vec2::operator+(const Vec2 &rhs)
{
	Vec2 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	return result;
}

Vec2 Vec2::operator-(const Vec2 &rhs)
{
	Vec2 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	return result;
}


