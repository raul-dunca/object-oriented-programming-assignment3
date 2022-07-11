#include "Repo.h"
#include <assert.h>
#include<algorithm>
//#include <iostream>
#include <fstream>
using namespace std;
Repo::Repo()
{
	string size, col, price, quant, photo;
	ifstream f("repo.in");
	while (f >> size >> col >> price >> quant >> photo)
	{
		TrenchCoat c{ size,col,stod(price),stoi(quant),photo };
		this->add_repo(c);

	}
}
void Repo::add_repo(TrenchCoat p)
{
	if (find(p.getPrice(), p.getColour()) == -1)

	{
		this->coats.push_back(p);
	}
	else
	{
		throw MyException{ "\nCoat already in repo!\n" };
	}

	
}
int Repo::get_repo_size() const
{
	return this->coats.size();
}

int Repo::find(double price, string color)
{
	int k = 0;
	for (auto i : this->coats)
	{
		if (i.getPrice() == price && i.getColour() == color)
		{
			return k;
		}
		k++;
	}
	return -1;
}
void  Repo::remove_repo(double price, string color)
{
	int k = find(price, color);
	if (k == -1)
		throw MyException{ "\nCoat is not in repo!\n" };
	else
	{
		this->coats.erase(this->coats.begin() + k);
	}
	
}
void Repo::update(double price, string color, string size, int quanity, string photo)
{
	int k = find(price, color);
	if (k == -1)
		throw MyException{ "\nCoat is not in repo!\n" };
	else
	{
		this->coats[k].setPhoto(photo);
		this->coats[k].setQuantity(quanity);
		this->coats[k].setSize(size);
	}
}
int Repo::count(string s)
{
	int k = 0;
	for (auto i : this->coats)
	{
		if (i.getSize() == s)
			k++;
	}
	return k;
}
vector<TrenchCoat> Repo::filter(string size)
{
	vector<TrenchCoat> v(this->count(size));
	copy_if(this->coats.begin(), this->coats.end(), v.begin(), [size](TrenchCoat t) { return t.getSize() == size; });
	return v;

}
vector<TrenchCoat> Repo::filter_null()
{
	vector<TrenchCoat> v;
	for (auto i : this->coats)
		v.push_back(i);
	return v;

}
//std::ostream& operator<<(std::ostream& out, TrenchCoat& t)
//{
//	out << t.getSize() << " " << t.getColour() << " " << t.getPrice() << " " << t.getQuantity() << " " << t.getPhoto();
//	return out;
//
//}

vector<TrenchCoat> Repo::get_vect_repo()
{
	return this->coats;
}

TrenchCoat Repo::get_coat(int pos)
{
	return this->coats[pos];
}

//void Repo::start_entries()
//{
//	add_repo(TrenchCoat("M", "brown", 149.99, 200, "https://ibb.co/7vGSTXB"));
//	add_repo(TrenchCoat("L", "grey", 139.90, 170, "https://ibb.co/ZxtrfJz"));
//	add_repo(TrenchCoat("S", "black", 210.10, 240, "https://ibb.co/KrRHKmS"));
//	add_repo(TrenchCoat("M", "green", 189.50, 210, "https://ibb.co/TvVFymy"));
//	add_repo(TrenchCoat("XL", "red", 310, 120, "https://ibb.co/TK1XqfW"));
//	add_repo(TrenchCoat("XS", "cream", 120.50, 55, "https://ibb.co/6YzJ3L1"));
//	add_repo(TrenchCoat("L", "black", 110.10, 250, "https://ibb.co/mT6DWqh"));
//	add_repo(TrenchCoat("S", "grey", 280.90, 80, "https://ibb.co/bgTxb7n"));
//	add_repo(TrenchCoat("L", "brown", 200, 40, "https://ibb.co/7kb8yzw"));
//
//}


std::ostream& operator<<(std::ostream& out, const Repo& r)
{
	for (auto i : r.coats)
	{
		out << i;
	}
	return out;

}
std::istream& operator>>(istream& is, Repo& r)
{

	TrenchCoat t;
	while (is >> t)
	{
		r.coats.push_back(t);
	}


	return is;
}


//Tests



void RepoHTML::save_html(string filename)
{

	ofstream ht(filename);
	//ht.open(filename);
	ht << "<!DOCTYPE html><html><head><title>TrenchCoats</title></head><body>";
	ht << "<table border='1'><tr><td>Size</td><td>Colour</td><td>Price</td><td>Quantity</td><td>Photograph</td>";

	for (auto i : this->coats)
	{
		ht << "<tr><td>" << i.getSize() << "</td><td>" << i.getColour() << "</td><td>" << i.getPrice() << "</td><td>" << i.getQuantity() << "</td><td><a href=" << i.getPhoto() << ">Link</a></td>";
	}
	ht << "</table></body></html>";
	ht.close();
}
void RepoHTML::display_html(string filename)
{
	system(string("start " + filename).c_str());
}
void RepoCSV::save_CSV(string filename)
{

	ofstream c(filename);
	//c.open(filename);
	for (auto i : this->coats)
	{
		c << i.getSize() << "," << i.getColour() << "," << i.getPrice() << "," << i.getQuantity() << "," << i.getPhoto() << "\n";


	}

	c.close();
}
void RepoCSV::display_csv(string filename)
{
	system(string("start " + filename).c_str());
}

