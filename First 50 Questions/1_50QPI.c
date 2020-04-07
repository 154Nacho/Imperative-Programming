// PROGRAMAÇÃO IMPERATIVA

// 50 QUESTÕES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1

int main1 () {
    int x;
    int maior = 0;
    scanf("%d", &x);
    while (x != 0) {
        if (x > maior) {
            maior = x;
        }
        scanf("%d", &x);
    }
    printf("%d\n", maior);
    return 0;
}

// 2

int main2 () {
    int x;
    int soma = 0;
    int i = 0;
    double media = 0;
    scanf("%d", &x);
    while (x != 0) {
        soma += x;
        i++;
        scanf("%d", &x);
    }
    media = soma / i;
    printf("%d\n", media);
    return 0;
}

// 3

int main3 () {
    int x;
    int maior1 = 0;
    int maior2 = 0;
    scanf("%d", &x);
    while (x != 0) {
        if (x > maior1 && x > maior2) {
            maior2 = maior1;
            maior1 = x;
        }
        if (x < maior1 && x > maior2) {
            maior2 = x;
        }
        scanf("%d", &x);
    }
    printf("%d\n", maior2);
    return 0;
}

// 4

int bitsUm (unsigned int n) {
    int r = 0;
    while (n != 0) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n /= 2;
            r++;
        }
    }
    return r;
}

// 5

int trailingZ (unsigned int n) {
    int r = 0;
    while (n != 0) {
        if (n % 2 == 0) {
            n /= 2;
            r++;
        } else {
            break;
        }
    }
    return r;
}

// 6

int qDig (unsigned int n) {
    int r = 0;
    while (n != 0) {
        n /= 10;
        r++;
    }
    return r;
}

// 7

int len (char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

char *mystrcat (char s1[], char s2[]) {
    int i;
    int s1len = len(s1);
    for (i = 0; s2[i] != '\0'; i++, s1len++) {
        s1[s1len] = s2[i];
    }
    s1[s1len] = '\0';
    return s1;
}

// 8

char *mystrcpy (char *dest, char source[]) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}

// 9

int mystrcmp(char s1[], char s2[]) {
    int i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0')) i++;
    return (s1[i] - s2[i]);
}

// 10

char *mystrstr (char s1[], char s2[]) {
    int i;
    int j = 0;
    int pos = 0;
    if (s2[0] == '\0') return s1;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[0]) pos = i;
        if (s1[i] == s2[j]) j++;
        if (s2[j] == '\0') return (s1 + pos);
    }
    return NULL;
}

// 11

int len (char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

char *mystrcpy (char *dest, char source[]) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
}

void strrev (char s[]) {
    int i;
    int slen = len(s);
    int stop = slen;
    char copy[slen];
    mystrcpy(copy,s);
    slen--;
    for (i = 0; i < stop; i++, slen--) {
        s[i] = copy[slen];
    }
    s[i] = '\0';
}

// 12

void strnoV (char s[]) {
    int i;
    int j = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'e' &&
        s[i] != 'i' && s[i] != 'o' &&
        s[i] != 'u' && s[i] != 'A' &&
        s[i] != 'E' && s[i] != 'I' &&
        s[i] != 'O' && s[i] != 'U') {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

// 13

void truncW (char t[], int n) {
    int i, j = 0, repetir = n,p;
    for (i = 0; t[i] != '\0'; i++) {
        if (t[i] == ' ') {
            repetir = n;
            t[j] = ' ';
            j++;
        }
        else {
            p = i;
            while (repetir > 0 && t[p] != ' ') {
                t[j] = t[p];
                p++;
                j++;
                if (t[p] != ' ') i++;
                repetir -= 1;
            }
        }
    }
    t[j] = '\0';
}

// 14

char charMaisfreq (char s[]) {
    int i;
    int j;
    int count = 0;
    int max = 0;
    char c;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; s[j] != '\0'; j++) {
            if (s[i] == s[j]) count++;
            if (count > max) {
                max = count;
                c = s[i];
            }
        }
        count = 0;
    }
    return c;
}

// 15

int iguaisConsecutivos (char s[]) {
    int i;
    int count = 1;
    int max = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1]) count++;
        else {
            if (count > max) max = count;
            count = 1;
        }
    }
    return max;
}

// 16

int diferente (char s[], int i, int j) {
    while (i < j) {
        if (s[i] == s[j]) return 0;
        i++;
    }
    return 1;
}

