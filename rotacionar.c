#include "funcoes.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/**  ################ ROTACIONAR MATRIZ ################ 
 *    Explicações: 
 *        - O código abaixo rotaciona a matriz para a direita (90 graus no sentido horário). 
 *        - Girar a matriz em 180 graus equivale a girar 2 vezes a matriz para a direita.
 *        - Girar a matriz para a esquerda equivale a girar 3 vezes a matriz para a direita.
 *        - Para girar a matriz para a direita basicamente 2 passos são realizados:
 *            (a) Inverte-se a matriz de cabeça para baixo (Espelhar a matriz verticalmente)
 *            (b) Realiza-se procedimento para obter a transposta da matriz previamente invertida
 *                Obs: O exemplo abaixo ilustra estes dois procedimentos considerando uma matriz genérica A.
 *
 *    Exemplo:
 *        # Dada uma matriz A
 *
 *                       | a  b  c  d |
 *            Matriz A = | e  f  g  h |
 *                       | i  j  k  l |
 *
 *        # Procedimento (a): Inverter matriz verticalmente
 *
 *                       | i  j  k  l |
 *            Matriz A = | e  f  g  h |
 *                       | a  b  c  d |
 *
 *        # Procedimento (b): Transposta de A
 *
 *                       | i  e  a |
 *            Matriz A = | j  f  b |
 *                       | k  g  c |
 *                       | l  h  d |
 *
 *        # Portanto, rotacionou para a direita.
 *
 *                Início                      Final
 *
 *            | a  b  c  d |              | i  e  a |
 *            | e  f  g  h |      ===>    | j  f  b |
 *            | i  j  k  l |              | k  g  c |
 *                                        | l  h  d |
 * Essa função rotaciona a imagem em 90, 180 ou 270 graus no sentido horário.
 * 
 * @param img - Referencia para a imagem que será rotacionada
 * @param terminal - Identifica se as entradas dos dados são feitas pelo terminal ou pelo arquivo de texto
 * @param lerEntradas - Referencia para o arquivo de texto 
 * @return int
 * @version 18-11-2019
 * @author Danilo Micaías Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */
int rotacionar(Imagem *img, int terminal, FILE *lerEntradas){
    char anguloRotacao[100];
    int nGiros, dimensaoTemporaria;
    nGiros = 0;

    //Escolha do angulo de rotação da imagem: 90° = Girar para a direita | 180 = De cabeça para baixo | 270 = Girar para a esquerda 
    if (terminal == 1){
        printf("Deseja rotacionar a imagem em quantos graus? (Opções: 90, 180 ou 270)\n");
        scanf("%s", anguloRotacao); //Leitura dos dados pelo terminal
    } else{
        fscanf(lerEntradas, "%s", anguloRotacao); //Leitura dos dados pelo arquivo entradas.txt
        printf("%s", anguloRotacao);
    }

    minuscula(anguloRotacao); //Converte as letras maiúsculas da string em letras minúsculas

    //Rotaciona matriz em 90° no sentido horário (Gira para a direita)
    if(strcmp(anguloRotacao, "90") == 0 || strcmp(anguloRotacao, "direita") == 0 || strcmp(anguloRotacao, "Direita") == 0){
        nGiros = 1;
    
    //Rotaciona matriz em 180° no sentido horário (De cabeça para baixo)
    }else if(strcmp(anguloRotacao, "180") == 0 || strcmp(anguloRotacao, "-180") == 0){
        nGiros = 2;
    
    //Rotaciona matriz em 270° no sentido horário (Gira para a esquerda)
    }else if(strcmp(anguloRotacao, "-90") == 0 || strcmp(anguloRotacao, "270") == 0 || strcmp(anguloRotacao, "esquerda") == 0 || strcmp(anguloRotacao, "Esquerda") == 0){
        nGiros = 3;
    
    //Angulo 0° de rotação: Não precisa realizar nenhuma ação
    }else if(strcmp(anguloRotacao, "0") == 0){
        return 1;

    //Condição de erro
    } else{
        printf("\n  Dado inválido! Imagem não foi rotacionada!");
        return 0;
    }


    //Procedimento para girar a matriz 'n' vezes para a direita
    for(int i=0; i<nGiros; i++){
        Pixel matrizTemporaria[img->lin][img->col]; //Declarando matriz temporaria para armazenar pixels originais da imagem

        //Armazena todos os pixels iniciais da imagem em uma matriz temporária
        for (int l=0; l<img->lin; l++){
            for (int c=0; c<img->col; c++){
                matrizTemporaria[l][c] = img->pixel[l][c];
            }
        }

        //Procedimento (a): Inverter a imagem verticalmente
        for (int l=0; l<img->lin; l++){
            for (int c=0; c<img->col; c++){
                img->pixel[l][c] = matrizTemporaria[img->lin-l-1][c];
            }
        }

        //Armazena os pixels da imagem invertida em uma matriz temporária
        for (int l=0; l<img->lin; l++){
            for (int c=0; c<img->col; c++){
                matrizTemporaria[l][c] = img->pixel[l][c];
            }
        }

        //Se a matriz não for quadrada, troca-se a quantidade de linhas pela quantidade de colunas e aloca-se novamente a matriz imagem
        if (img->col != img->lin){
            dimensaoTemporaria = img->col;
            img->col = img->lin;
            img->lin = dimensaoTemporaria;

            //Realocando dimensões da matriz imagem
            img->pixel = malloc(img->lin*sizeof(Pixel*)); //Linhas
            for (int l=0; l<img->lin; l++){
                img->pixel[l]= malloc(img->col*sizeof(Pixel)); //Colunas
            }
        }

        //Procedimento (b): Transposta da imagem invertida previamente
        for (int l=0; l<img->lin; l++){
            for (int c=0; c<img->col; c++){
                img->pixel[l][c] = matrizTemporaria[c][l]; 
            }
        }

    }
    
    return 1;

}