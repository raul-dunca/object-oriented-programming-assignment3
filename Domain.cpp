#include "Domain.h"
#include<string>
TrenchCoat::TrenchCoat(string s, string c, double price, int quantity, string photograph)
{
	this->size = s;
	this->colour = c;
	this->price = price;
	this->quantity = quantity;
	this->photograph = photograph;

}
TrenchCoat::TrenchCoat() :size{ "" }, colour{ "" }, price{ 0 }, quantity{ 0 }, photograph{ "" }
{
}

string TrenchCoat::getSize() const
{
	return this->size;
}

string TrenchCoat::getColour() const
{
	return this->colour;
}
double TrenchCoat::getPrice() const
{
	return this->price;
}
int TrenchCoat::getQuantity() const
{
	return this->quantity;
}
string TrenchCoat::getPhoto() const
{
	return this->photograph;
}
void TrenchCoat::setPhoto(string newphoto)
{
	this->photograph = newphoto;
}
void TrenchCoat::setQuantity(int newqant)
{
	this->quantity = newqant;
}

void TrenchCoat::setSize(string newsize)
{
	this->size = newsize;
}
void TrenchCoat::setColour(string newcol)
{
	this->colour = newcol;
}
void TrenchCoat::setPrice(int newprice)
{
	this->price = newprice;
}

