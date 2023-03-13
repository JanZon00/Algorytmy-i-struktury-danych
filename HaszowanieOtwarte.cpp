#include <iostream>

using namespace std;

#define B 65

typedef char * elementtype;
struct celltype
{
elementtype element;
celltype * next;
};

typedef celltype * position;

class dictionary
{
protected :
    position D[B];//tablica nagłówków list
public:
    dictionary();
    ~dictionary();
    void Makenul();
    bool Member(elementtype x);
    void Insert(elementtype x);
    void Delete(elementtype x);
    int H(elementtype x);
};

dictionary::dictionary()
{
    for(int i = 0; i < B; i++){
	    D[i] = NULL;
    }
}
dictionary::~dictionary()
{
    celltype *tmp = new celltype;
    for(int i = 0; i < B; i++){
	    while(D[i] != NULL){
		    tmp = D[i];
		    D[i] = D[i]->next;
		    delete tmp;
	    }
    }
}
void dictionary::Makenul(){

    celltype *tmp = new celltype;

    for(int i = 0; i < B; i++){
	    while(D[i] != NULL){
		    tmp = D[i];
		    D[i] = D[i]->next;
		    delete tmp;
	    }
        D[i] == NULL;
    }
}
bool dictionary::Member(elementtype x){

    celltype *tmp = new celltype;
    tmp = D[H(x)];

    while(tmp != NULL){

	    if(tmp->element == x){
		    return true;
        }

	    else{
		    tmp = tmp->next;
	    }
    }
    return false;
}

void dictionary::Insert(elementtype x){

    celltype *tmp = new celltype;
    cout<<"Insert : "<<x<<endl;
    tmp->element = x;

    if(Member(x) == false){
        int bucket = H(x);
        
        if(D[bucket] == NULL){
            D[bucket] = tmp;
            D[bucket]->next  = NULL;
        } 
        else{
            tmp->next = D[bucket]->next;
            D[bucket]->next = tmp; 
        }
    }
}
    
void dictionary::Delete(elementtype x){

    celltype *tmp = new celltype;
    celltype *tmp2 = new celltype;
    cout<<"Delete : "<<x<<endl;
    int bucket = H(x);
    if(D[bucket] != NULL){
        tmp = D[bucket];
        if(tmp->element == x){
            D[bucket] = D[bucket]->next;
        }
        else{
            while(tmp->next->element != x){
                tmp = tmp->next;
            }
            tmp2 = tmp->next;
            tmp->next = tmp->next->next;
            free(tmp2);
        }
    }
}

int dictionary::H(elementtype x){
    int ascii;
    ascii = int(x[0])%B;
    return ascii;
}

int main(){

    dictionary *d;
	d = new dictionary;
    char tab1[] = {'A', 'l', 'a', '\0'};
    cout<<"czy "<<tab1<<" w slowniku ? "<<d->Member(tab1)<<endl;
    d->Insert(tab1);
    cout<<"czy "<<tab1<<" w slowniku ? "<<d->Member(tab1)<<endl;
    cout<<"Wartosc hash dla "<<tab1<<" : "<<d->H(tab1)<<endl;
    cout<<"\n";
    char tab2[] = {'A', 's', '\0'};
    d->Insert(tab2);
    cout<<"czy "<<tab2<<" w slowniku ? "<<d->Member(tab2)<<endl;
    cout<<"Wartosc hash dla "<<tab2<<" : "<<d->H(tab2)<<endl;
    cout<<"Wartosc hash dla "<<tab1<<" : "<<d->H(tab1)<<endl;
    cout<<"\n";
    char tab3[] = {'Z', 'o', 'n', '\0'};
    d->Insert(tab3);
    cout<<"Wartosc hash dla "<<tab3<<" : "<<d->H(tab3)<<endl;
    cout<<"czy "<<tab3<<" w slowniku ? "<<d->Member(tab3)<<endl;
    cout<<"\n";
    d->Delete(tab1);
    cout<<"czy "<<tab2<<" w slowniku ? "<<d->Member(tab2)<<endl;
    cout<<"czy "<<tab1<<" w slowniku ? "<<d->Member(tab1)<<endl;
    cout<<"Makenul"<<endl;
    d->Makenul();
    cout<<"czy "<<tab2<<" w slowniku ? "<<d->Member(tab2)<<endl;
    cout<<"czy "<<tab3<<" w slowniku ? "<<d->Member(tab3)<<endl;
    d->~dictionary();
    return 0;
}

