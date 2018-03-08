#include "stdafx.h"
#include "Triangulo.h"


Triangulo::Triangulo()
	: ObjetoGeometrico(), v0(0.0), v1(0.0), v2(0.0)
{
}


Triangulo::~Triangulo()
{
}

bool Triangulo::impacto(const Rayo& ray, double& tnln, ShadeRec& sr) const
{
	double a = v0.x - v1.x;
	double b = v0.x - v2.x;
	double c = ray.vecD.x;
	double d = v0.x - ray.O.x;
	double e = v0.y - v1.y;
	double f = v0.y - v2.y;
	double g = ray.vecD.y;
	double h = v0.y - ray.O.y;
	double i = v0.z - v1.z;
	double j = v0.z - v2.z;
	double k = ray.vecD.z;
	double l = v0.z - ray.O.z;


	double m = f * k - g * j;
	double n = h * k - g * l;
	double p = f * l - h * j;
	double q = g * i - e * k;
	double s = e * j - f * i;


	double inv_denom = 1.0 / (a*m + b * q + c * s);
	double e1 = d * m - b * n - c * p;
	double beta = e1 * inv_denom;

	if (beta < 0.0)
	{
		return false;
	}
	//-----------------------------------

	double r = e * l - h * i;
	double e2 = a * n + d * q + c * r;
	double gamma = e2 * inv_denom;

	if (gamma < 0.0)
	{
		return false;
	}


	if (beta + gamma > 1.0)
	{
		return false;
	}


	double e3 = a * p - b * r + d * s;
	double t = e3 * inv_denom;

	if (t < kEpsilon)
	{
		return false;

	}

	tnln = t;
	//sr.normal

	sr.puntoImpactoLocal = ray.O + ray.vecD*t;

	return true;
}

void Triangulo::setVertexZero(const double & x, const double & y, const double & z)
{
	v0.x = x;
	v0.y = y;
	v0.z = z;
}

void Triangulo::setVertexOne(const double & x, const double & y, const double & z)
{
	v1.x = x;
	v1.y = y;
	v1.z = z;
}

void Triangulo::setVertexTwo(const double & x, const double & y, const double & z)
{
	v2.x = x;
	v2.y = y;
	v2.z = z;
}
