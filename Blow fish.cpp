#include <stdio.h>
#include <string.h>

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

int main() {
    char text[100];
    int choice;
    int x1 = 4, x2 = 19, y1 = 1, y2 = 20;
    int a = -1, b, a_inv;
    int x, y;

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);
    printf("Enter text (UPPERCASE letters only): ");
    scanf("%s", text);

    // Find 'a' such that it satisfies affine constraints
    for (int i = 1; i < 26; i++) {
        if ((i * ((x1 - x2 + 26) % 26)) % 26 == (y1 - y2 + 26) % 26) {
            a = i;
            break;
        }
    }

    if (a == -1) {
        printf("No valid 'a' found for the given points.\n");
        return 1;
    }

    b = (y1 - a * x1 + 26 * 26) % 26;
    a_inv = modInverse(a, 26);

    if (a_inv == -1 && choice == 2) {
        printf("No modular inverse exists for a = %d under mod 26.\n", a);
        return 1;
    }

    printf("%s text: ", (choice == 1) ? "Encrypted" : "Decrypted");

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            if (choice == 1) { // Encrypt
                x = text[i] - 'A';
                y = (a * x + b) % 26;
                printf("%c", y + 'A');
            } else if (choice == 2) { // Decrypt
                y = text[i] - 'A';
                x = (a_inv * (y - b + 26)) % 26;
                printf("%c", x + 'A');
            }
        } else {
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}
