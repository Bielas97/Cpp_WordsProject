#include "word.h"



void word::setId(const string & i)
{
	id = i;
}

void word::setEngWord(const string & i)
{
	EngWord = i;
}

void word::setPolWord(const string & p)
{
	PolWord = p;
}


void word::setKategoria(const string & i)
{
	Kategoria = i;
}

void word::setStatystyka(const string & i)
{
	statystka = i;
}

string word::getId() const
{
	return id;
}

string word::getEngWord() const
{
	return EngWord;
}

string word::getPolWord() const
{
	return PolWord;
}

string word::getKategoria() const
{
	return Kategoria;
}

string word::getStatystyka() const
{
	return statystka;
}

word word::operator=(const word & w)
{
	this->id = w.id;
	this->EngWord = w.EngWord;
	this->PolWord = w.PolWord;
	this->Kategoria = w.Kategoria;
	this->statystka = w.statystka;
	return *this;
}

bool word::operator==(const word & w)
{
	if (this->id == w.id && this->EngWord == w.EngWord && this->PolWord == w.PolWord &&
		this->statystka == w.statystka && this->Kategoria == w.Kategoria)
	{
		return true;
	}
	return false;
}


word::word(const word & w)
{
	id = w.id;
	EngWord = w.EngWord;
	PolWord = w.PolWord;
	Kategoria = w.Kategoria;
	statystka = w.statystka;
}

ostream & operator<<(ostream & out, const word & w)
{
	out << w.id << " " << w.EngWord << " " << w.PolWord << " " << w.Kategoria << " " << w.statystka;
	//out << w.EngWord << " " << w.PolWord << " kategoria: " << w.Kategoria << " id: " << w.id << " statystyka: " << w.statystka << endl;
	return out;
}
