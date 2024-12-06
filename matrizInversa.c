#include <stdio.h>

#define TAMANHO 3


float calcularDeterminante(float matriz[TAMANHO][TAMANHO]) {
	return matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) -
	       matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) +
	       matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
}


void calcularAdjunta(float matriz[TAMANHO][TAMANHO], float adjunta[TAMANHO][TAMANHO]) {
	adjunta[0][0] = (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]);
	adjunta[1][0] = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]);
	adjunta[2][0] = (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

	adjunta[0][1] = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]);
	adjunta[1][1] = (matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0]);
	adjunta[2][1] = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]);

	adjunta[0][2] = (matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1]);
	adjunta[1][2] = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]);
	adjunta[2][2] = (matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0]);
}


int calcularInversa(float matriz[TAMANHO][TAMANHO], float inversa[TAMANHO][TAMANHO]) {
	float determinante = calcularDeterminante(matriz);

	if (determinante == 0) {
		return 0;
	}

	float adjunta[TAMANHO][TAMANHO];
	calcularAdjunta(matriz, adjunta);

	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			inversa[i][j] = adjunta[i][j] / determinante;
		}
	}

	return 1;
}

void corrigirZeroNegativo(float *valor) {
    if (fabs(*valor) < 1e-6) {
        *valor = 0.0;
    }
}

int main() {
	float matriz[TAMANHO][TAMANHO], inversa[TAMANHO][TAMANHO], resultado[TAMANHO][TAMANHO];

	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			scanf("%f", &matriz[i][j]);
		}
	}

	if (!calcularInversa(matriz, inversa)) {
		printf("A matriz nao tem inversa.\n");
		return 1;
	}

	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			resultado[i][j] = matriz[i][j] * inversa[i][j];
			corrigirZeroNegativo(&resultado[i][j]);
		}
	}

	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			printf("%.1f ", resultado[i][j]);
		}
		printf("\n");
	}

	return 0;
}
