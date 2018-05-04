##06_Lista_Ligada

#Objetivo:

• 06_lista_ligada:

• Completar os métodos pra lista ligada 

Bom como foi abordado em sala o professor passou conteudos de lista encadeadas
assim como construtores e destrutores e diversos exemplos de como ultilizar.
Em sala, a partir do que foi passado começamos a fazer uma lista ligada
com varias funções para serem implementadas, como o push front, pop front,
push back pop back entre outros. A atividade pra casa foi justamente fazer o
metodo recursivo ou o interativo dependendo do que ja estivesse feito.
Mais uma vez eu e meu amigo Junior Jeronimo nos reunimos para fazer essa
atividade, fazendo uma por uma pra entender o que se acontece no codigo.
Primeiro assisti algumas aulas pra ajudar a entender e refiz o codigo algumas
vezes para entender o metodo interativo e recursivo de algumas funções.
Começando pelo deletaTudo interativo, pra explicar resumidamente ele é uma função void que entra com tipo Node e ponteiro node, no começo da função criei
um ponteiro aux pra receber o nullptr, em seguida ele entra no laço pra fazer
a condição de parada, geralmente todas as funções interativa tem que fazer
esse processo. Fiz um while e a condição que enquanto o node for diferente de 
nullptr ele faz. O que acontece é que o aux vai guardar a referencia para o proximo elemento, e em seguida usa o delete para deletar o node pra liberar
memoria, e por ultimo o node vai receber o aux que ja vai apontar pro proximo.
O metodo recursivo é bem mais fácil, porque fiz a condição de parada pra
retornar caso o node seja igual ao nullptr, se ele nao cair nessa condição
ele chama a função para o proximo elemento da lista.
O proximo a ser feito foi push_back interativo que tivemos que consertar ele,
e fazer ele o recursivo, a ideia é a mesma do que o professor deu em sala
o primeiro passo é sempre fazer primeiro a chamada de parada.
As funções que deram mais trabalho a fazer e demorou bastante foi a do remover
interativo e a do inserir ordenado recursivo, esses tive que pedir ajuda
e quebrar muito a cabeça porque no remove tive que ter 3 condições dentro do 
laço, e a do inserir ordenado, estava esquecendo de usar um contador.
Por ultimo de acordo com as ultimas aulas de serialize e do arranca rabo
tinhamos que implementar essas funções interativo e recursivo que foi um pouco mais complicado para se resolver, mas depois de uns dias e tirando duvidas com uns amigos, conseguimos implementar cada um delas

