// Ficha 1 PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>

// 4

void triangulo (int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i+1; j++) {
            putchar ('#');
        }
        putchar ('\n');
    }
    for (i = i-1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            putchar('#');
        }
        putchar ('\n');
    }
}
