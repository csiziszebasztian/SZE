#pragma once
#include <string>


class Termek
{
protected:
	const std::string name;
	int price;

public:
	Termek(const std::string&, int);
	virtual ~Termek(){}
	virtual std::string getName()const = 0;
	virtual std::string getFullName() const = 0;
	virtual bool operator==(Termek& other);


};

