#pragma once
class Mundo;

#include "Punto3D.h"
#include "Normal.h"
#include "ColorRGB.h"


class ShadeRec
{
public:
	ShadeRec(Mundo& m);				// Constructor
	ShadeRec(const ShadeRec& sr);	// Constructor copia
	~ShadeRec();					// Destructor



public:
	bool impactaUnObjeto;			// El rayo impacto un objeto
	Punto3D puntoImpactoLocal;		// Coordenadas mundo del punto de impacto
	Vector3D normal;				// Normal en el punto de impacto
	ColorRGB color;					// Usado solo en este capitulo
	Mundo& m;						// Referencia a mundo para shading
};




