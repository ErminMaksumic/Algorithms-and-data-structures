#include  <iostream>
using namespace  std;


template <class T>
struct Cvor
{
	Cvor* next;
	T info;
	Cvor(T info, Cvor* next)
	{
		this->info = info;
		this->next = next;
	}
};

template <class T>
class Stek
{
public:
	virtual void dodaj(T) = 0;
	virtual T ukloni() = 0;
	virtual bool jel_prazna() = 0;
};

template <class T>
class StekSekv : public Stek<T>
{
	int max_size = 2;
	T* podaci = new T[max_size];
	int brojac = 0;
	bool jelPun()
	{
		return (brojac == max_size);
	}
	void prosiri_niz()
	{
		T* t = new T[max_size * 2];

		for (int i = 0; i < max_size; i++)
		{
			t[i] = podaci[i];
		}
		delete[] podaci;
		podaci = t;
		cout << "|| Prosiren niz || Stara vrijednost: " << max_size<<" || Nova vrijednost:" <<max_size*2<<"||"<< endl;
		max_size = max_size * 2;
	}
public:
	void dodaj(T x)
	{
		if (jelPun())
			prosiri_niz();
		podaci[brojac++] = x;
	}
	T ukloni()
	{
		if (jel_prazna())
			throw exception("Lista prazna\n");
		T izbrisani = podaci[brojac - 1];
		brojac--;
		return izbrisani;
	}
	bool jel_prazna()
	{
		return brojac == 0;
	}
};

template <class T>
class StekPov : public Stek<T>
{
	Cvor<T>* prvi = nullptr;
	int brojac = 0;
public:
	void dodaj(T x)
	{
		Cvor<T>* temp = new Cvor<T>(x, prvi);
		prvi = temp;
		brojac++;
	}
	T ukloni()
	{
		if (jel_prazna())
			throw exception("Prazna lista\n");
		Cvor<T>* temp = prvi;
		prvi = prvi->next;
		T uklonjenaVrijednost = temp->info;
		delete temp;
		brojac--;
		return uklonjenaVrijednost;
	}
	bool jel_prazna()
	{
		return prvi == nullptr;
	}
};


void testiraj_stek(Stek<int>* A)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "dodato na vrha " << i << endl;
		A->dodaj(i);
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << "dodato na vrh " << i << endl;
		A->dodaj(i);
	}
	for (int i = 0; i < 3; ++i)
	{
		cout << "uklonjeno sa vrha: " << A->ukloni() << endl;
	}

	for (int i = 0; i < 12; ++i)
	{
		cout << "uklonjeno sa vrha: " << A->ukloni() << endl;
	}

	while (!A->jel_prazna())
	{
		cout << "uklonjeno sa vrha: " << A->ukloni() << endl;
	}
}
void main()
{


	testiraj_stek(new StekPov<int>);
	testiraj_stek(new StekSekv<int>);
}