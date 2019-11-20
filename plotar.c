#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "funcoes.h"

/**
 * Funcão plotar o gráfico de um polinômio de grau 'n' 
 * com o seguinte formato: y = an*x^n + a(n-1)*x^(n-1) + ... + a2*x^2 + a1*x^1 + a0*x^0
 * Obs: A função plota uma curva considerando o centro da imagem como sendo as coordenadasd (0,0)
 * @param img - Referencia para a imagem na qual será desenhada o "gráfico" da função
 * @param cor - Cor RGB que será pintada a linha
 * @param espessura - Espessura/densidade da linha que será desenhada na imagem
 * @param terminal - Identifica se as entradas dos dados são feitas pelo terminal ou pelo arquivo de texto
 * @param lerEntradas - Referencia para o arquivo de texto
 * @return int 
 * @version 18-11-2019
 * @author Danilo Micaías Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */
int plotar(Imagem img, Pixel cor, int espessura, int terminal, FILE *lerEntradas){
    int grauPolinomio, x1, x2, y1, y2;
    float y1Float, y2Float, coeficientes[MAXcoeficientes];
    Ponto p1, p2;

    //Entrada de dados
    if (terminal == 1){
        printf("Digite o grau do polinomio:\n");
        scanf("%d", &grauPolinomio); //Leitura dos dados pelo teclado

        //Armazenando coeficientes de cada termo do polinômio
        for(int a = grauPolinomio; a >= 0; a--){
            printf("Coeficiente x^%d: ", a);
            scanf("%f", &coeficientes[a]); //Leitura dos dados pelo teclaod
        }
    } else{
        fscanf(lerEntradas, "%d", &grauPolinomio); //Leitura dos dados pelo arquivo entradas.txt
        printf("%d ", grauPolinomio);

        //Armazenando coeficientes de cada termo do polinômio
        for(int a = grauPolinomio; a >= 0; a--){
            fscanf(lerEntradas, "%f", &coeficientes[a]); //Leitura dos dados pelo arquivo entradas.txt
            printf("%.1f ", coeficientes[a]);
        }
    }

    //Condição de erro:
    if(grauPolinomio < 0){
        printf("\n  Dado inválido! Polinômio não foi plotado.");
        return 0;
    }

    //Plotar função: Traça linha entre dois pontos consecutivos, isto é, p1(x,y1) e p2(x+1,y2).
    for (int x = 0; x<img.col; x++){
        x1 = x - img.col/2;
        x2 = x+1 - img.col/2;
        y1Float = 0;
        y2Float = 0;

        //Calculando valor de 'y' para x = x1 e x = x2 (pontos consecutivos)
        for(int a = grauPolinomio; a >= 0; a--){
            y1Float = y1Float + coeficientes[a]*pow(x1,a); //Ponto 1
            y2Float = y2Float + coeficientes[a]*pow(x2,a); //Ponto 2
        }

        //Arredondando valores de 'y' para o inteiro mais próximo
        y1 = y1Float+0.5;
        y2 = y2Float+0.5;

        //Armazenando coordenadas 'x' e 'y' dos pontos p1 e p2
        p1.x = x1;
        p1.y = y1;
        p2.x = x2;
        p2.y = y2;

        //Transladando coordenadas dos pontos (x1,y1) e (x2,y2) de modo que a origem seja no centro da imagem
        p1.x = p1.x + img.col/2 + 1;
        p1.y = img.lin/2 - (p1.y -1);
        p2.x = p2.x + img.col/2 + 1;
        p2.y = img.lin/2 - (p2.y - 1);

        //Chamando função para traçar linha entre dois pontos, neste caso, p1 e p2
        linha(img, p1, p2, cor, espessura);
    }
    
    return 1;

}