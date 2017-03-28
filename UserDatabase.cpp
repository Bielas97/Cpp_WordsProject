#include "UserDatabase.h"



UserDatabase::UserDatabase()
{
	//zaladowanie uzytkownikow

	ifstream odczyt;
	odczyt.open("baza.txt");
	if (odczyt.is_open())
	{
		string temp;
		while (!odczyt.eof())
		{
			getline(odczyt, temp);
			if (temp.length() > 2)
			{
				vector<string> slowa = rozdzielWiersz(temp);

				users.push_back(makeUzytkownikSharedPointer(Uzytkownik(slowa[0], slowa[1], slowa[2], slowa[3], slowa[4])));
				slowa = {};
			}
		}
		odczyt.close();
	}
	else
	{
		cout << " blad odczytu" << endl;
	}
}

vector<string> UserDatabase::rozdzielWiersz(const string & wiersz)
{
	vector<string> slowa;
	string temp = "";
	for (int i = 0; i < wiersz.length(); i++)
	{
		if (wiersz[i] == ' ' || wiersz[i] == '\0')
		{
			slowa.push_back(temp);
			temp = "";
		}
		else
		{
			temp += wiersz[i];
		}
	}
	slowa.push_back(temp);
	return slowa;
}

shared_ptr<Uzytkownik> UserDatabase::makeUzytkownikSharedPointer(const Uzytkownik & w)
{
	return shared_ptr<Uzytkownik>(new Uzytkownik(w));
}

vector<shared_ptr<Uzytkownik>> UserDatabase::getUsers() const
{
	return users;
}

UserDatabase & UserDatabase::getInstance()
{
	static UserDatabase ud;
	return ud;
}

void UserDatabase::update(const Uzytkownik& u)
{
	//vector<shared_ptr<Uzytkownik>> us = getInstance().getUsers();
	//us.push_back(makeUzytkownikSharedPointer(u));

	//us.push_back(makeUzytkownikSharedPointer(u));
	//getInstance().getUsers().push_back(makeUzytkownikSharedPointer(u));

	users.push_back(makeUzytkownikSharedPointer(u));

	ofstream zapis("baza.txt", std::ios::app);
	if (zapis.is_open())
	{
		zapis << u << endl;
		zapis.close();
	}
	else
	{
		cout << "blad w zapisie do pliku" << endl;
	}
}

Uzytkownik UserDatabase::znajdUzytkownikaPoLoginie(const string & login)
{
	Uzytkownik szukany;

	//vector<shared_ptr<Uzytkownik>> us = getInstance().getUsers();

	for (int i = 0; i < users.size(); i++)
	{
		if (login == users[i]->getLogin()) szukany = *users[i];
	}
	return szukany;
}

ostream & operator<<(ostream & out, const UserDatabase & u)
{
	for (const auto& a : u.users)
	{
		cout << *a;
	}
	return out;
}
