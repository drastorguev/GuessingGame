#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLU "\x1B[34m"
#define RESET "\x1B[0m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"

int main(void) {
  srand(time(NULL));
  int gamesCount = 1;
  while(gamesCount > 0) {
    int guess = 0; // Stores a guess
    int guessLow = 0;
    int rangeLow = -1;
    int rangeHigh = 0;
    printf("\n------------------------------");
    printf("\nLet's play a game!!!");
    printf("\n------------------------------");
    printf("\nThis is a Guessing Game.");
    printf("\nTell me the highest number to include...");
    while (rangeHigh < 10) {
      printf("\n( it needs to be above 10 ): ");
      scanf("%d", &rangeHigh);
    }
    int chosen = rand() % rangeHigh + 1;
    int count = rangeHigh / 5;
    int guessHigh = rangeHigh + 1;
    printf("\nI have chosen a number between 1 and %d, which you must guess.\n", rangeHigh);
    printf("\nYou will have %d guesses in total\n", count);
    for( ; count > 0 ; --count) {
      printf("------------------------------");
      printf(BLU "\nYou have %d tr%s left.", count, count == 1 ? "y" : "ies");
      printf(BLU "\nThe following numbers are remaining:\n [ ");
      for(int temp = guessLow + 1; temp < guessHigh ; temp++) {
        printf("%d ", temp);
      }
      printf(" ]");
      printf("\n------------------------------");
      printf("\nEnter a guess: " RESET); // Prompt for a guess
      scanf("%d", &guess); // Read in a guess
      // Check for a correct guess
      if (guess == chosen) {
        printf(GRN "\nCongratulations. You guessed it!\n" RESET);
        break;
      }
      else if (guess < 1 || guess > 20) {
        // Check for an invalid guess
        printf(RED "I said the number is between 1 and 20.\n " RESET);
      }
      else {
        printf(RED "Sorry, %d is wrong. My number is %s than that.\n" RESET, guess, chosen > guess ? "greater" : "less");
        if (chosen > guess) {
          guessLow = guess;
        }
        else if (chosen < guess) {
          guessHigh = guess;
        }
      }
    }
    if (count == 0) {
      printf(RED "\nYou have had three tries and failed. The number was %d\n" RESET, chosen);
    }
    continue;
  } // end of while loop

}
