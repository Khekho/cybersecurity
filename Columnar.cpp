#include <stdio.h>
#include <string.h>
int main() 
{
    char msg[100], key[20], mat[20][20];
    int col[20] = {0}, len, klen, row, i, j, t = 1, x = 0, ch, val = 1, ind;
    printf("1.Encrypt\n2.Decrypt\nEnter choice: ");
    scanf("%d", &ch);
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter text: ");
    scanf(" %[^\n]", msg);
    len = strlen(msg);
    klen = strlen(key);
    row = (len + klen - 1) / klen;
    while (val <= klen) {
        int min = 999;
        for (i = 0; i < klen; i++)
            if (key[i] < min && col[i] == 0) { min = key[i]; ind = i; }
        col[ind] = val++;
    }
    if (ch == 1) {
        for (i = 0; i < row; i++)
            for (j = 0; j < klen; j++)
                mat[i][j] = (x < len) ? msg[x++] : '_';

        for (t = 1; t <= klen; t++)
            for (j = 0; j < klen; j++)
                if (col[j] == t)
                    for (i = 0; i < row; i++)
                        printf("%c", mat[i][j]);
    } 
	else 
	{
        char cipher[100];
        scanf(" %[^\n]", cipher);
        x = 0;
        for (t = 1; t <= klen; t++)
            for (j = 0; j < klen; j++)
                if (col[j] == t)
                    for (i = 0; i < row; i++)
                        mat[i][j] = cipher[x++];

        for (i = 0; i < row; i++)
            for (j = 0; j < klen; j++)
                if (mat[i][j] != '_') printf("%c", mat[i][j]);
    }
    return 0;
}