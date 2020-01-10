#pragma once
#include "Termek.h"
class Mobil :
	public Termek
{
	bool LTE;
	bool NFC;
public:
	Mobil(const std::string& name, int price, bool lte, bool nfc);
	virtual ~Mobil() {}
	virtual std::string getName()const override;
	virtual std::string getFullName() const override;
	virtual bool operator==(Termek& other);
};

