#pragma once

#include "Punto3D.h"

class Normal
{
public:
	Normal();									// Constructor por defecto
	Normal(double _a);							// Constructor
	Normal(double _a, double _b, double _c);	// Constructor
	Normal(const Normal &n);					// Constructor copia
	Normal(const Vector3D &v);					// Construir una normal a partir de un vector
	~Normal();

	Normal& operator= (const Normal& rhs);		// Operador de asignacion
	Normal& operator= (const Vector3D& rhs);	// Asignacion de un vector a la normal
	Normal& operator= (const Punto3D& rhs);		// Asignacion de un punto a la normal
	Normal operator- () const;					// Menos unario
	Normal operator+ (const Normal& n) const;	// Sumar una normal
	Normal& operator+= (const Normal& n);		// Suma compuesta
	double operator* (const Vector3D& v) const; // Producto punto por un vector por la derecha
	Normal operator* (const double a) const;	// Multiplicacion por un escalar por la derecha

	void normalizar();							// Convertir a una normal unitaria

	double x;
	double y;
	double z;

};
