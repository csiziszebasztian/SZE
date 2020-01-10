#include "Laptop.h"


Laptop::Laptop(const std::string& name, int price) : Termek(name, price)
{
}


std::string Laptop::getName() const
{
	return name;
}

std::string Laptop::getFullName() const
{
	return getName();
}