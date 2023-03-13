#include <iostream>
#include <vector>

using namespace std;

class setList
{
    vector<int> vec;	

public:
	int getSize();  
    void printSet(); 
    void insert(int x);
    void withdraw(int x);
    bool isInSet(int x); 
    setList operator+(setList& obj);  
    setList operator*(setList& obj);   
    setList operator-(setList& obj);
    bool operator==(setList& obj);  
    bool operator<=(setList& obj);
};

int setList::getSize()
{
    return vec.size();
}

void setList::printSet(){
    for (int i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
}
void setList::insert(int x){
    vec.push_back(x);
}

void setList::withdraw(int x)
{
    for (auto i = vec.begin(); i != vec.end()+1; i++) {
        if(*i == x){
            vec.erase(i);
        }
    }
}

bool setList::isInSet(int x)
{
    for (auto i = vec.begin(); i != vec.end(); i++){
        if(*i == x){
            return true;
        }
    }
    return false;
}

setList setList::operator+(setList& object){
	setList C;

    for (auto i = vec.begin(); i != vec.end(); i++) {
       C.insert(*i);
    }
     for (auto j = object.vec.begin(); j != object.vec.end(); j++) {
            if(!C.isInSet(*j)){
                C.insert(*j);
            }
    }
	return C;
}
	
setList setList::operator*(setList& object){
    setList C;

    for (auto i = vec.begin(); i != vec.end()+1; i++) {
        if(object.isInSet(*i)){
            C.insert(*i);
        }
    }
	return C;
}

setList setList::operator-(setList& object){
    setList C;

    for (auto i = vec.begin(); i != vec.end(); i++) {
       C.insert(*i);
    }

    for (auto i = C.vec.begin(); i != C.vec.end()+1; i++) {
        if(object.isInSet(*i)){
            C.withdraw(*i);
        }
    }
	return C;
}

bool setList::operator==(setList& object){
	
	for (auto i = vec.begin(); i != vec.end()+1; i++) {
        if(!object.isInSet(*i)){
            return false;
        }
    }
	return true;
}

bool setList::operator<=(setList& object){

	for (auto i = object.vec.begin(); i != object.vec.end(); i++) {
        if(!this->isInSet(*i)){
            return false;
        }
    }
	return true;
}


int main()
{
    
	setList A;
	setList B;
	A.insert(2);
	A.insert(6);
    A.insert(5);
    A.insert(3);
	B.insert(3);
    B.withdraw(3);
    B.insert(2);
	cout<<"SET A : ";
	A.printSet();
	cout<<"SET B : ";
	B.printSet();
    cout<<"Czy w A jest 0? : "<<A.isInSet(0)<<endl;
    cout<<"Czy w A jest 6? : "<<A.isInSet(6)<<endl;
	cout<<"SUMA : ";
	(A.operator+(B)).printSet();
	cout<<"ILOCZYN : ";
	(A.operator*(B)).printSet();
    cout<<"SET A : ";
    cout<<"ROZMIAR zbioru A : ";
    cout<<A.getSize()<<endl;
	cout<<"SET B : ";
    cout<<"Czy rowne? "<<(A.operator==(B))<<endl;
	cout<<"Czy set B zawarty w A? "<<(A.operator<=(B))<<endl;
    cout<<"ROZNICA : ";
	(A.operator-(B)).printSet();


	return 0;
}