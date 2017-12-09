#include <bits/stdc++.h>
using namespace std;
const int SIZE = 50001;
bool visited[SIZE];
//Input: vector<int> Graph, vector<int> Reverce Graph,
// int Nomber Of vertexces
//Output:
//Strongly connected componnet Graph->
//--->SCC_Graph
//List of Each Componnent -->
//----->ListOfEachSCC
//to see each node blongs to where
//------SCC_list
//SCC returns the size of SCC graph
vector<int> SCC_Graph[SIZE];
vector<int> ListOfEachSCC[SIZE];
int SCC_List[SIZE];

void TopolSort(vector<int> g[],int u, stack<int>& ans){
    if(visited[u]){
        return;
    }
    visited[u] = true;
    for(int i = 0 ; i < g[u].size() ; i++){
        TopolSort(g,g[u][i],ans);
    }
    ans.push(u);
}

void DFSR(vector<int> g[],int u, int counter){
    if(visited[u]){
        return;
    }
    visited[u] = true;
    for(int i = 0 ; i < g[u].size() ; i++){
        DFSR(g,g[u][i], counter);
    }
    ListOfEachSCC[counter].push_back(u);
    SCC_List[u] = counter;
}

int SCC(vector<int> graph[], vector<int> graph_reverce[],int v){
    fill(visited, visited+v, false);
    for(int i = 0 ; i < v ; i++){
        SCC_Graph[i].clear();
        ListOfEachSCC[i].clear();
        SCC_List[i] = 0;
    }
    stack<int> TopolSorted;
    for(int i = 0 ; i < v ; i++){
        if(visited[i]){
            continue;
        }
        TopolSort(graph,i, TopolSorted);
    }
    fill(visited, visited+v, false);
    fill(SCC_List, SCC_List+v, 0);
    int counter = 0;
    while(!TopolSorted.empty()){
        int u = TopolSorted.top();
        TopolSorted.pop();
        if(visited[u]){
            continue;
        }
        DFSR(graph_reverce, u, counter);
        counter++;
    }
    for(int i = 0 ; i < counter ; i++){
        for(int j = 0 ; j < ListOfEachSCC[i].size() ; j++){
            int u = ListOfEachSCC[i][j];
            for(int k = 0 ; k < graph[u].size() ; k++){
                int w = graph[u][k];
                if(SCC_List[u] != SCC_List[w]){
                    SCC_Graph[SCC_List[u]].push_back(SCC_List[w]);
                }
            }
        }
    }
    return counter;
}