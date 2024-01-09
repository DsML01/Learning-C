#include <stdio.h>

int inverso(int p[], int n, int i) {
    if (i == n) return 0;
    else
    {
        printf("%d ", p[i]);

        return inverso(p, n, i - 1);
    }

}

int ler(int p[], int n, int i) {
    if (i == n)
    {
        inverso(p, -1, n-1);

        return 0;
    }
    else
    {
        scanf("%d", &p[i]);

        return ler(p, n, i + 1);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int p[n];

    ler(p, n, 0);

    return 0;
}