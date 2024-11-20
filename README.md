# Calculadora Pós-Fixada

## Introdução

Este repositório contém a implementação de uma calculadora que avalia expressões matemáticas em **notação pós-fixada** (notação polonesa reversa) e converte essas expressões para a **notação infixa** correspondente. 

A notação pós-fixada elimina a necessidade de parênteses para definir a ordem das operações, o que simplifica o cálculo e a manipulação de expressões matemáticas.

Repositório: [Calculadora_PosFixia](https://github.com/LeticiaParreiras/Calculadora_PosFixia)

---

## Implementação

### Estrutura de Dados Utilizada

**Pilha:**  
A estrutura de pilha é utilizada para armazenar valores intermediários e subexpressões durante o processamento da expressão. Os principais elementos da pilha incluem:
- **Valores:** Array para armazenar números.
- **Expressão:** Array bidimensional para armazenar subexpressões em strings.
- **Topo:** Índice que aponta para o elemento mais recente.

---

### Funções

#### OperadorB e OperadorA
Identificam operadores e funções matemáticas:
- **OperadorB:** Reconhece operadores binários (`+`, `-`, `*`, `/`, `^`).
- **OperadorA:** Reconhece funções como `raiz`, `sen`, `cos`, `tg` e `log`.

#### ConversorRad
Converte valores de graus para radianos, necessários para cálculos trigonométricos.

#### getValor
Avalia expressões em notação pós-fixada:
1. Divide a string em tokens.
2. Verifica se o token é número ou operador.
3. Realiza operações binárias (com dois operandos) ou unárias (com um operando).
4. Retorna o valor final como resultado.

#### getFormaInFixa
Converte uma expressão pós-fixada para a notação infixa:
1. Empilha subexpressões como strings.
2. Combina subexpressões para formar expressões infixas com parênteses.
3. Retorna a expressão final em formato infixo.

#### main
1. Processa várias expressões pós-fixadas.
2. Usa `getValor` para calcular o resultado e `getFormaInFixa` para obter a notação infixa.
3. Exibe os resultados na tela.

---

## Características e Funcionalidades

- **Suporte a Operadores e Funções Matemáticas:**
  - Operações básicas (`+`, `-`, `*`, `/`, `^`).
  - Funções trigonométricas (`sen`, `cos`, `tg`) e logarítmicas.
  - Conversão entre graus e radianos.

- **Suporte a Decimais e Números Negativos:**
  - Permite cálculos complexos com precisão.

- **Tratamento de Erros:**
  - Verifica condições como divisão por zero e operações inválidas.

---

## Limitações

1. **Tamanho da Pilha:**  
   Expressões muito grandes podem exceder o tamanho máximo da pilha.
   
2. **Precisão Numérica:**  
   Atualmente utiliza `float`, o que pode limitar a precisão com números muito grandes ou pequenos. O uso de `double` é recomendado para maior precisão.

---
