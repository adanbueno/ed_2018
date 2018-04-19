##05_LAB_PILHA

#Objetivo:

• Criar o labirinto usando pilha

Bom como foi abordado em sala, o professor ensinou como fazia a construção do labirinto por meio de recursão e também como percorrer de um ponto para outro.
O que foi passado para casa era refazer o código pra treinar e fazer a construção do labirinto com pilha.
No principio estava meio perdido em como começar a resolver, mas assistir as vídeos aulas o professor fazendo todo o percurso com pilha dai tirei uma base para resolver.
Me juntei com meu amigo Junior Jeronimo e começamos a fazer passo a passo seguindo a logica.
Iniciando a pilha de pares no ponto (1,1) ai ele fura o primeiro elemento e coloca dentro da pilha,
Depois ele entra na condição enquanto a pilha não estiver vazia faça, criei a variável topo que recebe o par de topo da pilha,
depois ele pega os vizinhos do topo através da função getneib, que podem ser furados e tbm so posso pegar vizinhos que tem no máximo um lado aberto. 
Em seguida tem outra condição se existe pelo menos um vizinho valido pra furar
Ele seleciona aleatoriamente um desses vizinhos então ele fura e empilha, 
e não existe ele desempilha o topo. Seguindo essa logica ficou um pouco mais fácil de fazermos, deu bastante trabalho mas no final deu certo, um ótimo resultado.

