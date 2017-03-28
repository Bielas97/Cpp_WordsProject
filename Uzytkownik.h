#pragma once
#include"Libs.h"

class Uzytkownik
{
private:
	string login;
	string haslo;
	string id;
	string imie;
	string nazwisko;

public:

	void setLogin(const string& l);
	void setHaslo(const string& l);
	void setId(const string& l);
	void setImie(const string& l);
	void setNazwisko(const string& l);

	string getLogin() const;
	string getHaslo() const;
	string getId() const;
	string getImie() const;
	string getNazwisko() const;


	Uzytkownik operator=(const Uzytkownik& u);

	Uzytkownik(const string& l, const string& h, const string& ID, const string& im, const string& na) : login(l), haslo(h),
		id(ID), imie(im), nazwisko(na) {};

	friend ostream& operator<<(ostream& out, const Uzytkownik& u);

	//friend istream& operator >> (istream& in, const Uzytkownik& u);

	~Uzytkownik() = default;
	Uzytkownik();
};

