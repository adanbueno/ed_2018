#include <iostream>
#include <sstream>

using namespace std;

enum State {Vazio, Existe, Removido};

struct Node {

    int value;
    State state;

    Node(){
        this->state = Vazio;
        this->value = -1;
    }

    Node(int value){

        this->state = Existe;
        this->value = value;

    }

    bool operator ==(int value){

        if(this->state == Existe)
            if(this->value == value)
                return true;

        return false;
    }

};

// Aqui tem vetor de dados, a capacidade e a quantidade de elementos alocados que é o size
//
class Hash {

    Node * _data;
    int _capacity;
    int _size;
    int _qtd_removido;

public:
    //Construtor do hash
    Hash(int capacity){

        this->_capacity = capacity;
        this->_data = new Node[capacity];
        this->_size = 0;
        this->_qtd_removido = 0;
    }
    //Destrutor do hash
    ~Hash(){

        delete [] this->_data; //não perde a referencia, mas ele é tirado pra não usar de novo
        this->_data = nullptr;

    }

    bool inserir(int value){

        int pos = search(value);

        if( _data[pos].state != Existe ){

            _data[pos] = Node(value);

            if(_data[pos].state == Removido)
                _qtd_removido--;

            _size++;

            if( (_size*100)/_capacity > 60 ){

                reinserir_todos( 2 * _capacity );

            }

            return true;

        }

        return false;
    }
    // Se existir elemento ele vai remover
    bool remover(int value){

        int pos = search(value);

        if( _data[pos] == value ){

            _data[pos].state = Removido;
            _qtd_removido++;
            _size--;

            if( (_qtd_removido*100)/_capacity > 30 ){

                reinserir_todos( _capacity );

            }

            return true;

        }

        return false;
    }

    // Pegar todos os elementos e reenserir com o dobro de capacidade
    //Ou realoca pro mesmo tamanho pra livrar os removidos
    void reinserir_todos(int capacity){

        Node * aux = _data;
        int c_aux = _capacity;

        _data = new Node[capacity];
        _capacity = capacity;
        _size = 0;
        _qtd_removido = 0;

        for(int i=0; i < c_aux; i++){
            if(aux[i].state == Existe)
                inserir(aux[i].value);
        }

    }

    //retornar onde o elemento esta
    //ou onde deveria estar
    int search(int value){

        int pos_del = -1;
        int atual = value % _capacity;

        while(_data[atual].state != Vazio ){

            if(_data[atual] == value)
                return atual;

            if(pos_del == -1)
                if( _data[atual].state == Removido )
                    pos_del = atual;

            atual = (atual+1) % _capacity;
        }

        if(pos_del != -1)
            return pos_del;

        return atual;
    }

    //return se existe ou não
    bool exists(int value){
        int atual = value % _capacity;

        while( _data[atual].state != Vazio ){

            if( _data[atual] == value )
                return true;

            atual = (atual+1) % _capacity;
        }

        return false;

    }

    int size(){
        return _size;
    }

    int capacity(){
        return _capacity;
    }

    string to_string(){
        stringstream ss;

        ss << "| Posicao | valor | status |" << endl;

        for(int i=0; i <_capacity; i++){
            ss << "| " << i << " | " << (_data[i].value) << " | " << (_data[i].state) << " |" << endl;
        }

        return ss.str();
    }

};

int main(){

    int menu = 1;
    Hash ha(5);

    while(menu){
        cout << string(150, '\n');
        cout << ha.to_string() << endl;
        cout << "Size: "<< ha.size() << endl;
        cout << "Cap: "<< ha.capacity() << endl << endl;

        cout << "--------------------------------" << endl << endl;

        cout << "Menu:" << endl;
        cout << "Inserir: 1 (value)" << endl;
        cout << "Remover: 2 (value)" << endl;
        cout << "Sair: 0" << endl;

        cout << "Opcao e valor: ";
        cin >> menu;

        switch (menu) {
            int value;

            case 1:
                cin >> value;
                ha.inserir(value);
                break;
            case 2:
                cin >> value;
                ha.remover(value);
                break;

            default:
                break;
        }
    }

    return 0;
}

