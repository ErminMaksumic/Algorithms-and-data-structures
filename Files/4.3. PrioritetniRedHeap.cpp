#include<iostream>
using namespace std;


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
class PrioritetniRedHeap : public PrioritetniRed<Tip>
{
	int maxSize = 20;
	Tip* A = new Tip[maxSize+1];
	int brojacN = 0;
	void rotacija(Tip& x, Tip& y)
	{
		Tip temp;
		temp = x;
		x = y;
		y = temp; 
	}
public:
	void dodaj(Tip v)
	{
		A[++brojacN] = v;
		rekonustrukcijaPremaGore(brojacN);
	}
	void rekonustrukcijaPremaGore(int x)
	{
		if (x == 1) // kada dodjemo do korijena prekid rekurzije
			return;
		int roditelj = x / 2;
		if (A[x] > A[roditelj])
		{
			rotacija(A[x], A[roditelj]);
		}
		rekonustrukcijaPremaGore(roditelj);
	}

	Tip ukloni()
	{
		int a = A[1];
		A[1] = A[brojacN];
		brojacN--;
		rekostrukcijaPremaDolje(1);
		return a;
	}
	void rekostrukcijaPremaDolje(int x)
	{
		if (2 * x > brojacN)  // ako je list - prekid
			return;
		int lijevoDijete = 2 * x;

		//ako postoji desno moze biti najveci broj DD, najveci broj LD, ili najveci broj R
		//ako ne postoji moze biti najveci broj LD ili najveci broj R
		int desnoDijete = 2 * x + 1;

		int maxIndex = lijevoDijete;

		if (PostojiDesnoDijete(x))
		{
			if (desnoDijete > A[maxIndex])
			{
				maxIndex = desnoDijete;
			}
		}
		if (A[x] > A[maxIndex])
		{
			maxIndex = x;
		}
		if (maxIndex != x)
		{
			rotacija(A[x], A[maxIndex]);
			rekostrukcijaPremaDolje(maxIndex);
		}
	}
	bool PostojiDesnoDijete(int x)
	{
		return 2 * x + 1 <= brojacN;
	}
	bool IsPrazan()
	{
		return brojacN == 0;
	}
	bool IsPun()
	{
		return brojacN == maxSize;
	}
	void print()
	{
		for (size_t i = 1; i < brojacN; i++)
		{
			cout << "[ " << A[i] << " ]" << " ";
		}
	}
};

	void main()
	{
	try
	{
		PrioritetniRedHeap<int>* a = new PrioritetniRedHeap<int>();
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