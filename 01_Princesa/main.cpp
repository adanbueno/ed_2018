#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

void rodar(list<int> &lista);
void mostrar(list<int> &lista);

int main(){
    cout << "Digite qtd e primeiro" << endl;
    int qtd = 0;
    cin >> qtd ;

    int primeiro = 0;
    cin >> primeiro;
    cout<< "Digite o numero de saltos: "<<endl;
    int saltos = 0;
    cin >> saltos;

    list<int> lista;
    for(int i = 1; i <= qtd; i++)
        lista.push_back(i);

    while(lista.front() != primeiro)
        rodar(lista);

    mostrar(lista);
    while(lista.size() > 1){
        // Vai rodar o numeros de vezes do valor de salto
        for(int j = 0; j < saltos; j++)
        rodar(lista);

        lista.pop_front();
        mostrar(lista);
    }
    return 0;
}

void rodar(list<int> &lista){
    lista.push_back(lista.front());
    lista.pop_front();
}


void mostrar(list<int> &lista){
    for(int x : lista)
        cout << x << " ";
    cout << "\n";
}
