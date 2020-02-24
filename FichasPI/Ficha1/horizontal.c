// Ficha 1 PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>

// 4

void triangulo (int n) {
    char p = '#';
    int e,i,r,f; // e = nº de espaços
    i = f = 0;
    e = n-1;
    r=1;
    while (f!=n){
        while (i!=e){ // nº de espaços 1 linha
            putchar (' ');
            i++;
        }
        i=0;
        while (i!=r){
            putchar (p);
            i++;
        }
        putchar ('\n');
        i=0;
        r+=2; // aumenta 2 caractéres p/ linha
        f++;
        e--;
    }
}
