#include<stdio.h>
#include<math.h>
int gcd(int a , int b)
{

    if(b == 0)
        return a;

    return gcd(b,a%b);
}

int mainasggd()
{
    int msg;
    printf("enter data to be encrypted\n");
    scanf("%d",&msg);
    printf("enter two prime numbers\n");

    int p,q;
    scanf("%d %d",&p,&q);

    int n = p * q; int tot = (p-1)*(q-1);

    int e = 0 , k = 2;
    while(k <= tot)
    {
        if(gcd(k,tot) == 1)
        {
            e = k;
            break;
        }
        k++;
    }
    int d = (1 + 2 * tot)/e;
    int c = pow(msg,e);
    int m = pow(c,d);

    c = fmod(c,n);
    m = fmod(m,n);

    printf(" original message %d\n cypher message %d\n decrypted message %d\n totient used = %d\n",msg,c,m,tot);


    return 0;
}
