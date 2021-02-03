#include<iostream>
using namespace std;

template <class Tip>
class Cvor
{
public:
	Tip info;
	Cvor* next;
	Cvor(Tip info, Cvor* next)
	{
		this->info = info;
		this->next = next;
	}
};


template <class Tip>
class PrioritetniRed
{
public:

	virtual void dodaj(Tip v) = 0;

	virtual Tip ukloni() = 0;

	virtual bool IsPrazan() = 0;

	virtual void print() = 0;
};

template <class Tip>
class PrioritetniRedSekv
{
	int maxSize = 15;
	int brojac = 0;
	Tip* podaci = new Tip[maxSize];
public:
	void dodaj(Tip v)
	{
		if (IsPun()) //ili prosiriNiz
			throw exception("Niz pun\n");
		podaci[brojac++] = v;
	}
	Tip ukloni()
	{
		if (IsPrazan())
			throw exception("Niz prazan\n");

		int maxIndex = 0;
		int maxValue = podaci[0];
		for (size_t i = 1; i < brojac; i++)
		{
			if (podaci[i] > maxValue)
			{
				maxValue = podaci[i];
				maxIndex = i;
			}
		}
		brojac--;
		podaci[maxIndex] = podaci[brojac]; //u obrisano polje smjestamo zadnji element
		return maxValue;
	}

	bool IsPrazan()
	{
		return brojac == 0;
	}
	bool IsPun()
	{
		return brojac == maxSize;
	}
	void print()
	{
		for (size_t i = 0; i < brojac; i++)
		{
			cout << "[ " << podaci[i] << " ]" << " ";
		}
	}
};
void main()
{
	try
	{
		PrioritetniRedSekv<int>* a = new PrioritetniRedSekv<int>();
		for (size_t i = 15; i < 25; i++)
		{
			a->dodaj(i*3);
			cout << "dodano -> " << i*3 << endl;
		}
		a->dodaj(250);
		cout << "dodano -> " << 250 << endl;
		a->dodaj(120);
		cout << "dodano -> " << 120 << endl;

		cout << "print dodano\n";
		a->print();
		cout << "\n";
		for (size_t i = 0; i < 9; i++)
		{
			cout << "uklonjeno -> " << a->ukloni() << endl;
		}
		cout << "\nprint obrisano\n";
		a->print();

	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}


}