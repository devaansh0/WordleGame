#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>

//Functions.
int randCard (void);  
int face2Num(int cardNum); 
int aceConv (int card,int cardCount);
int playAgain (int userBal); 
void dCardGen(int dealCard[], char dealName[13][6], int *dealCount, int *dCount, char cards[13][6]); 
void uCardGen(int userCard[], char userName[13][6], int *userCount, int *uCount, char cards[13][6]); 
void gameUpdate(int *userBal, int gameResult, int *gameStar); 

 


int main (void){ 
     
    //Seeding the random with the time, the internal clock time, and the process ID.
    srand(time(NULL) ^ clock() ^ _getpid());  

//The total count of the users and dealers cards. 
int userCount = 0; 
int dealCount = 0; 

//The amount of money that the user has. 
int userBal = 50;

//Determines whether or not to start the game. 
int gameStar = 0; 

//Array to hold users card number, and to accurately index the value. 
int userCard[10]; 
int uCount = 0; 

//Array to hold dealers card number, and to accurately index the value. 
int dealCard[10]; 
int dCount = 0; 


//Array with all the card names. 
char cards[13][6] = {
    "Ace",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Jack",
    "Queen",
    "King"
}; 

//Arrays to store user/dealer card names.
char userName[13][6]; 
char dealName[13][6];

//Array to state whether the user hits or stands. 
char userChoice[1][11]; 

//Variable to state whether the user wins, loses, or ties the game. 
int gameResult = -1;  

//Array to store user words
char userWord[50]; 


// Starts game for first time.
printf("\n \nHello! Welcome to Blackjack!\n \n");

//Runs every time game restarts, prompts user to start another game. 
while (gameStar == 0){

   
printf("Would you like to start a game? \n"   
            
            //States balance. 
            "Your balance is $%d \n"
            "Press (1) to start! \n \n", userBal);
    
        scanf("%d", &gameStar); 

            //Stores if user started game. 
            if (gameStar != 1){
                 
                    //Clears buffer input.
                    while(getchar() != '\n'){}
                    //Shows them the error of their ways. 
                    printf("Why are you still here if you do not want to play. \n \n \n");
                    Sleep(2000); 
                    }
                

                }


while (gameStar == 1){

    userCount = 0;
    dealCount = 0;
    uCount = 0;
    dCount = 0;
    gameResult = -1;

//Deals cards to user and dealer. 
printf("Dealing Cards!\n");
    
    //assigning first random card to user. 
    uCardGen(userCard, userName, &userCount, &uCount, cards); 

    //assigning second random card to user, and giving it a name. Converting any facecards into value "10". Converting any aces into value "11".
    uCardGen(userCard, userName, &userCount, &uCount, cards); 
 
    //assigning first random card to dealer, and giving it a name. Converting any facecards into value "10". Converting any aces into value "11".
    dCardGen(dealCard, dealName, &dealCount, &dCount, cards); 

    //assigning second random card to dealer, and giving it a name. Converting any facecards into value "10". Converting any aces into value "11".
     dCardGen(dealCard, dealName, &dealCount, &dCount, cards); 

     Sleep(500); 

    //Counts the total of both the player and dealers hand.  
    userCount = userCard[0] + userCard[1]; 
    dealCount = dealCard[0] + dealCard[1];

    //Displays cards. 
printf("Your cards are:                                The dealers first card is: \n"
       "%s       %s  (Total %d)                                  %s   \n \n", userName[0], userName[1], userCount, dealName[0]); 


     //while the game isnt over...
     while (gameResult != 0 && gameResult != 1 && gameResult != 2){

        if (userCount == 21)
            break; 

            //If its not 21, asks them to hit or stand.
            printf("Would you like to hit or stand?\n");
            scanf("%9s", userChoice[0]);
               
              //if the user chooses hit.
                if (strcmp(userChoice[0], "hit") == 0){
               
                //gives them a new card. 
                    uCardGen(userCard, userName, &userCount, &uCount, cards); 
                     Sleep(1500);   

                        printf("Your card is... %s  (Total %d)\n", userName[uCount-1], userCount); 


                                //Case where user busts. 
                                if (userCount > 21)
                                        gameResult = 1; 
                                       


                                
                                    //Case where user gets a 21. 
                                     else if(userCount == 21) 
                                        break; 
                                     
                             }


                     //if the user chooses stand
               else if (strcmp(userChoice[0], "stand") == 0) 
                    break; 
               
                
               //if they enter some bs
               else {
                    printf("Invalid input. \n \n"); 
                    Sleep(1000); 
                }
                
             }



             if (gameResult != 1){

                printf("The dealers second card is...\n \n"); 
                Sleep(1000); 
                printf("%s  (Total %d)\n", dealName[1], dealCount); 


                while(dealCount < 17){
                    printf("The dealers next card is...\n"); 
                     Sleep(1500); 
                     dCardGen(dealCard, dealName, &dealCount, &dCount, cards);
                     printf("%s     (Total %d)\n \n", dealName[dCount-1], dealCount);
                }

                if (dealCount > 21 || userCount > dealCount)
                    gameResult = 0; 
                
                    
                else if (dealCount > userCount)
                    gameResult = 1; 

                    else 
                    gameResult = 2;
             }

              gameUpdate( &userBal, gameResult, &gameStar); 
            }



                      return 0; 
                }

