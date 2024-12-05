#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME_MAX 50
int main(void) {
    char **nomes;
    int n_nomes;

    while (1) {
        printf("Digite o numero de nomes desejado: ");
        if (scanf("%d", &n_nomes) == 1 && n_nomes > 0) {
            getchar();
            break;
        } else {
            printf("Entrada inválida! Por favor, tente novamente.\n");

            while (getchar() != '\n');
        }
    }
    nomes = (char **) malloc(n_nomes * sizeof(char *));
    if (nomes == NULL) {
        printf("Erro ao alocar memoria");
        return 1;
    }

    for (int i = 0; i < n_nomes; i++) {
        nomes[i] = (char *) malloc(TAM_NOME_MAX * sizeof(char));
        if (nomes[i] == NULL) {
            printf("Erro ao alocar memoria para o nome %d\n", i+1);
            return 1;
        }

        printf("Digite o nome numero %d: ", i+1);
        fgets(nomes[i], TAM_NOME_MAX, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }


    for (int i = 0; i < n_nomes - 1; i++) {
        for (int j = 0; j < n_nomes - i - 1; j++) {
            if (strcasecmp(nomes[j], nomes[j + 1]) > 0) {
                char *temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;
            }
        }
    }

    printf("\nLista de nomes em ordem alfabética:\n");
    for (int i = 0; i < n_nomes; i++) {
        printf("%s\n", nomes[i]);
    }

    for (int i = 0; i < n_nomes; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;


}