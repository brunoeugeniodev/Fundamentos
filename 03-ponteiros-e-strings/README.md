# 03 · Ponteiros e strings

[Voltar ao portfólio](../README.md) · [Etapa anterior](../02-vetores-e-estruturas/README.md) · [Próxima etapa](../04-listas-encadeadas/README.md)

Os exercícios exploram textos em C: cada nome é alocado dinamicamente e seu endereço fica em um vetor de ponteiros. Os programas leem arquivos, ordenam nomes e buscam correspondências por prefixo.

## Mapa dos arquivos

| Arquivo | O que faz | Entrada |
| --- | --- | --- |
| [bubble-sort-strings.c](bubble-sort-strings.c) | Ordena por trocas entre vizinhos | `nomes2.txt` |
| [insertion-sort-strings.c](insertion-sort-strings.c) | Insere cada nome na parte já ordenada | `nomes2.txt` |
| [exercicio-strings-1.c](exercicio-strings-1.c) | Menu com bubble, selection, insertion, merge e quick sort; opção `6` encerra | `nomes2.txt` |
| [busca-strings.c](busca-strings.c) | Quick sort seguido de busca binária por prefixo e listagem das correspondências | `nomes.txt` e prefixo pelo terminal |
| [exercicio-strings.c](exercicio-strings.c) | Repete a implementação de busca presente em `busca-strings.c` | `nomes.txt` e prefixo pelo terminal |

## Fluxo de processamento

1. `fopen` abre o arquivo e `fgets` lê o texto.
2. `malloc(strlen(buffer) + 1)` reserva espaço para o conteúdo e o terminador nulo.
3. `strcpy` copia o texto e o vetor guarda seu endereço.
4. A ordenação reorganiza ponteiros, evitando copiar todo o texto a cada troca.
5. O programa imprime os resultados e libera as strings com `free`.

Há espaço para até 101 entradas. Nos programas com `nomes2.txt`, o buffer tem 20 bytes: use nomes ASCII de até 18 caracteres, um por linha, reservando espaço para a quebra de linha e o terminador. Linhas maiores podem ser divididas entre leituras. Nos exemplos de busca, o buffer tem 100 bytes e a quebra de linha é removida.

## Preparação e execução

Os arquivos de nomes não estão incluídos. Crie `nomes2.txt` nesta pasta com o conteúdo abaixo e uma quebra de linha após o último nome:

```text
carla
ana
bruno
```

A partir desta pasta, com GCC no `PATH`:

```powershell
gcc -std=c99 -Wall -Wextra bubble-sort-strings.c -o bubble.exe
./bubble.exe
```

Saída esperada:

```text
ana
bruno
carla
```

O arquivo é procurado no diretório de execução. Para estudar a busca, prepare `nomes.txt` com `ana`, `andre` e `bruno`, um por linha, e informe `an`: a intenção é listar os dois primeiros. Os programas de busca precisam das revisões descritas abaixo.

## Decisões e limitações

- As ordenações usam `strcmp`, sensível à caixa e sem regras linguísticas para acentos.
- A busca ignora maiúsculas e minúsculas, mas o quick sort não. A diferença entre os critérios pode invalidar a busca binária em dados com caixa misturada.
- `strncasecmp` não pertence ao C padrão. Falta sua declaração POSIX usual em `<strings.h>`, e a disponibilidade depende do ambiente; os exemplos de busca exigem revisão de portabilidade.
- As alocações com `malloc` não verificam falhas.
- No menu, cada algoritmo recebe o vetor deixado pelo anterior. Uma comparação de desempenho sobre a mesma entrada exige recarregar ou copiar os dados.

A [etapa 06](../06-algoritmos-de-ordenacao/README.md) complementa o estudo com outras implementações isoladas e análise de complexidade.
