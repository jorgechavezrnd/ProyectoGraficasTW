#include "stdafx.h"
#include "ViewPlane.h"

ViewPlane::ViewPlane()
  : verticalResolution(400), 
	horizontalResolution(400), 
	pixelSize(1.0)
{
}

ViewPlane::ViewPlane(const ViewPlane& vp)
  : verticalResolution(vp.verticalResolution),
	horizontalResolution(vp.horizontalResolution), 
	pixelSize(vp.pixelSize)
{
}

ViewPlane::ViewPlane(int _Rver, int _Rhor, double _s) 
  : verticalResolution(_Rver),
	horizontalResolution(_Rhor),
	pixelSize(_s)
{
}

ViewPlane::~ViewPlane()
{
}

ViewPlane& ViewPlane::operator=(const ViewPlane& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	horizontalResolution = rhs.horizontalResolution;
	verticalResolution = rhs.verticalResolution;
	pixelSize = rhs.pixelSize;
	return *this;
}

void ViewPlane::setVerticalResolution(const int& _Rhor)
{
	horizontalResolution = _Rhor;
} 

void ViewPlane::setHorizontalResolution(const int& _Rver)
{
	verticalResolution = _Rver;
}

void ViewPlane::setResolutions(const int& horizontalResolution, const int& verticalResolution)
{
	setVerticalResolution(verticalResolution);
	setHorizontalResolution(horizontalResolution);
}

void ViewPlane::setPixelSize(const float& _s)
{
	pixelSize = _s;
}
