// PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>

// FICHA 3

// Exercício 2

void swapM (int *x, int *y) {
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}

int main () {
	int x = 3, y = 5;
	swapM (&x, &y);
	printf ("%d %d\n", x, y);
	return 0;
}

// Exercício 3

void swap (int v[], int i, int j) {
	int aux;
	aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

int main () {
	int a[] = {10,22,31,2,45,8,300,44,88};
	int i = 3;
	int j = 5;
	printf ("%d %d\n", a[i], a[j]);
	swap (a, i, j);
	printf ("%d %d\n", a[i], a[j]);
	return 0;
}

// 4

int soma (int v[], int N) {
	int i;
	int soma = v[0];
	for (i = 1; i < N; i++) {
		soma += v[i];
	}
	return soma;
}

int main () {
	int a[] = {1,2,3,4,5};
	int resultado = soma (a, 5);
	printf ("%d\n", resultado);
	return 0;
}

// 5

int maximum (int v[], int N, int *m) {
	int i = 0;
	int max = v[0];
	for (i = 1; i < N; i++) {
		if (max < v[i]) max = v[i];
	}
	*m = max;
	return *m;
}

int main () {
	int *m;
	int a[] = {12,14,15,16,11,10};
	int maximo = maximum (a,6,&m);
	printf ("%d", maximo);
	return 0;
}

// 6

void quadrados (int q[], int N) {
	int i;
	for (i = 0;i < N; i++) {
		q[i] = (i+1) * (i+1);
	}
}

int main () {
	int x[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	quadrados(x,4);
    printf("%d %d %d %d %d\n\n\n\n",x[0],x[1],x[2],x[3],x[4]);
}

// 7

void pascal (int v[], int N) {
    int k,j;
    for (j=0;j<=N;j++) {
        v[j] = 1;
        if (j >= 2) {
            for (k = (j - 1); k > 0; k--) {
                v[k] = v[k] + v[k - 1];
            }
        }
    }
    for (k=0;k<=N;k++)
        printf("%d\n",v[k]);
}

int main () {
	int teste[6] = {9,71,41,21,9,7};
    pascal (teste,7);
}