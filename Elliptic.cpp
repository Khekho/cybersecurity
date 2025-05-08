#include <stdio.h>
typedef struct {
    int x;
    int y;
} Point;
int p = 23;
int a = 1;
int b = 1;
int modInverse(int a, int m) {
    int t = 0, newT = 1;
    int r = m, newR = a;
    while (newR != 0) {
        int quotient = r / newR;
        t = newT;
        newT = t - quotient * newT;
        r = newR;
        newR = r - quotient * newR;
    }
    if (r > 1) return -1; 
    if (t < 0) t = t + m;
    return t;
}
Point add(Point P, Point Q) {
    int lambda;
    Point R;
    if (P.x == Q.x && P.y == Q.y) {
        lambda = (3 * P.x * P.x + a) * modInverse(2 * P.y, p) % p;
    } else {
        lambda = (Q.y - P.y) * modInverse(Q.x - P.x, p) % p;
    }
    if (lambda < 0) lambda += p; 
    R.x = (lambda * lambda - P.x - Q.x) % p;
    if (R.x < 0) R.x += p;  
    R.y = (lambda * (P.x - R.x) - P.y) % p;
    if (R.y < 0) R.y += p;  
    return R;
}
Point multiply(int n, Point P) {
    Point R = {0, 0}; 
    Point Q = P;
    while (n > 0) {
        if (n % 2 == 1) {
            R = add(R, Q);
        }
        Q = add(Q, Q);
        n = n / 2;
    }
    return R;
}
int main() {
    Point G = {3, 10};
    int nA = 5;
    int nB = 7;
    Point PA = multiply(nA, G);
    Point PB = multiply(nB, G);
    printf("User A's public key (PA): (%d, %d)\n", PA.x, PA.y);
    printf("User B's public key (PB): (%d, %d)\n", PB.x, PB.y);
    Point sharedA = multiply(nA, PB);
    Point sharedB = multiply(nB, PA);
    printf("Shared secret computed by User A: (%d, %d)\n", sharedA.x, sharedA.y);
    printf("Shared secret computed by User B: (%d, %d)\n", sharedB.x, sharedB.y);
    return 0;
}
