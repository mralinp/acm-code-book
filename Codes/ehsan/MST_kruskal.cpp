#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Disjoint_set
{
  int *id, cnt, *sz;
public:
  Disjoint_set(int N)
  {
    cnt = N;
  	id = new int[N];
  	sz = new int[N];
    for(int i=0; i<N; i++)
    {
      id[i] = i;
	    sz[i] = 1;
    }
  }
  ~Disjoint_set()
  {
  	delete [] id;
  	delete [] sz;
  }
  int find(int p)
  {
    int root = p;
    while (root != id[root])
      root = id[root];
    while (p != root)
    {
      int newp = id[p];
      id[p] = root;
      p = newp;
    }
    return root;
  }
  void merge(int x, int y)
  {
    int i = find(x);
    int j = find(y);
    if (i == j) return;
    if   (sz[i] < sz[j])
    {
  		id[i] = j;
  		sz[j] += sz[i];
    }
    else
    {
  		id[j] = i;
  		sz[i] += sz[j];
    }
    cnt--;
  }
  bool connected(int x, int y) {return find(x) == find(y);}
  int count() {return cnt;}
};

const int Gsize = 9;

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
  return p1.second<p2.second;
}

vector<pair<int, int> > _A;

void MST_kruskal(vector<int> G[], vector<int> w[])
{
  Disjoint_set set(Gsize);
  _A.clear();
  vector<pair<pair<int, int>, int> > E;
  for(int i=0;i<Gsize;i++)
    for(int j=0;j<G[i].size();j++)
      if(i<G[i][j])
        E.push_back(make_pair(make_pair(i, G[i][j]), w[i][j]));
  sort(E.begin(), E.end(), cmp);
  for(int i=0;i<E.size();i++)
    if(!set.connected(E[i].first.first, E[i].first.second))
    {
      _A.push_back(make_pair(E[i].first.first, E[i].first.second));
      set.merge(E[i].first.first, E[i].first.second);
    }
}

void MST_kruskal(vector<pair<pair<int, int>, int> > E)
{
  Disjoint_set set(Gsize);
  _A.clear();
  sort(E.begin(), E.end(), cmp);
  for(int i=0;i<E.size();i++)
    if(!set.connected(E[i].first.first, E[i].first.second))
    {
      _A.push_back(make_pair(E[i].first.first, E[i].first.second));
      set.merge(E[i].first.first, E[i].first.second);
    }
}

int main()
{

  return 0;
}
