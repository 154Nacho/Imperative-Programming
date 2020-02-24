// PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>
#include <string.h>

// 2ª 50 QUESTÕES

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// 1

int length (LInt head) {
    int i;
    for (i = 0; head != NULL; i++) {
        head = head -> prox;
    }
    return i;
}

// 2

void freeL (LInt head) {
    LInt tmp;
    while (head != NULL) {
        tmp = head;
        head = head -> prox;
        free (tmp);
    }
}

// 3

void imprimeL (LInt head) {
  LInt current = head;
  while (current != NULL) {
      printf("%d\n", current -> valor);
      current = current -> prox;
  }
}

// 4

LInt reverseL (LInt head) {
    LInt tmp;
    LInt prev = NULL;
    while (head != NULL) {
        tmp = head -> prox;
        head -> prox = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}

// 5

LInt newLInt (int v, LInt t) {
    LInt new = (LInt) malloc (sizeof (struct lligada));
    if (new != NULL) {
        new -> valor = v;
        new -> prox = t;
    }
    return new;
}

void insertOrd (LInt *head, int x) {
    LInt current = *head;
    if (*head == NULL) {
        LInt new = newLInt (x,NULL);
        *head = new;
        return;
    }
    LInt tmp;
    int i;
    for (i = 0; current -> valor < x && current -> prox != NULL; i++) {
        tmp = current;
        current = current -> prox;
    }
    if (x > current -> valor) {
        LInt new = newLInt (x,NULL);
        current -> prox = new;
    } else {
        LInt new = newLInt (x,current);
        if (i == 0) {
            *head = new;
        } else {
            tmp -> prox = new;
        }
    }
}

// 6

int removeOneOrd (LInt *head, int x) {
    LInt current = *head;
    if (*head == NULL) return 1;
    if ((*head) -> valor == x && (*head) -> prox == NULL) {
        free (*head);
        *head = NULL;
        return 0;
    }
    LInt prev;
    while (current != NULL) {
        if (current -> valor == x) {
            prev -> prox = current -> prox;
            free (current);
            current = prev -> prox;
            return 0;
        } else {
            prev = current;
            current = current -> prox;
        }
    }
    return 1;
}

// 7

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

void merge (LInt *r, LInt a, LInt b) {
    *r = newLInt (154,NULL);
    LInt current = *r;
    while (a != NULL || b != NULL) {
        if (a == NULL) {
            current -> prox = b;
            break;
        } else if (b == NULL) {
            current -> prox = a;
            break;
        } else {
            if (a -> valor < b -> valor) {
                current -> prox = a;
                current = current -> prox;
                a = a -> prox;
            } else {
                current -> prox = b;
                current = current -> prox;
                b = b -> prox;
            }
        }
    }
    current = *r;
    *r = (*r) -> prox;
    free (current);
}

// 8

void splitQS (LInt head, int x, LInt *mx, LInt *Mx) {
    LInt mxcur, Mxcur;
    while (head != NULL) {
        if (head -> valor < x) {
            if (*mx == NULL) {
                *mx = head;
                mxcur = *mx;
                head = head -> prox;
                mxcur -> prox = NULL;
            } else {
                mxcur -> prox = head;
                mxcur = mxcur -> prox;
                head = head -> prox;
                mxcur -> prox = NULL;
            }
        } else {
            if (*Mx == NULL) {
                *Mx = head;
                Mxcur = *Mx;
                head = head -> prox;
                Mxcur -> prox = NULL;
            } else {
                Mxcur -> prox = head;
                Mxcur = Mxcur -> prox;
                head = head -> prox;
                Mxcur -> prox = NULL;
            }
        }
    }
}

// 9

int length (LInt head) {
    int i;
    for (i = 0; head != NULL; i++) {
        head = head -> prox;
    }
    return i;
}

LInt parteAmeio (LInt *head) {
    LInt start = *head;
    LInt current = *head;
    int len = length (current);
    int meio = len / 2;
    int i;
    if (len == 1) return NULL;
    for (i = 0; i + 1 < meio; i++) {
        current = current -> prox;
    }
    *head = current -> prox;
    current -> prox = NULL;
    return start;
}

// 10

int removeAll (LInt *head, int x) {
    int contaRM = 0;
    if (*head == NULL) return contaRM;
    while (*head != NULL) {
        if ((*head) -> valor == x) {
            *head = (*head) -> prox;
            contaRM++;
        } else {
            break;
        }
    }
    LInt current = *head;
    LInt prev;
    while (current != NULL) {
        if (current -> valor == x) {
            prev -> prox = current -> prox;
            free (current);
            current = prev -> prox;
            contaRM++;
        } else {
            prev = current;
            current = current -> prox;
        }
    }
    return contaRM;
}

// 11

int length (LInt head) {
    int i;
    for (i = 0; head != NULL; i++) {
        head = head -> prox;
    }
    return i;
}

void removeInt (LInt head, int x) {
    LInt prev = head;
    head = head -> prox;
    while (head != NULL) {
        if (head -> valor == x) {
            prev -> prox = head -> prox;
            free (head);
            head = prev -> prox;
        } else {
            prev = head;
            head = head -> prox;
        }
    }
}

int removeDups (LInt *head) {
    int start = length (*head);
    if (start == 0) {
        return 0;
    }
    LInt current = *head;
    while (current != NULL) {
        removeInt (current, current -> valor);
        current = current -> prox;
    }
    int end = length (*head);
    return (start - end);
}

// 12

int removeMaiorL (LInt *head) {
    LInt current = *head;
    LInt prev;
    LInt tmp;
    int max = current -> valor;
    while (current != NULL) {
        if (current -> valor > max) {
            max = current -> valor;
        } else {
            current = current -> prox;
        }
    }
    if ((*head) -> valor == max) {
        tmp = *head;
        *head = (*head) -> prox;
        free (tmp);
        return max;
    }
    current = *head;
    while (current -> valor != max) {
        prev = current;
        current = current -> prox;
    }
    tmp = current;
    prev -> prox = current -> prox;
    free (tmp);
    return max;
}

// 13

void init (LInt *head) {
    LInt current = *head;
    LInt prev;
    if ((*head) -> prox == NULL) {
        free (*head);
        *head = NULL;
        return;
    }
    while (current -> prox != NULL) {
        prev = current;
        current = current -> prox;
    }
    prev -> prox = NULL;
    free (current);
}

// 14

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

void appendL (LInt *head, int x) {
    LInt current = *head;
    LInt new = newLInt (x,NULL);
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (current -> prox != NULL) {
        current = current -> prox;
    }
    current -> prox = new;
}

// 15

void concatL (LInt *a, LInt b) {
    LInt current = *a;
    if (*a == NULL) {
        *a = b;
        return;
    }
    while (current -> prox != NULL) {
        current = current -> prox;
    }
    current -> prox = b;
}

// 16

LInt cloneL (LInt head) {
    if (head == NULL) return NULL;
    LInt new = newLInt (head -> valor, NULL);
    LInt current = head;
    LInt currentNew = new;
    while (current != NULL) {
        current = current -> prox;
        if (current != NULL) {
            currentNew -> prox = newLInt (current -> valor, NULL);
            currentNew = currentNew -> prox;
        }
    }
    return new;
}

// 17

LInt cloneRev (LInt head) {
    LInt current = head;
    if (head == NULL) return NULL;
    LInt new = NULL;
    while (current != NULL) {
        new = newLInt (current -> valor, new);
        current = current -> prox;
    }
    return new;
}
