#include "stdafx.h"
#include "Luz.h"
#include "Constantes.h"
Luz::Luz()
{
}

Luz::~Luz()
{
}

Luz& Luz::operator=(const Luz& rhs)
{
	if (this == &rhs)
		return (*this);

	return (*this);
}
ColorRGB Luz::L(ShadeRec& s) {
	return (negro);
}
