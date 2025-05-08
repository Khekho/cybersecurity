#include <stdio.h>
int mod(int x) {
    return (x % 26 + 26) % 26;
}
int main() {
    char msg[100], enc[100], dec[100];
    int key[2][2] = { {3, 3}, {2, 5} };
    int inv[2][2] = { {15, 17}, {20, 9} };
    int i, a, b, choice;
    printf("Enter 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter the plaintext (uppercase, even length): ");
        scanf("%s", msg);
        for (i = 0; msg[i] != '\0'; i += 2) {
            a = msg[i] - 'A';
            b = msg[i+1] - 'A';
            enc[i]   = mod(key[0][0]*a + key[0][1]*b) + 'A';
            enc[i+1] = mod(key[1][0]*a + key[1][1]*b) + 'A';
        }
        enc[i] = '\0';
        printf("Encrypted message: %s\n", enc);
    }
    else if (choice == 2) {
        printf("Enter the ciphertext (uppercase, even length): ");
        scanf("%s", msg);
        for (i = 0; msg[i] != '\0'; i += 2) {
            a = msg[i] - 'A';
            b = msg[i+1] - 'A';
            dec[i]   = mod(inv[0][0]*a + inv[0][1]*b) + 'A';
            dec[i+1] = mod(inv[1][0]*a + inv[1][1]*b) + 'A';
        }
        dec[i] = '\0';
        printf("Decrypted message: %s\n", dec);
    }
    else {
        printf("Invalid choice!\n");
    }
    return 0;
}
