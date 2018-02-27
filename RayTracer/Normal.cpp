#include "stdafx.h"
#include "Normal.h"
#include <math.h>

Normal::Normal() : x(0.0), y(0.0), z(0.0)
{
}

Normal::Normal(double _a) : x(_a), y(_a), z(_a)
{
}

Normal::Normal(double _a, double _b, double _c) : x(_a), y(_b), z(_c) 
{
}

Normal::Normal(const Normal &n) : x(n.x), y(n.y), z(n.z)
{
}

Normal::Normal(const Vector3D &v) : x(v.x), y(v.y), z(v.z)
{
}

Normal::~Normal()
{
} 

Normal& Normal::operator=(const Normal& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

Normal& Normal::operator= (const Vector3D& rhs)
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

Normal& Normal::operator= (const Punto3D& rhs) {
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

Normal Normal::operator- () const {
	return (Normal(-x, -y, -z));
}

Normal Normal::operator+ (const Normal& n) const {
	return (Normal(x + n.x, y + n.y, z + n.z));
}

Normal& Normal::operator+= (const Normal& n) {
	x += n.x; y += n.y; z += n.z;
	return (*this);
}

double Normal::operator* (const Vector3D& v) const {
	return (x * v.x + y * v.y + z * v.z);
}

Normal Normal::operator* (const double a) const {
	return (Normal(x * a, y * a, z * a));
}

void Normal::normalizar() {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
}
