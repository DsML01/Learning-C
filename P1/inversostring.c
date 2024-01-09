#include <stdio.h>
#include <string.h>

void inverso(char s[], int i) {
    if (i == -1)
    {
        printf("\n");

        return;
    }
    else
    {
        printf("%c", s[i]);

        return inverso(s, i - 1);
    }

}

int main() {

    char s[255];

    scanf("%s", s);

    inverso(s, strlen(s) - 1);

    return 0;
}