#pragma once
#include "Termek.h"
class Laptop :
	public Termek
{
public:
	Laptop(const std::string& name, int price);
	virtual ~Laptop() {}
	virtual std::string getName()const override;
	virtual std::string getFullName() const override;
};

