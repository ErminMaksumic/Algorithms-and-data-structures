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

template<class Tip>
class Cvor
{
public:

	Cvor* next;
	Tip info;
	Cvor(Cvor* next, Tip info)
	{
		this->next = next;
		this->info = info;
	}
};

template <class Tip>
class RedPov: public Red<Tip>
{
	Cvor<int>* pocetak = nullptr;
	Cvor<int>* kraj = nullptr;
	int brojac = 0;
public:
	void dodaj(Tip v)
	{
		Cvor<int>* novi = new Cvor<int>(nullptr, v);
		if (kraj != nullptr) //ako nije prazna lista
		{
			kraj->next = novi;
		}
		else //prazna lista
		{
			pocetak = novi;
		}
	    kraj = novi;
	}

	Tip ukloni()
	{
		if (IsPrazan())
		{
			throw exception("Nemoguce ukloniti element iz praznog niza\n");
		}
		else
		{
			Cvor<int>* uklonjeni = pocetak;
			Tip uInfo = uklonjeni->info;
			pocetak = pocetak->next;
			delete uklonjeni;

			if (pocetak == nullptr)
				kraj = nullptr;
			return uInfo;
		}

	}

	bool IsPrazan()
	{
		return pocetak == nullptr;
	}

	void print()
	{
		Cvor<int>* tempPoc = pocetak;
		if (tempPoc == nullptr)
		{
			cout << "Lista prazna\n";
			return;
		}
		while (tempPoc->next!=nullptr)
		{
			tempPoc = tempPoc->next;
			cout << "[ " << tempPoc->info << " ]" << " ";
		}
	}
};




void main()
{
	try
	{
		RedPov<int>* a = new RedPov<int>();
		for (size_t i = 0; i < 20; i++)
		{
			a->dodaj(i);
			cout << "dodano -> " << i << endl;
		}
		cout << "print dodano\n";
		a->print();
		cout << "\n";
		for (size_t i = 0; i < 25; i++)
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