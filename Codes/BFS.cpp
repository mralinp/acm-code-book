#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100; //Vertex size
int main(){
	int source = 0;
	vector<int> Graph[SIZE];
	bool visited[SIZE];
	int distance[SIZE];
	fill(visited, visited+SIZE, 0);
	fill(distance, distance+SIZE, INT_MAX);
	queue<int> q;
	q.push(source);
	visited[source] = true;
	distance[source] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0 ; i < Graph[u].size(); i++){
			if(visited[Graph[u][i]]){
				continue;
			}
			visited[Graph[u][i]] = true;
			distance[Graph[u][i]] = distance[u] + 1;
			q.push(Graph[u][i]);
		}
	}
	return 0;
}