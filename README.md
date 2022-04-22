# Tree Benchmark

Compara experimentalmente duas estruturas de dados

* Lista/Árvore ou Árvore/Árvore

Para compilar com o gcc:
```
gcc dataGen.c abp.c -o trab
```


Para rodar com o gcc:
```
./trab
```

### 1. Geração de dados

- Estrutura de Dados para um campo numérico inteiro
- Função: gerar dois conjuntos de dados, com valores únicos: dados ordenados e dados não ordenados.
- Quantidade de dados: 5.000, 10.000, 100.000, 1.000.000 (?)

### 2. Operações

- Carregar base de dados
- Inserir dados na estrutura
- Consultar dados
    - Ordenados: primeiro, meio e último; 
    - Aleatório: 10 valores
        - Média de tempo de cada consulta
        - Média de tempo das 10 consultas

### Critérios de Comparação
* Tempo
* Número de comparações (if, while, ==, >, <, ...)


---

Universidade Federal do Rio Grande do Sul, Instituto de Informática

INF01203 (Turma C) - Estruturas de Dados 2021/2 (Renata Galante)

Leonardo Azzi Martins, 00323721