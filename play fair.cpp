#include <stdio.h>
#include <string.h>
int main() {
    char key[100], text[100], m[5][5], used[26] = {0};
    int i, j, k = 0, r1, c1, r2, c2;
    printf("Key: ");
    scanf("%s", key);
    printf("Plaintext: ");
    scanf("%s", text);
    for (i = 0; key[i]; i++) {
        char ch = key[i] == 'j' ? 'i' : key[i];
        if (!used[ch - 'a']) {
            used[ch - 'a'] = 1;
            m[k / 5][k % 5] = ch;
            k++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (i + 'a' == 'j' || used[i]) continue;
        m[k / 5][k % 5] = i + 'a';
        k++;
    }
    printf("Encrypted: ");
    for (i = 0; text[i]; i += 2) {
        char a = text[i], b = text[i + 1] ? text[i + 1] : 'x';
        if (a == 'j') a = 'i'; if (b == 'j') b = 'i';
        if (a == b) b = 'x';

        for (j = 0; j < 5; j++)
            for (k = 0; k < 5; k++) {
                if (m[j][k] == a) { r1 = j; c1 = k; }
                if (m[j][k] == b) { r2 = j; c2 = k; }
            }

        if (r1 == r2)
            printf("%c%c", m[r1][(c1 + 1) % 5], m[r2][(c2 + 1) % 5]);
        else if (c1 == c2)
            printf("%c%c", m[(r1 + 1) % 5][c1], m[(r2 + 1) % 5][c2]);
        else
            printf("%c%c", m[r1][c2], m[r2][c1]);
    }
    return 0;
}