#include<iostream>
using namespace std;

template <class Tip>
class Cvor
{
public:
	Tip info;
	Cvor* next;

	Cvor(Cvor* next, Tip info)
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

template<class Tip>
class PrioritetniRedPov : public PrioritetniRed<Tip>
{
	Cvor<Tip>* prvi = nullptr;
	int brojac = 0;
public:
	void dodaj(Tip v)
	{
		
		Cvor<Tip>* temp = prvi;
		Cvor<Tip>* tempDoPrethodnog = nullptr;
		if (temp == nullptr)
		{
			prvi= new Cvor<Tip>(nullptr, v);
			return;
		}

			while (temp != nullptr && temp->info > v )
			{
				tempDoPrethodnog = temp;
				temp = temp->next;
			}
			Cvor<Tip>* novi = new Cvor<Tip>(temp, v);
			if (tempDoPrethodnog == nullptr)
			{
				prvi = novi;
			}
			else
			{
				tempDoPrethodnog->next = novi;
			}
		
	}
	Tip ukloni()
	{
		if (IsPrazan())
			throw exception("Niz prazan\n");
		Cvor<Tip>* uklonjeni = prvi;
		int uInfo = uklonjeni->info;
		prvi = prvi->next;
		delete uklonjeni;
		return uInfo;
		
	}

	bool IsPrazan()
	{
		return prvi == nullptr;
	}

	void print() 
	{
		if (prvi == nullptr)
		{
			cout << "Lista je prazna\n";
			return;
		}
		Cvor<Tip>* pok = prvi;
		while (pok!=nullptr)
		{
			cout << "[ " << pok->info << " ] ";
			pok = pok->next;
			
		}
	}
};
void main()
{
	try
	{
		PrioritetniRedPov<int>* a = new PrioritetniRedPov<int>();
		for (size_t i = 15; i < 30; i++)
		{
				a->dodaj(i * 3);
				cout << "dodano -> " << i * 3 << endl;
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