#include "Vertex.hpp"
#include <cmath>

Vertex3::Vertex3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vertex3::Vertex3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vertex3::~Vertex3()
{
}

Vertex3 Vertex3::cross(const Vertex3& other) const {
	return {this->y * other.z - this->z * other.y,
			this->z * other.x - this->x * other.z,
			this->x * other.y - this->y * other.x};
}

Vertex3 Vertex3::normalize() const {
	float length = std::sqrt(x * x + y * y + z * z);
	return {x / length, y / length, z / length};
}


Vertex3 &Vertex3::operator=(const Vertex3 &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return *this;
}

Vertex3 Vertex3::operator+(const Vertex3 &rhs)
{
	Vertex3 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;
	return result;
}

Vertex3 Vertex3::operator-(const Vertex3 &rhs)
{
	Vertex3 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;
	return result;
}