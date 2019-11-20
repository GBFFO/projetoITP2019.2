#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"

int main(int argc, char *argv[]){
    FILE *imagemFinal = NULL;
    FILE *lerEntradas = NULL;
    int terminal, x, y, xc, yc, raio, espessuraLinha, entradasValidas, colunasImagem, linhasImagem;
    char comando[MAX], nomeArquivo[MAX];
    Pixel cor, corInicial;
    Ponto p1, p2;
    Dimensoes prisma;
    Imagem img;

    entradasValidas = inicializa(&img, &cor, &espessuraLinha, comando, argc, argv, &terminal, &lerEntradas);
    if (entradasValidas == 0){
        printf("Não passou na inicialização!\n");
        return 0;
    }

    //COMANDOS: Programa roda até o usuário digitar '0', 'fim', 'end' ou algum comando inválido
    while(strcmp(comando,"end") != 0){
        if (terminal == 1){
            //Instruções para o usuário
            printf("\nLista de comandos\n");
            printf("1  - imagem: Criar nova imagem com dimensões escolhidas.\n");
            printf("2  - cor: Selecionar uma cor RGB.\n");
            printf("3  - linha: Traçar uma linha entre dois pontos.\n");
            printf("4  - poligono: Desenhar um poligono com 'n' pontos.\n");
            printf("5  - circulo: Desenhar um circulo de raio R e centro (xc,yc).\n");
            printf("6  - paralelepipedo: Desenhar um paralelepipedo.\n");
            printf("7  - preencher: Preencher com cor uma região da imagem.\n");
            printf("8  - plotar: Plotar função polinomial.\n");
            printf("9  - rotacionar: Rotacionar a imagem em 90, 180 ou 270 graus.\n");
            printf("10 - inverter: Inverter a imagem horizontalmente ou verticalmente.\n");
            printf("11 - redimensionar: Redimensionar as dimensões da imagem.\n");
            printf("12 - pintarpixel: Pintar um determinado pixel da imagem.\n");
            printf("13 - espessura: Escolher a espessura da linha.\n");
            printf("14 - limpar: Pintar toda a imagem com a cor que estiver selecionada.\n");
            printf("99 - salvar: Salvar a imagem.\n");
            printf("0  - fim: Terminar comandos.\n");
            printf("\nDigite o comando: ");
            scanf("%s", comando); //Leitura dos dados pelo terminal
            printf("\n");
        } else{
            printf("\nComando: ");
            fscanf(lerEntradas, "%s", comando); //Leitura dos dados pelo arquivo de texto
            printf("%s ", comando);
        }
        
        minuscula(comando); //Converte as letras maiúsculas da string em letras minúsculas.

        //Lista de comandos
        if(strcmp(comando,"1") == 0 || strcmp(comando,"imagem") == 0 || strcmp(comando,"image") == 0){
            //Leitura das dimensões da imagem
            if (terminal == 1){
                printf("Digite as dimensoes da imagem (colunas x linhas):\n");
                scanf("%d %d", &colunasImagem, &linhasImagem); //Leitura dos dados pelo terminal
            } else{
                fscanf(lerEntradas, "%d %d", &colunasImagem, &linhasImagem); //Leitura dos dados pelo arquivo de texto
                printf("%d %d", colunasImagem, linhasImagem);
            }
            alocaImagem(&img, colunasImagem, linhasImagem); //Criar uma nova imagem com as dimensões escolhidas
        
        } else if(strcmp(comando,"2") == 0 || strcmp(comando,"cor") == 0 || strcmp(comando,"color") == 0){
            escolheCor(&cor, terminal, lerEntradas); //Selecionar uma cor

              
        } else if(strcmp(comando,"3") == 0 || strcmp(comando,"linha") == 0 || strcmp(comando,"line") == 0){
            if (terminal == 1){
                printf("Digite as coordenadas 'x' e 'y' dos pontos p1 e p2:\n");
                scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y); //Leitura dos dados pelo terminal
            } else{
                fscanf(lerEntradas, "%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y); //Leitura dos dados pelo arquivo de texto
                printf("%d %d %d %d", p1.x, p1.y, p2.x, p2.y);
            }
            linha(img, p1, p2, cor, espessuraLinha); //Traçar uma linha entre os pontos p1 e p2

        } else if(strcmp(comando,"4") == 0 || strcmp(comando,"poligono") == 0 || strcmp(comando,"polygon") == 0){
            poligono(img, cor, espessuraLinha, terminal, lerEntradas); //Desenhar um poligono com 'n' lados

        } else if(strcmp(comando,"5") == 0 || strcmp(comando,"circulo") == 0 || strcmp(comando,"circle") == 0){
            //Escolher as coordenadas do centro do circulo (xc,yc) e o raio.
            if (terminal == 1){
                printf("Digite as coordenadas do centro do circulo (xc, yc):\n");
                scanf("%d %d", &xc, &yc);
                printf("Digite o raio do circulo: \n");
                scanf("%d", &raio);
            } else{
                fscanf(lerEntradas, "%d %d %d", &xc, &yc, &raio);
                printf("%d %d %d", x, y, raio);
            }
            circulo(img, xc, yc, raio, cor, espessuraLinha); //Desenhar circulo

        } else if(strcmp(comando,"6") == 0 || strcmp(comando,"paralelepipedo") == 0 || strcmp(comando,"parallelepiped") == 0){
            if (terminal == 1){
                printf("Digite as coordenadas (x,y) a partir do qual o paralelepípedo vai ser gerado:\n");
                scanf("%d %d", &prisma.verticeInicial.x, &prisma.verticeInicial.y);
                printf("Digite as a dimensões do paralelepípedo (altura, largura, comprimento):\n");
                scanf("%d %d %d", &prisma.altura, &prisma.largura, &prisma.comprimento);
                printf("Digite o ângulo de rotação do paralelepípedo:\n");
                scanf("%d", &prisma.anguloRotacao);
            } else{
                fscanf(lerEntradas, "%d %d %d %d %d %d", &prisma.verticeInicial.x, &prisma.verticeInicial.y,  &prisma.altura, &prisma.largura, &prisma.comprimento, &prisma.anguloRotacao);
                printf("%d %d %d %d %d %d", prisma.verticeInicial.x, prisma.verticeInicial.y, prisma.altura, prisma.largura, prisma.comprimento, prisma.anguloRotacao);
            }
            paralelepipedo(img, cor, prisma, espessuraLinha); //Desenhar um paralelepipedo

        } else if(strcmp(comando,"7") == 0 || strcmp(comando,"preencher") == 0 || strcmp(comando,"fill") == 0){
            //Escolher as coordenadas do pixel a ser preenchido
            if (terminal == 1){
                printf("Digite as coordenadas do pixel a ser preenchido (coluna x linha):\n");
                scanf("%d %d", &x, &y);
            } else{
                fscanf(lerEntradas, "%d %d", &x, &y);
                printf("%d %d", x, y);
            }
            corInicial = contaGota(img, x, y); //Obter cor do pixel
            preencher(img, x, y, cor, corInicial); //Preencher com cor uma região da imagem

        } else if(strcmp(comando,"8") == 0 || strcmp(comando,"plotar") == 0 || strcmp(comando,"plot") == 0){
            plotar(img, cor, espessuraLinha, terminal, lerEntradas); //Plotar função polinomial
        
        } else if(strcmp(comando,"9") == 0 || strcmp(comando,"rotacionar") == 0 || strcmp(comando,"girar") == 0 || strcmp(comando,"rotate") == 0){
            rotacionar(&img, terminal, lerEntradas); //Rotacionar a imagem

        } else if(strcmp(comando,"10") == 0 || strcmp(comando,"inverter") == 0 || strcmp(comando,"reverse") == 0){
            inverter(img, terminal, lerEntradas); //Inverter a imagem

        } else if(strcmp(comando,"11") == 0 || strcmp(comando,"redimensionar") == 0 || strcmp(comando,"resize") == 0){
            redimensionar(&img, terminal, lerEntradas); //Redimensionar dimensões da imagem

        } else if(strcmp(comando,"12") == 0 || strcmp(comando,"pintarpixel") == 0 || strcmp(comando,"paintpixel") == 0){
            //Escolher as coordenadas do pixel a ser pintado
            if (terminal == 1){
                printf("Digite as coordenadas do pixel a ser pintado (coluna x linha):\n");
                scanf("%d %d", &x, &y);
            } else{
                fscanf(lerEntradas, "%d %d", &x, &y);
                printf("%d %d", x, y);
            }
            pintarPixelmod(img, cor, x, y, espessuraLinha); //Pintar 1 pixel da imagem

        } else if(strcmp(comando,"13") == 0 || strcmp(comando,"espessura") == 0 || strcmp(comando,"thickness") == 0){
            espessura(&espessuraLinha, terminal, lerEntradas); //Escolher espessura das linhas 

        } else if(strcmp(comando,"14") == 0 || strcmp(comando,"limpar") == 0 ||strcmp(comando,"clear") == 0){
            limpar(img, cor); //Pintar toda a imagem com a última cor selecionada

        } else if(strcmp(comando,"99") == 0 || strcmp(comando,"salvar") == 0 || strcmp(comando,"save") == 0){
            //Nome do arquivo: nomeArquivo
            if (terminal == 1){
                printf("Nome do arquivo:\n");
                scanf("%s", nomeArquivo); //Leitura dos dados pelo terminal
            } else{
                fscanf(lerEntradas, "%s", nomeArquivo); //Leitura dos dados pelo arquivo de texto
                printf("%s", nomeArquivo);
            }
            salvar(img, nomeArquivo); //Salvar imagem

        } else if(strcmp(comando,"0") == 0 || strcmp(comando,"fim") == 0 || strcmp(comando,"end") == 0){
            printf("\nFinalizou comandos!\n\n"); //Fim do programa
            strcpy(comando,"end");
        
        } else{
            printf("\nCOMANDO INVÁLIDO! Fim!\n\n"); //Erro: Comando inválido e finaliza o programa
            strcpy(comando,"end");
        }

    }       
    
    if (terminal == 0){
        fclose(lerEntradas); //Fecha arquivo de texto
    }

    salvar(img, "imagem"); //Salva última imagem gerada
    desalocaImagem(&img); //Desalocando matriz de pixels que forma a imagem

    return 1;
}