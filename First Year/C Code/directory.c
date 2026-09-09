#include <stdio.h>
#include <string.h>

#define MAXNAMESIZE 20
#define MAXPHONEBOOK 100

typedef struct entry_tag{
    char name [MAXNAMESIZE];
    int id, prefix;
    long int body;
    int full;
}entry;

entry directory[MAXPHONEBOOK];

int nextID = 0; //keeps track of the next ID
int i;

int first_empty () {
    for(i = 0; i < MAXPHONEBOOK; i++) {
        if(directory[i].full == 0){
            return i; // finds the first empty entry
        }
    }
}

void add_entry (char addName[MAXNAMESIZE], int addPrefix, long int addBody) {
    entry addEntry; // defines a new empty entry

    // sets the elements of entry to what the user inputted
    strcpy(addEntry.name, addName); 
    addEntry.prefix = addPrefix;
    addEntry.body = addBody; 

    // sets the non-user defined elements to what they need to be
    addEntry.full = 1;
    addEntry.id = nextID;

    nextID++; // increments the next ID 
    int n = first_empty(); // finds the first empty slot
    directory[n] = addEntry; // inserts the entry

    // prints relevant information to the user
    printf("ID: %d \nName: %s \nPrefix: %d \nBody: %d", directory[n].id, directory[n].name, directory[n].prefix, directory[n].body);
}

void remove_entry (int givenID) {
    for(i = 0; i < MAXPHONEBOOK; i++) {
        if(directory[i].id == givenID){ //finds any entries that have a given ID
            directory[i].full = 0;  // tells the computer they're empty 
            strcpy(directory[i].name, ""); // wipes the name so that it's unsearchable
        }
    }
}

void return_entry(char givenName[MAXNAMESIZE]) {
    for(i = 0; i < MAXPHONEBOOK; i++) {
        if(strcmp(directory[i].name, givenName) == 0){ // finds any entries that match the given name
            // & prints the relevant information
            printf("Prefix: %d\n", directory[i].prefix);
            printf("Body: %d", directory[i].body);
        }
    }
}

int count_entries(){ 
    int count = 0;
    for(i = 0; i < MAXPHONEBOOK; i++) {
        if(directory[i].full == 1){ // counts the full entries
            count++;
        }
    }
    printf("%d valid entries.\n", count);
}


void main(){
    int pick;
    char inputName[MAXNAMESIZE];
    int inputID, inputPrefix;
    long int inputBody;

    while(1){
        int pick = 0;

        printf("What would you like to do? \n1. Add an Entry \n2. Remove an Entry \n3. Search a name \n4. Count entries\n5. Exit\n");
        scanf("%d", &pick); // user input (formatted nicely for once)

        switch(pick) {
            case 1:
                printf("\n-------\nAdding an Entry\n------\n");
                
                // takes user input
                printf("Name on entry? ");
                scanf("%s", inputName);

                printf("Prefix of phone number? ");
                scanf(" %d", &inputPrefix);

                printf("Body of phone number? ");
                scanf(" %d", &inputBody);

                // adds entry
                add_entry(inputName, inputPrefix, inputBody);

                printf("\n-------\nEntry Added!\n------\n");
            break;
            case 2:
                printf("\n-------\nRemoving an Entry\n------\n");
                
                // takes user input
                printf("Which ID would you like to remove? ");
                scanf(" %d", &inputID);

                // removes entry
                remove_entry(inputID);

                printf("\n-------\nEntry Removed!\n------\n");
            break;
            case 3:
                printf("\n-------\nSearching for an Entry\n------\n");
                
                // takes user input
                printf("Which name would you like to search for? ");
                scanf("%s", inputName);

                // returns matching entry
                return_entry(inputName);

                printf("\n------\n");
            break;
            case 4:
                count_entries();
            break;
            case 5:
                printf("\n-------\nExiting Program!\n------\n");
                return;
            break;
            }
    }
}