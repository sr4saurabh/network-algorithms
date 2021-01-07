#include <stdio.h>
#include <stdlib.h>
int cost[100][100];
int dist[50];
int n;
int flag[100];
int mainas()
{
    int i , j;
    printf("Hello world!\n");
    printf("Enter number of nodes\n");
    scanf("%d",&n);
        printf("Enter cost matrix\n");
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                {
                    printf("enter distance from %d to %d\n",i,j);
                    scanf("%d",&cost[i][j]);
                }
         printf("Enter the source vertex\n");

        int v;
        scanf("%d",&v);
        //start dijkstra



        for(int i = 0; i <= n; i++)
            dist[i] = cost[v][i] , flag[i] = 0;



        dist[v] = 0;
        flag[v] = 1;
        int count = 2;
      while(count <= n){
            int w; int mi = 100000;
            for( i = 1; i <= n; i++)
                if(dist[i] < mi && flag[i] == 0)
                    mi = dist[i] , w = i;

                flag[w] = 1;count++;

            for( j = 1; j <= n; j++)
                if(dist[w] + cost[w][j] < dist[j] && flag[j] == 0)
                    dist[j] = dist[w] + cost[w][j];

        }
        printf("minimum distances are \n");
        for(i = 1; i <= n; i++)
            printf("from %d to %d  --->   %d \n",v,i,dist[i]);
    return 0;
}
