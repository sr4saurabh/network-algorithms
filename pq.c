#include<stdio.h>

int sz = 10;
int arr[10];

int front,rear;

void init()
{
    front = -1;
    rear = -1;
}

void insert_priority(int v)
{
    if(rear == sz-1)
        printf("overflow cannot insert into this\n");
    else
    {
        int location = rear+1;
        int i , j;
        for( i = 0; i <= rear; i++)
        {
            if(v < arr[i])
            {
                location = i;
                break;
            }
        }

        for(j = rear+1 ; j > location; j--)
        arr[j] = arr[j-1];

        arr[location] = v;
        rear++;

    }
}

void delete_priority(int v)
{
    if(rear == -1)
        printf("underflow happened , cant remove elements\n");
    else
    {
        int i , location = -1;
        for(int i = rear; i >= 0; i--)
            if(arr[i] == v)
        {
            location = i;
            break;
        }

        if(location == -1)
            printf("element not found error\n");
        else{
            for(i = location; i < rear; i++)
                arr[i] = arr[i+1];
            rear--;
            printf("element removed\n");
        }
    }
}

void display()
{
    int i;
    printf("elements currently in queue from smallest priority to largest priority are as follows--->\n");
    for(i = front+1; i <= rear; i++)
        printf("%d  ",arr[i]);
    printf("\n");
}

int main()
{
    int choice = 4;
    do
    {
        printf("menu\n 1. reset the queue 2.  insert as priority 3. delete as priority 5. display the queue 4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1 : init(); break;
            case 2 : {printf("enter value to be inserted in queue\n");int val;scanf("%d",&val);insert_priority(val);break;}
            case 3 : {printf("enter value to be deleted in queue\n");int val;scanf("%d",&val);delete_priority(val);break;}
            case 5 : display();break;
            case 4 : break;
            default : printf("enter correct choice\n");break;
        }
    }while(choice!=4);

    return 0;
}
