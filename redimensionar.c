#include "funcoes.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

  
//Essa função redimensiona as dimensões da imagem (colunas x linhas).
int redimensionar(Imagem *img,  int terminal, FILE *lerEntradas){
    int colunasFinal, linhasFinal, colunasInicial, linhasInicial;
    Pixel matrizTemporaria[img->lin][img->col]; //Declarando matriz temporaria para armazenar pixels originais da imagem
    colunasInicial = img->col;
    linhasInicial = img->lin;

    //Escolha das novas dimensões da imagem
    if (terminal == 1){
        printf("Digite as novas dimensões da imagem (colunas x linhas):\n");
        scanf("%d %d", &colunasFinal, &linhasFinal); //Leitura dos dados pelo terminal
    } else{
        fscanf(lerEntradas, "%d %d", &colunasFinal, &linhasFinal); //Leitura dos dados pelo arquivo entradas.txt
        printf("%d %d", colunasFinal, linhasFinal);
    }

    //Verifica se quantidade de linhas e colunas são números positivos
    if(colunasFinal <= 0 || linhasFinal <= 0){
        printf("\n  Dimensões inválidas! Imagem não foi redimensionada.");
        return 0;
    }

    //Armazena todos os pixels iniciais da imagem em uma matriz temporária
    for (int l=0; l<linhasInicial; l++){
        for (int c=0; c<colunasInicial; c++){
            matrizTemporaria[l][c] = img->pixel[l][c];
        }
    }

    //Armazenando novas dimensões na imagem
    img->col = colunasFinal;
    img->lin = linhasFinal;
    
    //REDIMENSIONANDO A IMAGEM: Realocando dimensões da matriz imagem
    img->pixel = malloc(linhasFinal*sizeof(Pixel*)); //Linhas
    for (int l=0; l<linhasFinal; l++){
        img->pixel[l]= malloc(colunasFinal*sizeof(Pixel)); //Colunas
        for (int c=0; c<colunasFinal; c++){
            if (l < linhasInicial && c < colunasInicial){
                img->pixel[l][c] = matrizTemporaria[l][c]; //Armazena pixels já existentes na imagem original
            } else{
                //Caso a nova imagem seja maior que a anterior, os pixels externos são brancos
                img->pixel[l][c].R = 255;
                img->pixel[l][c].G = 255;
                img->pixel[l][c].B = 255;
            }
        }
    }

    return 1;
    
}