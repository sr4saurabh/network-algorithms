#include<stdio.h>
struct node{
    unsigned dist[10];
    unsigned from[10];
}rt[20];
int cost[100][100];
int n , i , j , count , k;

int mainass()
{
    printf("enter number of nodes\n");
    scanf("%d",&n);

    printf("enter the cost matrix\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            printf("enter the cost from %d to %d\n",i,j);
            scanf("%d",&cost[i][j]);
            rt[i].dist[j] = cost[i][j];
            rt[i].dist[i] = 0;
            cost[i][i] = 0;
            rt[i].from[j] = j;

        }

    do{
        count = 0;
        for(i = 1 ; i <= n; i++)
            for(j = 1; j <= n; j++)
                for(k = 1 ; k <= n; k++)
                {
                    if(cost[i][k] + rt[k].dist[j] < rt[i].dist[j]){
                            rt[i].dist[j] =  cost[i][k] + rt[k].dist[j]; count = 1;rt[i].from[j] = k;}
                }
    }while(count);

    for(i = 1; i <= n; i++)
        for( j = 1; j <= n; j++)
    {
        printf("distance from %d    to %d    via %d      is %d   \n", i,j,rt[i].from[j],rt[i].dist[j]);
    }

    return 0;
}
