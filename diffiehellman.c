#include<stdio.h>

int val(int a,int b, int n)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans = (ans * a) % n;
        ans = (ans * ans)%n;
        b /= 2;
    }

    return ans;
}

int mainsad()
{
    printf("enter base number and prime\n");
    int base,prime;
    scanf("%d %d",&base,&prime);
    int a , b;
    printf("enter the secret number of client A and B\n");
    scanf("%d %d",&a,&b);

    int d = val(base,a,prime);
    int e = val(base,b,prime);

    int f = val(base,d,prime);
    int g = val(base,e,prime);

    printf("%d    %d\n",f,g);
    return 0;
}
