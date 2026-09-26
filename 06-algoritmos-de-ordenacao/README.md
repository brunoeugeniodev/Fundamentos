# 06 · Algoritmos de ordenação

[Voltar ao portfólio](../README.md) · [Etapa anterior](../05-pilhas-e-filas/README.md) · [Próxima etapa](../07-arvores/README.md)

Três programas em C ordenam nomes usando a mesma representação por ponteiros e o mesmo formato de entrada. O objetivo é estudar como diferentes estratégias resolvem o problema e quais custos apresentam.

## Implementações

| Arquivo | Estratégia |
| --- | --- |
| [selection-sort-strings.c](selection-sort-strings.c) | Compara cada posição com as seguintes e troca imediatamente quando encontra um nome menor; difere da seleção clássica com uma única troca por rodada |
| [merge-sort-strings.c](merge-sort-strings.c) | Divide o intervalo recursivamente e intercala metades ordenadas em um vetor temporário |
| [quick-sort-strings.c](quick-sort-strings.c) | Usa o último elemento como pivô e ordena recursivamente as partições |

Bubble e insertion estão na [etapa 03](../03-ponteiros-e-strings/README.md), junto de um menu que reúne os cinco algoritmos.

## Comparação de complexidade

A tabela descreve as implementações do repositório. Considera `n` nomes e cada comparação como uma operação unitária. Para nomes de comprimento máximo `L`, uma comparação com `strcmp` pode custar O(L).

| Algoritmo | Melhor caso | Caso médio | Pior caso | Espaço auxiliar |
| --- | --- | --- | --- | --- |
| Bubble da etapa 03 | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion da etapa 03 | O(n) | O(n²) | O(n²) | O(1) |
| Selection por trocas | O(n²) | O(n²) | O(n²) | O(1) |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) em média; O(n) no pior caso |

O bubble de strings não encerra antecipadamente quando não há trocas. O espaço do quick inclui a pilha de recursão, embora suas trocas usem espaço constante. A memória dos nomes carregados não está incluída na coluna de espaço auxiliar.

No merge, empates escolhem primeiro a metade direita, portanto a implementação não preserva estabilidade. No quick, entradas ordenadas ou com muitos valores iguais podem gerar partições desequilibradas.

## Preparação e execução

Os três programas procuram `nomes2.txt` no diretório de execução. O arquivo não está incluído. Crie-o nesta pasta, com um nome por linha e uma quebra de linha após o último:

```text
carla
ana
bruno
```

Use até 101 nomes e, para o buffer de 20 bytes, nomes ASCII de até 18 caracteres, reservando espaço para a quebra de linha e o terminador.

A partir desta pasta, com GCC no `PATH`:

```powershell
gcc -std=c99 -Wall -Wextra merge-sort-strings.c -o merge.exe
./merge.exe
```

Após o cabeçalho de ordenação, a saída deve listar:

```text
ana
bruno
carla
```

Para as outras versões, substitua o arquivo-fonte e o nome do executável no comando. Os programas carregam as strings, ordenam seus ponteiros, imprimem e liberam a memória.

## Estado atual e evolução

`strcmp` diferencia maiúsculas de minúsculas e não aplica regras linguísticas de acentuação. O merge usa um vetor de tamanho variável, recurso de C99 que exige suporte do compilador. As alocações não verificam falhas de `malloc`.

Um roteiro de comparação é usar a mesma coleção aleatória, crescente, decrescente e com repetições. Não há medições de desempenho implementadas: os custos da tabela são análises dos algoritmos. Contar comparações e trocas e ampliar a leitura de linhas são possíveis evoluções.
