// Ficha 1 PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>

// 2

int main (int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            putchar ('#');
        }
        putchar ('\n');
    }
    return 0;
}

// 3

int main (int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j % 2 == 0) putchar ('#');
            else putchar ('_');
        }
        putchar ('\n');
    }
    return 0;
}
