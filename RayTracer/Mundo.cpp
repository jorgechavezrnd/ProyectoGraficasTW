#include "stdafx.h"
#include "Mundo.h"

Mundo::Mundo() 
  : backgroundColor(blanco),
	tracerPtr(nullptr) 
{
}

Mundo::~Mundo()
{
	delete tracerPtr;
	tracerPtr = NULL;
	delete_objects();
	delete_lights();
}

void Mundo::addGeometricObject(ObjetoGeometrico* ptrObject)
{
	objects.push_back(ptrObject);
}

void Mundo::build()
{
	viewPlane.setResolutions(700, 800);
	viewPlane.setPixelSize(0.4);
	tracerPtr = new EsferaSola(this);
	buildSphere();
	addLight(new LuzPuntual{
		Punto3D(0.0, 160.0, 200.0),
		blanco
	});
}

void Mundo::buildSphere()
{
	sphere.establecerCentro(0.0);
	sphere.establecerRadio(90.0);
}

// Vista paralela ortografica
void Mundo::drawScene() const
{
	int n = viewPlane.horizontalResolution * viewPlane.verticalResolution;
	ColorRGB* colors = new ColorRGB[n];
	ColorRGB colorPixel;
	Rayo	 rayo;
	int Rhor = viewPlane.horizontalResolution;
	int Rver = viewPlane.verticalResolution;

	rayo.vecD = Vector3D(0.0, 0.0, -1.0);

	for (int fila = 0; fila < Rver; fila++)
	{
		for (int col = 0; col < Rhor; col++)
		{
			// DISPARAMOS UN RAYO---------------------------------------------------------
			double x_w = viewPlane.pixelSize * (col - viewPlane.horizontalResolution / 2 + 0.5);   // coordenada x
			double y_w = viewPlane.pixelSize * (fila - viewPlane.verticalResolution / 2 + 0.5);  // coordenada y
			double z_w = 100.0;				   		         // coordenada z	
			Punto3D O(x_w, y_w, z_w);				         // Punto O		
			rayo.O = O;
			colorPixel = tracerPtr->trace_ray(rayo);
			colors[fila * Rhor + col] = colorPixel;
		}
	}
	Salida salida;
	int dpi = 72;
	salida.savebmp("escena.bmp", Rhor, Rver, dpi, colors);
}

void Mundo::addLight(Luz* ptrLuz)
{
	lights.push_back(ptrLuz);
}

void Mundo::delete_objects()
{
	for (int j = 0; j < objects.size(); j++)
	{
		delete objects[j];
		objects[j] = NULL;
	}
	objects.erase(objects.begin(), objects.end());
}

void Mundo::delete_lights()
{
	for (int j = 0; j < lights.size(); j++)
	{
		delete lights[j];
		lights[j] = NULL;
	}
	lights.erase(lights.begin(), lights.end());
}
