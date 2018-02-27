#include "stdafx.h"
#include "Mundo.h"

Mundo::Mundo() 
	: backgroundColor(negro), tracerPtr(nullptr) 
{
}

Mundo::~Mundo() 
{
	delete tracerPtr;
	tracerPtr = NULL;
	delete_objects();
	delete_lights();
}

void Mundo::addGeometricObject(ObjetoGeometrico* ptr_objeto)
{
	objects.push_back(ptr_objeto);
}

void Mundo::build() 
{
	viewPlane.establecerRhor(800);
	viewPlane.establecerRver(700);
	viewPlane.establecerS(0.4);
	backgroundColor = blanco;
	tracerPtr = new EsferaSola(this);
	sphere.establecerCentro(0.0);
	sphere.establecerRadio(90);
	// Luces
	LuzPuntual* ptrLuzPuntual = new LuzPuntual;
	ptrLuzPuntual->establecerUbicacion(0.0, 160.0, 200.0);
	ptrLuzPuntual->establecerColor(1.0,1.0,1.0);
	addLight(ptrLuzPuntual);
}

// Vista paralela ortografica
void Mundo::drawScene() const
{
	Salida salida;
	int dpi = 72;
	int n = viewPlane.Rhor * viewPlane.Rver;
	ColorRGB *colores = new ColorRGB[n];

	ColorRGB colorPixel;
	Rayo	 rayo;
	int Rhor = viewPlane.Rhor;
	int Rver = viewPlane.Rver;
	float s = viewPlane.s;
	float zw = 100;
	rayo.vecD = Vector3D(0.0, 0.0, -1.0);

	for (int fila = 0; fila < Rver; fila++)
	{
		for (int col = 0; col < Rhor; col++)
		{
			// DISPARAMOS UN RAYO---------------------------------------------------------
			double x_w = viewPlane.s * (col - viewPlane.Rhor / 2 + 0.5);   // coordenada x
			double y_w = viewPlane.s * (fila - viewPlane.Rver / 2 + 0.5);  // coordenada y
			double z_w = 100.0;				   		         // coordenada z	
			Punto3D O(x_w, y_w, z_w);				         // Punto O		
			rayo.O = O;
			colorPixel = tracerPtr->trace_ray(rayo);
			colores[fila * Rhor + col] = colorPixel;
		}
	}
	salida.savebmp("escena.bmp", Rhor, Rver, dpi, colores);
}

void Mundo::addLight(Luz* ptrLuz)
{
	lights.push_back(ptrLuz);
}

void Mundo::delete_objects() {

	for (int j = 0; j < objects.size(); j++) {
		delete objects[j];
		objects[j] = NULL;
	}

	objects.erase(objects.begin(), objects.end());
}

void Mundo::delete_lights() {

	for (int j = 0; j < lights.size(); j++) {
		delete lights[j];
		lights[j] = NULL;
	}

	lights.erase(lights.begin(), lights.end());
}
