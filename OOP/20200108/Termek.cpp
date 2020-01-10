#include "Termek.h"

Termek::Termek(const std::string& name, int price): name(name), price(price)
{
}

bool Termek::operator==(Termek& other)
{
	return name == other.name and price == other.price;
}
