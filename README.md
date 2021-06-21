# push_swap

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
