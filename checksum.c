#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int checksum(int choice)
{
    char inp[255];
    printf("enter the string\n");
    scanf("%s",&inp);

    int l = strlen(inp);
    int n = (l+1)/2;

    int sum = 0;
    for(int i = 0; i < n; i++)
        sum = sum + inp[2*i] * 256 + inp[2*i + 1];

    if(choice)
    {
        printf("enter checksum\n");
        int temp;
        scanf("%x",&temp);
        sum += temp;
    }

    if(sum % 65536 != 0)
    {
        int r = sum % 65536;
        sum = sum/65536 + r;
    }

    sum = 65535 - sum;
    printf("%x",sum);
    return sum;

}

int mainadadsa()
{
    int choice = 3;
    do
    {
        printf("enter your choice\n 1. decode 2.encode 3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {int v = checksum(1); if(v != 0) printf("tampered value\n"); else printf("no error in transmission\n"); break;}
            case 2: checksum(0);break;
            default : printf("enter correct value\n");


        }


    }while(choice!=3);

}
