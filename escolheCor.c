#include "stdio.h"
#include "funcoes.h"
#include "stdlib.h"

/**
 * Esta função permite que o usuário escolha as cores RGB a serem utilizadas nas próximas operações
 * Observação: É possível escrever a cor nominalmente ao invés dos valores R, G e B. Neste caso, as seguintes
 * cores podem ser escolhidas pelos nomes:
 *      branco, preto, cinza, vermelho, verde, verdeclaro, verdeescuro, azul, azulclaro, azulescuro,
 *      amarelo, laranja, marrom, roxo, magenta, rosa e bege.
 * @param cor - Referência para a cor RGB a ser utilizada nas próximas operações
 * @param terminal - Identifica se as entradas dos dados são feitas pelo terminal ou pelo arquivo de texto
 * @param lerEntradas - Referência para o arquivo de texto
 * @version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

//Usuário escolhe as cores RGB a serem utilizadas nas próximas operações. 
void escolheCor(Pixel *cor, int terminal, FILE *lerEntradas){
    char corNome[100];
    Pixel corAtual;

    //Usuário pode ter escolhido a cor "nominalmente"
    if (terminal == 1){
        printf("Digite as cores RGB ou o nome da cor:\n");
        scanf("%s", corNome); //Leitura dos dados pelo terminal
    } else{
        fscanf(lerEntradas,"%s", corNome); //Leitura dos dados pelo arquivo de texto
        printf("%s ", corNome);
    }

    //Verifica se o primeiro caractere da string é algum numero
    if(corNome[0] >= '0' && corNome[0] <= '9'){

        //A cor não foi informada nominalmente
        corAtual.R = atoi(corNome); //Converte a string em um numero inteiro (sem sinal) que equivale ao RED do pixel

        //Obter informações adicionais, isto é, GREEN e BLUE do pixel
        if(terminal == 1){
            scanf("%hhu %hhu", &corAtual.G, &corAtual.B); //Leitura dos dados pelo terminal
        } else{
            fscanf(lerEntradas, "%hhu %hhu", &corAtual.G, &corAtual.B); //Leitura dos dados pelo arquivo de texto
            printf("%hhu %hhu", corAtual.G, corAtual.B);
        }
        //Atribui as cores RGB selecionadas pelo usuário aos conteúdos do ponteiro *cor
        cor->R = corAtual.R;
        cor->G = corAtual.G;
        cor->B = corAtual.B;
    } else{
        //A cor foi informada nominalmente
        coresNome(corNome, &*cor); //Função que possui informações RGB de diversas cores
    }

}