#include "funcoes.h"

/**
 * Esta função obtém a cor RGB de um determinado pixel da imagem com coordenadas (x,y)
 * As coordenadas (1,1) correspondem ao canto superior esquerdo da imagem
 * @param img - Referência para a imagem que contém o pixel com coordenadas (x,y)
 * @param x - Coordenada X da imagem que corresponde à coluna da imagem 
 * @param y - Coordenada Y da imagem que corresponde à linha da imagem 
 * @return Retorna a cor RGB do pixel com coordenadas (x,y)
 * @version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

//Essa função obtém a cor RGB de um determinado pixel com coordenadas (x,y).
Pixel contaGota(Imagem img, int x, int y){
    Pixel corPixel;

    //Verifica se as coordenadas do pixel estão na imagem.
    if (x > 0 && x<=img.col && y > 0 && y<=img.lin){
        corPixel = img.pixel[y-1][x-1];
    } else{
        //Se estiver fora, assume que a cor do pixel é branco
        corPixel.R = 255;
        corPixel.G = 255;
        corPixel.B = 255;
        printf("\n    Pixel fora da imagem.");
    }

    return corPixel; 
}