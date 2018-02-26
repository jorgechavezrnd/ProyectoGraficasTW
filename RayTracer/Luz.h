#pragma once
#include "Vector3D.h"
#include "ColorRGB.h"
#include "ShadeRec.h"

class Luz
{
public:
	Luz();
	virtual ~Luz();
	
	Luz& operator=(const Luz& rhs);
	virtual Vector3D obtenerDireccion(ShadeRec& sr)=0;
	virtual ColorRGB L(ShadeRec& sr);
};


