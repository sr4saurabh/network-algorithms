#include<stdio.h>
int input[100];
int tim , bsize , rate , x , choice , count , dropped;

int min(int a , int b){
 return a<b?a:b;}

int mainasss()
{
    printf("enter the bucket size\n");
    scanf("%d",&bsize);
    printf("enter the output rate\n");
    scanf("%d",&rate);
    count = 0;
    do
    {
        tim++;
        printf("enter the number of packets coming at %d second\n",tim);
        scanf("%d",&input[tim]);

        printf("to continue press 1 else press  0\n");
        scanf("%d",&choice);
    }while(choice);
    int i;
    printf("time   incoming(received)     outgoing(sent)    dropped    remained \t\n");
    for(i = 1; i <= tim; i++)
    {
        printf("%d            \t         %d           \t          %d    ",i,input[i],min(input[i] + count , rate));
            if((x = (input[i] + count - rate)) > 0)
            {
                if(x > bsize)
                    dropped = x - bsize, count = bsize;
                else
                    dropped = 0, count = x;
            }
            else
            {
                count = 0;
                dropped = 0;
            }
            printf("\t  %d   \t     %d\n",dropped,count);
    }

    return 0;
}
