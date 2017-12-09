#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100;//Graph Size Vertex
int visited[SIZE];
vector <int> Graph[SIZE];
stack<int> ans;
int topolSort(int u)
{
	if(visited[u] == 1)
	{
		return -1;//cycle
	}
	if(visited[u] == 2)
	{
		return 0;
	}
	visited[u] = 1;
	for(int i = 0 ; i < Graph[u].size() ; i++)
	{
		topolSort(Graph[u][i]);
	}
	ans.push(u);
	return 0;
}

int main(){
	return 0;
}