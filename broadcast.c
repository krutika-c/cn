#include <stdio.h>

int main()
{
    int n, a[10][10], v[10] = {0};
    int q[10], front = 0, rear = 0;
    int i, j, src, u;

    printf("Enter number of hosts: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source host: ");
    scanf("%d", &src);

    q[rear++] = src;
    v[src] = 1;

    printf("Broadcast tree:\n");

    while(front < rear)
    {
        u = q[front++];

        for(j = 0; j < n; j++)
        {
            if(a[u][j] == 1 && v[j] == 0)
            {
                printf("%d -> %d\n", u, j);
                v[j] = 1;
                q[rear++] = j;
            }
        }
    }

    return 0;
}
