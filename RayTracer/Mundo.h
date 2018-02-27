#pragma once

#include <vector>


#include "Esfera.h"
#include "EsferaSola.h"
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
	void addLight(Luz* ptrLight);

	ViewPlane viewPlane;
	ColorRGB backgroundColor;
	Tracer*	tracerPtr;
	Esfera sphere;
	std::vector<ObjetoGeometrico*> objects;
	std::vector<Luz*> lights;
	
private:
	void delete_objects();
	void delete_lights();
};
