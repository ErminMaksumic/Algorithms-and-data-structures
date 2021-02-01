#include <iostream>
using namespace std;
const char* crt = "\n----------------------------------------------------------------------------------\n";

typedef int T;
class Cvor
{
public:
	Cvor* next;
	T info;
	Cvor(T info, Cvor* next)
	{
		this->info = info;
		this->next = next;
	}
};

class ListaPov
{
	Cvor* prvi = nullptr;
	int brojac = 0;
public:
	void dodaj_na_pocetak(T x)
	{
		Cvor* temp = new Cvor(x, prvi);
		prvi = temp;
		brojac++;
		cout << "Dodan na pocetak broj -> " << x << endl;
	}

	void dodaj_na_kraj(T x)
	{

		Cvor* temp = prvi;
		if (temp == nullptr)
		{
			prvi = new Cvor(x, nullptr);
			cout << "Dodan na kraj broj -> " << x << endl;
			brojac++;
		}
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new Cvor(x, nullptr);
			cout << "Dodan na kraj broj -> " << x << endl;
			brojac++;
		}
	}

	T ukloni_sa_pocetka()
	{
		if (jel_prazna())
			throw exception("Prazna lista");
		Cvor* temp = prvi;
		T info = prvi->info;
		if (prvi->next != nullptr)
		{
	    prvi = prvi->next;
		}
		delete temp;
		brojac--;
		return info;
	}

	T ukloni_sa_kraja()
	{
		if (jel_prazna())
			throw exception("Prazna lista\n");
		T uklonjeni;
		Cvor* tempDoZadnjeg = prvi;
		Cvor* tempDoPredzadnjeg = nullptr;
		while (tempDoZadnjeg->next != nullptr)
		{
			tempDoPredzadnjeg = tempDoZadnjeg;
			tempDoZadnjeg = tempDoZadnjeg->next;
		}
		uklonjeni = tempDoZadnjeg->info;
		delete tempDoZadnjeg;
		if (tempDoPredzadnjeg == nullptr) //ako je u listi samo jedan element
		{
			prvi->next = nullptr;
		}
		else
		{
			tempDoPredzadnjeg->next = nullptr;
		}
		brojac--;
		return uklonjeni;
	}

	bool jel_prazna()
	{
		return brojac == 0;
	}

	T operator[](int index)
	{
		if (index >= brojac || index < 0)
		{
			throw exception("Nedozvoljen index\n");
		}
		Cvor* temp = prvi;
		for (size_t i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->info;
	}

	int get_brojac()
	{
		return brojac;
	}
	void Ispisi()
	{

	}

};
void main()
{
	try
	{
		ListaPov a;


		a.dodaj_na_pocetak(9);
		a.dodaj_na_pocetak(10);
		a.dodaj_na_pocetak(4);
		a.Ispisi();

		cout << "Operator [] -> " << a[0] << " " << a[1] << " " << a[2] << endl;

		a.dodaj_na_kraj(1);
		a.dodaj_na_kraj(4);
		a.dodaj_na_kraj(6);
		a.Ispisi();

		cout << "Uklonjen sa pocetka broj -> " << a.ukloni_sa_pocetka() << endl;
		cout << "Uklonjen sa pocetka broj -> " << a.ukloni_sa_pocetka() << endl;
		cout << "Uklonjen sa pocetka broj -> " << a.ukloni_sa_pocetka() << endl;
		a.Ispisi();

		cout << "Uklonjen sa kraja broj -> " << a.ukloni_sa_kraja() << endl;
		cout << "Uklonjen sa kraja broj -> " << a.ukloni_sa_kraja() << endl;
		cout << "Uklonjen sa kraja broj -> " << a.ukloni_sa_kraja() << endl;
		a.Ispisi();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

}