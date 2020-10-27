#pragma once

#include "Object_7.h"

class Sphere : public RenderableObject
{
public:
	Sphere();
	~Sphere(){}

public:
	virtual void shutDown() override;
};