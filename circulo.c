#include "funcoes.h"
#include "math.h"

/**
 * Esta função desenha um círculo de raio R e coordenadas do centro (xc,yc)
 * As coordenadas (1,1) correspondem ao canto superior esquerdo da imagem
 * @param img - Referência para a imagem na qual o círculo será desenhado
 * @param xc - Coordenada X do centro do círculo
 * @param yc - Coordenada Y do centro do círculo
 * @param raio - Raio do círculo
 * @param cor - Cor RGB usada para desenhar o círculo
 * @param espessuraLinha - Espessura da linha que desenha o círculo
 * @version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

//Essa função desenha um círculo de raio 'r' e coordenadas do centro (xc, yc).
void circulo(Imagem img, int xc, int yc, int raio, Pixel cor, int espessuraLinha){
    int xDireita, xEsquerda, yCima, yBaixo;
    float yFloat;

    for(int x = 0; x <= (raio*sin(45*M_PI/180)); x++){

        yFloat = sqrt(raio*raio-x*x);
        //Deslocamentos para direta, para esquerda, para cima ou para baixo em relação ao centro (xc,yc)
        yBaixo = yFloat + 0.5;
        yCima = -yFloat - 0.5;
        xDireita = x;
        xEsquerda = -x;
        
        pintarPixelmod(img, cor, yBaixo + xc, xEsquerda + yc, espessuraLinha); //1º Octante
        pintarPixelmod(img, cor, xDireita + xc, yCima + yc, espessuraLinha); //2º Octante
        pintarPixelmod(img, cor, xEsquerda + xc, yCima + yc, espessuraLinha); //3º Octante
        pintarPixelmod(img, cor, yCima + xc, xEsquerda + yc, espessuraLinha); //4º Octante
        pintarPixelmod(img, cor, yCima + xc, xDireita + yc, espessuraLinha); //5º Octante
        pintarPixelmod(img, cor, xEsquerda + xc, yBaixo + yc, espessuraLinha); //6º Octante
        pintarPixelmod(img, cor, xDireita + xc, yBaixo + yc, espessuraLinha); //7º Octante
        pintarPixelmod(img, cor, yBaixo + xc, xDireita + yc, espessuraLinha); //8º Octante

    }

}