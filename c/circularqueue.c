#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
struct QUEUE
{
    int head;
    int tail;
    int count;
    int queue[SIZE];
}h,t,c,q;
typedef struct QUEUE qu;
void insert(qu *x);
void disp(qu *x);
void delete(qu *x);
int main(void)
{
    qu q;
    q.head=0;
    q.tail=0;
    q.count=0;
    int n=1;
    while(n){
        printf("Press 1 to Insert\n");
        printf("Press 2 to Delete\n");
        printf("Press 3 to Display\n");
        printf("Press 0 to Exit\n");
        scanf("%d",&n);
        switch (n) {
            case 1:insert(&q);
                    disp(&q);
                break;
            case 2:delete(&q);
                    disp(&q);
                break;
            case 3:disp(&q);
                break;
        }
    }
    return 0;
}
void insert(qu *x)
{
    int val;
    if( x->count==SIZE)
        printf("QUEUE is empty!\n");
    else
    {
        printf("Please enter the value\n");
        scanf("%d", &val);
        x->queue[x->tail]=val;
        x->tail=(x->tail+1)%SIZE;
        (x->count)++;
    }
}
void delete(qu *x)
{
    if(x->count==0)
        printf("QUEUE is empty!\n");
    else
    {
        printf("Deleted element = %d \n",x->queue[x->head]);
        x->head=(x->head+1)%SIZE;
        (x->count)--;
    }
}
void disp(qu *x)
{
    int i,j;
    if(x->count==0)
        printf("QUEUE is empty!\n");
    else{
        for(i=x->head , j=x->count;j>0 ;i=(i+1)%SIZE, j--)
            printf("| %d |",x->queue[i]);
        printf("\n");
    }
}
