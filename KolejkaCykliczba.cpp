#include <iostream>
using namespace std;

const int maxlength = 10;
typedef int elementtype;
typedef int position;

class Kolejka
{
protected:
    elementtype Queue[maxlength];
    position Front; // Indeks elementu czołowego
    position Rear;  // Indeks ostatniego elementu
public:
    Kolejka();
    int AddOne(int i);
    void Enqueue(elementtype x);
    void Dequeue();
    elementtype FrontElem();
    void Makenull();
    bool Empty();
};

Kolejka::Kolejka()
{
    Front = -1;
    Rear = -1;
}

int Kolejka::AddOne(int i)
{
    i = i + 1;
    return i;
}

void Kolejka::Enqueue(elementtype x)
{
    if (AddOne(Rear) == maxlength)
    {
        return;
    }
    else
    {
        Rear++;
        Queue[Rear] = x;
    }
    cout << "enque -> " << Queue[Rear] << endl;
}

void Kolejka::Dequeue()
{
    if (Rear == Front)
    {
        return;
    }

    else
    {
        Front++;
    }

    cout << "deque -> " << Queue[Front] << endl;
}

elementtype Kolejka::FrontElem()
{
    int x;

    if (Rear == Front)
    {
        return -1;
    }
    else
    {
        x = Queue[Front + 1];
    }
    return x;
}

bool Kolejka::Empty()
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
void Kolejka::Makenull()
{
    Rear = AddOne(Rear) % maxlength;
    Front = Rear;
}

int main()
{
    Kolejka k;

    cout << "is empty? " << k.Empty() << endl;
    k.Enqueue(5);
    cout << "is empty? " << k.Empty() << endl;
    cout << "Front element -> " << k.FrontElem() << endl;
    k.Dequeue();
    cout << "is empty? " << k.Empty() << endl;
    k.Enqueue(4);
    k.Enqueue(3);
    k.Enqueue(2);
    cout << "Front element -> " << k.FrontElem() << endl;
    k.Enqueue(1);
    cout << "Front element -> " << k.FrontElem() << endl;
    k.Dequeue();
    cout << "Front element -> " << k.FrontElem() << endl;
    k.Enqueue(6);
    cout << "Front element -> " << k.FrontElem() << endl;
    k.Dequeue();
    k.Dequeue();
    cout << "Front element -> " << k.FrontElem() << endl;
    k.Makenull();
    cout << "is empty? " << k.Empty() << endl;

    return 0;
}