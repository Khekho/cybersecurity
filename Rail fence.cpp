#include <stdio.h>
#include <string.h>
int main() {
    char text[100], rail[10][100];
    int choice, rails, len, i, j, dir, k = 0;
    printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);
    printf("Enter rails: ");
    scanf("%d", &rails);
    printf("Enter text: ");
    scanf(" %[^\n]", text);
    len = strlen(text);
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';
    if (choice == 1) {
        j = 0; dir = 1;
        for (i = 0; i < len; i++) {
            rail[j][i] = text[i];
            j += dir;
            if (j == 0 || j == rails - 1) dir = -dir;
        }
        printf("Encrypted: ");
        for (i = 0; i < rails; i++)
            for (j = 0; j < len; j++)
                if (rail[i][j] != '\n') printf("%c", rail[i][j]);
    } else if (choice == 2) {
        j = 0; dir = 1;
        for (i = 0; i < len; i++) {
            rail[j][i] = '*';
            j += dir;
            if (j == 0 || j == rails - 1) dir = -dir;
        }
        for (i = 0; i < rails; i++)
            for (j = 0; j < len; j++)
                if (rail[i][j] == '*') rail[i][j] = text[k++];
        j = 0; dir = 1;
        printf("Decrypted: ");
        for (i = 0; i < len; i++) {
            printf("%c", rail[j][i]);
            j += dir;
            if (j == 0 || j == rails - 1) dir = -dir;
        }
    } else {
        printf("Invalid choice");
    }
    return 0;
}
