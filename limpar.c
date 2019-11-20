#include "funcoes.h"


/**
 * Essa função pinta toda a imagem com a cor que estiver selecionada antes da chamada da função
 * 
 * @param img - Referencia para a imagem que será limpada
 * @param cor - Cor RGB que a imagem será pintada por completo
 * @version 18-11-2019
 * @author Danilo Micaías Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */
//Essa função pinta toda a imagem com a cor que estiver selecionada antes da chamada da função.
void limpar(Imagem img, Pixel cor){

    for(int l=0; l<img.lin; l++){
        for(int c=0; c<img.col; c++){
            img.pixel[l][c].R = cor.R;
            img.pixel[l][c].G = cor.G;
            img.pixel[l][c].B = cor.B;
        }
    }

}