# Fundamentos de programação em C e C++

Portfólio de estudos sobre lógica, memória, estruturas de dados e algoritmos, desenvolvido ao longo de aproximadamente um ano e meio. A sequência apresenta a evolução de funções simples até um projeto de classificação de times.

Comecei essa trajetória aos 21 anos, estudando principalmente C. Os exemplos em C++ ampliam esse aprendizado com métodos em `struct`, construtores e recursos da biblioteca padrão. Cada pasta explica o problema estudado, a implementação e seu estado atual.

## Explore o portfólio

| Etapa | Conteúdo | Aplicação prática |
| --- | --- | --- |
| [01 · Fundamentos](01-fundamentos-da-programacao/README.md) | Funções, condições e laços | Decomposição de problemas numéricos |
| [02 · Vetores e estruturas](02-vetores-e-estruturas/README.md) | Registros, vetores e ponteiros | Cadastros de clientes, funcionários e livros |
| [03 · Ponteiros e strings](03-ponteiros-e-strings/README.md) | Memória dinâmica, arquivos e busca | Processamento de nomes |
| [04 · Listas encadeadas](04-listas-encadeadas/README.md) | Nós, inserções e remoções | Coleção dinâmica de inteiros |
| [05 · Pilhas e filas](05-pilhas-e-filas/README.md) | Políticas LIFO e FIFO | Inversão de uma fila usando uma pilha |
| [06 · Ordenação](06-algoritmos-de-ordenacao/README.md) | Selection, merge e quick sort | Comparação de estratégias de ordenação |
| [07 · Árvores](07-arvores/README.md) | Etapa reservada, ainda sem código | Continuidade planejada dos estudos |
| [08 · Projetos](08-projetos-e-exercicios/README.md) | Arquivos, estatísticas e ordenação | Classificação de times com desempates |

Para conhecer uma aplicação integrada, comece pelo [projeto de classificação](08-projetos-e-exercicios/README.md). Para acompanhar a evolução dos estudos, siga a numeração das pastas.

## Competências trabalhadas

- Decompor problemas em funções com responsabilidades específicas.
- Modelar registros e percorrer coleções de dados.
- Manipular endereços, alocar memória e encadear nós.
- Implementar listas, pilhas e filas.
- Explorar busca binária, ordenação e divisão e conquista.
- Transformar resultados de partidas em estatísticas e uma classificação.

## Como executar

Cada arquivo contém um programa independente com seu próprio `main`. Compile um arquivo por vez. Os comandos usam GCC para C e G++ para C++, disponíveis no `PATH`, e execução pelo PowerShell no Windows.

Na raiz do repositório:

```powershell
gcc -std=c99 -Wall -Wextra 01-fundamentos-da-programacao/funcao10.c -o soma-pares.exe
./soma-pares.exe
```

Informe `2 10`: a soma dos pares do intervalo é `30`.

```powershell
g++ -std=c++11 -Wall -Wextra 05-pilhas-e-filas/pilha-e-fila.cpp -o pilha-fila.exe
./pilha-fila.exe
```

O segundo exemplo imprime os números de `11` a `1`. Em Linux ou macOS, com GCC/G++ disponíveis, os mesmos comandos podem ser usados; a extensão `.exe` é apenas parte do nome escolhido.

As etapas 03, 06 e 08 exigem arquivos de entrada. Seus READMEs explicam a preparação e os formatos.

## Estado do material

Este é um registro de formação, com implementações didáticas em diferentes estágios de maturidade. Há exercícios com erros de compilação ou comportamentos que precisam de revisão; os READMEs locais identificam os principais pontos encontrados na leitura do código.

Os arquivos de nomes e de partidas não estão incluídos. A pasta de árvores ainda não contém implementações. Não há suíte automatizada de testes ou processo único de build.

Os exemplos documentados servem como roteiro de verificação manual. Funcionalidades existentes e propostas de evolução são apresentadas separadamente para tornar o portfólio claro e fiel ao código.