int difConsecutivos (char s[]) {
    int i;
    int j;
    int count = 0;
    int max = 0;
    for (i = 0; s[i] != '\0'; i++) {
        count = 0;
        for (j = i; s[j] != '\0' && diferente(s, i, j); j++) {
            count++;
        }
        if (count > max) {
            max = count;
        }
    }
    return max;
}

// 17

int maiorPrefixo (char s1 [], char s2 []) {
    int i, pref = 0;
    for (i = 0; s1[i] == s2[i]; i++) pref++;
    return pref;
}

// 18

int len (char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

int maiorSufixo (char s1 [], char s2 []) {
    int i = len(s1) - 1;
    int j = len(s2) - 1;
    int suf = 0;
    for ( ; s1[i] == s2[j]; i--, j--) suf++;
    return suf;
}

// 19

int sufPref (char s1[], char s2[]) {
    int i, j = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[j]) j++;
        else j = 0;
    }
    return j;
}

// 20

int contaPal (char s[]) {
    int i, pal = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if ((!(isspace(s[i]))) && ((isspace(s[i+1])) || (s[i+1] == '\0'))) pal++;
    }
    return pal;
}

// 21

int contaVogais (char s[]) {
    int i, vogais = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' ||
        s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == 'A' ||
        s[i] == 'E' || s[i] == 'I' ||
        s[i] == 'O' || s[i] == 'U') vogais++;
    }
    return vogais;
}

// 22

int charContido (char a, char b[]) {
    int i;
    for (i = 0; b[i] != '\0'; i++) {
        if (b[i] == a) return 1;
    }
    return 0;
}

int contida (char a[], char b[]) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        if (charContido(a[i],b) == 0) return 0;
    }
    return 1;
}

// 23

int len (char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

int palindroma (char s[]) {
    int i = 0;
    int j = len(s) - 1;
    for ( ; s[i] != '\0'; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

// 24

int remRep (char x[]) {
    int i, j = 0;
    for (i = 0; x[i] != '\0'; i++) {
        if (x[i] != x[i+1]) {
            x[j] = x[i];
            j++;
        }
    }
    x[j] = '\0';
    return j;
}

// 25

int limpaEspacos (char t[]) {
    int i, j = 0;
    for (i = 0; t[i] != '\0'; i++) {
        if (t[i] == ' ' && t[i+1] == ' ');
        else {
            t[j] = t[i];
            j++;
        }
    }
    t[j] = '\0';
    return j;
}

// 26

void insere (int v[], int N, int x) {
    int i, j;
    for (i = 0; i < N && v[i] < x; i++);
    for (j = N; j != i; j--) {
        v[j] = v[j-1];
    }
    v[i] = x;
}

// 27

void merge (int r [], int a[], int b[], int na, int nb) {
    int i, aCount, bCount;
    for (i = 0, aCount = 0, bCount = 0; i < na + nb; i++) {
        if (na == aCount) {
            r[i] = b[bCount];
            bCount++;
        } else if (nb == bCount) {
            r[i] = a[aCount];
            aCount++;
        } else {
            if (a[aCount] < b[bCount]) {
                r[i] = a[aCount];
                aCount++;
            } else {
                r[i] = b[bCount];
                bCount++;
            }
        }
    }
}

// 28

int crescente (int a[], int i, int j) {
    int n;
    for (n = i; n < j; n++) {
        if (a[n] > a[n+1]) return 0;
    }
    return 1;
}

// 29

int retiraNeg (int v[], int N) {
    int i, j = 0;
    for (i = 0; i < N; i++) {
        if (v[i] >= 0) {
            v[j++] = v[i]; 
        }
    }
    return j;
}

// 30

int menosFreq (int v[], int N) {
    int i, count = 1, min = N, mf = v[0];
    for (i = 0; i < N; i++) {
        if (v[i] == v[i+1]) {
            count++;
        } else {
            if (count < min) {
                min = count;
                mf = v[i];
            }
            count = 1;
        }
    }
    return mf;
}

// 31

int maisFreq (int v[], int N) {
    int i, count = 1, max = 0, mf = v[0];
    for (i = 0; i < N; i++) {
        if (v[i] == v[i+1]) {
            count++;
        } else {
            if (count > max) {
                max = count;
                mf = v[i];
            }
            count = 1;
        }
    }
    return mf;
}

// 32

int maxCresc (int v[], int N) {
    int i, count = 1, max = 0;
    for (i = 0; i < N; i++) {
        if (v[i] <= v[i+1]) {
            count++;
        } else {
            if (count > max) {
                max = count;
            }
            count = 1;
        }
    }
    return max;
}

// 33

int temRep (int v[], int N, int x) {
    int i;
    for (i = 0; i < N; i++) {
        if (v[i] == x) return 1;
    }
    return 0;
}

int elimRep (int v[], int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        if (temRep(v,i,v[i])) {
            for (j = i; j < N; j++) {
                v[j] = v[j+1];
            }
            N--;
            i--;
        }
    }
    return N;
}

// 34

int elimRepOrd (int v[], int N) {
    int i, j = 0;
    for (i = 0; i < N; i++) {
        if (v[i] != v[j]) {
            j++;
            v[j] = v[i];
        } 
    }
    return j+1;
}

// 35

int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0, j = 0, comuns = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) i++;
        else if (b[j] < a[i]) j++;
        else if (a[i] == b[j]) {
            i++;
            j++;
            comuns++;
        }
    }
    return comuns;
}

