#pragma once
#include <map>
#include "Termek.h"




class Keszlet
{
	std::map<Termek*, int> keszlet;
public:
	void addTermek(Termek*, int);
	int getQuantity(Termek*);
	bool rendel(Termek*, int);
};

