#include<iostream>
using namespace std;

template <class Tip>
class Red
{
public:

	virtual void dodaj(Tip v) = 0;

	virtual Tip ukloni() = 0;

	virtual bool IsPrazan() = 0;

	virtual void print() = 0;
};

template <class Tip>
class RedSekv : public Red<Tip>
{
	int maxSize = 10;
	Tip* podaci = new Tip[maxSize];
	int pocetak = 0;
	int kraj = 0;
	int brojac = 0;
public:
	void dodaj(Tip v)
	{
		if (IsPun())
			return;
		podaci[kraj++] = v;
		if (kraj == maxSize)
			kraj = 0;
		brojac++;
	}

	Tip ukloni()
	{
		if (IsPrazan())
			throw exception("Prazna lista");
		Tip uklonjeni = podaci[pocetak];
		pocetak++;
		if (pocetak == maxSize)
			pocetak = 0;
		brojac--;
		return uklonjeni;
	}

	bool IsPrazan() {
		return brojac == 0;
	}
	bool IsPun()
	{
		return brojac == maxSize;
	}
	void print()
	{
		if (IsPrazan())
		{
			cout << "Prazno\n";
		}
		else
		{
			for (size_t i = pocetak; i < kraj; i++)
			{
				cout << "[ " << podaci[i] << " ]" << " ";
			}
		}
	}
};
void main()
{
	try
	{
		RedSekv<int>* a = new RedSekv<int>();
		for (size_t i = 0; i < 9; i++)
		{
			a->dodaj(i);
			cout << "dodano -> " << i << endl;
		}
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