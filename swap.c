//swap two integers without using a third variable

#include <stdio.h>

int main(){
    int a,b;

    printf("Enter the value of a: ");
    scanf("%d",&a);
    printf("Enter the value of b: ");
    scanf("%d",&b);

    b = a+b;
    a = b-a;
    b = b-a;

    printf("After swapping...\n");
    printf("Value of a: %d \n",a);
    printf("Value of b: %d \n",b);
}