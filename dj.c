#include <stdio.h>

int main()
{
    int n, cost[10][10], d[10], v[10];
    int i, j, src, min, u;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (99 for no edge):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source node: ");
    scanf("%d", &src);

    for(i = 0; i < n; i++)
    {
        d[i] = cost[src][i];
        v[i] = 0;
    }

    d[src] = 0;

    for(i = 0; i < n; i++)
    {
        min = 99;
        u = -1;

        for(j = 0; j < n; j++)
            if(!v[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }

        if(u == -1)
            break;

        v[u] = 1;

        for(j = 0; j < n; j++)
            if(!v[j] && d[u] + cost[u][j] < d[j])
                d[j] = d[u] + cost[u][j];
    }

    printf("Shortest distances:\n");
    for(i = 0; i < n; i++)
        printf("%d to %d = %d\n", src, i, d[i]);

    return 0;
}
