#pragma once
#include "Repo.h"
class Action
{
public:

	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};

class ActionAdd : public Action
{
protected:
	TrenchCoat addSong;
	Repo& repo;
public:
	ActionAdd(TrenchCoat s, Repo& r) :addSong{ s }, repo{ r }
	{
	}
	void executeUndo() override
	{
		this->repo.remove_repo(this->addSong.getPrice(),this->addSong.getColour());
	}
	void executeRedo() override
	{
		this->repo.add_repo(this->addSong);
	}
};

class ActionRemove : public Action
{
protected:
	TrenchCoat deletedSong;
	Repo& repo;
public:


	ActionRemove(TrenchCoat s, Repo& r) :deletedSong{ s }, repo{ r }
	{
	}
	void executeUndo() override
	{
		this->repo.add_repo(this->deletedSong);
	}
	void executeRedo() override
	{
		this->repo.remove_repo(this->deletedSong.getPrice(),this->deletedSong.getColour());
	}

};
class ActionUpdae : public Action
{
protected:
	TrenchCoat oldCoat;
	TrenchCoat newCoat;
	Repo& repo;
public:


	ActionUpdae(TrenchCoat old, TrenchCoat newc, Repo& r) :oldCoat{old},newCoat{newc},repo{r}
	{
	}
	void executeUndo() override
	{
		this->repo.update(this->newCoat.getPrice(), this->newCoat.getColour(), this->oldCoat.getSize(), this->oldCoat.getQuantity(), this->oldCoat.getPhoto());
	}
	void executeRedo() override
	{
		this->repo.update(this->oldCoat.getPrice(),this->oldCoat.getColour(), this->newCoat.getSize(), this->newCoat.getQuantity(), this->newCoat.getPhoto());

	}

};