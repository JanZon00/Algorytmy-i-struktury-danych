#include <iostream>

using namespace std;

typedef int elementtype;
struct celltype
{
	elementtype element;
	celltype *next;
};

typedef celltype *position;
celltype *l = NULL;

class Lista
{
protected:
	position l;
public:
	int licznik = 0;
	void Insert(elementtype x, position p);
	void Delete(position p);
	elementtype Retrieve(position p);
	position Locate(elementtype x, position p);
	position First();
	position Next(position p);
	position Previous(position p);
	position END();
	void print(position p);
};

position Lista::END()
{
	celltype *node = NULL;

	node = new celltype();
	node = l;

	while (node->next->next != NULL)
	{
		node = node->next;
	}
	return node;
}

position Lista::First()
{
	return l;
}

position Lista::Next(position p)
{
	celltype *node = NULL;
	node = new celltype();
	node = p->next;
	return node;

}

position Lista::Previous(position p)
{
	celltype *node = NULL;
	node = new celltype();
	node = l;
	while(node->next->element != p->element){
		node = node->next;
	}
	return node;
}

position Lista::Locate(elementtype x, position p)
{
	while (p->element != x)
	{
		p = p->next;
	}

	return p;
}

elementtype Lista::Retrieve(position p)
{

	if (p->element == 0)
	{
		return -1;
	}
	else
	{
		int x = p->element;
		return x;
	}
}

void Lista::Insert(elementtype x, position p)
{
	celltype *node = NULL;

	node = new celltype();
	while (p->element != 0)
	{
		p = p->next;
	}
	p->element = x;
	p->next = node;

	//node->element = x;
	//node->next = p->next;
	//p->next = node;
}

void Lista::Delete(position p)
{
	celltype *del_node = NULL;

	del_node = new celltype();
	while (p->next->element != 0)
	{
		p->element = p->next->element;
		p = p->next;
	}
	p->next = NULL;
}

void Lista::print(position p)
{
	while (p <= END())
	{
		cout << p->element << " ";
		p = p->next;
	}
	cout<<endl;
}

int main()
{
	Lista *obj = new Lista;
	l = new celltype();

	obj->Insert(4, l);
	obj->Insert(2, l->next);
	obj->Insert(5, l->next);

	obj->print(l);

	cout<<"Retrieve 4 -> " << obj->Retrieve(obj->Locate(4, l)) << endl;
	obj->Delete(obj->Locate(4, l));
	obj->print(l);
	delete (obj);
	return 0;
}