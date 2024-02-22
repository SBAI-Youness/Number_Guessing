#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char name[20];
    int play, play_again, guess, secret_number, number_gameplay = 0, attempts;

    printf("\t# WELCOME TO MY GAME #\n");

    do
    {
        printf("-> Press 1 to play\n-> Press 0 to exit\n--> ");
        scanf("%d", &play);

        if( play == 0 )
        {
            printf("You played %d time. GoodBye!", number_gameplay);
            return 0;
        }

        if( play == 1 )
        {
            printf("Enter your name: ");
            fflush(stdin);
            fgets(name, sizeof(name), stdin);
            name[strlen(name)-1] = 0;

            printf("Nice to meet you %s, I am Youness SBAI.\n", name);

            START:

            srand(time(NULL));
            secret_number = rand() % 100 + 1;

            attempts = 0;
            
            do
            {
                printf("Enter your guess (1-100): ");
                scanf("%d", &guess);
                attempts++;

                if( guess < secret_number )
                    printf("Too Low!\n");
                else if( guess > secret_number )
                    printf("Too High!\n");

                else
                {
                    printf("Great! You guessed the secret number in %d attempts.\n", attempts);
                    number_gameplay++;

                    do
                    {
                        printf("-> Press 1 to play\n-> Press 0 to exit\n--> ");
                        scanf("%d", &play_again);

                        if( play_again == 0)
                        {
                            printf("You played %d time%s GoodBye!", number_gameplay, (number_gameplay != 1)? "s.":".");
                            return 0;
                        }
                        if( play_again == 1 )
                            goto START;

                    } while( play_again != 0 && play_again != 1 );

                }
            } while( guess != secret_number );

        }

    } while( play != 0 && play != 1 );

    return 0;
}