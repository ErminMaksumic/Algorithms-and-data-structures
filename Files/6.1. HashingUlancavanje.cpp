
#include <iostream>
using namespace std;
#include <exception>

struct Tacka2D
{
	int x;
	int y;
	Tacka2D(int x=0, int y=0)
	{
		this->x = x; this->y = y;
	}
	friend bool operator==(const Tacka2D obj1, const Tacka2D obj2)
	{
		return obj1.x == obj2.x && obj1.y == obj2.y;
	}
	friend ostream& operator<<(ostream& cout, const Tacka2D& obj)
	{
		cout << obj.x << " " << obj.y << endl;
		return cout;
	}
};

template <class Tip>
struct Cvor
{
	Cvor* next;
	Tip info;

	Cvor(Tip info, Cvor<Tip>* next) : info(info)
	{
		this->next = next;
	}
};

template <class Tip>
class ListaPov
{
private:
	int brojac;
	Cvor<Tip>* prvi;
public:
	ListaPov()
	{
		brojac = 0;
		prvi = nullptr;
	}

	void dodaj(Tip v)
	{
		Cvor<Tip>* t = new Cvor<Tip>(v, prvi);
		prvi = t;
		brojac++;
	}

	Tip ukloni()
	{
		if (isPrazan())
			throw std::exception("Greska. Nije moguce ukloniti elemenat iz prazne liste");

		brojac--;
		Cvor<Tip>* t = prvi;
		prvi = prvi->next;
		Tip x = t->info;
		delete t;
		return x;
	}
	void ukloni(Tacka2D obj)
	{
		if (prvi == nullptr)
			return;
		Cvor<Tacka2D>* tempIza = prvi;
		Cvor<Tacka2D>* tempIspred = nullptr;
		while (tempIza !=nullptr)
		{
			if (tempIza->info == obj) //tempIza je trazeni
			{
				if (tempIspred == nullptr)
				{
					prvi = prvi->next;
				}
				else
				{
					tempIspred->next = tempIza->next;
				}
				return;
			}

			tempIspred = tempIza;
			tempIza = tempIza->next;
		}
	}



	bool isPrazan()
	{
		return (prvi == nullptr);
	}

	int count()
	{
		return brojac;
	}

	void print(string pre = "", string post = ", ")
	{
		Cvor<Tip>* t = prvi;
		while (t != nullptr)
		{
			cout << pre << t->info << post;
			t = t->next;
		}
		cout << endl;
	}

	Tip& get(int i)
	{
		if (i > brojac)
			throw std::exception("indeks je ve?i od brojaca");

		Cvor<Tip>* t = prvi;
		for (int j = 0; j < (brojac - i - 1); j++)
		{
			t = t->next;
		}
		return t->info;
	}

	Tip& operator[](int i)
	{
		return get(i);
	}

	void set(int i, Tip v)
	{
		get(i) = v;
	}

	bool sadrzi(Tip v)
	{
		Cvor<Tip>* t = prvi;
		while (t != nullptr)
		{
			if (t->info == v)
				return true;
			t = t->next;
		}
		return false;
	}

	Tip* formirajNiz()
	{
		Tip* niz = new Tip[this->brojac];

		int b = 0;
		Cvor<Tip>* t = prvi;
		while (t != nullptr)
		{
			niz[b++] = t->info;
			t = t->next;
		}
		return niz;
	}
};

class Hesiranje
{
	int maxSize = 20;
	ListaPov<Tacka2D>* lista = new ListaPov<Tacka2D>[maxSize]();
	int brojac = 0;
	int HashFunk(Tacka2D tacka)
	{
		return (int)sqrt(pow(tacka.x + tacka.y, 2) / 2) % maxSize;
	}
public:
	void dodaj(Tacka2D v)
	{
		int index = HashFunk(v);
		if (index > 20)
		{
			index = 0;
		}
		brojac++;
		lista[index].dodaj(v);
	}
	void ukloni(Tacka2D v)
	{
		int index = HashFunk(v);
		brojac--;
		lista[index].ukloni(v);
	}
	void print()
	{
		for (size_t i = 0; i < maxSize; i++)
		{
			
				cout << "Lista broj -> " << i << endl;
				lista[i].print();
			
		}
	}
};

void main()
{
	Hesiranje a;
	Tacka2D c (1, 1);
	Tacka2D d(2, 4);
	Tacka2D e(1, 0);
	a.dodaj(c);
	a.dodaj(d);
	a.dodaj(e);
	a.print();
	a.ukloni(c);
	a.print();
	a.ukloni(d);
	a.print();
	a.ukloni(e);
	a.print();
	cout << "---------\n" << endl;
	a.print();

	system("pause");

}



