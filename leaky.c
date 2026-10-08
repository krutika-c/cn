#include <stdio.h>

int main()
{
    int size, rate, n, packet, bucket = 0;
    int i, send;

    printf("Enter bucket size: ");
    scanf("%d", &size);

    printf("Enter output rate: ");
    scanf("%d", &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter packet size: ");
        scanf("%d", &packet);

        if(bucket + packet <= size)
        {
            bucket += packet;
            printf("Packet added to bucket\n");
        }
        else
            printf("Packet discarded\n");

        send = (bucket < rate) ? bucket : rate;
        bucket -= send;

        printf("Transmitted: %d\n", send);
        printf("Remaining in bucket: %d\n", bucket);
    }

    return 0;
}
