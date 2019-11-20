#include "funcoes.h"
#include "stdio.h"
#include "string.h"

/**
 * Essa função salva uma imagem com formato PPM, independente se o usuário já acabou sua edição.
 * 
 * @param img - Referencia para a imagem que será salva.
 * @param nomeArquivo - Nome que a função irá atribuir para a imagem. Depois disso, irá salvá-la.
 * @return int 
 */
int salvar(Imagem img, char *nomeArquivo){
    FILE *imagem = NULL;

    //ABRE O ARQUIVO nomeArquivo.ppm 
    imagem = fopen(nomeArquivo, "wb");

    //ESCREVE NO ARQUIVO nomeArquivo.ppm
    fprintf(imagem, "%s\n%d %d\n%d\n", img.formato, img.col, img.lin, img.RGBmax); //Cabeçalho do arquivo

    //Imprime informações de cada pixel no arquivo nomeArquivo.ppm
    for (int l=0; l<img.lin; l++){
        for (int c=0; c<img.col; c++){
            fprintf(imagem, "%u %u %u ", img.pixel[l][c].R, img.pixel[l][c].G, img.pixel[l][c].B);
        }
            fprintf(imagem, "\n");
    }
    fclose(imagem); //Fecha nomeArquivo.ppm

    return 1;
}