#include "stdio.h"
#include "funcoes.h"
#include "string.h"

/**
 * Esta função inicializa diversas variáveis do programa e verifica se a entrada dos dados será feita pelo terminal
 * ou pelo arquivo de texto
 * @param img - Referência para a imagem gerada (inicialmente uma imagem de dimensões 100 x 50 na cor branca é alocada dinamicamente)
 * @param cor - Referência para a cor RGB a ser utilizada nas próximas operações (inicialmente a cor selecionada é preta)
 * @param espessuraLinha - Referência para a espessura da linha a ser utilizada nas linhas, desenhos, funções trigonométricas etc (inicialmente a espessura vale 1)
 * @param comando - String com o comando que foi informado pelo usuário para executar alguma ação no programa
 * @param argc - Quantidade de argumentos no array
 * @param argv - Referêcia para os argumentos passados 
 * @param terminal - Identifica se as entradas dos dados são feitas pelo terminal ou pelo arquivo de texto
 * @param lerEntradas - Referência para o arquivo de texto
 * @return Retorna 1 se variáveis foram inicializadas corretamente ou Retorna 0 caso as variáveis não tenham sido inicializadas corretamente
 * @version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

int inicializa(Imagem *img, Pixel *cor, int *espessuraLinha, char *comando, int argc, char **argv, int *terminal, FILE **lerEntradas){

    //DEFININDO SE A ENTRADA DOS DADOS SERÁ PELO TERMINAL OU PELO ARQUIVO DE TEXTO
    if (argc == 1){
        printf("\nEntrada dos dados pelo ARQUIVO DE TEXTO\n");
        *terminal = 0; //Arquivo de texto
        *lerEntradas = fopen("entradas.txt", "r"); //Abre arquivo entradas.txt para leitura dos dados
        if (*lerEntradas == NULL){
            printf("Erro na leitura do arquivo de 'entradas.txt'.\n"); //Arquivo entradas.txt não identificado
        return 0;
        }
    } else if(argc > 1){
        if (strcmp(argv[1], "terminal") == 0){
            *terminal = 1; //Terminal
            printf("\nEntrada dos dados pelo TERMINAL\n");
        } else{
            *terminal = 0; //Arquivo de texto
            *lerEntradas = fopen(argv[1], "r"); //Abre arquivo de texto para leitura dos dados
            if (*lerEntradas == NULL){
                printf("Erro na leitura do arquivo '%s'.\n", argv[1]); //Arquivo de texto não identificado
                return 0;
            }
            printf("\nEntrada dos dados pelo ARQUIVO DE TEXTO\n");
        }    
    }
    
    //INICIALIZAÇÕES DAS VARIÁVEIS
    strcpy(comando,"inicio"); //Atribuição inicial para a string comando
    //Cor inicial é preta
    cor->R = 0;
    cor->G = 0;
    cor->B = 0;
    *espessuraLinha = 1; //Espessura da linha
    strcpy(img->formato, "P3"); //Formato do arquivo .ppm
    img->RGBmax = 255; //RGB máximo
    alocaImagem(img, 100, 50); //Imagem inicial com dimensões 100 por 50 na cor branca
    return 1;
}