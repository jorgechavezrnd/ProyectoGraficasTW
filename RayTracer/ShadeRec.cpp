#include "stdafx.h"
#include "Constantes.h"
#include "ShadeRec.h"

ShadeRec::ShadeRec(Mundo& _m)
	:impactaUnObjeto(false),
	puntoImpactoLocal(),
	normal(),
	color(negro),
	m(_m)
{}
ShadeRec::ShadeRec(const ShadeRec& sr)
	:impactaUnObjeto(sr.impactaUnObjeto),
	puntoImpactoLocal(sr.puntoImpactoLocal),
	color(sr.color),
	m(sr.m)
{}
ShadeRec::~ShadeRec(){}



