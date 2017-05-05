# PathCounter

Trabalho de Implementação 2

CI065 / CI755 - Algoritmos e Teoria dos Grafos

Bruno Freitas Serbena 20151343
Michel Melo de Souza 2015

O algoritmo criado pelo grupo funciona da seguinte maneira:

Existe uma classe chamada Path que armazena nodo e atributo;

O algoritmo percorre os nodos do grafo pegando todos que tem atributo (sumidouros), empilha eles e seus atributos numa pilha de "Path"s;

Enquanto a pilha não for vazia:
	Retira o primeiro Path dela, "X";
	O algoritmo cria uma lista de Paths, cada path "L", sendo L.nodo os nodos pais de X.nodo, e L.atributo = X.atributo. Coloca esses Paths em uma lista temporária; //(quando o nodo não tem pais não se coloca nada, para condiçao de saída do laço é necessário não ter ciclos)
		Percorre essa lista com Paths "L" e incrementa + 1 no L.atributo de cada L.nodo, eles recebem X.atributo valendo 1 se ele não já existir;
	Cada Path da lista, os "L"s, são colocado na pilha principal;
	loop;

Imprime o resultado:
Para cada nodo imprime seu nome e os atributos que tem valor maior que 0, em seguida imprime as arestas que saem do nodo;
