#include <iostream>
#include <string>
 
using namespace std;

class Punkt
{
	friend class Tablica;   // zaprzyja�nienie miedzy klasami potrzebne do por�wnania zawarto�ci klas
	float x;
	float y;

public:

	Punkt(float x_ = 0, float y_ = 0)  //przypisanie warto�ci dla punktu, je�eli u�ytkownik nie poda warto�ci, zostan� 
	{								   //przypisane zera
		x = x_;
		y = y_;
	}

	Punkt(Punkt &p2)                   // inicjalizacjia punktu innym punktem
	{
		x = p2.x;
		y = p2.y;
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
	Punkt *w;  // tablica punkt�w
	int dl; // dlugo�� Tablicy

public:

	Tablica(int dl_ = 0) // tworzy Tablice o zadanej d�ugo�ci i wype�nia punktami (0,0)
	{
		dl = dl_;		
		w = new Punkt[dl];  // rezerwacja pami�ci dla tablicy typu Punkt o d�ugo�ci dl
	}


	Tablica(Tablica &tab_) //inicjalizacja za pomoc� Tablicy tab_
	{
		dl = tab_.dl;
		w = new Punkt[dl];
		for (int i = 0; i < tab_.dl; i++)
		{
			w[i].dodaj(tab_.w[i]);    // dodanie warto�ci do tablicy(wype�nionej punktami 0,0) z innej tablicy
		}
	}

	Tablica(float x_, float y_, int dl_) // inicjalizacja tablicy punkt�w tablicami x -�w i y -�w
	{
		dl = dl_; 	
		w = new Punkt[dl];
		for (int i = 0; i < dl; i++)
		{		
			Punkt p(x_, y_);   // utworzenie zmiennej pomocniczej, kt�ra nie jest konieczna ze wzgl�du na to �e klasy s�
							   // zaprzyja�nione, lecz traktowa�em je tak, jakby nie by�y, gdzie tylko potrafi�em
			w[i].dodaj(p);     // przypisanie zmiennej pomocniczej do tablicy
		}	
	}

	void dodaj(Tablica &tab_) // dodaje do siebie Tablice tab_
	{		
		for (int i = 0; i < dl; i++)
		{			
			w[i].dodaj(tab_.w[i]);
		}
	}

	bool porownaj(Tablica &tab_) // porownnaie z Tablica tab_;
	{
		if (dl != tab_.dl)  // je�eli r�ni� si� wielko�ci�
		{
			return 0;
		}
		for (int i = 0; i < dl; i++)
		{
			if ((w[i].x != tab_.w[i].x) || (w[i].y != tab_.w[i].y)) return 0;  //je�eli r�ni� si� zawarto�ci�
		}
		return 1;
	}

	~Tablica()
	{
		delete[]w;
	}
};


int main()
{
	Punkt p1(1,4);
	Punkt p2(2,2);
	Punkt p3(p1);
	p1.dodaj(p2);
	p1.dodaj(p3);
	p1.drukuj();
	Tablica tab1(5);
	Tablica tab2(1,3,5);
	Tablica tab3(tab2);
	tab3.dodaj(tab2);
	if (tab3.porownaj(tab1) == 1)
	{
		cout << "tablice sa takie same" << endl;
	}
	else cout << "tablice sie roznia" << endl;
	return 0;
}