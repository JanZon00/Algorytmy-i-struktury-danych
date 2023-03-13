#include <iostream>

using namespace std;

class setArr
{	
	int size;
    const int universeSize = 100;
    bool* table;
    bool checkRangeCorrectness(int x);
	
public:
	setArr();
	void insert(int x);
	void withdraw(int x);
	bool isInSet(int i);
	int getSize();
	void clearSet();
	void printSet();
	setArr operator+(setArr& object);
	setArr operator*(setArr& object);
	setArr operator-(setArr& object);
	bool operator==(setArr& object);
	bool operator <= (setArr& object);
};

bool setArr::checkRangeCorrectness(int x){
	if(x >= universeSize){
		return false;
	}
	return true;
}

setArr::setArr()
{
	size = 0;
	table = new bool[universeSize];
	for(int i = 0; i < universeSize; i++){
		table[i] = 0;
	}
}

void setArr::insert(int x)
{
	if(checkRangeCorrectness(x)){
		table[x] = 1;
		if(size < x){
			size = x;
		}
	}
}

void setArr::withdraw(int x)
{
    table[x] = 0;
}

bool setArr::isInSet(int i)
{
    if(table[i] == 1){
        return true;
    }
    return false;
}

int setArr::getSize()
{
	return size;
}

void setArr::clearSet()
{	
	for(int i = 0; i <=size; i++){
		if(table[i] == 1){
			table[i] = 0;
		}
	}
}

void setArr::printSet(){
	for(int i = 0; i <=size; i++){
		if(table[i] == 1){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

setArr setArr::operator+(setArr& object){
	setArr C;
	C.size = size + object.size;

	for(int i = 0; i < C.size; i++){
		C.table[i] = table[i] || object.table[i]; 
	}
	return C;
}
	
setArr setArr::operator*(setArr& object){
	setArr C;
	C.size = size + object.size;

	for(int i = 0; i < C.size; i++){
		C.table[i] = table[i] && object.table[i]; 
	}
	return C;
}

setArr setArr::operator-(setArr& object){
	setArr C;
	C.size = size + object.size;

	for(int i = 0; i < C.size; i++){
		C.table[i] = table[i] && !object.table[i]; 
	}
	return C;
}

bool setArr::operator==(setArr& object){
	
	for(int i = 0; i < object.size; i++){
		if(table[i] != object.table[i]){
			return false;
		}
	}
	return true;
}

bool setArr::operator <= (setArr& object){

	for(int i = 0; i < object.size; i++){
		if(table[i] && !object.table[i]){
			return false;
		}
	}
	return true;
}


int main()
{
	setArr A;
	setArr B;
	A.insert(7);
	A.clearSet();
	A.insert(2);
	A.insert(6);
	A.insert(3);
	A.insert(9);
	A.withdraw(9);
	cout<<"SET A : ";
	A.printSet();
	B.insert(3);
	cout<<"SET B : ";
	B.printSet();
	cout<<"Rozmiar tablicy B : "<<B.getSize()<<endl;
	cout<<"Czy 3 jest w B? : "<<B.isInSet(3)<<endl;
	cout<<"Czy rowne? "<<(A.operator==(B))<<endl;
	cout<<"Czy set B zawarty w A? "<<(B.operator<=(A))<<endl;
	cout<<"SUMA : ";
	(A.operator+(B)).printSet();
	cout<<"ROZNICA : ";
	(A.operator-(B)).printSet();
	cout<<"ILOCZYN : ";
	(A.operator*(B)).printSet();

	return 0;
}