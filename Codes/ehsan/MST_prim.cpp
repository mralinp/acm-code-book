#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Gsize = 200;

int key[Gsize], p[Gsize];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {return a.second>b.second;}

void MST_prim(vector<int> G[Gsize], vector<int> w[Gsize], int r, int n)
{
  for(int i=0;i<n;i++)
    {key[i]=1000000000; p[i]=-1;}
  key[r]=0;
  vector<pair<pair<int, int>, int> > q;
  for(int i=0;i<G[r].size();i++)
    q.push_back(make_pair(make_pair(i, G[r][i]), w[r][i]));
  make_heap(q.begin(), q.end(), cmp);
  while(!q.empty())
  {
    pair<pair<int, int>, int> E = q.front();
    pop_heap(q.begin(), q.end(), cmp); q.pop_back();
    
  }
}

int main()
{

  return 0;
}
