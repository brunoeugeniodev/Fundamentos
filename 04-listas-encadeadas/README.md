# 04 · Listas encadeadas

[Voltar ao portfólio](../README.md) · [Etapa anterior](../03-ponteiros-e-strings/README.md) · [Próxima etapa](../05-pilhas-e-filas/README.md)

[atividade-lista.cpp](atividade-lista.cpp) implementa uma lista simplesmente encadeada de inteiros em C++. O exercício mostra como modificar uma coleção dinâmica ajustando ponteiros.

## Representação

Cada `No` contém `valor` e `prox`. A `Lista` mantém `inicio`, `fim` e o contador `n`. O último nó aponta para `NULL`; na lista vazia, ambos os extremos são nulos.

```text
inicio → [valor | prox] → [valor | prox] → [valor | NULL]
                                               ↑
                                              fim
```

As inserções usam `new` e as remoções liberam nós com `delete`.

## Operações

| Método | Comportamento | Tempo |
| --- | --- | --- |
| `inserirInicio` | Adiciona antes do primeiro nó | O(1) |
| `inserirFinal` | Adiciona usando o ponteiro final | O(1) |
| `removerInicio` | Remove o primeiro nó | O(1) |
| `removerFinal` | Percorre a lista até o penúltimo e remove o último | O(n) |
| `imprimir` | Percorre todos os nós | O(n) |
| `removeSegundo` | Remove o nó após o início | O(1) |
| `inserirPenultimo` | Insere antes do último, se houver ao menos dois nós | O(n) |
| `inserirNoFimTamanhoDaLista` | Acrescenta o tamanho atual como valor | O(1) |
| `inserirNumerosDeUmAteN` | Insere de 1 até k no início, invertendo essa sequência | O(k) |
| `removeNNumero` | Se k supera o tamanho, tenta k remoções no início; caso contrário, remove k vezes do final | O(k) no primeiro ramo; até O(k · n) no segundo |

Aqui, `n` é o tamanho inicial da lista e `k` é a quantidade solicitada. Manter `fim` acelera a inserção final, mas não elimina o percurso necessário para descobrir o penúltimo nó.

## Execução e resultado

A partir desta pasta, com G++ no `PATH`:

```powershell
g++ -std=c++11 -Wall -Wextra atividade-lista.cpp -o lista.exe
./lista.exe
```

Não há entrada pelo teclado. O `main` executa uma sequência fixa:

| Etapa | Estado esperado |
| --- | --- |
| Inserções iniciais | `8 → 1 → 5 → 10 → 7 → 3` |
| Inserir 50 antes do último | `8 → 1 → 5 → 10 → 7 → 50 → 3` |
| Remover quatro | `8 → 1 → 5` |
| Remover o segundo | `8 → 5` |
| Acrescentar o tamanho | `8 → 5 → 2` |
| Inserir 1, 2 e 3 no início | `3 → 2 → 1 → 8 → 5 → 2` |
| Inserir 20 antes do último | `3 → 2 → 1 → 8 → 5 → 20 → 2` |

A tabela agrupa as etapas; no terminal, cada valor aparece em uma linha, sem separadores entre as listas.

## Estado atual e evolução

`removeSegundo` não atualiza `fim` quando existem exatamente dois nós. Nesse caso, o ponteiro final referencia memória liberada e uma inserção posterior no final pode acessar memória inválida. A demonstração do `main` não exercita esse caso.

Também falta um destrutor para liberar os nós restantes. Próximos passos incluem corrigir os extremos, definir a política de cópia e verificar operações com zero, um e dois elementos.
