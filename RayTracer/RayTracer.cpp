// RayTracer.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include "Mundo.h"

int main()
{
	Mundo m;
	m.build();
	m.drawScene();
    return 0;
}
