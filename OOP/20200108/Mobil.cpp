#include "Mobil.h"
#include <typeinfo>


Mobil::Mobil(const std::string& name, int price, bool lte, bool nfc) : Termek(name, price), LTE(lte), NFC(nfc)
{
}

std::string Mobil::getName() const
{
	return name;
}

std::string Mobil::getFullName() const
{
	std::string fullname = name;
	if (LTE) fullname += " LTE";
	if (NFC) fullname += " NFC";
	return fullname;

}

bool Mobil::operator==(Termek& other)
{
	try {
		auto& mobil = dynamic_cast<Mobil&>(other);
		return name == mobil.name and price == mobil.price and LTE == mobil.LTE and NFC == mobil.NFC;
	}
	catch (std::bad_cast ex) {
		return false;
	}
}