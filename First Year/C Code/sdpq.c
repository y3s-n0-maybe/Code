#include <stdio.h>
#include <string.h>

int input1;
int input2;
char operation [1];

int main(){
    printf("Your operation: ");
    scanf("%c", &operation);

    printf("Your first number: ");
    scanf("%d", &input1);

    printf("Your second number: ");
    scanf("%d", &input2);
    
    if(!strcmp(operation, "+")){ printf("%d + %d = %d\n", input1, input2, input1 + input2);}
    else if(!strcmp(operation, "-")){printf("%d - %d = %d\n", input1, input2, input1 - input2);}
    else if(!strcmp(operation, "*")){printf("%d * %d = %d\n", input1, input2, input1*input2);}
    else if(!strcmp(operation, "/")){printf("%d / %d = %d\n", input1, input2, input1/input2);}
    else{printf("whuh");}

    return(0);
}