# 05 · Pilhas e filas

[Voltar ao portfólio](../README.md) · [Etapa anterior](../04-listas-encadeadas/README.md) · [Próxima etapa](../06-algoritmos-de-ordenacao/README.md)

[pilha-e-fila.cpp](pilha-e-fila.cpp) implementa duas estruturas encadeadas em C++ e as combina para inverter uma fila. O exemplo demonstra como a política de acesso aos elementos determina o resultado de uma transformação.

## Estruturas implementadas

Ambas usam `No`, formado por um inteiro e um ponteiro para o próximo nó. Inserções alocam com `new` e remoções liberam com `delete`.

| Estrutura | Regra | Estado | Métodos |
| --- | --- | --- | --- |
| `Fila` | FIFO: primeiro a entrar, primeiro a sair | `inicio`, `fim`, `n` | `enfileirar`, `desenfileirar`, `frente`, `imprimir`, `informarN` |
| `Pilha` | LIFO: último a entrar, primeiro a sair | `topo`, `n` | `inserir`, `remover`, `topoPilha`, `informarN` |

Na fila, elementos entram pelo final e saem pelo início. Na pilha, inserções e remoções acontecem no topo. Essas operações e as consultas de tamanho são O(1); imprimir a fila custa O(n).

## Algoritmo de inversão

1. Enfileirar os números de 1 a 11.
2. Transferir cada valor da frente da fila para o topo da pilha, removendo o nó da fila.
3. Transferir cada valor do topo da pilha para o final da fila, removendo o nó da pilha.
4. Imprimir a fila resultante.

```text
Fila inicial, da frente ao final: 1 2 3 ... 11
Pilha, do topo à base:           11 ... 3 2 1
Fila final, da frente ao final:  11 ... 3 2 1
```

A inversão tem tempo O(n) e espaço auxiliar O(n) para a pilha.

## Execução de referência

A partir desta pasta, com G++ no `PATH`:

```powershell
g++ -std=c++11 -Wall -Wextra pilha-e-fila.cpp -o pilha-fila.exe
./pilha-fila.exe
```

Não é necessário fornecer entrada ou arquivos. Saída esperada:

```text
11 10 9 8 7 6 5 4 3 2 1
```

Para explorar o comportamento, altere as inserções no `main`. Uma fila unitária mantém seu valor e uma fila vazia não realiza transferências.

## Estado atual e evolução

As remoções verificam estruturas vazias e ajustam os ponteiros ao retirar o último elemento. Entretanto, `frente()` e `topoPilha()` retornam zero quando vazias: sem consultar o tamanho, não é possível distinguir esse caso de um elemento com valor zero.

Faltam destrutores para liberar nós remanescentes. A demonstração termina com a pilha vazia e onze nós na fila. Limpeza automática, sinalização explícita de consulta vazia e uma política de cópia são próximos passos.
