#pragma once

#include <vector>


#include "Esfera.h"
#include "Triangulo.h"
#include "EsferaSola.h"
#include "TrianguloSola.h"
#include "LuzPuntual.h"
#include "Salida.h"
#include "ViewPlane.h"

class Mundo
{
public:
	Mundo();
	~Mundo();
	
	void addGeometricObject(ObjetoGeometrico* ptrObject);
	void build();
	void buildSphere();
	void drawScene() const;

	void buildTriangle();
	void drawTriangle() const;
	
	void addLight(Luz* ptrLight);

public:
	ViewPlane viewPlane;
	ColorRGB backgroundColor;
	Tracer*	tracerPtr;
	Esfera sphere;
	Triangulo triangle;
	std::vector<ObjetoGeometrico*> objects;
	std::vector<Luz*> lights;
	
private:
	void delete_objects();
	void delete_lights();
};
