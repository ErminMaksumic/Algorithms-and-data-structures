//#include <iostream>
//using namespace std;
//const char* crt = "\n----------------------------------------------------------------------------------\n";
//
//
//class ListaSekv
//{
//	int maxSize = 100;
//	int* podaci = new int[maxSize];
//	int brojac = 0;
//public:
//	void dodaj_na_pocetak(int x)
//	{
//		if (jel_puna())
//			ProsiriNiz();
//		for (size_t i = brojac; i > 0; i--)
//		{
//			podaci[i] = podaci[i - 1];
//		}
//		podaci[0] = x;
//		cout << "Dodan na pocetak broj -> " << x << "\n";
//		brojac++;
//
//	}
//	void ProsiriNiz()
//	{
//		int* tempPodaci = new int[maxSize * 2];
//		for (size_t i = 0; i < brojac; i++)
//		{
//			tempPodaci[i] = podaci[i];
//		}
//		delete[] podaci;
//		podaci = tempPodaci;
//		maxSize = maxSize * 2;
//		cout << "Prosiren niz na vrijednost maxSize -> [" << maxSize << "]" << "\n";
//	}
//	void dodaj_na_kraj(int x)
//	{
//		if (jel_puna())
//			ProsiriNiz();
//		podaci[brojac++] = x;
//		cout << "Dodan na kraj broj -> " << x << "\n";
//
//	}
//	int ukloni_sa_pocetka()
//	{
//		int temp = podaci[0];
//		if (jel_prazna())
//			return false;
//		for (size_t i = 0; i < brojac; i++)
//		{
//			podaci[i] = podaci[i + 1];
//		}
//		brojac--;
//		return temp;
//
//	}
//	int ukloni_sa_kraja()
//	{
//		if (jel_prazna())
//			return 0;
//		int temp = podaci[brojac - 1];
//		brojac--;
//		return temp;
//
//	}
//	bool jel_prazna()
//	{
//		return brojac == 0;
//	}
//	bool jel_puna()
//	{
//		return brojac >= maxSize;
//	}
//	int operator[](int index)
//	{
//		return podaci[index];
//
//	}
//	int get_brojac()
//	{
//		return brojac;
//	}
//	void Ispisi()
//	{
//		cout << crt;
//		for (size_t i = 0; i < brojac; i++)
//		{
//			cout << "[" << podaci[i] << "]" << endl;
//		}
//		if (brojac == 0)
//		{
//			cout << "PRAZNA LISTA\n";
//		}
//		cout << crt;
//	}
//
//
//};
//
//void main()
//{
//	ListaSekv a;
//	a.dodaj_na_pocetak(4);
//	a.dodaj_na_pocetak(8);
//	a.dodaj_na_pocetak(9);
//	a.Ispisi();
//	
//	a.dodaj_na_kraj(1);
//	a.dodaj_na_kraj(4);
//	a.dodaj_na_kraj(6);
//	a.Ispisi();
//
//	cout << "Uklonjen sa pocetka broj -> " << a.ukloni_sa_pocetka() << endl;
//	cout << "Uklonjen sa pocetka broj -> " << a.ukloni_sa_pocetka() << endl;
//	cout << "Uklonjen sa pocetka broj -> " << a.ukloni_sa_pocetka() << endl;
//	a.Ispisi();
//
//	cout << "Uklonjen sa kraja broj -> " << a.ukloni_sa_kraja() << endl;
//	cout << "Uklonjen sa kraja broj -> " << a.ukloni_sa_kraja() << endl;
//	cout << "Uklonjen sa kraja broj -> " << a.ukloni_sa_kraja() << endl;
//	a.Ispisi();
//}
//
