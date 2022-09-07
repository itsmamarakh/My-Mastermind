#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* function prototypes */
int raqam(char *inp);
void well(char *inp, char *code);
void mis(char *inp, char *code);
/* end funcion prototypes */

// mastermind main function
void mastermind(char *code, int attempts)
{
// intro text
printf("Will you find the secret code?\n---\n");
// initialize user input 
char in[5];
// attempt times get a code from user
    for (int i = 0; i < attempts; i++)
    {
        printf("Round %i\n>",i);
        scanf("%s", in);
        // check user input valid
        if (raqam(in))
        {
            if (strcmp(in, code) == 0)
            {
                // print the succes message
                printf("Congratz! You did it!\n");
                break;
            }
            // if user input is wrong say wellplaced and misplaced pieces
            well(in, code);
            mis(in, code);
            printf("---\n");
            // if user failed print the code
            if (i == attempts - 1)
            {
            printf("Failure!!!\n");
            printf("The secret code was %s\n", code);
            }
        }
        else
        {
        // invalid user input message
        printf("Wrong input!\n");
        }
    }
}

// how many misplaced code is entered
void mis(char *inp, char *code)
{
    int c = 0;
    for (int i = 0, len = strlen(code); i < len; i++)
    {
        if (inp[i] == code[i])
        {
            c++;
        }
    }
    int w = 0;
    for (int i = 0, len = strlen(code); i < len; i++)
    {
        for (int j = 0, leng = strlen(inp); j < leng; j++)
        {
            if (code[i] == inp[j])
            {
                w++;
            }
        }
    }
    printf("Misplaced pieces: %i\n", w-c);
}
// how many wellplaced code is entered
void well(char *inp, char *code)
{
    int c = 0;
    for (int i = 0, len = strlen(code); i < len; i++)
    {
        if (inp[i] == code[i])
        {
            c++;
        }
    }
    printf("Well placed pieces: %i\n", c);
}



// check user input 
int raqam(char *inp)
{
    for (int i = 0, len = strlen(inp); i < len; ++i)
    {
        if (!isdigit(inp[i]))
        {
            return 0;
        }
    }
    return 1;
}