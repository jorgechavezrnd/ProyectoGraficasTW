#pragma once
#include "Luz.h"
class LuzPuntual: public Luz
{
public:
	LuzPuntual();
	~LuzPuntual();
	Vector3D obtenerDireccion(ShadeRec& sr);
	ColorRGB L(ShadeRec& sr);
	void establecerColor(const ColorRGB& c);
	void establecerColor(float r, float g, float b);
	void establecerUbicacion(Punto3D p);
	void establecerUbicacion(float x, float y, float z);
private:
	float ls;
	ColorRGB color;
	Punto3D ubicacion;
};

