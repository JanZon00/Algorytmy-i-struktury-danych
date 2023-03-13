#include <iostream>
#include <vector>
#include<iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Graf
{
    vector<vector<int>> vertexList;
    int numberOfVertices;

public:
    Graf();
    void createVertices(int ile);    
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);    
    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx); 
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path); 
};

Graf::Graf(){
  numberOfVertices = 0;
  vertexList.clear();
}

void Graf::createVertices(int ile){
    numberOfVertices = ile;
    vertexList.resize(numberOfVertices + 1);
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){

    if(i_Vertex_Index_1 <= vertexList.size()){
        if(!checkEdge(i_Vertex_Index_1, i_Vertex_Index_2)){
            vertexList[i_Vertex_Index_1].push_back(i_Vertex_Index_2);
        }    
    }  
}

void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){

    if(i_Vertex_Index_1 <= vertexList.size()){
        if(checkEdge(i_Vertex_Index_1, i_Vertex_Index_2)){
            vector<int> v = vertexList[i_Vertex_Index_1];
            v.erase(std::remove(v.begin(), v.end(), i_Vertex_Index_2), v.end());
            vertexList[i_Vertex_Index_1] = v;
        }    
    }
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    if(i_Vertex_Index_1 <= vertexList.size()){
         if(vertexList[i_Vertex_Index_1].size() > 0){
                for (int i: vertexList[i_Vertex_Index_1]){
                    if(i == i_Vertex_Index_2)
                        return true;
                }
         }
    }
    return false;
}

int Graf::vertexDegree(int idx){
    return vertexList[idx].size();
}

vector<int> Graf::getNeighbourIndices(int idx){
    return vertexList[idx];
}

void Graf::printNeighbourIndices(int idx){
    for(int i : getNeighbourIndices(idx)){
        cout<<i<<" ";
    }
    cout<<endl;
}

int Graf::getNumberOfEdges(){
    int edges = 0;
    for(vector<int> v : vertexList){
        edges += v.size();
    }
    return edges;
}

void Graf::readFromFile(string path){
    string text;
    fstream GFile(path);
    int v1, v2;
    size_t found;
    while (getline (GFile, text)) {
        found = text.find(" ");
        if(found == string::npos){
            v1 = stoi(text);
            if(vertexList.size() < v1){
                vertexList.resize(v1 + 1);
            }
        }
        else{
            string delimiter = " ";
            size_t pos = 0;
            while ((pos = text.find(delimiter)) != string::npos) {
                v1 = stoi(text.substr(0, pos));
                if(vertexList.size() < v1){
                    vertexList.resize(v1 + 1);
                }
                text.erase(0, pos + delimiter.length());
                v2 = stoi(text);
                text = "";
            }
            addEdge(v1, v2);
        }
    }
    GFile.close();
}
void test1()
{
    Graf* G = new Graf();    
    G->createVertices(10);
    G->addEdge(1, 2);
    G->addEdge(2, 3);
    G->addEdge(1, 5);
    std::cout << G->vertexDegree(1)<<"\n";
    std::cout << G->vertexDegree(8) << "\n";
    G->printNeighbourIndices(1);
    G->printNeighbourIndices(1);
    std::cout << G->checkEdge(1, 2)<<"\n";
    G->removeEdge(1, 2);
    G->printNeighbourIndices(1);
    std::cout << G->checkEdge(1, 2) << "\n\n\n\n\n";   
}

void test2()
{
    Graf* G2 = new Graf();
    string file = "GrafM.txt";
    G2->readFromFile(file);
    G2->printNeighbourIndices(1);
    std::cout << G2->getNumberOfEdges();
}

int main()
{
    /*Graf* g = new Graf();
    string file = "GrafM.txt";
    g->createVertices(20);
    g->readFromFile(file);
    cout<<"Czy krawedz 5 7 istnieje? : "<<g->checkEdge(5,7)<<endl;
    g->removeEdge(5,7);
    cout<<"Czy krawedz 5 7 istnieje? : "<<g->checkEdge(5,7)<<endl;
    cout<<"Number of edges : "<<g->getNumberOfEdges()<<endl;
    cout<<"Stopien wierzcholka 20 : "<<g->vertexDegree(20)<<endl;
    cout<<"Stopien wierzcholka 2 : "<<g->vertexDegree(2)<<endl;
    cout<<"wierzcholki sasiadujace z 2 : ";
    g->printNeighbourIndices(2);
    cout<<endl;
    */
    test1();
    test2();
	return 0;
}