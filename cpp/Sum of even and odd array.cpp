#include<stdio.h>  //header files
#include<conio.h>
int main()    //function
    {
       int n,sumeven=0,sumodd=0;    // variable declaration 
        printf("Enter The Numbers of Elements :"); 
        scanf(" %d", &n); // input
        printf("\n Enter %d The Numbers : ",n);
        int a[n]; // array declartion 
            for(int i=0;i<n;i++)  // for loop
         {
                scanf("%d",&a[i]);
                if (a[i]%2==0)  // if condition for EVEN numbers
              {
                   sumeven=sumeven+a[i]; // if even , add all
              }
        else // else condition for ODD numbers
                 {
                    sumodd+=a[i]; // else , add all odd numbers
                }
             }
    printf("SUM of Even Numbers %d", sumeven);
    printf(" \n SUM of Odd Numbers %d", sumodd); // output
return 0;  // return value
}

