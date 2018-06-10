#include <random>
#include "Libs/pintor.h"
#include <vector>
#include "Libs/pintor.h"
#include <algorithm>
#include <time.h>//funcao time
#include <stdlib.h> //funcao srand

using namespace std;

//Cada dia possui 6 horas de trabalho
//60 minutos x 6 horas = 360 minutos
//cada minuto eh um turno.
const int TURNOS_DIA = 360;

//A quantidade máxima de caixas não pode ser alterada.
const int MAX_CAIXAS = 10;

//Esse valor determina o quanto o banco paga por caixa por dia de trabalho
const int CUSTO_CAIXA_DIA = 100;

//numero de simulacoes de teste para cada caixa
const int N_EXEC_TESTE = 100;

//gera um numero entre min e max, [min, max]
int rand_mm(int min, int max){
    static int init = 1;
    if(init){
        init = 0;
        srand(time(NULL));
    }
    return rand() % (max - min + 1) + min;
}

struct Param {
    int min_pac;
    int max_pac;
    int min_doc;
    int max_doc;
    int min_cli;
    int max_cli;
    int ncaixas;
};

//Essa simulação é apenas uma mostragem de como
//funciona a visualização.
int Simulacao(Param p){

    int min_pac = p.min_pac;
    int max_pac = p.max_pac;
    int min_doc = p.min_doc;
    int max_doc = p.max_doc;
    int min_cli = p.min_cli;
    int max_cli = p.max_cli;
   // Pintor pintor;
    int Lucro = 0;

    const unsigned int Time = TURNOS_DIA;
    const unsigned int numCX = p.ncaixas;

    std::vector<Cliente*> caixa(numCX);
    std::list<Cliente*> fila;
    std::list<Cliente*> fila_saida;
   /* Para cada minuto do expediente faça
        Gerar aleatoriamente N clientes.
        Para cada um desses N clientes faça:
            Se ainda tiver espaço no banco:
                Insira os clientes na fila de atendimento
            Senão:
                mande os clientes embora */
    for(unsigned int i = 0; i < Time; i++){
          //pintor.desenhar(caixa,fila,1000);
        int cli = rand_mm(min_cli, max_cli);

        if(fila.size() < 180){
            for(int i = 0; i < cli; i++){
                fila.push_back(new Cliente(rand_mm(min_pac, max_pac), rand_mm(min_doc, max_doc)));
            }
        }
        /*Para cada cliente na FILA de atendimento faça:
        Se cliente está sem paciência então:
            Remover cliente da FILA e colocálo na fila de saída
        Senão:
            Decrementar paciência do cliente */
        for(auto it = fila.begin(); it != fila.end();){
            if((*it)->paciencia == 0){
                fila_saida.push_back((*it));
                it = fila.erase(it);
            }else{
                (*it)->paciencia--;
                it ++;
            }
        }
        /*Para cada CAIXA faça:
        Se há um cliente no caixa então:
            Se o cliente tem algum documento para processar então:
                Processar documento do cliente.
            Senão:
                Colocar o cliente na fila de saida.
        Senão:
            Se a FILA não está vazia então:
                remover cliente da FILA e inserir no caixa. */
        for(int i = 0; i < (int)numCX; i++){
            if(caixa[i] != nullptr){
                if(caixa[i]->documentos >0){
                    caixa[i]->documentos--;
                    Lucro++;
                }else{
                    fila_saida.push_back(caixa[i]);
                    caixa[i] = nullptr;
                }
            }else{
                if(fila.size() > 0){
                    caixa[i] = fila.front();
                    fila.pop_front();
                }
            }
        }
        /*Para cada cliente da fila de saida faça:
        retire o cliente do banco
Para cada cliente que ainda está no banco faça:
    Remova o cliente do banco */

        while(fila_saida.size() > 0){
            delete fila_saida.front();
            fila_saida.pop_front();
        }


    }
    return Lucro - p.ncaixas *100;
}


int main ()
{


    vector<int> lucro_medio(10);

    for(int i = 0;i <= 9 ;i++){
       lucro_medio[i] = 0;
       for(int j = 0; j < 100; j++)
            lucro_medio[i] += Simulacao(Param{1, 60, 1, 10, 0,  1, i});
       lucro_medio[i] = lucro_medio[i]/100;
    }
    for(auto elem : lucro_medio)
        cout << elem << " ";
    cout << endl;

    int imaior = 0;
    for(int i = 0; i <= 9; i++)
        if(lucro_medio[i] > lucro_medio[imaior])
            imaior = i;

    cout << imaior << endl;

    //executar_testes();
    return 0;
}
