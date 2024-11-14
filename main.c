#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "calculadora.h"

#define TAM_MAX 200

int main() {

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
    Expressao E[TAM_MAX];
    
    for (int i = 0; i < numExpressoes; i++) {
        strcpy(E[i].posFixa, expressoes[i]);    

        E[i].Valor = getValor(E[i].posFixa);
        char *infixa = getFormaInFixa(E[i].posFixa);
        if (infixa == NULL) {
            printf("Erro ao converter para forma infixa para a expressão %d.\n", i + 1);
            continue;
        }
        strcpy(E[i].inFixa, infixa);
        
        printf("Expressao %d:\n", i + 1);
        printf("Pos-Fixa: %s\n", E[i].posFixa);
        printf("In-Fixa: %s\n", E[i].inFixa);
        printf("Total: %.2f\n\n", E[i].Valor);

        free(infixa);
    }

    return 0;
}
