// Ficha 5 PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap (int v[], int i, int j){
	int t = v[i];
	v[i] = v[j]; 
	v[j] = t;
}

// Exercício 1

void insere (int v[], int N, int x) {
    int i, j;
    for (i = 0; i < N && v[i] < x; i++);
    for (j = N; j != i; j--) {
        v[j] = v[j-1];
    }
    v[i] = x;
}

int main () {
	int v[] = {1,2,4,5,6,7};
	int x = 3;
	insere (v, 6, x);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", v[i]);
	}
	return 1;
}

// Exercício 2

void iSort1 (int v[], int N) {
    int i;
	for (i = 0; i < N; i++) {
	    insere (v, i, v[i]);
	}
}


void iSort2 (int v[], int N) {
    int i, j;
	for (i = 0; i < N - 1; i++) {
	    for (j = i + 1; j < N; j++) {
	        if (v[i] > v[j]) swap (v,i,j);
	    }
	}
}

int main () {
	int v[] = {3,2,1,5,4,6};
	int N = 5;
	iSort2 (v,N);
	for (int i = 0; i < 6; i++) {
		printf("%d\n", v[i]);
	}
	return 1;
}

// Exercício 3

int maxInd (int v[], int N){
	int i;
	int max = v[0];
	int p = 0;
	for (i = 1; i < N; i++) {
	    if (v[i] > max) {
	    	max = v[i];
	    	p = i;
	    }
	}
	printf("%d\n", p);
	return p;
}

int main () {
	int v[] = {10,3,6,7,20,13,16,18,19};
	maxInd (v,8);
	return 1;
}

// Exercício 4

void maxSort (int v[], int N) {
	int i;
	if (N > 1) {
		i = maxInd (v,N);
		swap (v,i,N);
		maxSort (v, N-1);
	}
}

int main () {
	int v[] = {3,2,1,5,4,6};
	int N = 6;
	maxSort (v,N);
	for (int i = 0; i < N; i++) {
		printf("%d\n", v[i]);
	}
	return 1;
}

// Exercício 5

void maxSort2 (int v[], int N) {
	int i, j;
	for(i = N; i > 0; i--){
	    for(j = 0; j < i; j++){
	        if(v[i] < v[j]) swap (v,j,i);
	    }
	}
}

// Exercício 6

int bubble (int v[], int N) {
	int i, r=0;
	for (i=1; i<N; i++)
		if (v[i] < v[i-1]) {
			swap (v, i, i-1); 
			r=i;
		}
	return r; // última posição trocada
}

// Exercício 7

void bubblesort1 (int v[], int N){
	int i,m;
	for (i = N; i > 0; i--){
	    m = bubble(v,i);
	    v[i] = v[m];
	}
}

// Exercício 8

void bubblesort2 (int v[], int N){
	int i,m;
	for (i = N; i > 0; i--){
	    m = bubble(v,i);
	    if (m == i) break;
	    v[i] = v[m];
	}
}