# 01 · Fundamentos da programação

[Voltar ao portfólio](../README.md) · [Próxima etapa](../02-vetores-e-estruturas/README.md)

Onze exercícios em C introduzem a transformação de um enunciado em entrada, processamento e saída. A sequência trabalha funções, parâmetros, retorno, decisões e repetições antes de avançar para coleções.

## Mapa dos exercícios

| Arquivo | Objetivo | Conceito central |
| --- | --- | --- |
| [funcao1.c](funcao1.c) | Calcular o discriminante `b² - 4ac`; possui erro de nomes de variáveis | Parâmetros e escopo |
| [funcao2.c](funcao2.c) | Identificar o maior de dois inteiros; falta retornar o resultado | Condição e retorno |
| [funcao3.c](funcao3.c) | Imprimir de `1` até o valor informado, sem separadores | Laço e função `void` |
| [funcao4.c](funcao4.c) | Receber três inteiros e imprimir os pares, sem separadores | Resto da divisão |
| [funcao5.c](funcao5.c) | Somar uma progressão aritmética a partir do primeiro termo, último e quantidade | Expressão aritmética |
| [funcao6.c](funcao6.c) | Retornar `1` para dimensões iguais e `0` para diferentes | Comparação |
| [funcao7.c](funcao7.c) | Somar o maior e o menor de três valores | Condições compostas |
| [funcao8.c](funcao8.c) | Calcular juros simples por `c * m * t` | `double` e formatação |
| [funcao9.c](funcao9.c) | Estudar raízes de uma equação quadrática; a função de impressão não é chamada | Composição de funções e `sqrt` |
| [funcao10.c](funcao10.c) | Somar os pares de um intervalo inclusivo | Acumulador |
| [funcao11.c](funcao11.c) | Listar divisores de um inteiro positivo | Divisibilidade e apresentação |

## O que está sendo construído

Os primeiros exemplos separam cálculos da função `main`. Em seguida, condições filtram resultados e laços percorrem sequências. Juros e raízes introduzem números reais e mostram como os tipos influenciam os cálculos.

Apesar do nome `enesimo`, a função de `funcao5.c` calcula a soma dos termos de uma progressão. Em `funcao8.c`, a taxa é utilizada diretamente: 2% deve ser informado como `0.02`.

## Execução de referência

A partir desta pasta, com GCC no `PATH`:

```powershell
gcc -std=c99 -Wall -Wextra funcao10.c -o soma-pares.exe
./soma-pares.exe
```

Entrada:

```text
2 10
```

Saída esperada:

```text
30
```

O resultado corresponde a `2 + 4 + 6 + 8 + 10`. Outros casos úteis são `3 3` → `0` e `4 4` → `4`. Se o limite inicial superar o final, o laço não executa e a soma permanece zero.

## Estado atual e evolução

- `funcao1.c` usa `a`, `b` e `c` dentro de uma função cujos parâmetros são `x`, `y` e `z`, impedindo a compilação.
- `funcao2.c` calcula `maior`, mas não faz `return maior`.
- `funcao7.c` usa comparações estritas que não cobrem corretamente todos os empates.
- `funcao9.c` contém apenas `impressaoDeRaiz;` no `main`. Também converte coeficientes reais para inteiros no discriminante, calcula a raiz antes de verificar seu sinal e não trata `a == 0`. Em ambientes que exigem ligação explícita com a biblioteca matemática, esse arquivo precisa de `-lm` no final do comando de compilação.
- Os programas assumem entradas válidas. Validação de leitura, domínio numérico e limites dos tipos são próximos passos.

Essas pendências também permitem estudar os diagnósticos do compilador e comparar a intenção de uma função com seu comportamento efetivo.
