#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define maxguess 200
#define wordlength 17

int guessCheck(char fuckMe[]); 

// Function to insert a random word in a string of random words
int main (void){

    //array to store predetermined words
    char words[][wordlength+1] = {
        {"dick"},
        {"buttcheeks"},
        {"mybrotherinchrist"},
        {"boobs"},
        {"keyboard"},
        {"youlying"},
        {"mouse"},
        {"waterbottle"},
        {"radheradhe"},
        {"poop"},
        {"eden"},
        {"nukes"},
        {"failure"},
        {"terrible"},
        {"whooped"},
 };

    //array to store users guess (must be lowercase chars)
    char userGuess[maxguess+1];

    //array to store hidden random word 
    char hiddenWord[wordlength+60];

    //filling user hidden random word with random lowercase letters
    srand(time(NULL)); 

    for (int count = 0; count<wordlength+60; count++){
        hiddenWord[count] = 'a'+ (rand()%26); 
    }

    hiddenWord[wordlength+60] = '\0'; 

    //finding a random position at which to insert the random word, ensuring word can fit in array
    int randind = rand()%60; 

    //choosing random word, and putting it into array
    char *randword = words[rand()%15];
    int len = strlen(randword); 
    
    for (int count=0; count<len; count++){
        hiddenWord[randind+count] = randword[count];
}

    

    int truth = 0; 

    while (truth==0){
   
        //displays array to user, and asks them to input their guess word
    printf("%s \n" , hiddenWord);

    printf("Please insert your guess (it must be a lowercase alphanumeric symbol)\n");
    scanf("%200s", userGuess); 

    //tells user if their guess is valid or not

    if (guessCheck(userGuess) == 0){
        printf("error, invalid guess, try again\n");
        continue; 
    } 

    int checker = strcmp(userGuess, randword); 

    if (checker == 0){
        printf("correct! you're awesome\n"); 
        truth = 1; 
    }

    else {
        printf("incorrect dumbass try again\n");  
    }
}
    
    return 0; 


    
}

//function that checks validity of word

int guessCheck(char fuckMe[]){

   for (int count=0; fuckMe[count]!='\0'; count++){
    if (
        isupper(fuckMe[count])!=0 ||
        ispunct(fuckMe[count])!=0 ||
        isdigit(fuckMe[count])!=0
    )
    return 0; 
    } 
   
    return 1; 
 }


    




