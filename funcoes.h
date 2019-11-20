#ifndef FUNCOES_H
#define FUNCOES_H
#include "stdio.h"

#define MAX 100
#define MAXcoeficientes 100

typedef enum{
    false = 0, true = 1
} bool;

typedef struct{
    int x, y;
} Ponto;

typedef struct{
    int altura, largura, comprimento, anguloRotacao;
    Ponto verticeInicial;
} Dimensoes;

typedef struct{
    unsigned char R, G, B;
} Pixel;

typedef struct{
    char formato[2]; 
    unsigned int col, lin, RGBmax;
    Pixel **pixel;
} Imagem;

//Assinaturas das funcoes
void escolheCor(Pixel *cor, int terminal, FILE *lerEntradas);
int limpar(Imagem img, Pixel cor);
int linha(Imagem img, Ponto p1, Ponto p2, Pixel cor, int espessuraLinha);
int poligono(Imagem img, Pixel cor, int espessuraLinha,int terminal, FILE *lerEntradas);
int salvar(Imagem img, char *nomeArquivo);
int coresNome(char *corNome, Pixel *cor);
int alocaImagem(Imagem *img, int colunasImagem, int linhasImagem);
void desalocaImagem(Imagem *img);
int pintarPixelmod(Imagem img, Pixel cor, int x, int y, int espessuraLinha);
int preencher(Imagem img, int x, int y, Pixel cor, Pixel corInicial);
void circulo(Imagem img, int xc, int yc, int raio, Pixel cor, int espessuraLinha);
Pixel contaGota(Imagem img, int x, int y);
int minuscula(char *string);
int inicializa(Imagem *img, Pixel *cor, int *espessuraLinha, char *comando, int argc, char **argv, int *terminal, FILE **lerEntradas);
//Extras
int rotacionar(Imagem *img, int terminal, FILE *lerEntradas);
int inverter(Imagem img, int terminal, FILE *lerEntradas);
int redimensionar(Imagem *img, int terminal, FILE *lerEntradas);
int plotar(Imagem img, Pixel cor, int espessuraLinha,int terminal, FILE *lerEntradas);
int espessura(int *espessuraLinha, int terminal, FILE *lerEntradas);
int paralelepipedo(Imagem img, Pixel cor, Dimensoes prisma, int espessuraLinha);

#endif