#include "stdafx.h"
#include "EsferaSola.h"
#include "Mundo.h"
#include "ShadeRec.h"
#include <algorithm> 

EsferaSola::EsferaSola(void) : Tracer()
{
}

EsferaSola::EsferaSola(Mundo* _worldPtr) : Tracer(_worldPtr)
{
}

EsferaSola::~EsferaSola(void) 
{
}

ColorRGB EsferaSola::trace_ray(const Rayo& ray) const 
{
	ShadeRec	sr(*world_ptr); 	// not used
	double    	t;  				// not used
	
	ColorRGB colorLuz(1.0, 1.0, 1.0);

	if (world_ptr->esfera.impacto(ray, t, sr))
	{
		Vector3D n = sr.normal;
		Vector3D l = sr.m.luces[0]->obtenerDireccion(sr);
		
		ColorRGB c;
		//c.r = 0.98 * colorLuz.r * std::max(0.0, n*l);
		//c.g = 0.45* colorLuz.g * std::max(0.0, n*l);
		//c.b = 0.36* colorLuz.b * std::max(0.0, n*l);
		c.r = 2.0 * colorLuz.r * std::max(0.0, n*l);
		c.g = 2.0 * colorLuz.g * std::max(0.0, n*l);
		c.b = 2.0 * colorLuz.b * std::max(0.0, n*l);
		return (c);
	}
	else
		return (blanco);
}
