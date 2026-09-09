#include <stdio.h>

int input;

float divbytwo(float num) {
    num = num/2;
}

void main(){
    printf("?: ");
    scanf("%d", &input);
    float x = divbytwo(input);
    printf("%f", x);
}