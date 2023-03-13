#include <iostream>

using namespace std;

const int maxlength = 20;
typedef int elementtype;
typedef int position;

class Stos
{
	int S[maxlength];
	int Top = -1;
	//position Top;//szczyt stosu
public:
	Stos();
	void Push(elementtype x);
	void Pop();
	bool Empty();
	elementtype TopElem();
	void Makenull();
	void Print();
};

Stos::Stos()
{
	Top = -1;
}

elementtype Stos::TopElem()
{
	if (Top == -1)
	{
		return -1;
	}
	else
	{
		int element = S[Top];
		return element;
	}
}

void Stos::Push(elementtype x)
{
	if (Top != maxlength)
	{
		Top += 1;
		S[Top] = x;
	}
	else
	{
		return;
	}
}

void Stos::Pop()
{
	if (Top == -1)
	{
		return;
	}
	else
	{
		Top -= 1;
	}
}

bool Stos::Empty()
{
	if (Top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Stos::Makenull()
{
	while (Top != -1)
	{
		Top -= 1;
	}
}

void Stos::Print()
{

	for (int i = 0; i <= Top; i++)
	{
		cout << S[i] << " ";
	}
	cout << endl;
}

int main()
{
	Stos s;

	s.Empty();
	s.Print();
	s.Push(5);
	s.Print();
	s.TopElem();
	s.Print();
	s.Empty();
	s.Print();
	s.Pop();
	s.Empty();
	s.Push(2);
	s.Push(3);
	s.Print();
	s.TopElem();
	s.Makenull();
	s.Empty();
	s.Print();
	return 0;
}
//TOP: s->Retrieve(First(), l);
//POP: s->Delete(s->First(), l);
//PUSH: s->Insert(x, s->First(), l);

//pusta stos ->top = -1
//0				0
//0  ->push(x)  0
//0				0											5
//0				1 -> top = 1 // jak dodamy kolejny el to 	1 -> top = 2