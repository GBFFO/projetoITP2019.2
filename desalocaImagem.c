#include "funcoes.h"
#include "stdlib.h"

/**
 * Esta função desaloca dinamicamente a matriz de pixels que forma a imagem
 * @param img - Referência para a imagem a ser desalocada dinamicamente
 * @version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

//Essa função desaloca dinamicamente a matriz de pixels que forma a imagem.
void desalocaImagem(Imagem *img){

    for (int l=0; l<img->lin;l++){
        free(img->pixel[l]); 
    }
    free(img->pixel); 

}