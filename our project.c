#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    char playerChoice, computerChoice;
    int playerWins = 0, computerWins = 0;
    int rounds = 0;
    const int MAX_ROUNDS = 4;

    srand(time(0));

    printf("Rock, Paper, Scissors Game!\n");
    printf("Enter R for Rock, P for Paper, S for Scissors\n");

    while(rounds < MAX_ROUNDS) {
        printf("\nRound %d/%d\n", rounds+1, MAX_ROUNDS);
        printf("Your choice (R/P/S): ");
        scanf(" %c", &playerChoice);
        playerChoice = toupper(playerChoice);

        if(playerChoice != 'R' && playerChoice != 'P' && playerChoice != 'S') {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        int random = rand() % 3;
        if(random == 0) computerChoice = 'R';
        else if(random == 1) computerChoice = 'P';
        else computerChoice = 'S';

        printf("Computer chose: %c\n", computerChoice);

        if(playerChoice == computerChoice) {
            printf("It's a tie!\n");
        }
        else if((playerChoice == 'R' && computerChoice == 'S') ||
                (playerChoice == 'P' && computerChoice == 'R') ||
                (playerChoice == 'S' && computerChoice == 'P')) {
            printf("You win this round!\n");
            playerWins++;
        }
        else {
            printf("Computer wins this round!\n");
            computerWins++;
        }

        printf("Current Score: You %d - %d Computer\n", playerWins, computerWins);
        rounds++;
    }

    printf("\nFinal Score after %d rounds: You %d - %d Computer\n",
           MAX_ROUNDS, playerWins, computerWins);

    if(playerWins > computerWins) {
        printf("You won the game!\n");
    }
    else if(computerWins > playerWins) {
        printf("Computer won the game!\n");
    }
    else {
        printf("The game ended in a tie!\n");
    }

    return 0;
}
