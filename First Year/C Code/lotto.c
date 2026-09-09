#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <stdbool.h>

// variable declaration
int upperBound= 10; 
int lowerBound = 0;
int length = 5;
bool inputGood = false;
int item;
bool testing = false;


// tests if value is not in array
bool not_in_array (int n, int* ray, int size){
    for(int j = 0; j < size; j++){ // runs through all values in the array
        if(n == ray[j]){return false;} // returns false if it matches a value
    }   
    return true; // returns true if it matches no values
}

// accepts user input
void user_input (){
    if(testing == false){
        printf("Upper bound? ");
        scanf("%d", &upperBound);

        printf("Lower bound? ");
        scanf("%d", &lowerBound);

        printf("Length of list to generate (max: 10)? ");
        scanf("%d", &length);
    }
}

void main() {
    srand(time(NULL)); // seeds rand with time
    while (inputGood == false){
        user_input(); // gets user input

        if(upperBound < lowerBound) {
            printf("Lower bound is less than upper bound \n");
        }
        else if((upperBound - lowerBound) < (length + 1)){
            printf("Length of list less than range \n");
        }
        else if(length > 10){
            printf("Length is greather than 10 :-( \n");
        }
        else {inputGood = true;} // only returns true if it passes all 3 tests
    }

    int lotto[length]; // defines array with given length

    int i;
    while(i < length){ 
        item = (rand() % (upperBound - lowerBound)) + lowerBound; // generates a random number within the range
        if(not_in_array(item, lotto, length)){ // if it is in the array it loops back & i doesn't increment
            lotto[i] = item; // because i only increments if it is in the array we get the correct amount of values and we can assign to value place i
            i++;
        }
    }

    for(i = 0; i < length; i++){ // insertion sort algorithm
        int key = lotto[i]; // saves this value for later
        int j = i - 1; 

        while(j >= 0 && lotto[j] > key){ // if [j] is less than key & j is not 0
            lotto[j+1] = lotto[j]; // moves lotto[j] up the list one
            j = j - 1; // moves j down the list
        }
        lotto[j+1] = key; // moves key down the list till it is less than [j]
    }
    

    printf("%d", lotto[0]); // starts the printing without a comma
    for(i = 1; i < length; i++){
        printf(", %d", lotto[i]); // prints the values with a comma before them
    }
}