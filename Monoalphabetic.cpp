#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char text[500], result[500], ch;
    char key[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    int choice, i;
    printf("Enter 1 to Encrypt\nEnter 2 to Decrypt\nChoice: ");
    scanf("%d", &choice);
    if(choice == 1)
        printf("Enter the plaintext: ");
    else if(choice == 2)
        printf("Enter the ciphertext: ");
    else
    {
        printf("Invalid choice");
        return 0;
    }
    getchar();
    fgets(text, sizeof(text), stdin);
    for(i = 0; text[i] != '\0'; i++)
    {
        ch = text[i];
        if(isalpha(ch))
        {
            if(islower(ch))
                ch = key[ch - 'a'];
            else if(isupper(ch))
                ch = key[ch - 'A'] - 32;
        }
        result[i] = ch;
    }
    result[i] = '\0';
    if(choice == 1)
        printf("Encrypted: %s", result);
    else
        printf("Decrypted: %s", result);
    return 0;
}
