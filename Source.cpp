#include "Uzytkownik.h"
#include "word.h"
#include "WordDatabase.h"
#include "UserDatabase.h"


//nowoczesne
vector<shared_ptr<word>> najslabszeSlowa(const int& n)  //nowoczesne
{
	vector<shared_ptr<word>> slowka(WordDatabase::getInstance().getWords());
	std::sort(slowka.begin(), slowka.end(), [](const shared_ptr<word>& w1, const shared_ptr<word>& w2) 
		{return w1->getStatystyka() < w2->getStatystyka();});
	vector<shared_ptr<word>> vectorTemp(slowka.begin(), slowka.begin()+n);
	return vectorTemp;
} 
//do zrobienia:
void UczSlowek()
{

	cout << "program do nauki slowek" << endl << "program wybiera w pierwszej kolejnosci";
	cout << " slowka ktore maja maly wskaznik" << endl << " poprawnych odpowiedzi, a ty musisz je prztlumaczyc" << endl << endl;
	
	//vector<shared_ptr<word>> slowka;

	int randomIdx;
	int jakiJezyk;

	string odpowiedz = "";
	string nowaStatystyka = "";

	string exit = "";

	vector<shared_ptr<word>> words = WordDatabase::getInstance().getWords();

	while (exit != "exit")
	{
		randomIdx = WordDatabase::getInstance().wspZer();

		jakiJezyk = rand();
		if (jakiJezyk % 2 == 0) //jesli parzyste to tlumaczysz z ang na pol
		{
			cout << words[randomIdx]->getEngWord() << ": ";
			cin >> odpowiedz;
			cin.get();
			if (odpowiedz == words[randomIdx]->getPolWord())
			{
				cout << "correct! :)" << endl << endl;

				WordDatabase::getInstance().update2(words[randomIdx]->getId(), "1");
			}
			else
			{
				cout << "wrong :(" << endl << endl;

				WordDatabase::getInstance().update2(words[randomIdx]->getId(), "0");
			}
			cout << "chcesz wyjsc? wpisz exit" << endl;
			cout << "dalej? wpisz cokolwiek" << endl << endl;
			cin >> exit;
			cin.get();
		}
		else  //jesli nieparzyste to tlumaczy z pol na ang
		{
			cout << words[randomIdx]->getPolWord() << ": ";
			cin >> odpowiedz;
			cin.get();
			if (odpowiedz == words[randomIdx]->getEngWord())
			{
				cout << "correct! :)" << endl << endl;

				WordDatabase::getInstance().update2(words[randomIdx]->getId(), "1");
			}
			else
			{
				cout << "wrong :(" << endl << endl;

				WordDatabase::getInstance().update2(words[randomIdx]->getId(), "0");
			}
			cout << "chcesz wyjsc? wpisz exit" << endl;
			cout << "dalej? wpisz cokolwiek" << endl << endl;
			cin >> exit;
			cin.get();
		}


	}


}
/*
void dodajUzytkownika()
{
	UserDatabase::getInstance().update();

	
	string temp;

	Uzytkownik u;
	cout << "imie: ";
	cin >> temp;
	cin.get();
	u.setImie(temp);
	temp = "";

	cout << "nazwisko: ";
	cin >> temp;
	cin.get();
	u.setNazwisko(temp);
	temp = "";

	cout << "login: ";
	cin >> temp;
	cin.get();
	u.setLogin(temp);
	temp = "";

	cout << "haslo: ";
	cin >> temp;
	cin.get();
	u.setHaslo(temp);
	temp = "";

	int id = rand() % 100;

	
	vector<shared_ptr<Uzytkownik>> v = zaladujUzytkownikow("baza.txt");
	
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i]->getId() == std::to_string(id))  id = rand() % 100;
	}
	
	u.setId(std::to_string(id));

	ofstream zapis("baza.txt", std::ios::app);
	//zapis.open("baza.txt");
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
*/
//jest ok
void ekranLogowania()
{
	system("cls");
	string tempLogin;
	cout << "podaj login: ";
	cin >> tempLogin;
	cin.get();
	while (tempLogin != UserDatabase::getInstance().znajdUzytkownikaPoLoginie(tempLogin).getLogin())
	{
		cout << "nie ma takiego loginu w bazie danych" << endl;
		cout << "podaj login: ";
		cin >> tempLogin;
		cin.get();
	}

	string tempHaslo;
	cout << "podaj haslo: ";
	cin >> tempHaslo;
	cin.get();
	while (tempHaslo != UserDatabase::getInstance().znajdUzytkownikaPoLoginie(tempLogin).getHaslo())
	{
		cout << "bledne haslo" << endl;
		cout << "podaj haslo: ";
		cin >> tempHaslo;
		cin.get();
	}
	cout << "zostales zalogowany!" << endl;

}

