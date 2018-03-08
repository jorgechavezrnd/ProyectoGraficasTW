#ifndef TRIANGULOSOLA_H
#define TRIANGULOSOLA_H
#pragma once
#include "Tracer.h"
class TrianguloSola: public Tracer
{
public:
	TrianguloSola();
	TrianguloSola(Mundo* _worldPtr);
	virtual ~TrianguloSola();
	virtual ColorRGB trace_ray(const Rayo& ray) const;
};

#endif // !TRIANGULOSOLA_H


