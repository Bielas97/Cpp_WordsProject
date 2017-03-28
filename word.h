#pragma once
#include "Libs.h"

class word
{
private:
	string id;
	string EngWord;
	string PolWord;
	string Kategoria;
	string statystka;
public:

	void setId(const string& i);
	void setEngWord(const string& i);
	void setPolWord(const string& p);
	void setKategoria(const string& i);
	void setStatystyka(const string& i);

	string getId() const;
	string getEngWord() const;
	string getPolWord() const;
	string getKategoria() const;
	string getStatystyka() const;

	word operator=(const word& w);

	bool operator==(const word& w);


	word(const string& i, const string& eng, const string& pol, const string& kat, const string& st) : id(i), EngWord(eng),
		PolWord(pol), Kategoria(kat), statystka(st) {};

	word(const word& w);

	friend ostream& operator<<(ostream& out, const word& w);

	word() = default;
	~word() = default;
};

