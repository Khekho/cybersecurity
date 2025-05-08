#include <stdio.h>
#include <math.h>
int main() {
    int p, g, a, b, A, B, key1, key2;
    printf("Enter prime number (p): ");
    scanf("%d", &p);
    printf("Enter primitive root (g): ");
    scanf("%d", &g);
    printf("Enter private key for User A (a): ");
    scanf("%d", &a);
    printf("Enter private key for User B (b): ");
    scanf("%d", &b);
    A = (int)pow(g, a) % p;
    B = (int)pow(g, b) % p;
    key1 = (int)pow(B, a) % p;
    key2 = (int)pow(A, b) % p;
    printf("Public key of User A: %d\n", A);
    printf("Public key of User B: %d\n", B);
    printf("Shared key computed by User A: %d\n", key1);
    printf("Shared key computed by User B: %d\n", key2);
    return 0;
}
