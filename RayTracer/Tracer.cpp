#include "stdafx.h"
#include "Tracer.h"

Tracer::Tracer(void)
	: world_ptr(NULL)
{
}

Tracer::Tracer(Mundo* _worldPtr)
	: world_ptr(_worldPtr)
{
}

Tracer::~Tracer(void) {
	if (world_ptr) {
		world_ptr = NULL;
	}
}

ColorRGB Tracer::trace_ray(const Rayo& ray) const 
{
	return (negro);
}

ColorRGB Tracer::trace_ray(const Rayo ray, const int depth) const 
{
	return (negro);
}
