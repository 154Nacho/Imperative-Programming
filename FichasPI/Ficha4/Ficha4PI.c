// Ficha 4 PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Exercício 1

int minusculas (char s[]) {
	int i, count = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (isupper (s[i])) {
			s[i] = s[i] + 32;
			count++;
		}
	}
	printf ("%d\n", count);
	return count;
}

int main () {
	char s[] = "Olá Mundo. Tudo Bem?";
	minusculas (s);
	return 1;
}

// Exercício 2

int contalinhas (char s[]) {
	int i, count = 1;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\n') count++;
	}
	printf("%d\n", count);
	return count;
}

int main () {
	char s[] = "Olá Mundo\n.Tudo Bem?\n.Sim, e contigo?";
	contalinhas (s);
	return 1;
}

// Exercício 3

int contaPal (char s[]) {
	int i, pal = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if ((!(isspace(s[i]))) && ((isspace(s[i+1])) || (s[i+1] == '\0'))) pal++;
	}
	printf("%d\n", pal);
	return pal;
}

int main () {
	char s[] = "Olá Mundo. Tudo Bem?. Sim, e contigo?";
	contaPal (s);
	return 1;
} 

// Exercício 4

int procura (char *p, char *ps[], int N) {
	int i;
	int found = -1;
	for (i = 0; i < N; i++) {
		if (strcmp (p,ps[i]) == 0) found = i;
	}
	printf("%d\n", found);
	return found;
}

int main () {
	char *ps[] = {"Olá", "Mundo", "tudo", "bem"};
	char *p = "Mundo";
	procura (p, ps, 4);
	return 1;
}

// Exercício 5

#define MAX 100
typedef struct stack {
int sp;
int valores [MAX];
} STACK;

// Exercício a)

void initStack (STACK *s) {
	STACK *aux = malloc (sizeof (struct STACK));
	aux -> sp = 0;
	aux -> valores = NULL;
	s = aux;
}

// Exercício b)

int isEmptyS (STACK *s) {
	if (s -> sp == 0 && s -> valores == NULL) return 1;
	return 0;
}

// Exercício c)

int push (STACK *s, int x) {
	if (s -> sp == 100) return 1;
	else {
		s -> valores[(s -> sp)] = x;
		(s -> sp)++;
	}
	return 0;
}

// Exercício d)

int pop (STACK *s, int *x) {
	if (isEmptyS s) return 1;
	else {
		*x = s -> valores[(s -> sp)];
		(s -> sp)--; 
	}
	return 0;
}

// Exercício e)

int top (STACK *s, int *x) {
	if (isEmptyS) return 1;
	else {
		*x = s -> valores[(s -> sp)];
	}
	return 0;
}