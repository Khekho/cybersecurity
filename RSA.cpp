#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int mod_inverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((d * e) % phi == 1)
            return d;
    }
    return -1;
}
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int main() {
    int p = 3, q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 7; 
    if (gcd(e, phi) != 1) {
        printf("Invalid e\n");
        return 1;
    }
    int d = mod_inverse(e, phi);
    if (d == -1) {
        printf("No modular inverse for e\n");
        return 1;
    }
    int msg;
    printf("Enter message (0 to %d): ", n - 1);
    scanf("%d", &msg);
    long long encrypted = mod_exp(msg, e, n);
    long long decrypted = mod_exp(encrypted, d, n);
    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n", d, n);
    printf("Encrypted: %lld\n", encrypted);
    printf("Decrypted: %lld\n", decrypted);

    return 0;
}
