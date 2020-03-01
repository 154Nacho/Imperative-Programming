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
        new -> prox  = t;
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
    LInt tmp = current;
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
    LInt prev = current;
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

void merge (LInt *r, LInt l1, LInt l2) {
    *r = newLInt (154,NULL);
    LInt current = *r;
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            current -> prox = l2;
            break;
        } else if (l2 == NULL) {
            current -> prox = l1;
            break;
        } else {
            if (l1 -> valor < l2 -> valor) {
                current -> prox = l1;
                l1 = l1 -> prox;
                current = current -> prox;
            } else {
                current -> prox = l2;
                l2 = l2 -> prox;
                current = current -> prox;
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

int length (LInt head){
    int i;
    for (i = 0; head != NULL; i++){
    	head = head->prox;
    }
    return i;
}

void removeInt (LInt head, int x){
	LInt prev = head;
	head = head->prox;
	while (head != NULL){
		if (head->valor == x){
			prev->prox = head->prox;
			free(head);
			head = prev->prox;
		}
		else {
			prev = prev->prox;
			head = head->prox;
		}
	}
}

int removeDups (LInt *head){
	int start = length(*head);
	if (start == 0){
		return 0;
	}
	LInt current = *head;
	while (current != NULL){
    	removeInt (current, current -> valor);
    	current = current -> prox;
    }
    int end = length(*head);
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
		}
		current = current -> prox;
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

void appendL (LInt *head, int x){
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
		(*a) = b;
		return;
	}
	while (current -> prox != NULL) {
		current = current -> prox;
	}
	current -> prox = b;
}

// 16

LInt cloneL (LInt head){
    if (head == NULL){
        return NULL;
    }
    LInt new = newLInt(head->valor, NULL);
    LInt current = head;
    LInt currentNew = new;
    while (current != NULL){
        current = current->prox;
        if (current != NULL){
            currentNew -> prox = newLInt(current->valor, NULL);
            currentNew = currentNew -> prox;
        }
    }
    return new;
}

// 17

LInt cloneRev (LInt head){
    LInt current = head;
    if (head == NULL){
    	return NULL;
    }
    LInt new = NULL;
    while (current != NULL){
    	new = newLInt(current->valor, new);
    	current = current->prox;
    }
    return new;
}


// 18

int maximo (LInt head){
    LInt current = head;
    int max = current->valor;
    while (current != NULL){
    	if (current->valor > max){
    		max = current->valor;
    	}
    	current = current->prox;
    }
    return max;
}

// 19

void freeL (LInt head){
	LInt tmp;
	while (head != NULL){
		tmp = head;
		head = head->prox;
		free(tmp);
	}
}

int take (int n, LInt *head){
	LInt current = *head;
	int i;
    for (i = 0; i < (n-1) && current != NULL; i++){
    	current = current->prox;
    }
    if (current == NULL){
    	return i;
    }
    LInt freeMe = current->prox;
    current->prox = NULL;
    freeL(freeMe);
    return ++i;
}

// 20

void freeL (LInt head){
	LInt tmp;
	while (head != NULL){
		tmp = head;
		head = head->prox;
		free(tmp);
	}
}

int length (LInt head){
    int i;
    for (i = 0; head != NULL; i++){
    	head = head->prox;
    }
    return i;
}

int drop (int n, LInt *head){
    LInt current = *head; // Apontador usado para percorrer a lista
    int len = length(current); // length da lista

    /* Se houver mais elementos a eliminar que elementos na lista, é libertada toda a memória
       da lista e *head passa a ser um apontador nulo. Devolve-se a lenght da lista pois é o
       número de elementos eliminados */
    if (n >= len){
    	freeL(current);
    	*head = NULL;
    	return len;
    }

    /* Atualiza-se current até chegar ao último elemento a ser eliminado */
    int i;
    for (i = 0; i < (n-1); i++){
    	current = current->prox;
    }

    LInt output = current->prox; // Guarda-se a posição do elemento seguinte
    current->prox = NULL; // Separa-se a lista em dois (eliminados/restantes)
    freeL(*head); // Liberta-se a lista do eliminados
    *head = output; // Atualiza-se o apontador
    return n;
}

// 21

LInt NForward (LInt head, int N){
    LInt current = head; // Apontador que percorre a lista

    /* Loop que percorre a lista, a cada iteração N diminui, ou seja, faltam percorrer
       menos 1 elementos que antes, quando N == 0 o loop para e retorna-se o endereço
       guardado em current */
    int i;
    while (N--){
    	current = current->prox;
    }
    return current;
}

// 22

int listToArray (LInt head, int v[], int N){
	LInt current = head; // Apontador que percorre a lista

	/* Loop que percorre a lista, inserindo na posição i o valor guardado no nodo
	   current, após ser inserido o apontador current é atualizado para a posição
	   seguinte. No final é returnado i, que corresponde ao número de elementos
	   inseridos no array v */
	int i;
	for (i = 0; i < N && current != NULL; i++){
		v[i] = current->valor;
		current = current->prox;
	}

    return i;
}

// 23

LInt arrayToList (int v[], int N){
	/* Se v for um array vazio, a função retorna um apontador nulo */
    if (N == 0){
        return NULL;
    }
    LInt head = newLInt(v[0], NULL); // Cria-se o primeiro nodo com o primeiro elemento de v
    LInt current = head; // Apontador que percorre a lista

    /* Loop que insere na posição a seguir ao nodo current um novo nodo com valor v[i], depois
       current passa a apontar para o nodo seguinte. Nota: o loop começa em i = 1 porque ao
       inicializar head é lhe atribuido logo uma componente valor correspondente a v[0] */
    int i;
    for (i = 1; i < N; i++){
        current->prox = newLInt(v[i], NULL);
        current = current->prox;
    }
    return head; // É retornado o apontador para o primeiro nodo da lista
}

// 24

LInt somasAcL (LInt head) {
	/* Se head for um apontador nulo a função retorna um apontador nulo */
	if (head == NULL){
		return NULL;
	}
	LInt current = head; // Apontador que percorre a lista

	int soma = current->valor; // Inteiro onde é guardado a somaAc
	LInt listaSomas = newLInt(soma, NULL); // Primeiro nodo da lista
	LInt currentSomas = listaSomas; // Apontador que vai percorrer a nova lista

	/* Loop em que current está sempre 1 indice à frente de currentSomas (em listas diferentes).
	   É acrescentado a soma o valor guardado no nodo current e a currentSomas é ligado um novo
	   nodo com o valor de soma. A cada iteração current e currentSomas passam a apontar para o
	   nodo seguinte */
	while (current != NULL){
		current = current->prox;
		if (current != NULL){
			soma += current->valor;
			currentSomas->prox = newLInt(soma, NULL);
			currentSomas = currentSomas->prox;
		}
	}
    return listaSomas; // Apontador para o primeiro nodo da nova lista
}

// 25

void removeInt (LInt head, int x) {
	LInt prev = head;
	head = head -> prox;
	while (head != NULL) {
		if (head -> valor == x) {
			prev -> prox = head -> prox;
			free (head);
			head = prev -> prox;
		} else {
			prev = prev -> prox;
			head = head -> prox;
		}
	}
}

void remreps (LInt head){
	/* Se head for vazia não se faz nada */
    if (head == NULL){
    	return;
    }
    while (head != NULL){
    	removeInt (head, head->valor);
    	head = head->prox;
    }
}

// 26

LInt rotateL (LInt head){
	/* Casos de listas vazias ou listas de 1 único elemento, em que não acontece nada
	   e é returned o própio apontador */
    if (head == NULL || head->prox == NULL){
    	return head;
    }
    LInt current = head; // Apontador que percorrer a lista
    LInt newStart = head->prox; // Apontador que marca o começo da nova lista
    LInt firstNode = head; // Apontador que marca o nodo a ser colocado no fim da lista

    /* Loop que percorre a lista até encontrar o último nodo */
    while (current->prox != NULL){
    	current = current->prox;
    }

    current->prox = firstNode; // O último nodo passa a apontar para o primeiro
    firstNode->prox = NULL; // O (antigo) primeiro nodo passa a apontar para NULL (fim de lista)

    return newStart; // Retorna-se a posição do primeiro nodo da nova lista
}

// 27

LInt parte (LInt current){
	int i;

	LInt evenStart = newLInt(86, NULL); // Cria-se um nodo "falso" que é removido no fim
	LInt oddStart = newLInt(86, NULL);  // Cria-se um nodo "falso" que é removido no fim

	LInt even = evenStart; // Apontador que percorre a lista de indices pares
	LInt odd = oddStart;   // Apontador que percorre a lista de indices ímpares

	for (i = 1; current != NULL; i++){
		if (i % 2 == 0){             // Se for par:
			even->prox = current;    //     - even aponta para current
			even = even->prox;       //     - even avança um nodo para a frente
			current = current->prox; //     - current avança um nodo para a frente
			even->prox = NULL;       //     - fecha-se a lista even
		} else { // O processo para a lista ímpar é exatamente igual
			odd->prox = current;
			odd = odd->prox;
			current = current->prox;
			odd->prox = NULL;
		}
	}

	LInt tmp = evenStart;        // tmp guarda o nodo a ser removido
	evenStart = evenStart->prox; // evenStart passa a apontar para o verdadeiro início da lista
	free(tmp);                   // O nodo com o 86 é libertado da memória

	tmp = oddStart;              // tmp guarda o nodo a ser removido
	oddStart = oddStart->prox;   // oddStart passa a apontar para o verdadeiro início da lista
	free(tmp);                   // O nodo com o 86 é libertado da memória

	return evenStart;            // Return para o apontador do começo da nova lista
}

// 28

int altura (ABin a) {
    int i = 0;
    if (a == NULL) {
        return 0;
    } else if (altura (a -> esq) > altura (a -> dir)) {
        i = 1 + altura (a -> esq);
    } else {
        i = 1 + altura (a -> dir);
    }
    return i;
}

// 29

ABin cloneAB (ABin a) {
    if (a == NULL) {
        return NULL;
    }
    ABin new = malloc (sizeof (struct nodo));
    new -> valor = a -> valor;
    new -> dir = cloneAB (a -> dir);
    new -> esq = cloneAB (a -> esq);
    return new;
}

// 30

void mirror (ABin *a) {
    ABin current = *a;
    if (current != NULL) {
        ABin tmp = current -> dir;
        current -> dir = current -> esq;
        current -> esq = tmp;
        mirror (&current -> esq);
        mirror (&current -> dir);
    }
}

// 31

LInt mynewLInt (int v, LInt t) {
    LInt new = malloc (sizeof (struct lligada));
    if (new != NULL) {
        new -> valor = v;
        new -> prox = t;
    }
    return new;
}

void appendL (int x, LInt *head) {
    LInt current = *head;
    LInt new = mynewLInt (x,NULL);
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (current -> prox != NULL) {
        current = current -> prox;
    }
    current -> prox = new;
}

void inorder2 (ABin a, LInt *l) {
    if (a != NULL) {
        inorder2 (a -> esq, l);
        appendL (a -> valor,l);
        inorder2 (a -> dir, l);
    }
}

void inorder (ABin a, LInt *l) {
    *l = NULL;
    inorder2 (a, l);
}

// 32

LInt mynewLInt (int v, LInt t) {
    LInt new = malloc (sizeof (struct lligada));
    if (new != NULL) {
        new -> valor = v;
        new -> prox = t;
    }
    return new;
}

void appendL (int x, LInt *head) {
    LInt current = *head;
    LInt new = mynewLInt (x,NULL);
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (current -> prox != NULL) {
        current = current -> prox;
    }
    current -> prox = new;
}

void preorder2 (ABin a, LInt *l) {
    if (a != NULL) {
        appendL (a -> valor,l);
        preorder2 (a -> esq, l);
        preorder2 (a -> dir, l);
    }
}

void preorder (ABin a, LInt *l) {
    *l = NULL;
    preorder2 (a, l);
}

// 33

LInt mynewLInt (int v, LInt t) {
    LInt new = malloc (sizeof (struct lligada));
    if (new != NULL) {
        new -> valor = v;
        new -> prox = t;
    }
    return new;
}

void appendL (int x, LInt *head) {
    LInt current = *head;
    LInt new = mynewLInt (x,NULL);
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (current -> prox != NULL) {
        current = current -> prox;
    }
    current -> prox = new;
}

void posorder2 (ABin a, LInt *l) {
    if (a != NULL) {
        posorder2 (a -> esq, l);
        posorder2 (a -> dir, l);
        appendL (a -> valor,l);
    }
}

void posorder (ABin a, LInt *l) {
    *l = NULL;
    posorder2 (a, l);
}

// 34

int depth (ABin root, int x) {
	if (root == NULL) {
		return -1;
	}
	if (root->valor == x){
		return 1;
	}
	if (depth(root->esq, x) < 0 && depth(root->dir, x) < 0){
		return -1;
	}
	else if (depth(root->esq, x) < 0){
		return depth(root->dir, x) + 1;
	}
	else if (depth(root->dir, x) < 0){
		return depth(root->esq, x) + 1;
	}
	else {
		if (depth(root->esq, x) < depth(root->dir, x)){
			return depth(root->esq, x) + 1;
		} else {
			return depth(root->dir, x) + 1;
		}
	}
}

// 35

int freeAB (ABin root) {
	if (root == NULL) {
		return 0;
	} else {
		ABin tmpEsq = root -> esq;
		ABin tmpDir = root -> dir;
		free (root);
		return (1 + freeAB (tmpEsq) + freeAB (tmpDir));
	}
}

// 36

int pruneAB (ABin *root, int depth) {
	/* Casso *root for uma ABin nula não se removem elementos nenhuns */
	if (*root == NULL){
		return 0;
	}

	/* Caso se tenha chegado à profundidade pretendida:
	        1. Guarda-se em res o número de elementos removidos chamando a função aos ramos.
	        2. Liberta-se a memória onde *root era guardado.
	        3. Fecha-se esse ramo da árvore.
	        4. Dá-se return ao resultado. */
	if (depth == 0){
		int res = 1 + pruneAB( &((*root)->esq), 0)  // Step 1
		            + pruneAB( &((*root)->dir), 0); // Step 1
		free(*root);                                // Step 2
		*root = NULL;                               // Step 3
		return res;                                 // Step 4
	}
	/* Caso contrário, retorna-se o resultado de chamar a função ao dois ramos. */
	else {
		return ( pruneAB( &((*root)->esq), depth - 1 ) +
				 pruneAB( &((*root)->dir), depth - 1 ) );
	}
}

// 37

int iguaisAB (ABin a, ABin b) {
	/* Casos de paragem */
	if (a == NULL && b == NULL){
		return 1;
	} else if (a == NULL && b != NULL){
		return 0;
	} else if (a != NULL && b == NULL){
		return 0;

	} else {
		/* Compara-se o valor dos dois nodos, se forem iguais chama-se a função recursivamente
		   aos ramos usando o princípio enunciado na Nota a cima, caso contrário é retornado
		   o valor 0. */
		if (a->valor == b->valor){
			return (iguaisAB(a->esq, b->esq) * iguaisAB(a->dir, b->dir));
		} else {
			return 0;
		}
	}
}

// 38

void nivel (ABin root, int n, LInt *tail) {
	/* Se o nodo não existir para-se a função */
    if (root == NULL){
    	return;
    }

    /* Quando o nodo é encontrado é inserido o novo nodo no INICIO e é atualizado o apontador para
       a nova cabeça da lista */
    if (n == 1){
	    LInt head = (LInt) malloc(sizeof(struct lligada));
	    head->valor = root->valor;
	    head->prox = *tail;
	    *tail = head;
    }
    /* Chama-se a função recursivamente aos ramos, sendo prioritarizado o ramo direito pois a função
       insere os novos nodos no inicio da lista */
    else {
    	nivel(root->dir, n-1, tail);
    	nivel(root->esq, n-1, tail);
    }
}

LInt nivelL (ABin root, int n) {
	LInt start = NULL;      // Cria-se o apontador para a lista a ser returned
	nivel(root, n, &start); // Enche-se a lista com nodos enviando a sua referencia (&start)
	return start;           // Retorna-se o inicio da lista
}

// 39

int nivelV (ABin root, int n, int v[]) {

	/* Se o nodo não existir para-se a função */
    if (root == NULL){
    	return 0;
    }

    /* Se chegarmos à profundidade pretendida atualiza-se o array e dá-se return 1 para a atualizar
       a posição a ser atualizada */
    if (n == 1){
    	v[0] = root->valor;
    	return 1;
    }
    /* Caso não chegamos à profundidade chama-se a função ao ramo esquerdo e guarda-se o output em pos,
       pos representa agora o desvio em relação a v[0], ou seja, v[pos] é a posição onde o próximo int
       será guardado, como v[pos] == (v + pos)[0], chama-se a função recursivamente à direita com v
       correspondente a (v + pos) para se poder introduzir o número na posição (v + pos)[0] */
    else {
    	int pos = nivelV(root->esq, n-1, v);
    	return pos + nivelV(root->dir, n-1, v + pos);
    }
}

// 40

int dumpAbin (ABin root, int v[], int n) {
	/* Se não existe nodo na posição então retorna-se 0 */
    if (root == NULL){
    	return 0;
    }

    /* n (número de slots disponiveis no array) vai diminuindo, quando chega a 0 não é inserido
       mais nenhum número */
    if (n == 0){
    	return 0;
    } else {
    	int pos = dumpAbin(root->esq, v, n - 1);                          // Step 1
    	v[pos] = root->valor;                                             // Step 2
    	return pos + 1 + dumpAbin(root->dir, v + pos + 1, n - (pos + 1)); // Step 3
    }
}

// 41

ABin somasAcA (ABin root) {
	/* Se root for null, então a sua somasAcA é uma ABin nula também */
    if (root == NULL){
    	return NULL;
    }

    ABin newEsq = somasAcA(root->esq); // somasAcA do ramo esquerdo
    ABin newDir = somasAcA(root->dir); // somasAcA do ramo direito

    ABin newRoot = (ABin) malloc(sizeof(ABin)); // Nova ABin que contem as somasAcA
	newRoot->esq = newEsq; // Ligar o ramo esquerdo à nova ABin
	newRoot->dir = newDir; // Ligar o ramo direito à nova ABin

	int somaEsq; // Int onde é guardado a somaAcA do ramo esquerdo
	int somaDir; // Int onde é guardado a somaAcA do ramo direito

	/* Caso haja um ramo do lado esquerdo, ele contém a soma de todos os elementos da árvore
	   a baixo de si */
	if (newEsq != NULL){
	    somaEsq = newEsq->valor;
	}
	/* Caso contrário, é atribuida à soma o valor 0 */
	else {
		somaEsq = 0;
	}

	if (newDir != NULL){
	    somaDir = newDir->valor;
	} else {
		somaDir = 0;
	}

	/* Após se guardar o valor da somaAcA de cada ramo, junta-se esse valor ao valor já contido
	   no nodo principal e por fim dá-se return ao endereço desse nodo.s */
	newRoot->valor = somaEsq + somaDir + root->valor;
	return newRoot;
}

// 42

int contaFolhas (ABin a) {
	/* Se a for um ABin vazia, não tem folhas */
	if (a == NULL){
		return 0;
	} else {
		/* Testa se a é uma folha, caso seja, retorna 1 */
		if (a->esq == NULL && a->dir == NULL){
			return 1;
		/* Chama a função recursivamente aos ramos, somando o número de folhas
		   do lado esquerdo com o número de folhas no lado direito. */
		} else {
			return (contaFolhas(a->esq) + contaFolhas(a->dir));
		}
	}
}

// 43

ABin cloneMirror (ABin root) {
	ABin new = NULL;
	if (root != NULL){
    	new = (ABin) malloc (sizeof (struct nodo));
    	new->valor = root->valor;
    	new->esq = cloneMirror(root->dir);
    	new->dir = cloneMirror(root->esq);
	}
    return abin;
}

// 44

int addOrd (ABin *root, int x) {

	/* Caso *root seja vazio, cria-se uma nova árvore binária com o valor x e ramos nulos, e atualiza-se
	   o apontador *root */
	if (*root == NULL){
		ABin new = (ABin) malloc(sizeof(ABin));
		new->valor = x;
		new->esq = NULL;
		new->dir = NULL;
		*root = new;
		return 0;
	}

	ABin current = *root; // Apontador que percorre a ABin
	ABin prev; // Apontador sempre 1 nodo atrás de current

	/* Loop que guarda em prev o nodo no qual se vai criar um novo ramo */
	while (current != NULL){
		/* Se se encontrar o valor x na árvore binária, é dado logo return de 1 e não se
		   adiciona um novo nodo. */
		if (current->valor == x){
			return 1;
		}

		prev = current; // prev toma o valor de current

		/* Avança-se current 1 nodo para a esquerda ou direita, dependendo se x é maior ou
		   menor que o que está guardado em current. */
		if (x < current->valor){
			current = current->esq;
		} else {
			current = current->dir;
		}
	}

	/* Novo nodo com o valor de x e ramos nulos. */
	ABin new = (ABin) malloc(sizeof(ABin));
	new->valor = x;
	new->esq = NULL;
	new->dir = NULL;

	/* Se x for menor que o valor de prev, liga-se o ramo à esquerda, caso contrário, liga-se o
	   ramo à direita. */
	if (x < prev->valor){
		prev->esq = new;
	} else {
		prev->dir = new;
	}
    return 0; // return 0 pois o ramo foi inserido com sucesso.
}

// 45

int lookupAB (ABin root, int x) {
	/* Se encontra x dá return a 1, caso contrário vai procurando à esquerda ou direita dependendo
	   se é maior ou menor, se o loop acabar significa que não se encontrou o nodo e dá-se return 0 */
	while(root != NULL){
		if(x == root->valor){
			return 1;
		} else if (x < root->valor){
			root = root->esq;
		} else {
			root = root->dir;
		}
	}
	return 0;
}

// 46

int depthOrd2 (ABin root, int x, int depth){
	/* Se root é nulo, então x não existe na árvore binária */
	if (root == NULL){
		return -1;
	}
	if (x < root->valor){
		return depthOrd2(root->esq, x, depth + 1); // Se x é menor procura-se à esquerda
	} else if (x > root->valor){
		return depthOrd2(root->dir, x, depth + 1); // Se x é maior procura-se à direita
	} else {
		return depth; // Caso se encontre x, retorna-se a profundidade a que está
	}
}

int depthOrd (ABin root, int x) {
	/* Chama-se a função auxiliar depthOrd2, que recebe os mesmos parametros que depthOrd,
	   mas tem um parametro extra (depth), onde é guardada a profundidade que está a ser
	   inspecionada a cada iteração. */
    return depthOrd2(root, x, 1);
}

// 47

int maiorAB (ABin root) {
	/* Procura o ultimo nodo à direita e devolve o seu valor no final*/
	while(root->dir != NULL){
		root = root->dir;
	}
	return root->valor;
}

// 48

void removeMaiorA (ABin *root) {
	/* Quando é encontrado o maior elemento da árvore binária de procura, o apontador
	   *root representa o ramo direito do ramo anterior, assim atualizando *root para
	   o apontador do seu ramo esquerdo a árvore binária ignora o maior nodo e o ramo
	   fica ligado ao valor à esquerda do maior valor. */
	if ((*root)->dir == NULL){
		ABin temp = *root;
		*root = (*root)->esq;
		free(temp);
	/* Chama-se a função recursivamente até encontrar o último valor. */
	} else {
		removeMaiorA(&((*root)->dir));
	}
}

// 49

int quantosMaiores (ABin root, int x) {
	/* Se não existir uma árvore */
	if (root == NULL){
		return 0;
	}
	/* Se x < root->valor, acrescentamos 1 e chama-mos a função aos dois ramos, pois tanto pode haver elementos menores
	   que root->valor que são menores ou maiores que x. */
	if (x < root->valor){
		return 1 + quantosMaiores(root->esq, x) + quantosMaiores(root->dir, x);
	}
	/* Caso contrário, basta apenas chamar ao ramo direito (sem acrescentar 1), pois todos os valores no ramo esq de root
	   são menores que x */
	else {
		return quantosMaiores(root->dir, x);
	}
}

// 50

int length (LInt l) {

	int x = 0;

	while (l != NULL) {
		l = l->prox;
		x++;
	}

	return x;
}

LInt parteAMeio (LInt *l) {

	LInt atual = *l, ant = newLInt (0, atual);
	*l = ant;


	int x = length (atual) / 2;

	while (x > 1) {
		atual = atual->prox;
		ant = ant->prox;
		x--;
	}

	ant->prox = NULL;

	ant = *l;
	*l = ant->prox;
	free (ant);

	return atual;
}

void listToBTree (LInt l, ABin *a) {

	if (l == NULL) {
		*a = NULL;
		return;
	}

	LInt dir = parteAMeio (&l);

	*a = newABin (dir->valor, NULL, NULL);

	listToBTree (l, &(*a)->esq);
	listToBTree (dir->prox, &(*a)->dir);

	return;
}

// 51

/* Devolve o valor mais à esquerda de todo. */
int minValue(ABin root){
	if (root->esq == NULL){
		return root->valor;
	} else {
		return minValue(root->esq);
	}
}

/* Devolve o valor mais à direita de todo. */
int maxValue(ABin root){
	if (root->dir == NULL){
		return root->valor;
	} else {
		return maxValue(root->dir);
	}
}

int deProcura (ABin root) {
	/* Se root for uma arvore binária vazia, então é de procura */
	if (root == NULL){
		return 1;
	}
	/* Se o maior valor à esquerda for maior que o valor guardado em root, então a árvore não é de procura. */
	if (root->esq != NULL && maxValue(root->esq) > root->valor){
		return 0;
	}
	/* Se o menor valor à direita for menor que o valor guardado em root, então a árvore não é de procura. */
	else if (root->dir != NULL && minValue(root->dir) < root->valor){
		return 0;
	}
	/* Se o ramo da esquerda ou da direita não fore de procura, então a árvore não é de procura. */
	else if (!deProcura(root->esq) || !deProcura(root->dir)){
		return 0;
	}
	/* Caso passe todos os testes, a árvore é de procura. */
	return 1;
}
