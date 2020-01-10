#include <iostream>

#include "Termek.h"
#include "Mobil.h"
#include "Laptop.h"
#include "Keszlet.h"

// K�sz�tsen programot mobiltelefonok �s laptopok lelt�ri nyilv�ntart�s�ra
// az al�bbiak szerint:
//
// A Laptop �s Mobil objektumok egyfajta Term�kek
// A Laptop p�ld�nyos�t�sakor meg kell adni a laptop nev�t �s �r�t
// A Mobil p�ld�nyos�t�sakor meg kell adni a mobil nev�t, �r�t �s hogy t�mogatja-e az LTE-t ill. NFC-t
// A Term�knek legyen egy getName() met�dusa, ami adja vissza stringk�nt a konstruktorban megadott nevet
// Legyen egy getFullName() met�dus is, ami Laptop eset�n ugyanaz, mint a getName(),
// viszont Mobil eset�n f�zze hozz� a t�mogatott technol�gi�k nev�t, pl.: "iPhone LTE NFC"
//
// A K�szlet oszt�ly feladata tetsz�leges Term�kek darabsz�m�nak t�rol�sa
// Az addTermek() met�dusa egy Term�kre mutat� pointert �s egy darabsz�mot v�r
// -- ami a k�szleten fellelhet� darabok sz�m�t jelenti
// A getQuantity() met�dusa egy Term�kre mutat� pointert v�r, �s visszaadja, hogy
// az adott Term�kb�l h�ny darab lelhet� fel a k�szletben
// A rendel() met�dusa egy Term�kre mutat� pointert v�r, illetve egy darabsz�mot,
// �s ha a term�kb�l van el�g k�szleten, azt cs�kkentse, �s t�rjen vissza igazzal,
// ha nincs el�g k�szleten, ne cs�kkentse a darabsz�mot, csak t�rjen vissza hamissal

// Az alapfeladatban felt�telezheti, hogy ha 2 Term�k mem�riac�me k�l�nb�z�, akkor az 2 k�l�nb�z� term�k

// +1 jegy, ha a Term�k objektumokat nem mem�riac�m�k alapj�n hasonl�tja �ssze, hanem
// akkor tekint egyez�nek 2 Term�ket, ha adattagjaik megegyeznek
// Tov�bbi +1 jegy, ha az �sszehasonl�t�shoz fel�ldefini�lja a Term�kek k�z�tti == oper�tort
// Megj.: Figyelni kell r�, hogy a Mobilnak olyan adattagjai is vannak, amik a Laptopnak nincsenek

// +1 jegy, ha a K�szlet std::map-ben t�rolja a Term�k-db p�rokat

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








