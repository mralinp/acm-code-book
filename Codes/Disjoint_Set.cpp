// To represent Disjoint Sets
struct DisjointSets
{
    int *parent, *rnk;
    int n;
    
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
 
            parent[i] = i;
        }
    }
    
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
 
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};