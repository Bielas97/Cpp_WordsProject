#include "WordDatabase.h"



WordDatabase::WordDatabase()
{
	//pobieranie slowek z pliku
	string temp1 = "";

	ifstream odczyt;
	odczyt.open("dictionary.txt");
	if (odczyt.is_open())
	{
		vector<string> slowaTemp;
		while (!odczyt.eof())
		{
			getline(odczyt, temp1);
			//slowaTemp = rozdzielWiersz(temp1);
			
			for (int i = 0; i < rozdzielWiersz(temp1).size(); i++)
			{
				slowaTemp.push_back(rozdzielWiersz(temp1)[i]);
			}
			/*
			cout << slowaTemp[0]; // tu jest dobrze
			cout << slowaTemp[1]; //wyrzuca blad
			cout << slowaTemp[2]; //blad
			cout << slowaTemp[3]; // blad
			cout << "+++" << endl;*/
			words.push_back(makeWordSharedPointer(word(slowaTemp[0], slowaTemp[1], slowaTemp[2], slowaTemp[3], slowaTemp[4])));
			// words to wektor shared_ptr i jest to pole skladowe klasy WordDatabase i docelowo chcialbym miec w nim obiekty klasy
			//word zaladowane z pliku txt
			slowaTemp = {};
		}
		odczyt.close();
	}
	else
	{
		cout << "blad odczytu pliku" << endl;
	}
}

vector<string> WordDatabase::rozdzielWiersz(const string & wiersz)
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

shared_ptr<word> WordDatabase::makeWordSharedPointer(const word & w)
{
	return shared_ptr<word>(new word(w));
}

WordDatabase& WordDatabase::getInstance()
{
	static WordDatabase wd;
	return wd;
}

void WordDatabase::update2(const string& id, const string & statystyka)
{
	vector<shared_ptr<word>> wordsVector = getInstance().getWords();

	for (int i = 0; i < wordsVector.size(); i++)
	{
		if (wordsVector[i]->getId() == id)
		{
			wordsVector[i]->setStatystyka(wordsVector[i]->getStatystyka() + statystyka);
		}
	}

	ofstream zapis;
	zapis.open("dictionary.txt");
	if (zapis.is_open())
	{
		for (int i =0; i<wordsVector.size()-1; i++)
		{
			zapis << *wordsVector[i] << endl;
		}
		zapis << *wordsVector[wordsVector.size() - 1];
		zapis.close();
	}
	else
	{
		cout << "blad zapisu" << endl;
	}
}

std::vector<shared_ptr<word>> WordDatabase::getWords() const
{
	return words;
}

int WordDatabase::ileZer(const string & w)
{
	int counter = 0;
	for (int i = 0; i < w.length(); i++)
	{
		if (w[i] == '0') counter++;
	}
	return counter;
}

int WordDatabase::wspZer()
{
	int idx;
	vector<shared_ptr<word>> temp = WordDatabase::getInstance().getWords();
	double wsp = 0.0;
	double maxWsp = 0.0;
	double t;

	for (int i = 0; i < temp.size(); i++)
	{
		t = temp[i]->getStatystyka().length();
		wsp = ileZer(temp[i]->getStatystyka()) / t;
		//cout << wsp << endl;
		if (wsp > maxWsp) maxWsp = wsp;
	}

	auto a = std::find_if(temp.begin(), temp.end(), [&](const shared_ptr<word>& w)
	{
		double tt = w->getStatystyka().length();
		return maxWsp == ileZer(w->getStatystyka()) / tt;
	});
	
	idx = std::distance(temp.begin(), a);

	/*
	cout << maxWsp << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		if (maxWsp == ileZer(temp[i]->getStatystyka()) / temp[i]->getStatystyka().length()) idx = i;
		else idx = 9999;
	}
	*/
	//cout << idx;

	return idx;
}

bool WordDatabase::operator==(const WordDatabase & w)
{
	if (this->getInstance().getWords().size() != w.getInstance().getWords().size())
	{
		return false;
	}
	for (int i = 0; i < this->getInstance().getWords().size(); i++)
	{
		if (this->getInstance().getWords()[i] != w.getInstance().getWords()[i])
		{
			return false;
		}
	}
	return true;
}

WordDatabase WordDatabase::operator=(const WordDatabase & w)
{
	if (this->getInstance().getWords().size() != w.getInstance().getWords().size())
	{
		return *this;
	}
	for (int i = 0; i < this->getInstance().getWords().size(); i++)
	{
		this->getInstance().getWords()[i] = w.getInstance().getWords()[i];
	}
	return *this;
}

ostream & operator<<(ostream & out, const WordDatabase & d)
{
	for (const auto& a : d.words)
	{
		cout << *a << endl;
	}
	return out;
}
