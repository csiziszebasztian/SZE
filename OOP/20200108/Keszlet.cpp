#include "Keszlet.h"

void Keszlet::addTermek(Termek* ter, int pcs)
{


	/*auto t = keszlet.find(ter);
	if (*ter == *((*t).first)) {
		(*t).second += pcs;
	}*/

	bool in=false;
	for (auto& it : keszlet) {
		if (*ter == *it.first) {
			it.second += pcs;
			in = true;
		}
	}
	if(!in) keszlet.insert(std::make_pair(ter, pcs));
}

int Keszlet::getQuantity(Termek* ter)
{
	for (auto& it : keszlet) {
		if (*ter == *it.first) 
			return it.second;
	}
	return 0;
}

bool Keszlet::rendel(Termek* ter, int pcs)
{
	auto t = keszlet.find(ter);
	if ((*t).second >= pcs) {
		(*t).second -= pcs;
		return true;
	}
	else return false;
}


