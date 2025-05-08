#include<stdio.h>
#include<ctype.h>
int main()
{
    char text[500], result[500], ch;
    int key, i, choice;
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
    printf("Enter the key: ");
    scanf("%d", &key);
    for(i = 0; text[i] != '\0'; i++)
    {
        ch = text[i];
        if(isalpha(ch))
        {
            if(islower(ch))
            {
                if(choice == 1)
                    ch = (ch - 'a' + key) % 26 + 'a';
                else
                    ch = (ch - 'a' - key + 26) % 26 + 'a';
            }
            else if(isupper(ch))
            {
                if(choice == 1)
                    ch = (ch - 'A' + key) % 26 + 'A';
                else
                    ch = (ch - 'A' - key + 26) % 26 + 'A';
            }
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