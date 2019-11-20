#include "funcoes.h"
#include "stdio.h"
#include <math.h>


/**
 * Essa função desenha um paralelepípedo dadas as dimensões deste prisma, 
 * o ângulo de rotação e as coordenadas de 1 dos vértices.
 * 
 * @param img - Referencia para a imagem na qual será traçado o paralelepípedo
 * @param cor - Cor RGB que será pintado as linhas do paralelepipedo
 * @param prisma - Referencia para as dimensões/características do paralelepipedo
 * que será desenhado(altura, largura, comprimento e angulo de rotação)
 * @param espessuraLinha 
 * @return int 
 * @version 18-11-2019
 * @author Danilo Micaías Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */
int paralelepipedo(Imagem img, Pixel cor, Dimensoes prisma, int espessuraLinha){
    Ponto p[10];
    int x, y, altura, largura, comprimento, angulo;
    float pi = M_PI;
    int angulo0a90, angulo90a180, angulo180a270, angulo270a360;

    if (prisma.altura < 0 || prisma.largura < 0 || prisma.comprimento < 0){
        printf("\n   Dados inválidos! Paralelepípedo não foi gerado.");
        return 0;
    }

    //Ponto a partir do qual o prisma é desenhado
    x = prisma.verticeInicial.x;
    y = prisma.verticeInicial.y;

    //Armazenando dimensões do prisma e o ângulo de rotação (visão)
    altura = prisma.altura;
    largura = prisma.largura;
    comprimento = prisma.comprimento;
    angulo = prisma.anguloRotacao%360; //Rotação de -360 até 360 graus
    
    //printf("\nx: %d\ny: %d\npi: %f\naltura: %d\nlargura %d\ncomprimento %d\nangulo %d\n", x, y, pi, altura, largura, comprimento, angulo);
    //Vértices do paralelepipedo 
    p[0].x = x; //Inicial x
    p[0].y = y; //Inicial y
    p[1].x = x;  
    p[1].y = y + altura;
    p[2].x = x + largura;
    p[2].y = y;
    p[3].x = x + largura;
    p[3].y = y + altura;
    p[4].x = x - comprimento*cos(angulo*pi/180);
    p[4].y = y - comprimento*sin(angulo*pi/180);
    p[5].x = p[4].x;
    p[5].y = p[4].y + altura;
    p[6].x = p[4].x + largura;
    p[6].y = p[4].y;
    p[7].x = p[4].x + largura;
    p[7].y = p[4].y + altura;

    //Identificando a região da rotação do prisma
    angulo0a90 = ((angulo >= 0 && angulo <= 90) || (angulo >= -360 && angulo <= -270));
    angulo90a180 = ((angulo > 90 && angulo <= 180) || (angulo > -270 && angulo <= -180));
    angulo180a270 = ((angulo >180 && angulo <= 270) || (angulo > -180 && angulo <= -90)); 
    angulo270a360 = ((angulo >270 && angulo < 360) || (angulo > -90 && angulo < 0));

    //Traçando arestas visíveis a depender do ângulo de rotação usando a função linha
    if (angulo0a90){
        linha(img, p[0], p[1], cor, espessuraLinha);
        linha(img, p[0], p[2], cor, espessuraLinha);
        linha(img, p[0], p[4], cor, espessuraLinha);
        linha(img, p[1], p[3], cor, espessuraLinha);
        linha(img, p[1], p[5], cor, espessuraLinha);
        linha(img, p[2], p[3], cor, espessuraLinha);
        linha(img, p[2], p[6], cor, espessuraLinha);
        linha(img, p[4], p[5], cor, espessuraLinha);
        linha(img, p[4], p[6], cor, espessuraLinha);
    } else if (angulo90a180){
        linha(img, p[0], p[1], cor, espessuraLinha);
        linha(img, p[0], p[2], cor, espessuraLinha);
        linha(img, p[0], p[4], cor, espessuraLinha);
        linha(img, p[1], p[3], cor, espessuraLinha);
        linha(img, p[2], p[3], cor, espessuraLinha);
        linha(img, p[2], p[6], cor, espessuraLinha);
        linha(img, p[3], p[7], cor, espessuraLinha);
        linha(img, p[4], p[6], cor, espessuraLinha);
        linha(img, p[6], p[7], cor, espessuraLinha);
    } else if (angulo180a270){
        linha(img, p[0], p[1], cor, espessuraLinha);
        linha(img, p[0], p[2], cor, espessuraLinha);
        linha(img, p[0], p[4], cor, espessuraLinha);
        linha(img, p[1], p[5], cor, espessuraLinha);
        linha(img, p[2], p[6], cor, espessuraLinha);
        linha(img, p[4], p[5], cor, espessuraLinha);
        linha(img, p[4], p[6], cor, espessuraLinha);
        linha(img, p[5], p[7], cor, espessuraLinha);
        linha(img, p[6], p[7], cor, espessuraLinha);
    } else{
        linha(img, p[0], p[2], cor, espessuraLinha);
        linha(img, p[0], p[4], cor, espessuraLinha);
        linha(img, p[2], p[3], cor, espessuraLinha);
        linha(img, p[2], p[6], cor, espessuraLinha);
        linha(img, p[3], p[7], cor, espessuraLinha);
        linha(img, p[4], p[5], cor, espessuraLinha);
        linha(img, p[4], p[6], cor, espessuraLinha);
        linha(img, p[6], p[7], cor, espessuraLinha);
        linha(img, p[5], p[7], cor, espessuraLinha);

    }
    return 1;
    
}