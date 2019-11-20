#include "funcoes.h"
#include "stdio.h"

/**
 * Essa função desenha um polígono com 'n' lados dadas as coordenadas dos vértices do polígono.
 * 
 * @param img - Referencia para a imagem na qual será desenhada o polígono de 'n' lados definido
 * @param cor - Cor RGB que será pintada as linhas do polígono
 * @param espessuraLinha - Espessura/densidade da linha do polígono que será desenhada na imagem
 * @param terminal - Identifica se as entradas dos dados são feitas pelo terminal ou pelo arquivo de texto
 * @param lerEntradas - Referencia para o arquivo de texto
 * @return int
 * @version 18-11-2019
 * @author Danilo Micaías Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */
int poligono(Imagem img, Pixel cor, int espessuraLinha, int terminal, FILE *lerEntradas){
    int nPontos;

    //Quantidade 'n' de pontos
    if (terminal == 1){
        printf("Digite a quantidade 'n' de lados do poligono:\n");
        scanf("%d", &nPontos); //Leitura dos dados pelo teclado
    } else{
        fscanf(lerEntradas, "%d", &nPontos); //Leitura dos dados pelo arquivo entradas.txt
        printf("%d ", nPontos);
    }

    //Quantidade de pontos inválida
    if(nPontos <= 0){
        return 0;
    }

    Ponto pontos[nPontos]; //Declara o vetor com quantidade de elementos igual a quantidade de lados do polígono

    //Leitura das coordenadas dos 'n' pontos (coordenadas dos vértices)
    if (terminal == 1){
        printf("Digite as coordenadas (x,y) dos vértices do poligono:\n");
        for(int i=0; i<nPontos; i++){
            scanf("%d %d", &pontos[i].x, &pontos[i].y);  //Leitura dos dados pelo teclado
        }
    }else{
        for(int i=0; i<nPontos; i++){
            fscanf(lerEntradas, "%d %d", &pontos[i].x, &pontos[i].y); //Leitura dos dados pelo arquivo entradas.txt
            printf("%d %d ", pontos[i].x, pontos[i].y);
        }
    }

    //Polígono com 1 ponto: Preenche 1 pixel apenas
    if (nPontos == 1){
        linha(img, pontos[0], pontos[0], cor, espessuraLinha);
    } else{
        //Polígono com mais de 1 lado
        for(int i=0; i<(nPontos-1); i++){
            linha(img, pontos[i], pontos[i+1], cor, espessuraLinha); //Traça linha entre dois vértices consecutivos
        }
        linha(img, pontos[0], pontos[nPontos-1], cor, espessuraLinha); //Traça linha entre o primeiro e o último vértice
    }

    return 1;
}