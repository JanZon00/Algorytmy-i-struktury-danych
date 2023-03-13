#include <iostream>
#include <vector>
#include <queue>
#include<iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Jasio{
    
    int numberOfVertices;
    vector<vector<int>> vertexList;
    vector<int> numOfChildren;
    vector<int> vec;

public:
    Jasio(); 
    void readFromFile(string path);
    void addEdge(int vertex1, int vertex2);
    bool checkEdge(int vertex1, int vertex2);
    void deepFirstSearch(bool visited[], int root);
    int countSubGraph();
    void setSize(int x);
};

Jasio::Jasio(){
    vertexList.clear();
    numOfChildren.clear();
    numberOfVertices = 0;
    vec.clear();
}

void Jasio::setSize(int x){
    numberOfVertices = x;
    vertexList.resize(numberOfVertices);
}

void Jasio::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){

    if(i_Vertex_Index_1<= numberOfVertices){
        if(!checkEdge(i_Vertex_Index_1, i_Vertex_Index_2)){
            vertexList[i_Vertex_Index_1].push_back(i_Vertex_Index_2);
        }    
    }
}

bool Jasio::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){

    if(i_Vertex_Index_1 <= numberOfVertices){
         if(vertexList[i_Vertex_Index_1].size() > 0){
                for (int i: vertexList[i_Vertex_Index_1]){
                    if(i == i_Vertex_Index_2)
                        return true;
                }
         }
    }
    return false;
}

void Jasio::readFromFile(string path){

    string text;
    fstream GFile(path);
    int v;
    size_t found;
    bool size = false;
    while (getline (GFile, text)) {
        found = text.find(" ");
        if(found == string::npos){
            v = stoi(text);
            if(!size){
                numberOfVertices = v;
                vertexList.resize(numberOfVertices);
                size = true;
            }
            else{
                vec.push_back(v - 1);       //tablica do przechowywania elemntow z pliku
                numOfChildren.push_back(0);
            }
        }
    }
    
    for(int i = 0; i < vec.size(); i++){
        //tworze krawedzie grafu oraz wypelniam tablice numOfChildren ktora przechowuje liczbe dzieci kazdego wierzcholka
        addEdge(vec[i], i);     
        numOfChildren[vec[i]] += 1;
    }
    GFile.close();
}

int Jasio::countSubGraph(){

    bool visited[numberOfVertices];
	int result = 0;

	for (int i = 0; i < numberOfVertices; i++){
			visited[i] = 0;
	}

    //usuwam wszystkie wierzcholki ktore nie posiadaja dzieci, samotne wierzcholki nie zostana usuniete poniewaz jednoczesnie sa dzieckiem i rodzicem siebie samego
    while ((std::count(numOfChildren.begin(), numOfChildren.end(), 0))) {
        for(int i = 0; i < numberOfVertices; i++){
            if(numOfChildren[i] == 0){
                numOfChildren[i] = -1;      //wierzcholki nie posiadajace dzieci inicjuje na -1
                numOfChildren[vec[i]] -= 1;     //zmniejszam o 1 liczbe dzieci rodzica
                visited[i] = 1;    //w tablicy visited inicjuje na 1 komorke odpowiadajaca wierzcholkowi bez dzieci, zostanie on pominiety w algorytmie dfs
            }
        }
    }
	//pozostaly same cykle, ponizej algorytm liczy ile ich jest    
    for (int i = 0; i < numberOfVertices; i++){
		if (visited[i] == 0){
				result++;
				deepFirstSearch(visited, i);
		}
	}		
    return result;
}

void Jasio::deepFirstSearch(bool visited[], int root){

		visited[root] = 1;
		for (int i = 0; i < vertexList[root].size(); i++){
            if (visited[vertexList[root][i]] == 0){
				deepFirstSearch(visited, vertexList[root][i]);
			}
		}
}


void test(){
    Jasio* j = new Jasio();
    string file = "Skarbonki.txt";
    j->readFromFile(file);
    cout<<"Jasio musi rozbic : "<<j->countSubGraph()<<" skarbonek"<<endl;
}

void test2(){
    Jasio* j2 = new Jasio();
    j2->setSize(4);
    j2->addEdge(0, 1);
    j2->addEdge(1, 0);      //1
    j2->addEdge(1, 2);

    j2->addEdge(3, 3);      //2
    cout<<"Jasio musi rozbic : "<<j2->countSubGraph()<<" skarbonek"<<endl;

}

void test3(){
    Jasio* j3 = new Jasio();
    j3->setSize(12);
    j3->addEdge(0, 1);
    j3->addEdge(1, 0);      //1
    j3->addEdge(1, 2);

    j3->addEdge(3, 4);
    j3->addEdge(4, 5);
    j3->addEdge(5, 6);      //2
    j3->addEdge(6, 3);

    j3->addEdge(7, 8);
    j3->addEdge(8, 7);      //3

    j3->addEdge(9, 9);      //4

    j3->addEdge(10, 10);    //5
    
    j3->addEdge(11, 11);    //6
    cout<<"Jasio musi rozbic : "<<j3->countSubGraph()<<" skarbonek"<<endl;

}

int main()
{
    test();
    test2();
    test3();
	return 0;
}