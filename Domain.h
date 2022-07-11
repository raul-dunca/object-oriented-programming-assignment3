#pragma once
#include <string>
#include<iostream>
using namespace std;
class TrenchCoat
{
private:
	string size;
	string colour;
	double price;
	int quantity;
	string photograph;
public:
	/// <summary>
	/// Constructor, creates a new trench coat with the given characteristics
	/// </summary>
	/// <param name="s">the size</param>
	/// <param name="c">the color</param>
	/// <param name="price">the price</param>
	/// <param name="quantity">the quantity</param>
	/// <param name="photograph">the photo</param>
	TrenchCoat(string s, string c, double price, int quantity, string photograph);
	/// <summary>
	/// Defaul constructor
	/// </summary>
	TrenchCoat();
	/// <summary>
	/// returnes the parameter size from the Trench Coat
	/// </summary>
	/// <returns></returns>
	string getSize() const;
	/// <summary>
	/// returnes the parameter colour from the Trench Coat
	/// </summary>
	/// <returns></returns>
	string getColour() const;
	/// <summary>
	/// returnes the parameter price from the Trench Coat
	/// </summary>
	/// <returns></returns>
	double getPrice() const;
	/// <summary>
	/// returnes the parameter quantity from the Trench Coat
	/// </summary>
	/// <returns></returns>
	int getQuantity() const;
	/// <summary>
	/// returnes the parameter photograph from the Trench Coat
	/// </summary>
	/// <returns></returns>
	string getPhoto() const;

	/// <summary>
	/// set the photo of the trench coat to the new one
	/// </summary>
	/// <param name="newphoto"></param>
	void setPhoto(string newphoto);
	/// <summary>
	/// set the size of the trench coat to the new one
	/// </summary>
	/// <param name="newphoto"></param>
	void setSize(string newsize);
	/// <summary>
	/// set the quantity of the trench coat to the new one
	/// </summary>
	/// <param name="newphoto"></param>
	void setQuantity(int newquant);


	void setColour(string newcol);

	void setPrice(int newprice);



	friend ostream& operator<<(ostream& out, const TrenchCoat& t);
	friend istream& operator>>(istream& is, TrenchCoat& t);



private:

};
inline std::ostream& operator<<(std::ostream& out, const TrenchCoat& t)
{

	//ofstream os("t.out");
	out << t.getSize() << " " << t.getColour() << " " << t.getPrice() << " " << t.getQuantity() << " " << t.getPhoto() << endl;
	return out;

}
inline std::istream& operator>>(istream& is, TrenchCoat& t)
{
	string s, colour, photo;
	double price;
	int quant;
	is >> s;
	t.setSize(s);
	is >> colour;
	t.setColour(colour);
	is >> price;
	t.setPrice(price);
	is >> quant;
	t.setQuantity(quant);
	is >> photo;
	t.setPhoto(photo);




	is.ignore(1024, '\n'); // after reading the trenchCoat, skip the trailing '\n'
	return is;
}