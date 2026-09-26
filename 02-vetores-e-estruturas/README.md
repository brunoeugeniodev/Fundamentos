# 02 · Vetores e estruturas

[Voltar ao portfólio](../README.md) · [Etapa anterior](../01-fundamentos-da-programacao/README.md) · [Próxima etapa](../03-ponteiros-e-strings/README.md)

Esta etapa passa de valores isolados para registros e coleções. Os programas usam C++ para reunir dados e métodos em `struct`, organizar menus e percorrer vetores, mantendo principalmente a entrada e saída com `scanf` e `printf`.

## Mapa dos arquivos

| Arquivo | O que implementa | Conceitos |
| --- | --- | --- |
| [atv01-clientes.cpp](atv01-clientes.cpp) | Cadastro e listagem de até 50 clientes, com nascimento, sexo e cálculo de idade | Composição de `Cliente` e `Data` |
| [atv02-funcionarios.cpp](atv02-funcionarios.cpp) | Cadastro, listagem, média salarial e maior salário líquido | Agregação e busca por máximo |
| [atv03-conjuntos.cpp](atv03-conjuntos.cpp) | Criação, leitura, impressão, união e interseção | Vetores de até 20 valores e `std::set` |
| [atv04.cpp](atv04.cpp) | Área superficial e volume de esfera a partir de dois valores de entrada | Ponteiros e aritmética |
| [atv05.cpp](atv05.cpp) | Mínimo e máximo de dez inteiros, devolvidos por ponteiros | Parâmetros de saída |
| [tad-biblioteca.cpp](tad-biblioteca.cpp) | Cadastro de até dez livros, listagem e consulta ao livro com mais páginas | Construtor e tipo abstrato de dados |

## Organização dos dados

Nos cadastros, um vetor guarda os registros e um contador indica quantas posições estão ocupadas. Métodos de leitura, cadastro e impressão distribuem as responsabilidades. Os dados permanecem apenas na memória durante a execução.

O salário líquido é calculado por `salarioBase + beneficios - descontos`. Na união dos conjuntos, `std::set` elimina duplicatas e mantém os valores ordenados. A interseção usa laços aninhados e pode imprimir valores repetidos.

Os exercícios de ponteiros mostram como uma função pode acessar e modificar variáveis do chamador, preparando a transição para a etapa seguinte.

## Execução de referência: biblioteca

A partir desta pasta, com G++ no `PATH`:

```powershell
g++ -std=c++11 -Wall -Wextra tad-biblioteca.cpp -o biblioteca.exe
./biblioteca.exe
```

1. Escolha `1` e cadastre `Algoritmos`, autor `Autor Exemplo`, com `200` páginas.
2. Escolha `1` e cadastre `Estruturas de Dados`, autor `Outro Autor`, com `350` páginas.
3. Escolha `2` para listar os dois registros.
4. Escolha `3`: o livro com mais páginas deve ser `Estruturas de Dados`.
5. Escolha `4` para encerrar.

A biblioteca aceita espaços no título e no autor. Clientes e funcionários usam `%s` nos campos textuais, aceitando apenas uma palavra por campo.

## Estado atual e evolução

| Arquivo | Ponto identificado no código |
| --- | --- |
| `atv01-clientes.cpp` | `setarDataAtual()` não é chamada antes do cálculo da idade, deixando campos sem inicialização |
| `atv02-funcionarios.cpp` | A opção do menu não é inicializada; `qtdFunc > 10` permite ultrapassar o vetor; a busca do maior salário pressupõe algum valor positivo |
| `atv03-conjuntos.cpp` | É necessário criar o conjunto antes de usá-lo; leituras repetidas acumulam `n` sem ajustar a posição de escrita |
| `atv04.cpp` | `4/3` faz divisão inteira no volume; endereços são impressos com `%d` em vez de `%p` |
| `atv05.cpp` | A atribuição a `vetor[10]` escreve fora dos índices válidos, de `0` a `9` |
| `tad-biblioteca.cpp` | Se nenhum livro tiver páginas acima de zero, a consulta ao maior mantém uma posição inválida |

Validar o tamanho dos textos, os resultados das leituras e os valores informados é uma evolução comum aos cadastros.