void ekranRejestracji()
{
	system("cls");

	string tempLogin, tempNazwisko, tempImie, tempHaslo;
	int tempId;

	cout << "podaj imie: ";
	cin >> tempImie;
	cin.get();
	cout << "podaj nazwisko: ";
	cin >> tempNazwisko;
	cin.get();
	cout << "podaj login: ";
	cin >> tempLogin;
	cin.get();
	cout << "podaj haslo: ";
	cin >> tempHaslo;
	cin.get();

	vector<shared_ptr<Uzytkownik>> us = UserDatabase::getInstance().getUsers();
	
	tempId = rand() % 100;   //if there is such an id in users database do:
	
	auto it = std::find_if(us.begin(), us.end(), [&tempId](const shared_ptr<Uzytkownik>& u1)
	{return std::to_string(tempId) == u1->getId();});

	while (it != us.end())
	{
		tempId = rand() % 100;   //making sure that this id is not in user database
	}

	UserDatabase::getInstance().update(Uzytkownik(tempLogin, tempHaslo, std::to_string(tempId), tempImie, tempNazwisko));

	cout << "uzytkownik zostal dodany" << endl << endl << endl;

}

void menuPoZalogowaniu()
{
	vector<shared_ptr<word>> words = WordDatabase::getInstance().getWords();

	cout << "-----------EKRAN PO ZALOGOWANIU-------------" << endl;
	cout << "-----------Ucz sie, wybierz 1---------------" << endl;
	cout << "---------pokaz slowka, wybierz 2------------" << endl;
	cout << "-pokaz slowa posortowane od najtrudniejszych - 3-" << endl;
	cout << "---------------koniec - 0-------------------" << endl;
	int m;
	cin >> m;
	cin.get();
	switch (m)
	{
	case 1:
		UczSlowek();
		menuPoZalogowaniu();
		break;
	case 0:
		break;
	case 2:
		cout << endl;
		cout << WordDatabase::getInstance();
		cout << endl << endl;
		menuPoZalogowaniu();
		break;
	case 3:
		cout << "ile slow pokazac?" << endl;
		int n;
		cin >> n;
		cin.get();
		if (n > words.size()) n = words.size();
		for (const auto& a : najslabszeSlowa(n))
		{
			cout << *a << endl;
		}
		cout << endl;
		menuPoZalogowaniu();

	}

}

void menuPierwsze()
{
	cout << "-------Program do nauki slowek----------" << endl;
	cout << "------------------menu------------------" << endl;
	cout << "-------Zaloguj sie, wybierz 1-----------" << endl;
	cout << "-------Stworz konto, wybierz 2----------" << endl;
	cout << "-Zakoncz dzialanie programu, wybierz 0-" << endl;
	int m;
	cin >> m;
	cin.get();
	switch (m)
	{
	case 1: 
		ekranLogowania();
		menuPoZalogowaniu();
		break;
	case 2:
		ekranRejestracji();
		menuPierwsze();
		break;
	case 0:
		break;
	}
	cout << "wcisniej enter" << endl;
}


int main()
{
	srand(time(NULL));


	menuPierwsze();


	

	cin.get();
	return 0;
}