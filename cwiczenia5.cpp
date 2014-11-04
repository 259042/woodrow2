#include <iostream>
#include <list>
using namespace std;

class IPolaczenie{
public:
	virtual string* pobierzSzczegoly() = 0;
	virtual void drukuj() = 0;
};

class Wydruk{
public:
	static void drukujPolaczenie(Polaczenie p);
};

class Polaczenie : IPolaczenie {
	
public:
	Polaczenie(time_t cO, time_t cP, string mO, string mP);
	string* pobierzSzczegoly();
	void drukuj(){
		Wydruk::drukujPolaczenie(*this);
	}

private:
	time_t cO, cP;
	string mO, mP;

};

class Wyszukiwanie{

public:
	Wyszukiwanie(string pP, string pK, time_t d, int lP);
	list<IPolaczenie> szukajPolaczenia();

private:
	string pP, pK;
	time_t d;
	int lP;
};

class PolaczenieBezposrednie : Polaczenie{
public:
		PolaczenieBezposrednie(time_t cO, time_t cP, string mP, string mO, float dT, float pCB);
		void pobierzSzczegoly(string*);
		void drukuj();
private:
		float dT, pCB;
};

class PolaczeniePosrednie : Polaczenie{
public:
	PolaczeniePosrednie(time_t cO, time_t cP, string mP, string mO, MiejscePrzesiadki miejsce, time_t czasP);
	void pobierzSzczegoly(string*);
	void drukuj();
private:
	MiejscePrzesiadki miejscePrzesiadki;
	time_t czasP;
	
};

class MiejscePrzesiadki{
public:
	MiejscePrzesiadki(string m, int peronP, int peronO);
private:
	string m;
	int peronP, peronO;
};





int main(){


	return 0;
}