// Wordle style game.
// If user guesses correct letter, it remains.
// If letter non existent, it gets X in its place. 
// If letter in wrong spot, it gets a - in its place 

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int validCheck(char guess[]); 


int main (void){ 

    //array to store possible words 
    char bank[][6] = {
                        "spank",
                        "adieu",
                        "crank",
                        "crime",
                        "swoon",
                        "broom",
                        "spine",
                        "alive",
                        "power",
                        "cream",
                        "stove",
                        "strip",
                        "bride"
    }; 

    //array to store user guess
    char userGuess[6] = "aaaaa";  

    //array to display random word
    char guessWord[6]; 

    //choosing random word 
    srand(time(NULL)); 
    int randInd = (rand() % (sizeof(bank)/sizeof(bank[0]))); 
    strcpy(guessWord ,bank[randInd]); 

    //prompting user for guess and ensuring it matches criteria 
    printf("The word must be 5 letters and lowercase\n"); 
    
    
    while (strcmp(userGuess, guessWord) != 0){
    
    printf("Guess the Word!\n");
    scanf("%s", userGuess);
    
    if (validCheck(userGuess) == 0){
        printf("Error, Guess is too long!\n");     
    }
        else if (validCheck(userGuess) == 1){
            printf("Error, Guess is too short!\n"); 
        }

            else if (validCheck(userGuess) == 2){
            printf("Error, Guess must be a lowercase letter\n"); 
        }
    else {
        int count = 0; 
        
        while(userGuess[count] != '\0'){

             if (userGuess[count] == guessWord[count]){
                 printf("%c", userGuess[count]); 
                 count++;
                 } 
            
             else {
                int count2 = 0; 
                    while (guessWord[count2] != '\0'){
                        if (userGuess[count] == guessWord[count2]){
                            printf("-"); 
                        }
                        else {
                            printf("X"); 
                        }
                        count2++; 
                    }

                 }
                count++; 
            }
        }

    }


return 0; 
}



int validCheck(char guess[]) {
    
     if (strlen(guess) > 5)   {
            return 0;
        }
    else if (strlen(guess) < 5){
        return 1; 
    }
    for (int count=0; guess[count] != '\0'; count++){
         if (
            isupper(guess[count]) != 0 ||
            isdigit(guess[count]) != 0 ||
            ispunct(guess[count]) != 0
        ) {
        return 2; 
    }
 }


        return 3;
    
}

   

    