//gives them a random card 1-13.
int randCard (void){
    int card = (rand() % 13) + 1; 
    return card; 
}

//turns all face cards into having a value of 10. 
int face2Num(int cardNum){
    if (cardNum == 11 || cardNum == 12 || cardNum == 13){
        cardNum = 10; 
        return cardNum; 
    }
    else {
        return cardNum; 
    }
}

//Allows the user to turn their ace into value 11 if applicable. 
int aceConv (int card,int cardCount){
    
    if(card == 1 && cardCount + 11 <= 21){
        card = 11; 
            return card;  
                  
            }
                else {
                    return card; 
                }
            }

   
//Updates and displays user game result, user balance, and prompts user to start another game.  
void gameUpdate(int *userBal, int gameResult, int *gameStar){

    if (gameResult == 0){
            (*userBal) += (*userBal)/2; 
            printf("You win! Congratulations!\n");
            Sleep (1000); 
                printf("Your current balance is: $%d\n \n ", (*userBal));
                 Sleep(1000); 
                    
                 printf("Press (1) to play again! \n \n"); 
                 scanf("%d", gameStar);
                    while (*gameStar != 1){
                        while(getchar() != '\n'){}; 
                            printf("Wrong choice, you must play. Input 1 \n \n"); 
                            scanf("%d", gameStar); 
                    } 
    }
        else if (gameResult == 1){
           (*userBal) -= (*userBal)/2; 
            printf("You lose! Better luck next time! \n"); 
            Sleep(1000); 
                printf("Your current balance is $%d \n \n", (*userBal)); 
                 Sleep(1000);
                 
                    while (*userBal <= 5){
                        int size = 0; 
                        printf("damn you broke, type '1' to get 5 more dollars\n \n"); 
                        scanf("%d", &size); 
                        Sleep(1000); 
                            if (size == 1){
                                (*userBal) = (*userBal) + 5; 
                            }
                                else {
                                    printf("Please type 1 ma boii\n \n"); 
                                }
                    }
                  

                    printf("Press (1) to play again! \n \n"); 
                    scanf("%d", gameStar);
                        while (*gameStar != 1){
                            while(getchar() != '\n'){}; 
                            printf("Wrong choice, you must play. \n \n"); 
                    } 
        }
            else if (gameResult == 2){
                printf("Tie game! Better luck next time! \n "); 
                Sleep(1000); 
                     printf("Your current balance is $%d \n \n "); 
                     Sleep(1000); 

                          printf("Press (1) to play again! \n \n"); 
                             scanf("%d", gameStar);
                                 while (*gameStar != 1){
                                       while(getchar() != '\n'){}; 
                                      printf("Wrong choice, you must play. \n \n"); 
                    } 
            }
}


    //Produces random card, stores it in dealer data, does stuff to face/ace, updates count of cards, and updates card index. 
    void dCardGen(int dealCard[], char dealName[13][6], int *dealCount, int *dCount, char cards[13][6]){

        dealCard[*dCount] = randCard(); 
            strcpy(dealName[*dCount], cards[dealCard[*dCount]-1]); 
             dealCard[*dCount] = face2Num(dealCard[*dCount]); 
              dealCard[*dCount] = aceConv(dealCard[*dCount], *dealCount);
                (*dealCount) += dealCard[*dCount]; 
                 (*dCount)++; 
         return; 

    } 

    //Produces random card, stores it in user data, does stuff to face/ace, updates count of cards, and updates card index. 
    void uCardGen(int userCard[], char userName[13][6], int *userCount, int *uCount, char cards[13][6]){

        userCard[*uCount] = randCard();   
            strcpy(userName[*uCount], cards[userCard[*uCount]-1]); 
             userCard[*uCount] = face2Num(userCard[*uCount]); 
                userCard[*uCount] = aceConv(userCard[*uCount], *userCount);
                (*userCount) += userCard[*uCount]; 
                        (*uCount)++; 
        return; 

    } 
    

    



