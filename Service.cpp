#include "Service.h"
#include "assert.h"
#include "Validator.h"
#include <fstream>
Service::Service()
{
	this->repo = Repo();
	
	
	//this->repo.start_entries();
}
//Service::Service(): repo{}
//{}
void Service::addCoat(string s, string c, double price, int quantity, string photograph)
{
	TrenchCoat tc{ s, c, price, quantity, photograph };

	CoatValidator::validate(tc);




	this->repo.add_repo(tc);


	std::unique_ptr<Action> ptr1 = std::make_unique<ActionAdd>(tc, this->repo);
	this->actions_undo.push_back(move(ptr1));

	
}
int Service::undo()
{
	if (this->actions_undo.size() == 0)
		return 0;
	else
	{
		auto pt1 = move(this->actions_undo[this->actions_undo.size() - 1]);
		pt1->executeUndo();

		this->actions_redo.push_back(move(pt1));

		this->actions_undo.pop_back();
		return 1;
	}
}
int Service::redo()
{
	if (this->actions_redo.size() == 0)
		return 0;
	else
	{
		auto pt1 = move(this->actions_redo[this->actions_redo.size() - 1]);
		pt1->executeRedo();

		this->actions_undo.push_back(move(pt1));

		this->actions_redo.pop_back();
		return 1;
	}
}

void Service::deleteCoat(double price, string color)
{
	int k;
	k = this->repo.find(price, color);
	if (k==-1)
		throw MyException{ "\nCoat is not in repo!\n" };
	else
	{
		TrenchCoat tc = this->repo.coats[k];
		this->repo.remove_repo(price, color);
		std::unique_ptr<Action> ptr1 = std::make_unique<ActionRemove>(tc, this->repo);
		this->actions_undo.push_back(move(ptr1));
	}
}
void Service::updateCoar(double price, string color, string size, int quanity, string photo)
{
	TrenchCoat tc{ size, color, price,quanity, photo };
	CoatValidator::validate(tc);

	int k;
	k = this->repo.find(price, color);
	if (k == -1)
		throw MyException{ "\nCoat is not in repo!\n" };
	else
	{
		TrenchCoat oldtc = this->repo.coats[k];
		this->repo.update(price, color, size, quanity, photo);
		std::unique_ptr<Action> ptr1 = std::make_unique<ActionUpdae>(oldtc,tc, this->repo);
		this->actions_undo.push_back(move(ptr1));

	}
	
}
int Service::getSize_serv() const
{
	return this->repo.get_repo_size();
}

TrenchCoat Service::get_element(int pos)
{
	return this->repo.get_coat(pos);
}
vector<TrenchCoat> Service::filter_serv(string size)
{
	return this->repo.filter(size);
}
vector<TrenchCoat> Service::filter_null_serv()
{
	return this->repo.filter_null();
}
vector<TrenchCoat> Service::get_vector()
{
	return this->repo.get_vect_repo();
}
std::ostream& operator<<(std::ostream& out, const Service& s)
{

	out << s.repo;
	return out;
}
std::istream& operator>>(istream& is, Service& s)
{

	is >> s.repo;
	return  is;
}




