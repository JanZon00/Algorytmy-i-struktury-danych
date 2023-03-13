#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Graf
{

    int matrix[100][100];
    int numberOfVertices;

public:
    Graf();
    void createVertices(int ile);    
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);    
    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx); 
    vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path); 

private:
    void clear();
};

Graf::Graf(){
    numberOfVertices = 0;
    for(int i = 0; i < sizeof(matrix)/sizeof(matrix[0]); i++){
        for(int j = 0; j < sizeof(matrix)/sizeof(matrix[0]); j++){
           matrix[i][j] = 0;
        }
    }
}

void Graf::clear(){
    numberOfVertices = 0;
    for(int i = 0; i < sizeof(matrix)/sizeof(matrix[0]); i++){
        for(int j = 0; j < sizeof(matrix)/sizeof(matrix[0]); j++){
           matrix[i][j] = 0;
        }
    }
}

void Graf::createVertices(int ile){
    numberOfVertices = ile;
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 1;
}

void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 0;
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    if(matrix[i_Vertex_Index_1][i_Vertex_Index_2] == 1)
        return true;
    return false;
}

int Graf::vertexDegree(int idx){
    int deg = 0;
    if(idx < numberOfVertices){
        for(int i = 0; i < numberOfVertices; i++){
            if(idx!=i && matrix[idx][i] == 1){
                deg++;
            }
        }
    }    
    return deg;
}

vector<int> Graf::getNeighbourIndices(int idx){
    vector<int> vec;
    for(int i = 0; i <numberOfVertices ; i++){
        if(matrix[idx][i] == 1){
            vec.push_back(i);
        }
    }
    
    return vec;
}

void Graf::printNeighbourIndices(int idx){
    vector<int> v;
    v = getNeighbourIndices(idx);
    for (int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int Graf::getNumberOfEdges(){
    int edges = 0;
    for(int i = 0; i < numberOfVertices; i++){
        for(int j = 0; j < numberOfVertices; j++){
            if(i != j){
                if(matrix[i][j] == 1){
                    edges++;
                }
            }
        }
    }
    return edges;
}

void Graf::readFromFile(string path){
    numberOfVertices = (sizeof(matrix)/sizeof(*matrix));
    string text;
    fstream GFile(path);
    int v1, v2;
    size_t found;
    while (getline (GFile, text)) {
        found = text.find(" ");
        if(found == string::npos){
            v1 = stoi(text);
            matrix[v1][v1] = 1;
        }
        else{
            string delimiter = " ";
            size_t pos = 0;
            while ((pos = text.find(delimiter)) != string::npos) {
                v1 = stoi(text.substr(0, pos));
                text.erase(0, pos + delimiter.length());
                v2 = stoi(text);
                text = "";
            }
            matrix[v1][v2] = 1;
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