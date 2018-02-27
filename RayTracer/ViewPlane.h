#pragma once

class ViewPlane
{
public:
	ViewPlane();								// Constructor por defecto
	ViewPlane(const ViewPlane& vp);				// Constructor coipa
	ViewPlane(int _Rver, int _Rhor, double _s);	// Constructor
	~ViewPlane();

	ViewPlane& operator= (const ViewPlane& rhs);// Operador de asignacion
	void setVerticalResolution(const int& Rhor);
	void setHorizontalResolution(const int& Rver);
	void setResolutions(const int& horizontalResolution, const int& verticalResolution);
	void setPixelSize(const float& size);
	
	// Datos
	int verticalResolution;		// Resolucion vertical
	int horizontalResolution;	// Resolucion horizontal
	double pixelSize;			// Tamaño del pixel
};
