#include <iostream>
#include <string>
 
using namespace std;

class Punkt
{
	friend class Tablica;   // zaprzyjaŸnienie miedzy klasami potrzebne do porównania zawartoœci klas
	float x;
	float y;

public:

	Punkt(float x_ = 0, float y_ = 0)  //przypisanie wartoœci dla punktu, je¿eli u¿ytkownik nie poda wartoœci, zostan¹ 
	{								   //przypisane zera
		x = x_;
		y = y_;
	}

	Punkt(Punkt &p2)                   // inicjalizacjia punktu innym punktem
	{
		x = p2.x;
		y = p2.y;
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
	Punkt *w;  // tablica punktów
	int dl; // dlugoœæ Tablicy

public:

	Tablica(int dl_ = 0) // tworzy Tablice o zadanej d³ugoœci i wype³nia punktami (0,0)
	{
		dl = dl_;		
		w = new Punkt[dl];  // rezerwacja pamiêci dla tablicy typu Punkt o d³ugoœci dl
	}


	Tablica(Tablica &tab_) //inicjalizacja za pomoc¹ Tablicy tab_
	{
		dl = tab_.dl;
		w = new Punkt[dl];
		for (int i = 0; i < tab_.dl; i++)
		{
			w[i].dodaj(tab_.w[i]);    // dodanie wartoœci do tablicy(wype³nionej punktami 0,0) z innej tablicy
		}
	}

	Tablica(float x_, float y_, int dl_) // inicjalizacja tablicy punktów tablicami x -ów i y -ów
	{
		dl = dl_; 	
		w = new Punkt[dl];
		for (int i = 0; i < dl; i++)
		{		
			Punkt p(x_, y_);   // utworzenie zmiennej pomocniczej, która nie jest konieczna ze wzglêdu na to ¿e klasy s¹
							   // zaprzyjaŸnione, lecz traktowa³em je tak, jakby nie by³y, gdzie tylko potrafi³em
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
		if (dl != tab_.dl)  // je¿eli ró¿ni¹ siê wielkoœci¹
		{
			return 0;
		}
		for (int i = 0; i < dl; i++)
		{
			if ((w[i].x != tab_.w[i].x) || (w[i].y != tab_.w[i].y)) return 0;  //je¿eli ró¿ni¹ siê zawartoœci¹
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