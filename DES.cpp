#include <stdio.h>
#include <stdint.h>
int IP[64] = {
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
};
int FP[64] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
};
uint64_t permute(uint64_t input, int* table) {
    uint64_t output = 0;
    for (int i = 0; i < 64; i++) {
        output <<= 1;
        output |= (input >> (64 - table[i])) & 1;
    }
    return output;
}
uint32_t feistel(uint32_t half, uint64_t key) {
    return half ^ (uint32_t)(key & 0xFFFFFFFF);
}
void des_round(uint32_t* left, uint32_t* right, uint64_t key) {
    uint32_t temp = *right;
    *right = *left ^ feistel(*right, key);
    *left = temp;
}
uint64_t des(uint64_t block, uint64_t key, int decrypt) {
    block = permute(block, IP);

    uint32_t left = (block >> 32) & 0xFFFFFFFF;
    uint32_t right = block & 0xFFFFFFFF;

    for (int i = 0; i < 16; i++) {
        int round = decrypt ? 15 - i : i;
        des_round(&left, &right, key);  
    }
    uint64_t combined = ((uint64_t)right << 32) | left;
    return permute(combined, FP);
}
int main() {
    int choice;
    uint64_t message, key;
    printf("DES Cipher (Simplified)\n");
    printf("1. Encrypt\n2. Decrypt\nChoose (1 or 2): ");
    scanf("%d", &choice);
    printf("Enter 16-digit hex message (e.g., 0123456789ABCDEF): ");
    scanf("%llx", &message);
    printf("Enter 16-digit hex key (e.g., 133457799BBCDFF1): ");
    scanf("%llx", &key);
    uint64_t result = des(message, key, choice == 2);
    if (choice == 1)
        printf("Encrypted: %016llX\n", result);
    else
        printf("Decrypted: %016llX\n", result);
    return 0;
}