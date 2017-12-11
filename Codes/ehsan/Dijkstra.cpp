#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int Gsize = 100000;

int _d[Gsize], _p[Gsize];

void _Relax(int u, int v, int w)
{
  if(_d[v]>(_d[u]+w))
  {
    _d[v] = _d[u]+w;
    _p[v] = u;
  }
}

bool _cmp(int a, int b)
{
  return _d[a]>_d[b];
}

void Dijkstra(vector<int> G[], vector<int> W[], int s)
{
  for(int i=0;i<Gsize;i++)
    _d[i]=500000000;
  _d[s] = 0;
  int vis[Gsize]={0};
  vector<int> H;
  H.push_back(s);
  while(!H.empty())
  {
    pop_heap(H.begin(), H.end(), _cmp);
    int u=H.back(); H.pop_back();
    if(!vis[u])
      for(int i=0;i<G[u].size();i++)
      {
        _Relax(u, G[u][i], W[u][i]);
        H.push_back(G[u][i]); push_heap(H.begin(), H.end(), _cmp);
      }
    vis[u]=1;
  }
}

int main()
{

  return 0;
}
