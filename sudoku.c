#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 9

bool verificarNumeros(int vetor[TAMANHO]) {
    bool encontrado[TAMANHO + 1] = {false};

    for (int i = 0; i < TAMANHO; i++) {
        if (vetor[i] < 1 || vetor[i] > 9 || encontrado[vetor[i]]) {
            return false;
        }
        encontrado[vetor[i]] = true;
    }
    return true;
}

bool verificarLinhas(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        if (!verificarNumeros(matriz[i])) {
            return false;
        }
    }
    return true;
}

bool verificarColunas(int matriz[TAMANHO][TAMANHO]) {
    int coluna[TAMANHO];

    for (int j = 0; j < TAMANHO; j++) {
        for (int i = 0; i < TAMANHO; i++) {
            coluna[i] = matriz[i][j];
        }
        if (!verificarNumeros(coluna)) {
            return false;
        }
    }
    return true;
}

bool verificarSubgrades(int matriz[TAMANHO][TAMANHO]) {
    int subgrade[TAMANHO];

    for (int linha = 0; linha < TAMANHO; linha += 3) {
        for (int coluna = 0; coluna < TAMANHO; coluna += 3) {
            int index = 0;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    subgrade[index++] = matriz[linha + i][coluna + j];
                }
            }

            if (!verificarNumeros(subgrade)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matriz[TAMANHO][TAMANHO];

    printf("Digite os elementos da matriz 9x9 (números de 1 a 9):\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    if (verificarLinhas(matriz) && verificarColunas(matriz) && verificarSubgrades(matriz)) {
        printf("É uma resposta válida de Sudoku\n");
    } else {
        printf("Não é uma resposta válida de sudoku\n");
    }

    return 0;
}
