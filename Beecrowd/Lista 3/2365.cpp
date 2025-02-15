#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int s1;
    int s2;
} JData;

typedef struct {
    char n[100];
    int p;
    JData *j;
} Plr;

int cmpPlrs(const void *a, const void *b) {
    const Plr *pA = (const Plr *)a;
    const Plr *pB = (const Plr *)b;
    if (pA->p != pB->p) {
        return pB->p - pA->p;
    }
    return strcmp(pA->n, pB->n);
}

void allocPlrs(Plr **p, int c) {
    *p = (Plr *)calloc(c, sizeof(Plr));
    if (*p == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }
}

void allocJData(Plr *p, int jCount) {
    p->j = (JData *)calloc(jCount, sizeof(JData));
    if (p->j == NULL) {
        fprintf(stderr, "Erro na alocação de memória para dados de jogo\n");
        exit(1);
    }
}

void updScores(Plr *p, int pCount, char *input, int jIndex) {
    int s1, s2;
    sscanf(input, "%*s %d %*s %d", &s1, &s2);
    int res1 = (s1 > s2) ? 1 : (s1 < s2) ? 2 : 0;

    for (int i = 0; i < pCount; i++) {
        JData curr = p[i].j[jIndex];
        int res2 = (curr.s1 > curr.s2) ? 1 : (curr.s1 < curr.s2) ? 2 : 0;
        int points = 0;

        if (res1 == res2) {
            if (curr.s1 == s1 && curr.s2 == s2) {
                points = 10;
            } else if (curr.s1 == s1 || curr.s2 == s2) {
                points = 7;
            } else {
                points = 5;
            }
        } else if (s1 == curr.s1 || s2 == curr.s2) {
            points = 2;
        }
        p[i].p += points;
    }
}

int main() {
    char input[256];
    int pCount, jCount;
    Plr *p = NULL;

    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "0 0\n") == 0) break;

        sscanf(input, "%d %d", &pCount, &jCount);
        allocPlrs(&p, pCount);

        for (int i = 0; i < pCount; i++) {
            p[i].p = 0;
            fgets(p[i].n, sizeof(p[i].n), stdin);
            p[i].n[strcspn(p[i].n, "\n")] = 0;

            allocJData(&p[i], jCount);

            for (int j = 0; j < jCount; j++) {
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%*s %d %*s %d", &p[i].j[j].s1, &p[i].j[j].s2);
            }
        }

        for (int i = 0; i < jCount; i++) {
            fgets(input, sizeof(input), stdin);
            updScores(p, pCount, input, i);
        }

        qsort(p, pCount, sizeof(Plr), cmpPlrs);

        for (int i = 0; i < pCount; i++) {
            printf("%s %d\n", p[i].n, p[i].p);
            free(p[i].j);
        }
        free(p);
    }
    return 0;
}
