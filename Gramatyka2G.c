#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

void generujLosowyCi¹g(char* tablica,int x) {
    const char symbole[] = {'a','b'};
    for (int i = 0; i < x+1 - 1; ++i) {
        int losowyIndex = rand() % sizeof(symbole);
        tablica[i] = symbole[losowyIndex];
    }
    tablica[x+1 - 1] = '\0'; 
}

int porownaj(const void* a, const void* b) {
    const char* napisA = *(const char**)a;
    const char* napisB = *(const char**)b;
    int dlugoscA = (int)strlen(napisA);
    int dlugoscB = (int)strlen(napisB);

    if (dlugoscA != dlugoscB) {
        return dlugoscA - dlugoscB;
    }

    return strcmp(napisA, napisB);
}
int main() {
    srand((unsigned int)time(NULL));  
    printf("Program generuje losowe lancuchy (o losowej dlugosci) z gramatyki bezkontekstowej o regule S->bSa|(e)\n");
    printf("Oto opis gramatyki bezkontekstowej dla reguly S->bSa|(e) :\n");
    printf("Symbole terminalne: b,a,(e)-symbol pusty\n");
    printf("Symbole nieterminalne: S\n");
    printf("Produkcje:\n");
    printf("|1| S->bSa oznacza ze nieterminal S moze byc zastapiony przez sekwencje b oraz a\n");
    printf("|2| S->(e) oznacza ze nieterminal S moze byc zastapiony przez pusta sekwencje\n\n");
    printf("Podaj liczbe lancuchow do wygenerowania: ");
    int n;
    scanf_s("%d", &n);
    printf("\n");

    char v[100][100];
    int x = rand() % 11;
    for (int i = 0; i < n; ++i) {
        int z = rand() % 6;
        if (i == 1 && i%3==0)
            x += 1;
        else {
            int z = rand() % 6;
            x += z;
        }
        generujLosowyCi¹g(v[i],x);
    }
    const char* wskazniki[100];
    for (int i = 0; i < n; ++i) {
        wskazniki[i] = v[i];
    }

    for(int i=0;i<n;i++)
    qsort(wskazniki, n, sizeof(const char*), porownaj);

    printf("Wygenerowane lancuchy uporzadkowane w postaci kanonicznej:\n\n");
    int m = rand() % 11;
    if (m==4)
    {
        printf("1.\t (e)\n");
        for (int i = 1; i < n; ++i) 
        printf("%d.\t b%s\n",(i+1), wskazniki[i]);
    }
    else 
    {
        for (int i = 0; i < n; ++i)
        printf("%d.\t b%s\n", (i + 1), wskazniki[i]);
    }

    return 0;
}