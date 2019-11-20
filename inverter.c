#include "funcoes.h"
#include "stdio.h"
#include "string.h"

/**
 * Esta função inverte a imagem horizontalmente ou verticalmente
 * Explicações: O código abaixo inverte uma matriz horizontalmente ou verticalmente. 
 *
 *          (a) Horizontalmente: Sentido Oeste - Leste (da esquerda para a direita)
 *               - Inverte-se as colunas.
 *
 *                Início                          Final
 *            | a  b  c  d |                  | d  c  b  a |
 *            | e  f  g  h |      ===>        | h  g  f  e |
 *            | i  j  k  l |                  | l  k  j  i |
 *
 *            (b) Verticalmente: Sentido Norte - Sul (de cima para baixo)
 *                - Inverte-se as linhas.
 *
 *                Início                          Final
 *            | a  b  c  d |                  | i  j  k  l |
 *            | e  f  g  h |      ===>        | e  f  g  h |
 *            | i  j  k  l |                  | a  b  c  d |
 * 
 * @param img - Referência para a imagem a ser invertida
 * @param terminal - Identifica se as entradas dos dados são feitas pelo terminal ou pelo arquivo de texto
 * @param lerEntradas - Referência para o arquivo de texto
 * @return Retorna 0 se a imagem não foi invertida e Retorna 1 se a imagem for corretamente invertida
 * version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

//Essa função inverte (espelha) a imagem horizontalmente ou verticalmente.
int inverter(Imagem img, int terminal, FILE *lerEntradas){
    char tipoInversao[MAX];
    int horizontalmente, verticalmente;
    Pixel matrizTemporaria[img.lin][img.col]; //Declarando matriz temporaria para armazenar pixels originais da imagem

    //Escolha do tipo de inversão: horizontalmente ou verticalmente
    if (terminal == 1){
        printf("Deseja inverter a imagem horizontalmente ou verticalmente?\n");
        scanf("%s", tipoInversao); //Leitura dos dados pelo teclado
    } else{
        fscanf(lerEntradas, "%s", tipoInversao); //Leitura dos dados pelo arquivo entradas.txt
        printf("%s", tipoInversao);
    }

    //Comparação do nome digitado com o tipo de inversão a ser realizada
    minuscula(tipoInversao); //Converte as letras maiúsculas da string em letras minúsculas
    //Horizontalmente
    horizontalmente = (strcmp(tipoInversao, "horizontalmente") == 0 || strcmp(tipoInversao, "horizontal") == 0);
    //Verticalmente
    verticalmente = (strcmp(tipoInversao, "verticalmente") == 0 || strcmp(tipoInversao, "vertical") == 0);

    if (verticalmente == 0 && horizontalmente == 0){
        printf("\n  Dado inválido! Imagem não foi invertida!");
        return 0;
    }

    //Armazena todos os pixels iniciais da imagem em uma matriz temporária
    for (int l=0; l<img.lin; l++){
        for (int c=0; c<img.col; c++){
            matrizTemporaria[l][c] = img.pixel[l][c];
        }
    }

    //INVERTER: (a) Horizontalmente: Sentido Oeste - Leste (da esquerda para a direita)
    if (horizontalmente){
        for (int l=0; l<img.lin; l++){
            for (int c=0; c<img.col; c++){
                img.pixel[l][c] = matrizTemporaria[l][img.col-c-1];
            }
        }
    }

    //INVERTER: (b) Verticalmente: Sentido Norte - Sul (de cima para baixo)
    if (verticalmente){
        for (int l=0; l<img.lin; l++){
            for (int c=0; c<img.col; c++){
                img.pixel[l][c] = matrizTemporaria[img.lin-l-1][c];
            }
        }
    }
        
    return 1;
}