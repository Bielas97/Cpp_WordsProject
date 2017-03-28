#include "Uzytkownik.h"

ostream & operator<<(ostream & out, const Uzytkownik & u)
{
	out << u.login << " " << u.haslo << " " << u.id << " " << u.imie << " " << u.nazwisko;
	return out;
}

void Uzytkownik::setLogin(const string & l)
{
	login = l;
}

void Uzytkownik::setHaslo(const string & l)
{
	haslo = l;
}

void Uzytkownik::setId(const string & l)
{
	id = l;
}

void Uzytkownik::setImie(const string & l)
{
	imie = l;
}

void Uzytkownik::setNazwisko(const string & l)
{
	nazwisko = l;
}

string Uzytkownik::getLogin() const
{
	return login;
}

string Uzytkownik::getHaslo() const
{
	return haslo;
}

string Uzytkownik::getId() const
{
	return id;
}

string Uzytkownik::getImie() const
{
	return imie;
}

string Uzytkownik::getNazwisko() const
{
	return nazwisko;
}

Uzytkownik Uzytkownik::operator=(const Uzytkownik & u)
{
	this->login = u.login;
	this->haslo = u.haslo;
	this->id = u.id;
	this->imie = u.imie;
	this->nazwisko = u.nazwisko;

	return *this;
}

Uzytkownik::Uzytkownik()
{
	setImie("admin");
	setHaslo("admin");
	setId("admin");
	setNazwisko("admin");
	setLogin("admin");
}


