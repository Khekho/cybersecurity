#include <stdio.h>
int main()
{
    char ct[100];
    int y1 = 1, y2 = 20, x1 = 4, x2 = 19;
    int a, b, a_inv, x, y;
    printf("Enter ciphertext (UPPERCASE letters only): ");
    scanf("%s", ct);
    for (a = 1; a < 26; a++)
	{
        if ((a * ((x1 - x2 + 26) % 26)) % 26 == (y1 - y2 + 26) % 26)
            break;
    }
    for (a_inv = 1; a_inv < 26; a_inv++)
	{
        if ((a * a_inv) % 26 == 1)
            break;
    }
    b = (y1 - a * x1 + 26 * 26) % 26;
    printf("Decrypted text: ");
    for (int i = 0; ct[i] != '\0'; i++)
	 {
        if (ct[i] >= 'A' && ct[i] <= 'Z') 
		{
            y = ct[i] - 'A';
            x = (a_inv * (y - b + 26)) % 26;
            printf("%c", x + 'A');
        } 
		else 
		{
            printf("%c", ct[i]);
        }
    }
    printf("\n");
    return 0;
}