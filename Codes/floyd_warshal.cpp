// C Program for Floyd Warshall Algorithm
#include<stdio.h>

#define V 4
#define INF 9999999

void floydWarshall (int graph[][V])
{
  int dist[V][V], i, j, k;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
      for (i = 0; i < V; i++)
      {
        for (j = 0; j < V; j++)
        {
          if (dist[i][k] + dist[k][j] < dist[i][j])
              dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
    // All distances -> dist
}

int main()
{
    /* example Graph:
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] =
    {
      {0,   5,  INF, 10},                    
      {INF, 0,   3, INF},
      {INF, INF, 0,   1},
      {INF, INF, INF, 0}
    };

    // Print the solution
    floydWarshall(graph);
    return 0;
}