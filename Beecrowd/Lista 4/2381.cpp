#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char **nomes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        nomes[i] = (char *)malloc(101 * sizeof(char));
        scanf("%s", nomes[i]);
    }

    qsort(nomes, n, sizeof(char *), comparar);

    printf("%s\n", nomes[k - 1]);

    for (int i = 0; i < n; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}
