#pragma once
#include"Libs.h"
#include"Uzytkownik.h"

class UserDatabase
{
private:
	vector<shared_ptr<Uzytkownik>> users;
	UserDatabase();  //zaladowanie uzytkownikow

	vector<string> rozdzielWiersz(const string& wiersz);

public:
	vector<shared_ptr<Uzytkownik>> getUsers() const;

	static UserDatabase& getInstance();

	void update(const Uzytkownik& u);

	static shared_ptr<Uzytkownik> makeUzytkownikSharedPointer(const Uzytkownik& w);

	Uzytkownik znajdUzytkownikaPoLoginie(const string& login);

	friend ostream& operator<<(ostream& out, const UserDatabase& u);


	~UserDatabase()= default;
};

