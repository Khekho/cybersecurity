#include <stdio.h>
#include <string.h>
char substitute(char ch) 
{
    switch(ch) 
	{
        case '5': return 'H';
        case '3': return 'E';
        case '‡': return 'L';
        case '†': return 'O';
        case '4': return 'W';
        case ')': return 'R';
        case '6': return 'D';
        case '*': return ' ';
        case ';': return 'A';
        case '8': return 'N';
        case '2': return 'G';
        case '(': return 'S';
        case '¶': return 'Y';
        case '9': return 'U';
        case '1': return 'I';
        case ':': return 'T';
        case '?': return '.';
        case '—': return ',';
        case ']': return 'C';
        default: return ch;
    }
}
int main() 
{
    char ciphertext[100];
    char decryptedText[100];
    int index = 0;
    printf("Enter the ciphertext:\n");
    scanf("%s", ciphertext);
    for (int i = 0; i < strlen(ciphertext); i++) {
        decryptedText[index++] = substitute(ciphertext[i]);
    }
    decryptedText[index] = '\0'; 
    printf("\nDecrypted text: %s\n", decryptedText);
    return 0;
}