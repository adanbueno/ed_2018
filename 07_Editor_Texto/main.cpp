#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "libs/sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();

    }

    //construtor de cópia
    Ambiente(const Ambiente& other):
        texto(other.texto)
    {
        this->cursor = this->texto.begin();
        for(auto it = other.texto.begin(); it != other.cursor; it++)
            this->cursor++;
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "#";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "#";
        return ss.str();
    }
//    void del(){
//        if(cursor != texto.end())
//            cursor = texto.erase(cursor);
//    }
//    void backspace(){
//        if(cursor != texto.begin())
//            cursor = texto.erase(--cursor);

//    }
};

int main()
{
    Ambiente amb;
    list<Ambiente> aux;
    list<Ambiente>::iterator Atual;
//    amb.texto.push_back('a');
//    amb.texto.push_back('m');
//    amb.texto.push_back('o');
//    amb.texto.push_back('r');
    amb.cursor = amb.texto.end();
    aux.push_back((amb));
    Atual = aux.begin();
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.control && (event.key.code == sf::Keyboard::Z)){
                        cout << "control z" << endl;
                        if(Atual == aux.end())
                            Atual--;

                        if(Atual != aux.begin())
                            Atual--;


                        amb = *Atual;
                }
                else if(event.key.control && (event.key.code == sf::Keyboard::R)){
                        cout << "control r" << endl;
                        if(Atual != aux.end()){
                            Atual++;

                            if(Atual != aux.end())
                                amb = *Atual;

                        }
                }
                else if((event.key.code >= sf::Keyboard::A) && (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    if(event.key.shift)
                        tecla += -'a' + 'A';
                    cout << tecla << endl;
                    amb.texto.insert(amb.cursor,tecla);
                }
                else if((event.key.code == sf::Keyboard::Return)){
                    cout << "enter" << endl;
                    
                }
                else if((event.key.code == sf::Keyboard::Space)){
                    cout << "espaco" << endl;
                    amb.texto.insert(amb.cursor,' ');
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    cout << "backspace" << endl;
                    //amb.backspace();
                    amb.texto.erase(amb.cursor++,amb.cursor--);

                }
                else if(event.key.code == sf::Keyboard::Delete){
                    cout << "delete" << endl;
                    //amb.del();
                    amb.texto.erase(amb.cursor++);
                }
                else if(event.key.code == sf::Keyboard::Left){
                    amb.cursor--;
                }
                else if(event.key.code == sf::Keyboard::Right){
                    amb.cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}




