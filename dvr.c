#include <stdio.h>

int main()
{
    int n, cost[10][10], d[10][10];
    int i, j, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (99 for no link):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            d[i][j] = cost[i][j];
        }

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("\nRouting Tables:\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRouter %d:\n", i);
        printf("Destination\tCost\n");

        for(j = 0; j < n; j++)
            printf("%d\t\t%d\n", j, d[i][j]);
    }

    return 0;
}
