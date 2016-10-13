/*Zadanie c++ (PK3 lab 1)
Dana jest klasa :
class Punkt
{
	float x
		float y;
public:
	Punkt(Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	dodaj(Punkt &p);//dodaje do siebie wspó³rzêdne punktu p (dodawanie wektorów w przestrzeni 2d )
	dodaj(Punkt *p);
	drukuj();// drukuje swoje wspó³rzêdne

};

1. Dla klasy zdefiniowaæ konstruktory i metody : dodaj oraz drukuj.
Napisaæ funkcje main która sprawdza powy¿sze metody dla obiektów stworzonych statycznie i dynamicznie.

Dana jest klasa :
class Tablica
{
	Punkt * w;
	int dl; // dlugoœæ Tablicy
public:
	Tablica(int dl = 0); // tworzy Tablice o zadanej d³ugoœci i wype³nia punktami (0,0)
	Tablica(Tablica &w_); //inicjalizacja za pomoc¹ Tablicy w_
	Tablica(float *x, float *y, dl); // inicjalizacja tablicy punktów tablicami x -ów i y -ów

	~Tablica();

	dodaj(Tablica &w_);// dodaje do siebie Tablice w_

	bool porownaj(&w);// porownnaie z Tablica w_;
};
2. Zaimplementowaæ powy¿sze metody, konstruktory i destruktory
Do programu ( funkcja main ) dopisaæ kod który wykorzystuje powy¿sze funkcje.
Tablicay zainicjalizowaæ dowolnymi wartoœciami np. losowymi albo na podstawie licznika pêtli.
Klasy , metody i program powinny byæ w odzielnych plikach (w sumie 3 pliki)*/

#include <iostream>
#include <string>
 
using namespace std;

class Punkt
{
//public:
	float x;
	float y;
public:

	Punkt(float x_ = 0, float y_ = 0)
	{
		x = x_;
		y = y_;
	}


	void dodaj(Punkt &p2) //dodaje do siebie wspó³rzêdne punktu p (dodawanie wektorów w przestrzeni 2d )
	{
		x += p2.x;
		y += p2.y;
	}

	void drukuj() // drukuje swoje wspó³rzêdne
	{
		cout << x << endl;
		cout << y << endl;
	}

};

class Tablica
{
	Punkt *w;
	int dl; // dlugoœæ Tablicy

public:

	Tablica(int dl_ = 0) // tworzy Tablice o zadanej d³ugoœci i wype³nia punktami (0,0)
	{
		dl = dl_;
		for (int i = 0 ; i < dl_ ; i++)
		{
			w[i] = Punkt();
		}
	}


	Tablica(Tablica &tab_) //inicjalizacja za pomoc¹ Tablicy w_
	{
		dl = tab_.dl;
		for (int i = 0; i < tab_.dl; i++)
		{
			w[i] = dodaj(tab_.w[i]);
		//	w[i].x = tab_.w[i].x;
		//	w[i].y = tab_.w[i].y;


		}
	}

	Tablica(float x, float y, int dl_) // inicjalizacja tablicy punktów tablicami x -ów i y -ów
	{
		dl = dl_;
		
	}

	~Tablica();

	void dodaj(Tablica &w_) // dodaje do siebie Tablice w_
	{

	}

	bool porownaj(Tablica &w_) // porownnaie z Tablica w_;
	{

	}
};


int main()
{
	Punkt p1(1,4);
	Punkt p2(2,2);
	p1.dodaj(p2);
	p1.drukuj();
	Tablica tab1(5);
	Tablica tab2(tab1);
	return 0;
}