#include "stdafx.h"
#include "TrianguloSola.h"
#include "Mundo.h"
#include "ShadeRec.h"
#include <algorithm>
#include <iostream>


TrianguloSola::TrianguloSola():Tracer()
{
}

TrianguloSola::TrianguloSola(Mundo* _worldPtr):Tracer(_worldPtr)
{
}

TrianguloSola::~TrianguloSola()
{
}

ColorRGB TrianguloSola::trace_ray(const Rayo & ray) const
{
	ShadeRec	sr(*world_ptr); 	// not used
	double    	t;  				// not used

	ColorRGB colorLuz(1.0, 1.0, 1.0);

	if (world_ptr->triangle.impacto(ray, t, sr))
	{
		Vector3D n = sr.normal;
		Vector3D l = sr.m.lights[0]->obtenerDireccion(sr);

		ColorRGB c;
		c.r = 0.0;// *colorLuz.r * std::max(0.0, n*l);
		c.g = 0.0;//* colorLuz.g * std::max(0.0, n*l);
		c.b = 1.0;// *colorLuz.b * std::max(0.0, n*l);
		return (c);
	}
	else
		return (blanco);
}
