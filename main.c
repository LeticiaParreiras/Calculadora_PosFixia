#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "calculadora.h"

#define TAM_MAX 100

int main() {
    
    // Declara e inicializa as expressões a serem testadas
    char *expressoes[] = {
        "9 5 2 8 * 4 + * +",
        "2 3 + log 5 /",
        "45 60 + 30 cos *",
        "10 0 /",
        "-4 raiz",
        "100.5 50.25 - 2.5 /",
        "0.15 -0.20 + 3 *",
        "9 raiz 5 - 60 cos *",
    };

    int numExpressoes = sizeof(expressoes) / sizeof(expressoes[0]);

    // Estrutura para armazenar os resultados
    Expressao E[TAM_MAX];
    
    // Loop para processar cada expressão
    for (int i = 0; i < numExpressoes; i++) {
        strcpy(E[i].posFixa, expressoes[i]);    // Copiando a expressão pos-fixa para a estrutura

        // Calcula o valor da expressão
        E[i].Valor = getValor(E[i].posFixa);

        // Converte para a forma infixa
        char *infixa = getFormaInFixa(E[i].posFixa);
        if (infixa == NULL) {
            printf("Erro ao converter para forma infixa para a expressão %d.\n", i + 1);
            continue;
        }
        strcpy(E[i].inFixa, infixa);
        
        // Exibe o resultado
        printf("Expressao %d:\n", i + 1);
        printf("Pos-Fixa: %s\n", E[i].posFixa);
        printf("In-Fixa: %s\n", E[i].inFixa);
        printf("Total: %.2f\n\n", E[i].Valor);

        // Libera a memória alocada
        free(infixa);
    }

    return 0;
}
