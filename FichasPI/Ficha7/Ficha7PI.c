// PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>
#include <stdlib.h>

// FICHA 7

typedef struct slist *LInt;

typedef struct slist {
	int valor;
	LInt prox;
} Nodo;

// Pergunta 1

// Alínea a)

void showLInt (LInt l) {
	while (l != NULL) {
		printf("%d\n", l->valor);
		l = l->prox;
	}
}

void showLIntRec (LInt l) {
	if (l) {
		printf("%d\n", l->valor);
		showLIntRec(l->prox);
	}
}

int main () {

	LInt lista, aux;

	lista = (LInt) malloc(sizeof(Nodo));
	lista->valor = 15;
	lista->prox = NULL;

	aux = (LInt) malloc(sizeof(Nodo));
	aux->valor = 5;
	aux->prox = lista;

	lista = (LInt) malloc(sizeof(Nodo));
	lista->valor = 10;
	lista->prox = aux;

	showLInt(lista);

	return 0;
}

// Alínea b)

// Alínea i)

LInt cons (LInt l, int x) {
	LInt novo = (LInt) malloc(sizeof(Nodo));
	novo->valor = x;
	novo->prox = l;
	return novo;
}

// Alínea ii)

LInt tail (LInt l) {
	LInt r = l->prox;
	free(l);
	return r;
}

// Alínea iii)

LInt init (LInt l) {
	LInt r = l, prev;
	while (l->prox != NULL) {
		prev = l;
		l = l->prox;
	}
	prev->prox = NULL
	free(l);
	return r;
}

// Alínea iv)

LInt snoc (LInt l, int x) {
	LInt novo = malloc(sizeof(Nodo));
	novo->valor = x;
	novo->prox = NULL;
	LInt current = l;
	while (current && current->prox) {
		current = current->prox;
	}
	if (!current) {
		l = novo;
	} else {
		current->prox = x;
	}
	return l;
} 

// Alínea v)

LInt concat (LInt a, LInt b) {
	LInt current = a;
	while (current && current->prox) {
		current = current->prox;
	}
	if (!current) {
		a = b
	} else {
		current->prox = b;
	}
	return a;
}

// Pergunta 2

// Alínea a)

typedef struct aluno {
	char nome[61];
	int numeroAluno, nota;
} Aluno;

typedef struct turma *Turma;

typedef struct turma {
	Aluno aluno;
	Turma proxAluno;
} NodoTurma;

























