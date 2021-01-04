#include <stdio.h>
int main() {    

    int num1, num2, dif;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

   
    dif = num1 - num2;      
    
    printf("%d - %d = %d", num1, num2, dif);
    return 0;
}