#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digit(string input);
int main(int argc, string argv[])
{
    if (argc != 2 || !only_digit(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    if (key != 0)
    {
        string text = get_string("Enter plain text: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(text); i++)
        {
            char letter = text[i];
            if (isalpha(letter))
            {
                if (isupper(letter))
                {
                    int cipher = ((int) letter - 65 + key) % 26 + 65;
                    printf("%c", cipher);
                }
                else if (islower(letter))
                {
                    int cipher = ((int) letter - 97 + key) % 26 + 97;
                    printf("%c", cipher);
                }
            }
            else
            {
                printf("%c", letter);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Error\n");
    }
}

bool only_digit(string input)
{
    for (int j = 0; j < strlen(input); j++)
    {
        if (!isdigit(input[j]))
        {
            return false;
        }
    }
    return true;
}