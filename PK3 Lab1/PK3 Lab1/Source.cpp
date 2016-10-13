/*Zadanie c++ (PK3 lab 1)
Dana jest klasa :
class Punkt
{
	float x
		float y;
public:
	Punkt(Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	dodaj(Punkt &p);//dodaje do siebie wsp�rz�dne punktu p (dodawanie wektor�w w przestrzeni 2d )
	dodaj(Punkt *p);
	drukuj();// drukuje swoje wsp�rz�dne

};

1. Dla klasy zdefiniowa� konstruktory i metody : dodaj oraz drukuj.
Napisa� funkcje main kt�ra sprawdza powy�sze metody dla obiekt�w stworzonych statycznie i dynamicznie.

Dana jest klasa :
class Tablica
{
	Punkt * w;
	int dl; // dlugo�� Tablicy
public:
	Tablica(int dl = 0); // tworzy Tablice o zadanej d�ugo�ci i wype�nia punktami (0,0)
	Tablica(Tablica &w_); //inicjalizacja za pomoc� Tablicy w_
	Tablica(float *x, float *y, dl); // inicjalizacja tablicy punkt�w tablicami x -�w i y -�w

	~Tablica();

	dodaj(Tablica &w_);// dodaje do siebie Tablice w_

	bool porownaj(&w);// porownnaie z Tablica w_;
};
2. Zaimplementowa� powy�sze metody, konstruktory i destruktory
Do programu ( funkcja main ) dopisa� kod kt�ry wykorzystuje powy�sze funkcje.
Tablicay zainicjalizowa� dowolnymi warto�ciami np. losowymi albo na podstawie licznika p�tli.
Klasy , metody i program powinny by� w odzielnych plikach (w sumie 3 pliki)*/

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


	void dodaj(Punkt &p2) //dodaje do siebie wsp�rz�dne punktu p (dodawanie wektor�w w przestrzeni 2d )
	{
		x += p2.x;
		y += p2.y;
	}

	void drukuj() // drukuje swoje wsp�rz�dne
	{
		cout << x << endl;
		cout << y << endl;
	}

};

class Tablica
{
	Punkt *w;
	int dl; // dlugo�� Tablicy

public:

	Tablica(int dl_ = 0) // tworzy Tablice o zadanej d�ugo�ci i wype�nia punktami (0,0)
	{
		dl = dl_;
		for (int i = 0 ; i < dl_ ; i++)
		{
			w[i] = Punkt();
		}
	}


	Tablica(Tablica &tab_) //inicjalizacja za pomoc� Tablicy w_
	{
		dl = tab_.dl;
		for (int i = 0; i < tab_.dl; i++)
		{
			w[i] = dodaj(tab_.w[i]);
		//	w[i].x = tab_.w[i].x;
		//	w[i].y = tab_.w[i].y;


		}
	}

	Tablica(float x, float y, int dl_) // inicjalizacja tablicy punkt�w tablicami x -�w i y -�w
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