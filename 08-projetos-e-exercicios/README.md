# 08 · Projetos e exercícios integrados

[Voltar ao portfólio](../README.md) · [Etapa anterior](../07-arvores/README.md)

O projeto [classificacao-de-times.cpp](classificacao-de-times.cpp) aplica os fundamentos em um problema completo: ler partidas, acumular estatísticas de doze times e apresentar uma classificação usando o algoritmo escolhido pelo usuário.

## Regras implementadas

Vitórias valem três pontos; empates, um; derrotas não acrescentam pontos. A `struct Time` guarda nome, pontos, vitórias, empates, derrotas, saldo de gols, gols pró e gols contra.

A classificação usa valores decrescentes, nesta prioridade:

1. Pontos.
2. Vitórias.
3. Saldo de gols.
4. Gols pró.

Não há critério adicional para empate completo. A ordem de times equivalentes pode variar entre algoritmos.

## Organização do código

| Parte | Responsabilidade |
| --- | --- |
| `inicializaTime` | Define o nome e zera as estatísticas |
| `encontraTime` | Localiza a sigla por busca linear |
| `calculaEstatisticas` | Atualiza resultados, pontos e gols dos dois participantes |
| `bubbleSort`, `selectionSort`, `insertionSort`, `mergeSort` | Aplicam os critérios de classificação |
| `imprimeTabela` | Formata as colunas com `setw` |
| `main` | Inicializa os times, lê o arquivo e apresenta o menu |

O vetor contém doze siglas fixas: `CAM`, `CAL`, `ATH`, `DGV`, `AME`, `CRU`, `TOM`, `VNO`, `URT`, `POU`, `CAP` e `UBE`.

## Preparação dos dados

O arquivo de partidas não está incluído. O código usa um caminho absoluto de outra máquina:

```cpp
ifstream arquivo("C:/Users/natsa/OneDrive/Documentos/dados/dados.txt");
```

Para executar localmente, altere essa linha para apontar ao seu arquivo. Uma opção é usar um caminho relativo e executar nesta pasta:

```cpp
ifstream arquivo("dados.txt");
```

Crie `dados.txt` com uma partida por linha, sem cabeçalho ou linhas vazias:

```text
CAM 2x1 CAL
ATH 0x0 DGV
CAM 1x1 ATH
```

O leitor extrai as siglas dos três primeiros e dos três últimos caracteres, e os gols das posições `4` e `6`, contando a partir de zero. Portanto, esse formato exige siglas de três caracteres e placares de um dígito. O separador `x` ocupa uma posição, mas não é validado.

## Compilação e uso

Depois de ajustar o caminho e preparar a entrada, execute nesta pasta, com G++ no `PATH`:

```powershell
g++ -std=c++11 -Wall -Wextra classificacao-de-times.cpp -o classificacao.exe
./classificacao.exe
```

| Opção | Ação |
| --- | --- |
| `1` | Bubble sort e impressão |
| `2` | Selection sort e impressão |
| `3` | Insertion sort e impressão |
| `4` | Merge sort e impressão |
| `5` | Encerrar |

O arquivo é lido uma única vez antes do menu. Escolher outro algoritmo reorganiza os registros já carregados.

## Resultado de referência

Para as três partidas do exemplo, as primeiras posições devem ser:

| Time | Pontos | Vitórias | Empates | Derrotas | Saldo | Gols pró | Gols contra |
| --- | --- | --- | --- | --- | --- | --- | --- |
| CAM | 4 | 1 | 1 | 0 | 1 | 3 | 2 |
| ATH | 2 | 0 | 2 | 0 | 0 | 1 | 1 |
| DGV | 1 | 0 | 1 | 0 | 0 | 0 | 0 |

`CAL` termina com zero ponto, uma derrota, um gol pró, dois contra e saldo `-1`. Fica atrás dos oito times que não jogaram e continuam zerados. O programa imprime os doze registros.

## Competências aplicadas

O projeto combina modelagem com `struct`, passagem por referência, leitura com `ifstream`, extração com `substr` e `stoi`, atualização de registros e comparação por múltiplos critérios. O merge também usa vetores auxiliares com `new[]` e `delete[]`.

Bubble, selection e insertion têm custo quadrático no pior caso em relação ao número de times. Merge tem tempo O(n log n) e espaço auxiliar O(n). O bubble desta versão encerra quando uma rodada não realiza trocas. Não há medição de tempo implementada.

## Estado atual e evolução

- **Arquivo:** o caminho precisa ser configurado e a abertura não é validada. Um arquivo inacessível pode resultar em uma tabela zerada.
- **Formato:** posições fixas não comportam gols de dois dígitos; linhas curtas ou valores inválidos podem gerar exceções.
- **Validação:** siglas desconhecidas não atualizam estatísticas; falhas de leitura do menu não são tratadas.
- **Manutenção:** os critérios de desempate se repetem nos quatro algoritmos. Centralizar a comparação facilitaria mantê-los consistentes.
- **Verificação:** casos automatizados para vitórias, empates e cada critério de desempate ajudariam a verificar a classificação.

Esses pontos orientam a evolução do exercício para uma aplicação mais portátil e verificável.
