#include "funcoes.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * Esta função aloca dinamicamente uma matriz de pixels para formar uma imagem com dimensões 'colunas' x 'linhas'
 * @param img - Referência para a imagem a ser alocada
 * @param colunasImagem - Número de colunas da imagem
 * @param linhasImagem - Número de linhas da imagem
 * @return Retorna 0 se a matriz não foi alocada dinamicamente e 1 se a matriz for corretamente alocada dinamicamente
 * @version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

//Essa função aloca dinamicamente uma matriz de pixels para formar a imagem com dimensões 'colunas' x 'linhas'.
int alocaImagem(Imagem *img, int colunasImagem, int linhasImagem){

        //Verifica se quantidade de linhas e colunas são números positivos
        if(linhasImagem <= 0 || colunasImagem <= 0){
            printf("\nDimensões inválidas!\n");
            return 0;
        }

        //Modifica as dimensões da imagem
        img->col = colunasImagem;
        img->lin = linhasImagem;

        //Alocação dinâmica dos pixels da imagem
        img->pixel = malloc(linhasImagem*sizeof(Pixel*)); //Linhas
        for (int l=0; l<linhasImagem; l++){
            img->pixel[l]= malloc(colunasImagem*sizeof(Pixel)); //Colunas
            for (int c=0; c<colunasImagem; c++){
                //Inicialmente todos os pixels são brancos
                img->pixel[l][c].R = 255;
                img->pixel[l][c].G = 255;
                img->pixel[l][c].B = 255;
            }
        }

        return 1;
}