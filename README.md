# Emparelhamento

#### TAG2-2019

<i>Trabalho 1 da matéria de Teoria e Aplicação de Grafos, segundo semestre de 2019, Universidade de Brasília - UnB</i>

Alunos:

- Yuri Crystian Ribeiro e Silva, 18/0029479,  yuricrystian@hotmail.com\
- Luis Filipe Siqueira Ribeiro,  18/0053906,  luisfilipesrct@gmail.com

----------------------------------------------------------------------
<b>COMPILAÇÃO E EXECUÇÃO</b>

Para compilar o programa basta, pelo terminal aberto no diretório onde o programa se encontra, executar o seguinte comando:
```      
make
```
          
Para executar o programa, execute o comando
```
make run
```

Caso o programa não tenha sido compilado, o comando acima irá compilá-lo e executá-lo respectivamente.

O comando
```
make clean
```
remove todos os objetos criados pela compilação e o executável.

A saída do programa é exibida no terminal.

Caso o usuário não possua Makefile instalado, a compilação pode ser feita da seguinte forma:
```
g++ main.cpp graph.cpp node_escola.cpp node_professor.cpp -o emparelha
```
E a execução:
```
./emparelha
```