// 36

int comuns (int a[], int na, int b[], int nb) {
    int i, j, comuns = 0;
    for (i = 0; i < na; i++) {
        for (j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                comuns++;
                break;
            }
        }
    }
    return comuns;
}

// 37

int minInd (int v[], int N) {
   int i, min = v[0], p = 0;
   for (i = 0; i < N; i++) {
       if (v[i] < min) {
           min = v[i];
           p = i;
       }
   }
   return p;
} 

// 38

void somasAc (int v[], int Ac [], int N) {
    int i;
    Ac[0] = v[0];
    for (i = 1; i < N; i++) {
        Ac[i] = Ac[i-1] + v[i];
    }
}

// 39

int triSup (int N, int m [N][N]) {
    int i, j, r = 1;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i > j) {
                if (m[i][j] != 0) r = 0;
            }
        }
    }
    return r;
}

// 40

void transposta (int N, float m [N][N]) {
    int i, j;
    float t[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            t[i][j] = m[i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = t[j][i];
        }
    }
}

// 41

void addTo (int N, int M, int a [N][M], int b[N][M]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}

//42

int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++) {
        if (v1[i] == 1 || v2[i] == 1) r[i] = 1;
        else r[i] = 0;
    }
}

// 43

int intersectSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++) {
        if (v1[i] == 1 && v2[i] == 1) r[i] = 1;
        else r[i] = 0;
    }
}

// 44

int intersectMSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++) {
        if (v1[i] > v2[i]) r[i] = v2[i];
        else r[i] = v1[i];
    }
}

// 45

int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++) {
        if (v1[i] > v2[i]) r[i] = v1[i];
        else r[i] = v2[i];
    }
}

// 46

int cardinalMSet (int N, int v[N]) {
    int i, soma = 0;
    for (i = 0; i < N; i++) {
        soma += v[i];
    }
    return soma;
}

// 

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
int x, y;
} Posicao;

// 47

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (mov[i] == Norte) inicial.y++;
        if (mov[i] == Sul) inicial.y--;
        if (mov[i] == Este) inicial.x++;
        if (mov[i] == Oeste) inicial.x--;
    }
    return inicial;
}

// 48

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i, r = 0;
    for (i = 0; (inicial.x != final.x) || (inicial.y != final.y); i++) {
        if (inicial.y < final.y) {
            mov[i] = Norte;
            inicial.y++;
            r++;
        } else if (inicial.y > final.y) {
            mov[i] = Sul;
            inicial.y--;
            r++;
        } else if (inicial.x < final.x) {
            mov[i] = Este;
            inicial.x++;
            r++;
        } else if (inicial.x > final.x) {
            mov[i] = Oeste;
            inicial.x--;
            r++;
        }
    }
    if (r > N) r = -1;
    return r;
}

// 49

int distancia (Posicao n) {
    int dis = 0;
    dis = abs(n.x) + abs(n.y);
    return dis;
}

int maiscentral (Posicao pos[], int N) {
    int i, p = 0;
    int min = distancia(pos[0]);
    for (i = 0; i < N; i++) {
        if (distancia(pos[i]) < min) {
            min = distancia(pos[i]);
            p = i;
        }
    }
    return p;
}

// 50

int vizinhos (Posicao p, Posicao pos[], int N) {
    int i, v = 0;
    for (i = 0; i < N; i++) {
        if ((p.x == pos[i].x) && (p.y == pos[i].y + 1)) v++;
        else if ((p.x == pos[i].x) && (p.y == pos[i].y - 1)) v++;
        else if ((p.y == pos[i].y) && (p.x == pos[i].x + 1)) v++;
        else if ((p.y == pos[i].y) && (p.x == pos[i].x - 1)) v++;
    }
    return v;
}