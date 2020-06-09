// Text encrypting
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Check argc
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Print key
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
    int count = atoi(argv[1]);
    printf("%i\n", count);

    // Prompt for plaintext
    string plaintext = get_string("plaintext: ");

    // Print ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
        int delta = isupper(plaintext[i]) ? 'A' : 'a';
        int p_i = plaintext[i] - delta;
        int c_i = (p_i + count) % 26;
        int result = c_i + delta;
        printf("%c", result);
    }
    printf("\n");
}



