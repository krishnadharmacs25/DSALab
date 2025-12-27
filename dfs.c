#include <stdio.h>

#define MAX 20

int n;
int adj[MAX][MAX];
int visited[MAX];

/* DFS function */
void DFS(int v)
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;   // initialize visited array
    }

    // Perform DFS starting from vertex 0
    DFS(0);

    // Check if all vertices are visited
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The given graph is CONNECTED\n");
    else
        printf("The given graph is NOT CONNECTED\n");

    return 0;
}