#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 5

typedef struct LinkeckList //self refarential structure //diclaration of new datatype
{
    int data;
    struct LinkeckList *addr;
}LL;

void APPEND( LL **H ); //Function prototype diclaration
void DISPLAY( LL *Node );

int main( void )
{
    LL *Head = NULL;//defining a pointer type variable
    int n=1;
    while(n)
    {
        printf("APPEND press 1\n");
        printf("DISPLAY pree 2\n");
        printf("EXIT press 0\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1: APPEND( &Head );
                    break;
    
            case 2: DISPLAY( Head );
                    break;
            
                 
        }
    }
    return 0;
}

void APPEND( LL **H )
{
    int val;
    printf("Please Enter the data :");
    scanf("%d",&val);
    
    if( *H == NULL)
    {
        LL *temp = (LL *)malloc( sizeof(LL));
        temp->data = val;
        temp->addr = NULL;
        *H = temp;
    }
    else
    {
        LL *Current = *H;
        while( Current->addr != NULL )
            Current = Current->addr;
        
        Current->addr = (LL*)malloc( sizeof(LL));
        Current->addr->data = val;
        Current->addr->addr = NULL;
    }
    
}

void DISPLAY( LL *Node )
{
    if( Node == NULL )
        printf("ERROR!!! NO LINK LIST !!!\n");
    else
    {
        while( Node != NULL )
        {
            printf("[ %d | %lu ]--->",Node->data, Node->addr);
            Node = Node->addr;
        }
        printf("NULL\n");
    }
}

