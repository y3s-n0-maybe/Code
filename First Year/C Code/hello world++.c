#include <stdio.h>
#include <string.h>

char fullName [30];
char pronoun [30];
char age [30];

void introduceMe(){
    if ((!strcmp(pronoun, "she"))||(!strcmp(pronoun, "he"))){
        printf("This is %s, %s is %s years old.", fullName, pronoun, age);
    }
    else{
        printf("This is %s, %s are %s years old.", fullName, pronoun, age);
    }
}

int main(){
    printf("What is your name? \n");
    fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = 0;
    fflush(stdin);

    printf("Hello %s \n", fullName);

    printf("What age are you? \n");
    fgets(age, sizeof(age),stdin);
    age[strcspn(age, "\n")] = 0;
    fflush(stdin);

    printf("What pronouns do you use? \n");
    fgets(pronoun, sizeof(pronoun), stdin);
    fflush(stdin);
    pronoun[strcspn(pronoun, "/")] = 0;

    if ((!strcmp(pronoun, "she"))||(!strcmp(pronoun, "he"))){
        printf("This is %s, %s is %s years old.", fullName, pronoun, age);
    }
    else{
        printf("This is %s, %s are %s years old.", fullName, pronoun, age);
    }

return(0);
}
