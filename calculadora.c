#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define TAM_MAX 200

typedef struct Pilha
{
    int Topo;
    float Valores[TAM_MAX];
    char Expressao[TAM_MAX][TAM_MAX];
} Pilha;

int OperadorB(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int OperadorA(char *token) {
    return (strcmp(token, "raiz") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tg") == 0 || strcmp(token, "log") == 0);
}

double ConversorRad(double graus) {
    return graus * 3.14 / 180.0;
}

float getValor(char *Str) {
    Pilha P;
    P.Topo = -1;
    char strcopia[TAM_MAX];
    strcpy(strcopia, Str);
    char *token = strtok(strcopia, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])) || token[0] == '.') {
            P.Topo++;
            P.Valores[P.Topo] = atof(token);
        } else if (OperadorB(token[0])) {
            float op2 = P.Valores[P.Topo--];
            float op1 = P.Valores[P.Topo];

            switch (token[0]) {
                case '+':
                    P.Valores[P.Topo] = op1 + op2;
                    break;
                case '-':
                    P.Valores[P.Topo] = op1 - op2;
                    break;
                case '*':
                    P.Valores[P.Topo] = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("\nERRO: Nao e possivel dividir por zero\n");
                        return(-1);
                    }
                    P.Valores[P.Topo] = op1 / op2;
                    break;
                case '^':
                    P.Valores[P.Topo] = pow(op1, op2);
                    break;
                default:
                    break;
            }
        } else if (OperadorA(token)) {
            float op = P.Valores[P.Topo];

            if (strcmp(token, "raiz") == 0) {
                if (op < 0) {
                    printf("\nERRO: Nao e possivel calcular raiz negativa\n");
                    return(-1);
                }
                P.Valores[P.Topo] = sqrt(op);
            } else if (strcmp(token, "sen") == 0) {
                P.Valores[P.Topo] = sin(ConversorRad(op));
            } else if (strcmp(token, "cos") == 0) {
                P.Valores[P.Topo] = cos(ConversorRad(op));
            } else if (strcmp(token, "tg") == 0) {
                P.Valores[P.Topo] = tan(ConversorRad(op));
            } else if (strcmp(token, "log") == 0) {
                if(op <= 0){
                    printf("\nERRO: Para calcular log precisa ser maior que zero");
                    return(-1);
                }
                P.Valores[P.Topo] = log10(op);
            }
        }else{
            printf("\nERRO: Operador invalido\n");
            return(-1);
        }
        token = strtok(NULL, " ");
    }
    return P.Valores[P.Topo];
}

char *getFormaInFixa(char *Str) {
    Pilha P;
    P.Topo = -1;
    char strcopia[TAM_MAX];
    strcpy(strcopia, Str);
    char *token = strtok(strcopia, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])) || token[0] == '.') {
            P.Topo++;
            sprintf(P.Expressao[P.Topo], "%s", token);
            
        } else if (OperadorB(token[0])) {
            float op2 = P.Valores[P.Topo--];
            float op1 = P.Valores[P.Topo];
            char SubExp[TAM_MAX];
            sprintf(SubExp, "(%s %s %s)", P.Expressao[P.Topo], token, P.Expressao[P.Topo + 1]);
            strcpy(P.Expressao[P.Topo], SubExp);
        } else if (OperadorA(token)) {
            float op = P.Valores[P.Topo];
            char SubExp[TAM_MAX];
            sprintf(SubExp, "%s(%s)", token, P.Expressao[P.Topo]);
            strcpy(P.Expressao[P.Topo], SubExp);
        }
        token = strtok(NULL, " ");
    }
    char *resultado = malloc(strlen(P.Expressao[P.Topo]) + 1);
    if (resultado == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(resultado, P.Expressao[P.Topo]);
    return resultado;
}