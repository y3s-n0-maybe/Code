#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;


// declaration of variables
char filename[256];
char dir [256] = "C:\\Users\\Owner\\Desktop\\Code\\C Code\\Spare Files\\";
char uncypher[256];
char cypher[256];
int i;
int ascii;
int x;
int eod;

void main() {
    printf("What would you like to do? \n0. Encrypt \n1. Decrypt \n");
    scanf("%d", &eod); //asks & saves user choice

    printf("Which file would you like to encrypt/decrypt? ");
    scanf("%s", filename); //gets filename
    strcat(dir, filename);
    //appends filename to filepath so it can be accessed
    //(unneccesary if filepath is in the same directory as code)

    fptr = fopen(dir, "r");
    if(fptr == NULL) {
        printf("File does not exist"); //exits if file does not exist
        return;
    }
    fgets(uncypher, sizeof(dir), fptr); // saves content of file to uncypher
    fclose(fptr);

    printf("Cypher key (integer)? "); // gets & saves cypher key
    scanf("%d", &x);

    if(eod == 1){x = 0 - x;} // reverses cypher key if it is decrypting

    while (i < sizeof(uncypher)) { // runs through every character in uncyphered string
        ascii = (int)uncypher[i]; // takes the ascii number of character in uncyphered string
        ascii = ascii + x; // adds x to ascii number (if decrypting this will take x from ascii number)
        cypher[i] = ascii; // sets cyphered string[i] to the encrypted of uncyphered[i]
        i++; 
    }

    printf("%s", cypher); // prints the cyphered string

    fptr = fopen("C:\\Users\\Owner\\Desktop\\Code\\C Code\\Spare Files\\cypher.txt", "w");
    fprintf(fptr, cypher);
    fclose(fptr);
    // saves it to file
}