#include <stdio.h>

// declaration of all the variables used in the loops and functions
int counter = 0;
int astCounter = 0;
int goCounter = 0;
int spaceCounter = 0;
int length;
int width;
char character = '*';
int form;

void printSquare(int length, int width, char character, int form){    
    while(goCounter < 2) {
        // print first & last line
        while(counter < width){
            printf("%c", character);
            counter++;
        }
        printf("\n");
        counter = 0;

        while(astCounter < (length - 2)){ // prints middle lines
            printf("%c", character); // prints edge character

            while(spaceCounter < (width - 2)){ // will print middle characters, spaces if hollow, char if full
                if(form == 1){printf(" ");}
                else if(form == 0){printf("%c", character);}
                spaceCounter++;
            }
            spaceCounter = 0;

            printf("%c\n", character);
            astCounter++;
        }
        goCounter++;
    }
}

void main() {
    // user inputs
    printf("Length?: ");
    scanf("%d", &length);

    printf("Width?: ");
    scanf("%d", &width);
    fflush(stdin);

    printf("Character?: ");
    scanf(" %c", &character);

    printf("Hollow (1) or Solid (0)? ");
    scanf("%d", &form);
    fflush(stdin);

    // call the function
    printSquare(length, width, character, form);
}