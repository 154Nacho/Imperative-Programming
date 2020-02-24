// Ficha 2 PROGRAMAÇÃO IMPERATIVA

#include <stdio.h>

// Exercício 1

int main(){

	int n, m, r = 0;
	printf("Inserir o valor de n: ");
	scanf("%d",&n);
	printf("Inserir o valor de m: ");
	scanf("%d",&m);
	while(n > 0){
		r += m;
		n--;
	}
	printf("Valor da multiplicação: %d\n",r);
	return 0;
}

// Exercício 2

int main(){
	int n;
	float m,r = 0;

	printf("Inserir o valor de n: ");
	scanf("%d",&n);
	printf("Inserir o valor de m: ");
	scanf("%f",&m);

	int size,aux = n;

	for(size = 1; aux != 1; size ++) aux = aux / 2; //Determina o tamanho da tabela. Torna a função pouco eficiente

	float tabelaM[size]; //Uso duas tabelas para evitar o conflito entre tipos int e float de n e m respetivamente
 	int tabelaN[size];
	
	for(int i = 0; i < size; i++){
		if(n%2 == 1) r += m; //Condição do valor do n ser ímpar. Se se verificar, somamos o valor de m nessa linha ao valor da soma.
		tabelaN[i] = n;
		tabelaM[i] = m;
		n /= 2;
		m *= 2;
	}

	for(int i = 0; i<size; i++){
		printf("%d | %d | %f \n", i+1, tabelaN[i], tabelaM[i]); //Imprime a tabela
	}

	printf("%f\n",r); //Imprime o resultado da multiplicação

	return 0;
}

// Exercício 3

int main(){

	int a, b;
	printf("Inserir o valor de a: ");
	scanf("%d",&a);
	printf("Inserir o valor de b: ");
	scanf("%d",&b);

	int maior, menor, mdc = 0;
	if(a < b){
		maior = b;
		menor = a;
	} else{maior = a; menor = b;}	

	int i = menor;
	while(i > 1 && mdc == 0){
		if(menor % i == 0){
			if(maior % i == 0) mdc = i;
			else i--;
		}
		else i--;
	}

	printf("MDC: %d\n",mdc);
	return 1;
}

// Exercício 4

int mymdc(int a, int b){
	int r;
	if(a == b) r = a;
	if(a > b) r = mymdc(a-b,b);
	if(a < b) r = mymdc(a,b-a);
	return r;
}

int main(){
	int a, b;
	printf("Inserir o valor de a: ");
	scanf("%d",&a);
	printf("Inserir o valor de b: ");
	scanf("%d",&b);

	int mdcV = mymdc(a,b);

	printf("%d\n",mdcV);

	return 0;
}

// Exercício 5

int mymdc(int maior, int menor){
	int r = maior % menor; //Valor do resto capaz de iniciar o ciclo
	int aux;
	while(r != 0){
		aux = r; // Garante que quando resto == 0, conseguimos saber o seu valor anterior.
		r = menor % r;
		 
	}
	return aux;
}

int main(){
	int a, b;
	printf("Inserir o valor de a: ");
	scanf("%d",&a);
	printf("Inserir o valor de b: ");
	scanf("%d",&b);

	int maior, menor;
	if(a<b){maior=b;menor=a;}
	else{maior=a;menor=b;}

	int mdcV = mymdc(maior,menor);

	printf("%d\n",mdcV);

	return 0;
}

// Exercício 6

// Exeercício a)

int fib(int n){
	int r;
	if(n < 2) r = 1;
	else{
		r = fib(n-1) + fib(n-2);
	}
	return r;
}

int main(){
	int n;
	scanf("%d",&n);
	int r = fib(n-1); //n-ésimo elemento está na n-1ª posição

	printf("%d\n",r);
	return 0;
}

// Exercício b)

int fib (int n) {

	int anterior = 1;
	int antanterior = 0;
	int r = 0;
	int x = 0;
	int i = 1;
	while( i < n ){
		r = anterior + antanterior;
		x = anterior;
		anterior = anterior + antanterior; 
		antanterior = x; 
		i++;
	}
	return r;
}


int main(){
	int n;
	scanf("%d",&n);
	int r = fib(n); //n-ésimo elemento está na n-1ª posição

	printf("%d\n",r);
	return 0;
}