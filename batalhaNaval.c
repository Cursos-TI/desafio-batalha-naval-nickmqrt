#include <stdio.h>
#include <string.h>

#define TAM 5  // Tamanho fixo da matriz (5x5)

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
	
// Função para exibir a matriz
void exibirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Zera toda a matriz
void limparMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;
}

// Padrão Cone
void habilidadeCone(int matriz[TAM][TAM]) {
    int centro = TAM / 2;
    for (int i = 0; i <= centro; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            matriz[i + centro][j] = 1;
        }
    }
}

// Padrão Octaedro
void habilidadeOctaedro(int matriz[TAM][TAM]) {
    int centro = TAM / 2;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Padrão Cruz
void habilidadeCruz(int matriz[TAM][TAM]) {
    int centro = TAM / 2;
    for (int i = 0; i < TAM; i++) {
        matriz[centro][i] = 1;  // Linha central
        matriz[i][centro] = 1;  // Coluna central
    }
}

int main() {
    int matriz[TAM][TAM];

    // Cone
    limparMatriz(matriz);
    printf("Habilidade: Cone\n");
    habilidadeCone(matriz);
    exibirMatriz(matriz);

    // Octaedro
    limparMatriz(matriz);
    printf("Habilidade: Octaedro\n");
    habilidadeOctaedro(matriz);
    exibirMatriz(matriz);

    // Cruz
    limparMatriz(matriz);
    printf("Habilidade: Cruz\n");
    habilidadeCruz(matriz);
    exibirMatriz(matriz);

    return 0;
}
