#pragma once
#include <string>
#include <vector>
#include"Domain.h"
using namespace std;
class Repo
{

private:
	//vector<TrenchCoat> coats;
public:
	// default constructor for a DynamicVector
	vector<TrenchCoat> coats;

	

	Repo();
	/// <summary>
	/// adds a coat to the repo, return 1 if succesfull and -1 otherwise
	/// </summary>
	/// <param name="p"></param>
	/// <returns></returns>
	void add_repo(TrenchCoat p);
	/// <summary>
	/// return the size of the dynamic vector of trenchcoats
	/// </summary>
	/// <returns></returns>
	int get_repo_size() const;
	/// <summary>
	/// remove a trench coat from the repo return -1 if the coat doaes not exists 1 otherwise
	/// </summary>
	/// <param name="price"></param>
	/// <param name="color"></param>
	/// <returns></returns>
	void remove_repo(double price, string color);
	/// <summary>
	/// return the position of the coat found or -1 is nothing was found
	/// </summary>
	/// <param name="price"></param>
	/// <param name="color"></param>
	/// <returns></returns>
	int find(double price, string color);
	/// <summary>
	/// update te trench coat found by price and color (updates with the info in size ,quantity,photo)
	/// </summary>
	/// <param name="price"></param>
	/// <param name="color"></param>
	/// <param name="size"></param>
	/// <param name="quanity"></param>
	/// <param name="photo"></param>
	/// <returns></returns>
	void update(double price, string color, string size, int quanity, string photo);
	/// <summary>
	/// initialize the repo with 10 entryes on start
	/// </summary>
	//void start_entries();
	/// <summary>
	/// get the trenchcoat on postion pos
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	TrenchCoat get_coat(int pos);


	//	string getSize() const;
	//	string getColour() const;
	//	double getPrice() const;
	//	int getQuantity() const;
	//	string getPhoto() const;

	vector<TrenchCoat> filter(string size);

	int count(string size);
	vector<TrenchCoat> filter_null();

	//friend ostream& operator<<(ostream& out, TrenchCoat& t);
	vector<TrenchCoat> get_vect_repo();

	

	friend ostream& operator<<(ostream& out, const Repo& t);
	friend istream& operator>>(istream& is, Repo& t);
};
void testRepo();

class MyException : public std::exception
{
private:
	string message;

public:
	MyException(const string& s) : message{ s } {}

	const char* what() const throw() override {
		return this->message.c_str();
	}
};

class RepoHTML : public Repo
{
private:


public:
	void save_html(string filename);
	void display_html(string filename);
};

class RepoCSV : public Repo
{
private:


public:
	void save_CSV(string filename);
	void display_csv(string filename);
};