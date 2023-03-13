#include <iostream>
#include <vector>

using namespace std;

class KolejkaPriorytetowa
{
    vector<int> vec;

    public:
    void insert(int x);
    void RemoveRootElem();
    void print();
    int getRootElem();
};

void KolejkaPriorytetowa::insert(int x){
    vec.push_back(x);
    int index = vec.size() - 1;
    if(index != 0){
        if(index %2 != 0){
            int parent = vec.at((index - 1)/2);
            while(parent > x){
                int temp = vec.at(index);
                vec.at(index) = parent;
                vec.at((index-1)/2) = temp;
                index = (index-1)/2;
                if(index <= 0){
                    break;
                }
                parent = vec.at((index - 1)/2);
            }
        }
        if(index != 0 && index %2 == 0){
            int parent = vec.at((index - 2)/2);
            while(parent > x){
                int temp = vec.at(index);
                vec.at(index) = parent;
                vec.at((index-2)/2) = temp;
                index = (index-1)/2;
                if(index <= 0){
                    break;
                }
                parent = vec.at((index - 1)/2);
            }
        }
    }
}

void KolejkaPriorytetowa::RemoveRootElem(){
    vec.at(0) = vec.at(vec.size()-1);
    vec.pop_back();
    int index = 0;
    int tmp;
    int size = vec.size();
    if(size <= 1){}
    else if(size == 2){
        tmp = vec.at(1);
        vec.at(1) = getRootElem();
        vec.at(0) = tmp;
    } 
    else{
        int child_1 = index*2 + 1;
        int child_2 = index*2 + 2;
        while(vec.at(index) > vec.at(child_1) || vec.at(index) > vec.at(child_2)){
            if(vec.at(child_1) >= vec.at(child_2)){
                tmp = vec.at(child_2);
                vec.at(child_2) = vec.at(index);
                vec.at(index) = tmp;
                index = child_2;
            }
            else{
                tmp = vec.at(child_1);
                vec.at(child_1) = vec.at(index);
                vec.at(index) = tmp;
                index = child_1;
            }
            if(index*2+2 <= vec.size()-1){
                    child_1 = index*2 + 1;
                    child_2 = index*2 + 2;
            }
            else{
                if(index*2+2 == vec.size()){
                    child_1 = index*2 + 1;
                    tmp = vec.at(child_1);
                    vec.at(child_1) = vec.at(index);
                    vec.at(index) = tmp;
                }
                break;
            }
        }  
    }     
}

void KolejkaPriorytetowa::print(){
    for (int i: this->vec){
        cout<<i<<" ";
    }
    cout<<endl;
}

int KolejkaPriorytetowa::getRootElem(){
    return vec.front();
}

int main()
{
    KolejkaPriorytetowa k;
    k.insert(2);
    k.insert(3);
    k.insert(4);
    k.insert(5);
    k.insert(6);
    k.insert(7);
    k.insert(8);
    k.insert(9);
    k.insert(10);
    k.insert(1);
    cout<<"Sterta : ";
    k.print();
    cout<<"Korzen : "<<k.getRootElem()<<endl;
    k.RemoveRootElem();
    cout<<"Sterta po usunieciu korzenia: ";
    k.print();
    k.RemoveRootElem();
    cout<<"Sterta po usunieciu korzenia: ";
    k.print();
	return 0;
}

