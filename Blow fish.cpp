#include <stdio.h>
#include <stdint.h>
uint32_t P[2] = {0x243F6A88, 0x85A308D3}; 
uint32_t F(uint32_t x) {
    return (x ^ 0xA5A5A5A5);
}
void encrypt(uint32_t *L, uint32_t *R) {
    *L ^= P[0];
    *R ^= F(*L);
    *L ^= P[1];
    *R ^= F(*L);
}
void decrypt(uint32_t *L, uint32_t *R) {
    *R ^= F(*L);
    *L ^= P[1];
    *R ^= F(*L);
    *L ^= P[0];
}
int main() {
    uint32_t L = 0x12345678;
    uint32_t R = 0x9abcdef0;
    printf("Original:   %08x %08x\n", L, R);
    encrypt(&L, &R);
    printf("Encrypted:  %08x %08x\n", L, R);
    decrypt(&L, &R);
    printf("Decrypted:  %08x %08x\n", L, R);
    return 0;
}
