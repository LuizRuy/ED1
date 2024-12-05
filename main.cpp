#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 100
#define MAX_TAM_NOME 50

int main() {
    char **nomes;
    int numero_nomes = 0;
    char buffer[MAX_TAM_NOME];
    FILE *arquivo;

    //Substituir para o local do arquivo
    arquivo = fopen("/home/luiz/CLionProjects/untitled1/nomes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    nomes = (char **)malloc(MAX_NOMES * sizeof(char *));
    if (nomes == NULL) {
        printf("Erro ao alocar memória para os nomes.\n");
        fclose(arquivo);
        return 1;
    }

    while (fgets(buffer, MAX_TAM_NOME, arquivo) != NULL) {
        if (numero_nomes >= MAX_NOMES) {
            printf("Número máximo de nomes atingido. Alguns nomes serão ignorados.\n");
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        nomes[numero_nomes] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (nomes[numero_nomes] == NULL) {
            printf("Erro ao alocar memória para o nome %d.\n", numero_nomes + 1);
            break;
        }

        strcpy(nomes[numero_nomes], buffer);
        numero_nomes++;
    }

    fclose(arquivo);

    for (int i = 0; i < numero_nomes - 1; i++) {
        for (int j = 0; j < numero_nomes - i - 1; j++) {
            if (strcasecmp(nomes[j], nomes[j + 1]) > 0) {
                char *temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;
            }
        }
    }

    printf("\nLista de nomes em ordem alfabética:\n");
    for (int i = 0; i < numero_nomes; i++) {
        printf("%s\n", nomes[i]);
    }

    for (int i = 0; i < numero_nomes; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}
