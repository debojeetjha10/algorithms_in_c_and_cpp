#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void PUSH(int *s,int *t,int val){
    ++(*t);
    s[*t]=val;
}
int POP(int *s,int *t){
    --(*t);
    return(s[(*t)+1]);
}
void DISP(int *s,int t){
    for(int i=t;i>=0;i--){
        printf("| %d |\n",s[i]);
    }
    printf("\n");
}
int main(){
    int stack[100],t=-1;
    char postfix[100];
    printf("Enter the postfix expression : ");
    scanf("%s",postfix);
    int n=strlen(postfix),v1,v2,res=0;
    for(int i=0;i<n;i++){
        if(isdigit(postfix[i])){
            PUSH(stack,&t,postfix[i]-48);
        }else{
            v1=POP(stack, &t);
            v2=POP(stack, &t);
            switch(postfix[i])
            {
                case '+':
                    res=v1+v2;
                    break;
                case '-':
                    res=v2-v1;
                    break;
                case '*':
                    res=v2*v1;
                    break;
                case '/':
                    res=v2/v1;
                    break;
                case '^':
                    res=pow(v2, v1);
                    break;
            }
            PUSH(stack, &t, res);
        }
        DISP(stack, t);
    }
    printf("Your result is : %d",POP(stack, &t));
    return 0;
}

