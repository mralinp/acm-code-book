#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int Gsize = 100000;

void BFS(vector<int> G[], int s, int n)
{
  int color[Gsize], d[Gsize], p[Gsize];
  queue<int> Q;
  for(int i=0;i<Gsize;i++)
  {
    color[i]=0; p[i]=-1;
  }
  color[s]=1; d[s]=0;
  Q.push(s);
  while(!Q.empty())
  {
    int v ,u=Q.front(); Q.pop();
    // code :
    for(int i=0;i<G[u].size();i++)
    {
      v=G[u][i];
      if(color[v]==0)
      {
          color[v]=1; d[v]=d[u]+1; p[v]=u;
          Q.push(v);
      }
    }
    color[u]=2;
  }
}

int main()
{
  
  return 0;
}
