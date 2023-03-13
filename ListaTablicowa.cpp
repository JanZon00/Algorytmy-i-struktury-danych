#include <list>
#include <iostream>

using namespace std;

typedef int elementtype, position;
const int maxlength = 20;
struct List
{
	elementtype elements[maxlength];
	int last; //indeks ostatniego elementu listy
};

position END(List l)
{
	return l.last + 1;
}

position First(List l)
{
	if (l.last == -1)
	{
		return END(l);
	}
	else
	{
		return 0;
	}
}

position Next(position p, List l)
{
	if (p == END(l))
	{
		return -1;
	}
	else
	{
		return p + 1;
	}
}

position Previous(position p, List l)
{
	if (p == First(l))
	{
		return -1;
	}

	else
	{
		return p - 1;
	}
}

position Locate(elementtype x, List l)
{ //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
	for (int j = 0; j < END(l); j++)
	{
		if (l.elements[j] == x)
		{
			return j;
		}
	}
	return END(l);
}

elementtype Retrieve(position p, List l)
{
	//return l(p);
	int liczba = l.elements[p];
	return liczba;
}

bool Insert(int x, position p, List &l)
{
	l.last += 1;
	for (int z = l.last; z >= p; z--)
	{
		l.elements[z + 1] = l.elements[z];
	}
	l.elements[p] = x;

	return 1;
}

bool Delete(position p, List &l)
{
	for (int z = Next(p, l); z <= l.last; z++)
	{
		l.elements[z - 1] = l.elements[z];
	}

	l.last -= 1;

	return 1;
}
bool Dodaj_duplikat(List &l)
{
	int duplikat;
	int size = END(l);

	for (int f = 0; f < size; f++)
	{
		duplikat = l.elements[f];
		Insert(duplikat, END(l), l);
	}

	return 1;
}
bool Usun_duplikat(List &l)
{
	int licznik;
	for (int t = 0; t < END(l) - 2; t++)
	{

		licznik = t + 1;
		for (int u = 0; u < END(l); u++)
		{
			if (l.elements[t] == l.elements[licznik])
			{
				Delete(licznik, l);
			}
			licznik++;
		}
	}
	Delete(END(l) - 1, l);
	return END(l);
}

void print(List l)
{
	position i = First(l);

	while (i != END(l))
	{
		cout << Retrieve(i, l) << endl;

		i = Next(i, l);
	}
	cout << endl;
}

int main()
{

	List l;
	l.last = -1;

	for (int i = 1; i < 5; i++)
	{
		Insert(i, First(l), l);
	}
	Insert(5, Locate(2, l), l);
	print(l); 
	Delete(Locate(2, l), l);
	print(l);

	cout << "Przed dodaniem duplikatow : " << endl;
	print(l);

	cout << "Po dodaniu duplikatow : " << endl;
	Dodaj_duplikat(l);
	print(l);

	cout << "Po usunieciu duplikatow : " << endl;
	Usun_duplikat(l);
	print(l);

	return 0;
}