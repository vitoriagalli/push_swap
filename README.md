# PUSH_SWAP

![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-black)


## Introduction


#### Game rules

The game is composed of 2 stacks named A and B.
The goal is to sort in ascending order the stack A with the minimum possible number of operations.
To do this you have the following operations at your disposal

operation | action |
---|------|
`sa` | swap a - swap the first 2 elements at the top of stack_a |
`sb` | swap b - swap the first 2 elements at the top of stack_b |
`ss` | sa and sb at the same time |
`pa` | push a - take the first element at the top of b and put it at the top of a |
`pb` | push b - take the first element at the top of a and put it at the top of b |
`ra` | rotate a - shift up all elements of stack_a by 1. The first element becomes the last one |
`rb` | rotate b - shift up all elements of stack_b by 1. The first element becomes the last one |
`rr` | ra and rb at the same time |
`rra` |  reverse rotate a - shift down all elements of stack_a by 1. The last element becomes the first one |
`rrb` |  reverse rotate b - shift down all elements of stack_b by 1. The last element becomes the first one |
`rrr` | rra and rrb at the same time |


## Usage

#### Build Instructions

```bash
$ git clone https://github.com/vscabell/push_swap
$ cd push_swap
$ make
```

#### Run the commands

##### Mandatory

The `push_swap` program must display the smallest list of instructions possible to sort the stack A

##### Bonus

The `checker` program will read instructions on the standard input, each instruction
will be followed by ’\n’. When EOF is triggered, the program will execute them and display if the resulting list is sorted

```bash
$ make
$ ./push_swap 9 -1 4 -7 11
...
$ make bonus
$ ./checker 9 -1 4 -7 11
$ ./checker -v 9 -1 4 -7 11
...
$ make test
```











https://github.com/VBrazhnik/Push_swap/wiki/Algorithm

ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l

make fclean; mkdir -p .objs/stack ; make



INDEXACAO
o indice 0 será atribuído ao menor numero
o maior recebera o index de (lenght - 1)



MARCAÇÃO (dois modos)

maior que -
by index -

fazer os dois metodos de mercação e no fim comparar e usar o que apresenta melhor resultado

durante a marcação, decide-se quais elementos serão mantidos na pilha A
os outros serão movidos para a pilha B

descobrir o markup head, aquele elemento que manterá o maior numero de elementos na pilha A
caso dois elementos tenham o mesmo resultado, o markup_head sera aquele com indice menor

MAIOR QUE (compara índice)

a partir do markup_head cada elemento deve ser maior que o anterior.
(todos os elementos até o markup_head recebem marcação de falso, mesmo que maiores)
os elementos não satisfeitos (falso) vão para B

markup_head = -1 por exemplo
exemplo	index	manter em A
-2100	0			f
220010	5			f
-1		1			v
7		2			v
121		4			v
21		3			f


BY INDEX (compara indice)

a partir do markup_head o indice deve ser maior em 1 do que o indice do elemento anterior marcado como verdadeiro
os elementos não satisfeitos (falso) vão para B


markup_head = -2100 por exemplo
exemplo	index	manter em A
-2100	0			v
220010	5			f
-1		1			v
7		2			v
121		4			f
21		3			v

enquanto stack A tem elementos marcados como falso, mantenha na stack A
	se SA é necessário, atualize o markup
	se a cabeça de A é falsa, jogue para b PB
	else RA

como checar se SA é necessário?
ver depois


DA PILHA B PARA A

enquanto B não esta vazia
	escolher qual elemento mover para A
	mova stack a e b e pretare elas para PA com o elemento escolhido
	performe PA

como escolher?
calcular quantos comandos são necessários para mover o elemento da pilha B para o topo e o mesmo para mover o elemento adequado na pilha A

deve-se calcular esse valor para cada elemento da pilha B e em seguida escolher o elemento com o menor valor calculado

ALINHE A



"5",	7		v
"1",	5			v
"3",	6			v
"-99",	0
"-3",	3
"57",	9
"9",	8		v
"0",	4
"-33",	1
"-11",	2
"777",	11
"99"	10
