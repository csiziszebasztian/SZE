#include <iostream>

#include "Termek.h"
#include "Mobil.h"
#include "Laptop.h"
#include "Keszlet.h"

// Készítsen programot mobiltelefonok és laptopok leltári nyilvántartására
// az alábbiak szerint:
//
// A Laptop és Mobil objektumok egyfajta Termékek
// A Laptop példányosításakor meg kell adni a laptop nevét és árát
// A Mobil példányosításakor meg kell adni a mobil nevét, árát és hogy támogatja-e az LTE-t ill. NFC-t
// A Terméknek legyen egy getName() metódusa, ami adja vissza stringként a konstruktorban megadott nevet
// Legyen egy getFullName() metódus is, ami Laptop esetén ugyanaz, mint a getName(),
// viszont Mobil esetén fûzze hozzá a támogatott technológiák nevét, pl.: "iPhone LTE NFC"
//
// A Készlet osztály feladata tetszõleges Termékek darabszámának tárolása
// Az addTermek() metódusa egy Termékre mutató pointert és egy darabszámot vár
// -- ami a készleten fellelhetõ darabok számát jelenti
// A getQuantity() metódusa egy Termékre mutató pointert vár, és visszaadja, hogy
// az adott Termékbõl hány darab lelhetõ fel a készletben
// A rendel() metódusa egy Termékre mutató pointert vár, illetve egy darabszámot,
// és ha a termékbõl van elég készleten, azt csökkentse, és térjen vissza igazzal,
// ha nincs elég készleten, ne csökkentse a darabszámot, csak térjen vissza hamissal

// Az alapfeladatban feltételezheti, hogy ha 2 Termék memóriacíme különbözõ, akkor az 2 különbözõ termék

// +1 jegy, ha a Termék objektumokat nem memóriacímük alapján hasonlítja össze, hanem
// akkor tekint egyezõnek 2 Terméket, ha adattagjaik megegyeznek
// További +1 jegy, ha az összehasonlításhoz felüldefiniálja a Termékek közötti == operátort
// Megj.: Figyelni kell rá, hogy a Mobilnak olyan adattagjai is vannak, amik a Laptopnak nincsenek

// +1 jegy, ha a Készlet std::map-ben tárolja a Termék-db párokat

int main()
{
	Termek* laptop = new Laptop("Asus", 1000);
	Termek* mobil1 = new Mobil("Samsung", 180, false, false);
	Termek* mobil2 = new Mobil("Samsung", 350, true, false);
	Termek* mobil3 = new Mobil("Apple", 800, true, true);



	Keszlet keszlet;
	keszlet.addTermek(laptop, 15);
	keszlet.addTermek(mobil1, 9);
	keszlet.addTermek(mobil2, 23);

	std::cout << laptop->getFullName() << " " << keszlet.getQuantity(laptop) << " mennyisegben all rendelkezesre" << std::endl; // 15
	std::cout << mobil1->getFullName() << " " << keszlet.getQuantity(mobil1) << " mennyisegben all rendelkezesre" << std::endl; // 9
	std::cout << mobil2->getFullName() << " " << keszlet.getQuantity(mobil2) << " mennyisegben all rendelkezesre" << std::endl; // 23
	std::cout << mobil3->getFullName() << " " << keszlet.getQuantity(mobil3) << " mennyisegben all rendelkezesre" << std::endl; // 0


	std::cout << "done" << std::endl;

	bool siker = true;
	while (siker) {
		siker = keszlet.rendel(laptop, 4);
		std::cout << laptop->getName() << " mar csak " << keszlet.getQuantity(laptop) << " mennyisegben all rendelkezesre" << std::endl;
	}


	

	// ugyanaz mint mobil2
	Termek* mobil4 = new Mobil("Samsung", 350, true, false);
	// egyszer mar hozzadtunk mobil2-bol 23-at:
	keszlet.addTermek(mobil4, 5); // vajon most 28 van belole? +1 jegy
	std::cout << mobil4->getName() << " " << keszlet.getQuantity(mobil4) << " mennyisegben all rendelkezesre" << std::endl; // 28


	delete laptop;
	delete mobil1;
	delete mobil2;
	delete mobil3;
	delete mobil4;

	return 0;
}








