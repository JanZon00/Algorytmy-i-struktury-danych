#include <iostream>
#include <vector>
#include <queue>
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
    int numberOfParents(int idx);
    vector<int> getTopologicalSort();
    void printTopologicalSort();
    int isAcyclic();
    void createVertices(int ile);    
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);    
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    void readFromFile(std::string path);
};

Graf::Graf(){
  numberOfVertices = 0;
  vertexList.clear();
}

int Graf::numberOfParents(int idx){
    int parents = 0;
    for(vector<int> v : vertexList){
        if (std::count(v.begin(), v.end(), idx)) {
            parents++;
        }
    }
    return parents;
}

vector<int> Graf::getTopologicalSort(){
    queue<int> que;
    vector<int> vec_sort_result;
    vector<int> parents;
    
    for(int i = 0; i < vertexList.size(); i++){
        int nOfParents = numberOfParents(i);
        parents.push_back(nOfParents);
        if (nOfParents == 0) {
            que.push(i);
        }
    }
    
    while (!que.empty()){
        vec_sort_result.push_back(que.front());
        vector<int> temp = getNeighbourIndices(que.front());
        que.pop();
        for(int i : temp){
            parents[i] -= 1;
            if(parents[i] == 0){
                que.push(i);
            }
        }
    }
    return vec_sort_result;
}

void Graf::printTopologicalSort(){
    
    for(int i : getTopologicalSort()){
        cout<<i<<" ";
    }
    cout<<endl;
}

int Graf::isAcyclic(){ 
    if(getTopologicalSort().size() == vertexList.size())
        return true;
    return false;    
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

vector<int> Graf::getNeighbourIndices(int idx){
    return vertexList[idx];
}

void Graf::printNeighbourIndices(int idx){
    for(int i : getNeighbourIndices(idx)){
        cout<<i<<" ";
    }
    cout<<endl;
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
            numberOfVertices = v1;
            if(vertexList.size() < v1){
                vertexList.resize(v1);
            }
        }
        else{
            string delimiter = " ";
            size_t pos = 0;
            while ((pos = text.find(delimiter)) != string::npos) {
                v1 = stoi(text.substr(0, pos));
                if(vertexList.size() < v1){
                    vertexList.resize(v1);
                }
                text.erase(0, pos + delimiter.length());
                pos = text.find(delimiter);
                v2 = stoi(text.substr(0, pos));
                text = "";
            }
            addEdge(v1, v2);
        }
    }
    GFile.close();
}


int main()
{
    Graf* g = new Graf();
    string file = "Graf1.txt";
    
    g->readFromFile(file);
    cout<<"Graf acykliczny? : "<<g->isAcyclic();
    cout<<endl;
    Graf* g2 = new Graf();
    string file2 = "Graf2.txt";
    
    g2->readFromFile(file2);
    g2->printTopologicalSort();
    cout<<"Graf acykliczny? : "<<g2->isAcyclic();
    cout<<endl;
    
	return 0;
}