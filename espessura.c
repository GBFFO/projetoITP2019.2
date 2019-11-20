#include "stdio.h"
#include "funcoes.h"


/**
 * Esta função permite que o usuário escolha a espessura da linha a ser usada nas próximas operações
 * Explicações: A espessura da linha pode possuir três tamanhos - 1, 3 e 5.
 *      Exemplos: 
 *           - Dada uma matriz A de dimensão 5x5.
 *           - Considerando que o pixel central da matriz A vai ser pintado.
 *           - Elementos 1 representam os pixels pintados, já os elementos 0 não foram pintados.
 *   
 *               (a) Espessura = 1          (b) Espessura = 3           (c) Espessura = 5
 *   
 *                  | 0 0 0 0 0 |              | 0 0 0 0 0 |               | 0 0 1 0 0 |  
 *                  | 0 0 0 0 0 |              | 0 0 1 0 0 |               | 0 1 1 1 0 |
 *                  | 0 0 1 0 0 |              | 0 1 1 1 0 |               | 1 1 1 1 1 |
 *                  | 0 0 0 0 0 |              | 0 0 1 0 0 |               | 0 1 1 1 0 |
 *                  | 0 0 0 0 0 |              | 0 0 0 0 0 |               | 0 0 1 0 0 |
 *    
 * @param cor - Referência para a espessura da linha
 * @param terminal - Identifica se as entradas dos dados são feitas pelo terminal ou pelo arquivo de texto
 * @param lerEntradas - Referência para o arquivo de texto
 * @return Retorna 1 se a espessura da linha informada pelo usuário foi válida ou Retorna 0 se a espessura não foi válida
 * @version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

//Essa função permite a escolha da espessura da linha para as próximas operações (1, 3 ou 5).
int espessura(int *espessuraLinha, int terminal, FILE *lerEntradas){
    float espessuraValida;
    bool entradaValida;

    //Escolher a espessura
    if (terminal == 1){
        printf("Digite a espessura da linha (1, 3 ou 5):\n");
        scanf("%f", &espessuraValida); //Leitura dos dados pelo terminal
    } else{
        fscanf(lerEntradas, "%f", &espessuraValida); //Leitura dos dados do arquivo entradas.txt
        printf("%.1f ", espessuraValida);
    }

    //Espessuras válidas: 1, 3 ou 5.
    entradaValida = (espessuraValida == 1 || espessuraValida == 3 || espessuraValida == 5);

    //Verificando se o valor da espessura informada é válida
    if(entradaValida){
        *espessuraLinha = espessuraValida;
    }else{
        printf("\n  Dado inválido! Espessura não foi modificada.");
        return 0;
    }

    return 1;
}