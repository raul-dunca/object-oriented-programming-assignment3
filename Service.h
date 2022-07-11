#pragma once
#include "Repo.h"
#include "Actions.h"
class Service
{
private:
	//Repo repo;

public:
	Repo repo;
	Repo userRepo;
	RepoHTML htmlrepo;
	RepoCSV csvrepo;
	
	//Service(Repo repository);
	
	
	std::vector<std::unique_ptr<Action>> actions_undo;
	std::vector<std::unique_ptr<Action>> actions_redo;

	/// <summary>
	/// the service defaul constructor
	/// </summary>
	Service();
	/// <summary>
	/// adds the coat with the following parameters
	/// </summary>
	/// <param name="s"></param>
	/// <param name="c"></param>
	/// <param name="price"></param>
	/// <param name="quantity"></param>
	/// <param name="photograph"></param>
	/// <returns></returns>
	void addCoat(string s, string c, double price, int quantity, string photograph);
	/// <summary>
	/// delete the trench coat with the specific price and colour
	/// </summary>
	/// <param name="price"></param>
	/// <param name="color"></param>
	/// <returns></returns>
	void deleteCoat(double price, string color);
	/// <summary>
	/// update de coat with the specific price and color (updates its size with size, qunatity w quantit and photograph with photo)
	/// </summary>
	/// <param name="price"></param>
	/// <param name="color"></param>
	/// <param name="size"></param>
	/// <param name="quanity"></param>
	/// <param name="photo"></param>
	/// <returns></returns>
	void updateCoar(double price, string color, string size, int quanity, string photo);
	/// <summary>
	/// return the size od the vector of coat  from repo
	/// </summary>
	/// <returns></returns>
	int getSize_serv() const;
	/// <summary>
	/// return the element found at positon pos
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	TrenchCoat get_element(int pos);


	vector<TrenchCoat> filter_serv(string size);

	vector<TrenchCoat> filter_null_serv();

	vector<TrenchCoat> get_vector();
	
	
	int undo();
	int redo();

	friend ostream& operator<<(ostream& out, const Service& t);
	friend istream& operator>>(istream& is, Service& t);
};
void testServ();
