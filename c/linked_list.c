#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct LinkedList{
    int data;
    struct LinkedList *addr;
};
typedef struct LinkedList LL;
void APPEND(LL **h){
    int val;
    printf("Enter the number to append : ");
    scanf("%d",&val);
    if(*h==NULL){
        LL *temp=(LL *)malloc(sizeof(LL));
        temp->data=val;
        temp->addr=NULL;
        *h=temp;
    }else{
        LL *curr=*h;
        while(curr->addr!=NULL)
            curr=curr->addr;
        curr->addr=(LL*)malloc(sizeof(LL));
        curr->addr->data=val;
        curr->addr->addr=NULL;
    }
}
void DISPLAY(LL *node){
    if(node==NULL){
        printf("ERROR ! NO LINKED LIST\n");
    }else{
        while (node!=NULL) {
            printf("[ %d | %lu ]---->",node->data,node->addr);
            node=node->addr;
        }
        printf("NULL\n");
    }
}
void INSTBEF(LL **h){
    int val,target;
    if(*h==NULL){
        printf("NO LINKED LIST FOUND!\n");
    }else{
        printf("Enter the value that is to be added : ");
        scanf("%d",&val);
        printf("Enter the target value : ");
        scanf("%d",&target);
        LL *temp,*curr,*prev;
        curr=prev=*h;
        while(curr!=NULL){
            if(curr->data!=target){
                prev=curr;
                curr=curr->addr;
            }else{
                break;
            }
        }
        if(curr==NULL){
            printf("Target Not Found ERROR\n");return;
        }
        temp=(LL * )malloc(sizeof(LL));
        temp->data=val;
        temp->addr=curr;
        if(curr == *h){
            *h=temp;
        }else{
            prev->addr=temp;
        }
    }
}
void INSTAFT(LL **h){
    int val,target;
    if(*h==NULL){
        printf("NO LINKED LIST FOUND!\n");
    }else{
        printf("Enter the value that is to be added : ");
        scanf("%d",&val);
        printf("Enter the target value : ");
        scanf("%d",&target);
        LL *temp,*curr;
        curr=*h;
        while(curr!=NULL){
            if(curr->data!=target)
                curr=curr->addr;
            else
                break;
        }
        if(curr==NULL){
            printf("Target Not Found ERROR\n");return;
        }
        temp=(LL *)malloc(sizeof(LL));
        temp->addr=curr->addr;
        curr->addr=temp;
        temp->data=val;
    }
}
int main(){
    LL *head=NULL;
    int i=1;
    while(i){
        printf("Press 1 to APPEND\nPress 2 to DISPLAY\nPress 3 INSERT AFTER \nPress 4 INSERT BEFORE \nPress 0 to EXIT\n");
        scanf("%d",&i);
        switch (i) {
            case 1:
                APPEND(&head);
                break;
            case 2:
                DISPLAY(head);
                break;
            case 3:
                INSTAFT(&head);
                break;
            case 4:
                INSTBEF(&head);
                break;
            default:
                break;
        }
    }
    return 0;
}

