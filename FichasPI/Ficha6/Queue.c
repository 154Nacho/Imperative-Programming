#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Static queues 

void SinitQueue (SQueue q){
     q->front = 0;
     q->length = 0;
}

int SisEmptyQ (SQueue q){
    return (q->length == 0);
}

int Senqueue (SQueue q, int x){
    int r = 1,pos;
    if(q->length < Max){
	pos = (q->front)+(q->length)%Max;
    	q->value[pos] = x;
    	q->length++;
    	r = 0;
     }
     return r;
}

int Sdequeue (SQueue q, int *x) {
    int r = 1;
    if(!(SisEmptyQ(q)){
         *x = q->values[q->front];
         q->front = (q->front+1)%Max;
	 q->length--;
	 r = 0;
    }
    return r;
}

int Sfront (SQueue q, int *x) {	
    int r = 1;
    if(!(SisEmptyQ(q)){
         *x = q->values[q->front];
	 r = 0;
    }
    return r;
}

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

// Queues with dynamic arrays



int dupQueue (DQueue q)){
    int i, j, r = 0;
    int *aux = malloc(2*q->size,(sizeof(int)));
    if(aux == NULL) r = 1;
    else{
    	for (i = q->front; j = 0; j < q->size; j++, i = (i+1)%q->size) {
        	aux[j] = q->values[i];
   	 }
    	free(q->values);
    	q->values = aux;
    	q->size = 2*q->size;
    	q->front = 0;
    }
    return r;
}

void DinitQueue (DQueue q) {
	q->front = 0;
	q->length = 0;
	q->size = 1;
	q->values = malloc(sizeof(int));
}

int  DisEmptyQ (DQueue s) {
	return (q->length == 0);
}

int  Denqueue (DQueue q, int x){
	int r = 0;
	int pos;
	if(q->length == q->size) r = dupStack(q);
	if(r == 0) {
		pos = (q->front)+(q->length)%q->size;
		q->values[pos] = x;
		q->length++;
	}
	return r;
}

int  Ddequeue (DQueue q, int *x) {
	int i,r = 1;
	if (!(DisEmpty(q))) {
		*x = q->values[q->front];
		q->front = (q->front +1)%q->size;
		q->length--;
		r = 0;
	}
	return r;
}



int  Dfront (DQueue q, int *x){
	int i,r = 1;
	if(!(DisEmpty(q))){
		*x = q->values[q->front];
		r = 0;
	}
	return r;
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}