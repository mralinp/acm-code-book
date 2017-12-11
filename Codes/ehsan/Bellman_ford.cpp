#include <iostream>
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

bool Bellman_ford(vector<int> G[], vector<int> W[], int s)
{
  for(int i=0;i<Gsize;i++)
    _d[i]=500000000;
  _d[s] = 0;
  for(int k=0;k<Gsize-1;k++)
    for(int i=0;i<Gsize;i++)
      for(int j=0;j<G[i].size();j++)
        _Relax(i, G[i][j], W[i][j]);
  for(int i=0;i<Gsize;i++)
    for(int j=0;j<G[i].size();j++)
    {
      int u=i, v=G[i][j], w=W[i][j];
      if(_d[v]>_d[u]+w)
        return false;
    }
    return true;
}

int main()
{

  return 0;
}
