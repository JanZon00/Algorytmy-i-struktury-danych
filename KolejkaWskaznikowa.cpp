#include <iostream>

using namespace std;

typedef int elementtype;
struct celltype
{
	elementtype element;
	celltype *next;
};

typedef celltype *position;

class Queue
{
protected:
	position Front;
	position Rear;

public:
	int j = 0;
	int n = 0;
	Queue();
	~Queue();
	void Enqueue(elementtype x);
	void Dequeue();
	elementtype FrontElem();
	bool Empty();
};

Queue::Queue()
{
	Front = new celltype();
	Rear = new celltype();

	Front = Rear;
	Front->next = NULL;
	Rear->next = NULL;
}
Queue::~Queue() {}

elementtype Queue::FrontElem()
{

	int i;
	if (Front == Rear)
	{
		return -1;
	}
	else
	{
		i = Front->next->element;
		return i;
	}
}

void Queue::Enqueue(elementtype x)
{

	celltype *p = NULL;
	p = new celltype();

	p->element = x;

	Rear->next = p;
	Rear = p;

	cout << "Enqueue-> " << Rear->element << endl;
}

void Queue::Dequeue()
{
	celltype *p = NULL;
	p = new celltype();

	if (Front == Rear)
	{
		cout << "brak elementow";
	}
	else
	{
		p = Front;
		Front = Front->next;
		cout << "Dequeue-> " << Front->element << endl;
	}
	free(p);
}

bool Queue::Empty()
{
	if (Front == Rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	Queue *q;
	q = new Queue;

	cout << "is empty? " << q->Empty() << endl;
	q->Enqueue(5);
	cout << "is empty? " << q->Empty() << endl;
	cout << "Front element -> " << q->FrontElem() << endl;
	q->Dequeue();
	cout << "is empty? " << q->Empty() << endl;

	q->Enqueue(4);
	q->Enqueue(3);
	q->Enqueue(2);
	cout << "Front element -> " << q->FrontElem() << endl;
	q->Enqueue(1);
	q->Dequeue();
	q->Dequeue();
	q->Dequeue();
	q->Dequeue();
	q->Enqueue(20);
	q->Enqueue(30);
	cout << "Front element -> " << q->FrontElem() << endl;
	q->Dequeue();
	cout << "Front element -> " << q->FrontElem() << endl;
	q->Enqueue(6);
	cout << "Front element -> " << q->FrontElem() << endl;
	q->Dequeue();
	q->Dequeue();
	cout << "Front element -> " << q->FrontElem() << endl;
	cout << "is empty? " << q->Empty() << endl;
	q->~Queue();
	return 0;
}