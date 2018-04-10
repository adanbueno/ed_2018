#include <lib/pen.h>

void triangulo(Pen &p, int lado){
    if(lado < 10)
        return;
    for(int i = 0; i < 3; i++){
        p.walk(lado);
        p.left(120);
        triangulo(p, lado/2);
    }
}
void circulos(Pen& p, double lado){
    if(lado < 1)
        return;
    p.circle(lado);
    for(int i = 0; i < 6; i++){
        p.left(60);
        p.up();
        p.walk(lado);
        p.down();
        circulos(p,lado*2/6);
        p.up();
        p.walk(-lado);
        p.down();
    }
}

void trigo(Pen& p, int lado){
    float angulo = 45;

    if(lado <= 0)
        return;
    for(int i = 0; i < 4; i++){
        p.walk(lado);
        p.left(angulo);
        trigo(p, lado * 0.30);
        p.right(angulo*2);
        trigo(p, lado * 0.30);
        p.left(angulo);
    }
    for(int i = 0; i < 4; i++){
        p.walk(-lado);
    }
}

void trigo2(Pen& p, double lado){
    if (lado < 0.1)
        return;
    p.setColor(255, 255, 255);

    for(int i = 0; i < 4; i++){
        p.walk(lado);
        p.right(45);
        trigo2(p,lado/4);
        p.left(90);
        trigo2(p,lado/4);
        p.right(45);
    }
   p.setColor(rand() % 255,rand() % 255,rand() % 255);
   p.walk(-lado*4);
}
void frozen(Pen& p,int aux, int lado){
    float angulo = 72;
    if(aux == 0 || lado < 3)
    return;

    p.walk(lado);
    gelo(p,5, lado *0.36);
    p.walk(-lado);
    p.right(angulo); // 360*0.2
    p.setColor(rand() % 255,rand() % 255,rand() % 255);
    aux--;
    gelo(p,aux, lado);
}



void arvore(Pen& p, int lado){
    float ang = 35;
    float dec = 0.75;
    lado -= (p.rand() % 7 - 3);
    if(lado < 10)
        return;
    p.setColor(rand() % 255, rand() % 255, rand() % 255);
    p.walk(lado);
    p.right(ang);
    arvore(p, lado * dec);
    p.left(ang);
    arvore(p, lado * dec);
    p.left(ang);
    arvore(p, lado * dec);
    p.right(ang);
    //p.setColor(sf::Color::Red);
    p.walk(-lado);
}

void fractal(){
    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 300);// floco de neve
    //p.setXY(400, 500);// trigo

    //faz o pincel apontar pra direita
    //p.setHeading(0);//para o circulo
    p.setHeading(90);//para o trigo
    //p.setHeading(60);//para floco de neve
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    //circulos(p,200);
    //trigo2(p,80);
    //trigo(p,80);
    //frozen(p,5,200);
    //arvore(p, 100);
    //triangulo(p, 400);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
