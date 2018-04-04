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

void arvore(Pen& p, int lado){
    float ang = 35;
    float dec = 14;
    lado -= (p.rand() % 7 - 2);
    if(lado < 10)
        return;
    p.setColor(rand() % 78, rand() % 56, rand() % 77);
    p.walk(lado);
    p.right(ang);
    arvore(p, lado * dec);
    p.left(ang);
    arvore(p, lado * dec);
    p.left(ang);
    arvore(p, lado * dec);
    p.left(ang);
    arvore(p, lado * dec);
    p.left(ang);
    arvore(p, lado * dec);
    p.right(ang);
    p.walk(-lado);
}

void fractal(){
    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 500);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    arvore(p, 100);
    //triangulo(p, 400);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
