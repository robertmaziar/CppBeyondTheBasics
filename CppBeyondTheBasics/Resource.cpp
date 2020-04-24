#include "Resource.h"
#include <iostream>

Resource::Resource(std::string n)
{
	std::cout << "constructing " << name << std::endl;
}

Resource::Resource(const Resource& r) : name(r.name)
{
	std::cout << "copy constructing " << name << std::endl;
}

Resource& Resource::operator=(const Resource& r)
{
	// If this class managed Resource lifetime, clean up existing one
	// before setting new values. No need here because string takes care of it
	name = r.GetName();
	std::cout << "copy assigning " << name << std::endl;
	return *this;
}

Resource::~Resource(void)
{
	// If this class managed Resource lifetime, clean up existing one
	// No need here because string takes care of it
	std::cout << "destructing " << name << std::endl;
}
