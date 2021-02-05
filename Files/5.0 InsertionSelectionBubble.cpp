#include<iostream>
using namespace std;

void insertionSort(int niz[], int n)
{
	for (size_t i = 1; i < n; i++)
	{
		int j = i;
		while (j>0 && niz[j-1] > niz[j])
		{
			int pom = niz[j];
			niz[j] = niz[j - 1];
			niz[j - 1] = pom;
			j--;
		}
	}
}
void selectionSort(int niz[], int n)
{
	int i, j, minIndex, pom;
	for (size_t i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < n; j++)
		{
			if (niz[j] < niz[minIndex])
				minIndex = j;

			if (minIndex != i)
			{
				pom = niz[i];
				niz[i] = niz[minIndex];
				niz[minIndex] = pom;
			}
		}
	}
}
void bubbleSort(int niz[], int n)
{
	bool promjena = true;
	int j = 0;
	while (promjena)
	{
		promjena = false;
		j++;
		for (size_t i = 0; i < n-j; i++)
		{
			if (niz[i] > niz[i + 1])
			{
				int pom = niz[i];
				niz[i] = niz[i];
				niz[i + 1] = pom;
				promjena = true;
			}
		}
	}
}


void main()
{
	int* niz = new int[20];
	for (size_t i = 0; i < 10; i++)
	{
		niz[i] = rand() % 100 + 1;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << "[ " << niz[i] << " ]" << endl;
	}
	cout << "Poslije sortiranja\n";
	//insertionSort(niz, 10);
	//selectionSort(niz, 10);
	bubbleSort(niz, 10);
	for (size_t i = 0; i < 10; i++)
	{
		cout << "[ " << niz[i] << " ]" << endl;

	}
}