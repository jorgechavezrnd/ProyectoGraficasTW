#pragma once

#include "ObjetoGeometrico.h"

class Triangulo : public ObjetoGeometrico
{
public:
	Triangulo();
	~Triangulo();
	bool impacto(const Rayo& ray, double& tmin, ShadeRec& sr) const;

	void setVertexZero(const double & x, const double & y, const double & z);
	void setVertexOne(const double & x, const double & y, const double & z);
	void setVertexTwo(const double & x, const double & y, const double & z);


public:
	Punto3D v0;
	Punto3D v1;
	Punto3D v2;
};

