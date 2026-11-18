#include <stdio.h>

int graph[10][10], visited[10], rec[10];
int n;

int detect(int v)
{
    visited[v] = rec[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i])
        {
            if(!visited[i] && detect(i))
                return 1;
            else if(rec[i])
                return 1;
        }
    }

    rec[v] = 0;
    return 0;
}

int main()
{
    int i, j, cycle = 0;

    printf("Enter number of transactions: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for(i = 0; i < n; i++)
    {
        if(!visited[i] && detect(i))
        {
            cycle = 1;
            break;
        }
    }

    if(cycle)
        printf("Circular Wait Detected! Deadlock Possible.");
    else
        printf("No Circular Wait. No Deadlock.");

    return 0;
}
