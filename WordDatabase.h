#pragma once
#include "Libs.h"
#include "word.h"
#include "Uzytkownik.h"

class WordDatabase
{
private:
	std::vector<shared_ptr<word>> words;
	WordDatabase();
	//Uzytkownik& user;  na pozniej

	vector<string> rozdzielWiersz(const string& wiersz);
	shared_ptr<word> makeWordSharedPointer(const word& w);
public:
	static WordDatabase& getInstance();
	//static WordDatabase& update(const shared_ptr<word>& stareSlowo, const string& statystyka);

	void update2(const string& id, const string& statystyka);

	~WordDatabase() = default;

	std::vector<shared_ptr<word>> getWords() const;

	int ileZer(const string& w);

	int wspZer();

	bool operator==(const WordDatabase& w);

	WordDatabase operator=(const WordDatabase& w);
	
	friend ostream& operator<<(ostream& out, const WordDatabase& d);
};

