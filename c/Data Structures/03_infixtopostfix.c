#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void PUSH(char *s,int *t,char val){
    ++(*t);
    s[*t]=val;
}
char POP(char *s,int *t){
    --(*t);
    return(s[(*t)+1]);
}
void DISP(int *s,int t){
    for(int i=t;i>=0;i--){
        printf("| %c |\n",s[i]);
    }
    printf("\n");
}
char TOP(char *s,int *t){
    return(s[*t]);
}
int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
int main(){
    char stack[100],count=0;
    char infix[100],postfix[100];
    printf("Enter the infix string : ");
    scanf("%s",infix);
    int len=strlen(infix),t=-1;
    PUSH(stack, &t, 'N');
    for(int i=0;i<len;i++){
        if(isdigit(infix[i])){
            postfix[count]=infix[i];count++;
        }else if(infix[i]=='('){
            PUSH(stack, &t, infix[i]);
        }else if(infix[i]==')'){
            while(TOP(stack,&t)!='(' && TOP(stack, &t)!='N'){
                char k=POP(stack,&t);
                postfix[count]=k;count++;
            }
            if(TOP(stack,&t)=='('){
                POP(stack,&t);
            }
        }
        else{
            while(TOP(stack, &t)!='N' && prec(infix[i])<=prec(TOP(stack, &t))){
                char k=POP(stack, &t);
                postfix[count]=k;count++;
            }
            PUSH(stack, &t, infix[i]);
        }
    }
    while(TOP(stack, &t)!='N'){
        char k=POP(stack, &t);
        postfix[count]=k;count++;
    }
    for(int i=0;i<count;i++){
        printf("%c",postfix[i]);
    }
    return 0;
}

