#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    int value;
    Node* next;

    //Construtores
    Node(int value = 0, Node* next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{
    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        head = deletarTudo(head);
    }

    /*void deletarTudo(Node* node){
            Node *aux = nullptr;
            while(node != nullptr){
                aux = node->next; // Guarda a referência para o prox elemento
                delete node; // libera a memória apontada a p
                node = aux; // faz p apontar para o próximo
            }
    }*/

    Node* deletarTudo(Node* node){
        if(node == nullptr)
            return nullptr;

        deletarTudo(node->next);

        delete node;
        return nullptr;
    }


    Node * arrancaRabo(Node * node, int value){
            if(node == nullptr)
                return nullptr;
    node->next = arrancaRabo(node->next, value);
    if(node->next == nullptr){
        if(node->value != value){
            delete node;
            return nullptr;
        }else{
            return node;
        }
    }
    return node;
   }

    // Feito
    Node* cortarRabo(Node* node, int value){
        if(node == nullptr)
            return nullptr;

        node->next = cortarRabo(node->next,value);
        if(node->value == value){
            delete node;
            return nullptr;
        }
        return node;
    }

  /*  void _serialize(stringstream &ss, Node* node){
        if(node == nullptr)
            return;
        ss << node->value;
        _serialize(ss,node->next);
    }

    string serialize(){
        stringstream ss;
        _serialize(ss, head);
        return ss.str();
    }
*/
    void push_front(int value){
        Node* node = new Node(value); //Cria um novo nó
        node->next = head; // o next apontar para valor de head, então head aponta para o node
        this->head = node;
    }


    void pop_front(int value){
        if(head == nullptr)
            return;
        Node* aux;
        aux = head; // Guardo a referência
        this->head = head->next; // Aponto para o próximo nó
        delete aux; // Deleto o valor
    }
    //Consertado
    void push_back(int value){
         Node* node = head;
         Node* anterior = nullptr;
        if(head ==  nullptr){
            head = new Node(value);
            return;
        }

        while (node != nullptr) {
            anterior = node;
            node = node->next;
        }
        anterior->next = new Node(value);
    }

    // feito
    Node * r_push_back(Node * node, int value){
            if(node == nullptr){
                node = new Node(value,nullptr);
                //return nullptr;
            }
            else
                node->next = r_push_back(node->next,value);
            //return node;
    }
    // Feito
    void rpush_back(int value){
        this->head = r_push_back(head,value);
    }


    Node* _rpop_back(Node* node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }

       node->next = _rpop_back(node->next);
    }

    void rpop_back(){
           this->head = _rpop_back(head);
       }


    void pop_back(int value){
        if(head == nullptr)
            return;

        if(head->next == nullptr){
           delete head;
            head = nullptr;
            return;
        }

        auto node = head;

        while(node->next->next != nullptr)
            node = node->next;

        delete node->next;
        node->next = nullptr;

    }
    void show(){
        Node* node = head;
        while(node != nullptr){
            cout<<node->value<<" ";
            node = node->next;
        }
         cout<<"\n";
    }

    void _rshow(Node* node){
        if(node == nullptr)
            return;

        cout<<node->value<<" ";
        _rshow(node->next);
    }
    void rshow(){
        _rshow(head);
        cout << endl;
    }


    Node* _remove(Node* node, int value){
       if(node == nullptr)
           return nullptr;

        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }

       node->next = _remove(node->next,value);
    }

    void remove(int value){
        head = _remove(head,value);
    }

    // Feito
    void iremove(int value){
        Node* node = head;
        Node* anterior = nullptr;

        while(node != nullptr && node->value != value){
            anterior = node;
            node = node->next;
        }

        if(node == nullptr)
            return;

        if(anterior == nullptr)
            head = node->next;
        else
            anterior->next = node->next;

    }

        //Feito
    int rsomar(Node * node){
           if(node == nullptr)
               return 0;
         return node->value + rsomar(node->next);
    }

    // Feito
    Node * _rinserir_ordenado(Node * node, int value){
           if(node ==  nullptr || node->value > value){
               node = new Node(value,node);
            return node;
           }
           else
               node->next = _rinserir_ordenado(node->next,value);
       }

        // Feito
    void rinserir_ordenado(int value){
            this->head = _rinserir_ordenado(head,value);
        }
    //feito
    int size(Node *node){
    int cont = 0;

    while(node != nullptr){
        cont++;
        node = node->next;
    }
        return cont;
   }
    //Feito
    int _rsize(Node* node){
    int cont = 0;

        if(node == nullptr)
            return 0;

       cont+= _rsize(node->next);
        return cont + 1;
    }
// Se for usar o recursivo tira os coments
    //void rsize(){
      //  this->head = _rsize(head);
    //}
};

