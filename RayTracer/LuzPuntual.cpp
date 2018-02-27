#include "stdafx.h"
#include "LuzPuntual.h"

LuzPuntual::LuzPuntual() :Luz(), ls(1.0), color(1.0), ubicacion(0,1,0)
{
}

LuzPuntual::LuzPuntual(const Punto3D& punto3d, const ColorRGB& color)
  : ubicacion(punto3d),
	color(color)
{
}

LuzPuntual::~LuzPuntual()
{
}

Vector3D LuzPuntual::obtenerDireccion(ShadeRec& sr)
{
	return (ubicacion - sr.puntoImpactoLocal).hat();
}

ColorRGB LuzPuntual::L(ShadeRec& sr)
{
	return(color*ls);
}

void LuzPuntual::establecerColor(const ColorRGB& c)
{
	color = c;
}

void LuzPuntual::establecerColor(float r, float g, float b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

void LuzPuntual::establecerUbicacion(Punto3D p)
{
	ubicacion = p;
}

void LuzPuntual::establecerUbicacion(float x, float y, float z)
{
	ubicacion.x = x;
	ubicacion.y = y;
	ubicacion.z = z;
}
