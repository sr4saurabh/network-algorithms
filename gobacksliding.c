#include<stdio.h>
int mainaqq()
{
    printf("enter the no. of frames to be sent\n");
    int n;
    scanf("%d",&n);
    printf("enter the window size\n");
    int w;
    scanf("%d",&w);
    //------------
    int frames[n+1];
    printf("enter frames one by one\n");
    for(int i = 1; i <= n; i++)
        scanf("%d",&frames[i]);
    //------------

    printf("sending frames one by one and receiving acknowledgment assuming no frames are lost in the network\n");
    for(int i = 1; i <= n; i++)
    {
        printf("%d ",frames[i]);
        if(i % w == 0)
        {
            printf("\n Acknowledgement of above frames received\n");
        }

    }

    if(n%w != 0)
        printf("\n Acknowledgement of above frames received\n");
    return 0;
}
