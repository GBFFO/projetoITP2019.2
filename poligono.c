#include "funcoes.h"
#include "stdio.h"

//Essa função desenha um polígono com 'n' lados dadas as coordenadas dos vértices do polígono.
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