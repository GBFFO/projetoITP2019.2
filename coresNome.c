#include "stdio.h"
#include "string.h"
#include "funcoes.h"

/**
 * Esta função possui valores RGB de diversas cores que podem ser escolhidas nominalmente
 * Observação: As seguintes cores podem ser escolhidas nominalmente
 *      branco, preto, cinza, vermelho, verde, verdeclaro, verdeescuro, azul, azulclaro, azulescuro,
 *      amarelo, laranja, marrom, roxo, magenta, rosa e bege.
 * @param corNome - Referência para o nome da cor
 * @param cor - Referência para a cor RGB a ser utilizada nas próximas operações
 * @return Retorna 1 se for válido o nome da cor e Retorna 0 se o nome da cor não foi válido
 * @version 18-11-2019
 * @author Danilo Micaias Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */

//Essa função possui valores RGB de diversas cores que podem ser escolhidas nominalmente.
int coresNome(char *corNome, Pixel *cor){
    unsigned char paleta[3];
    bool achouCor;
    achouCor = false;

    minuscula(corNome); //Converte as letras maiúsculas da string em letras minúsculas

    // ################# PALETA DE CORES CADASTRADAS ################# //
    //PRETO
    if (strcmp(corNome, "preto") == 0 || strcmp(corNome, "preta") == 0){
        unsigned char paleta[3] = {0, 0, 0};
        achouCor = true;
    }

    //BRANCO
    if (strcmp(corNome, "branco") == 0 || strcmp(corNome, "branca") == 0){
        unsigned char paleta[3] = {255, 255, 255};
        achouCor = true;
    }

    //CINZA
    if (strcmp(corNome, "cinza") == 0){
        unsigned char paleta[3] = {128, 128, 128};
        achouCor = true;
    }

    //VERMELHO
    if (strcmp(corNome, "vermelho") == 0 || strcmp(corNome, "vermelha") == 0){
        unsigned char paleta[3] = {255, 0, 0};
        achouCor = true;
    }

    //VERDE
    if (strcmp(corNome, "verde") == 0){
        unsigned char paleta[3] = {0, 128, 0};
        achouCor = true;
    }

    //VERDECLARO
    if (strcmp(corNome, "verdeclaro") == 0){
        unsigned char paleta[3] = {0, 255, 0};
        achouCor = true;
    }

    //VERDEESCURO
    if (strcmp(corNome, "verdeescuro") == 0){
        unsigned char paleta[3] = {0, 100, 0};
        achouCor = true;
    }

    //AZUL
    if (strcmp(corNome, "azul") == 0){
        unsigned char paleta[3] = {0, 0, 255};
        achouCor = true;
    }

    //AZULCLARO
    if (strcmp(corNome, "azulclaro") == 0){
        unsigned char paleta[3] = {0, 255, 255};
        achouCor = true;
    }

    //AZULESCURO
    if (strcmp(corNome, "azulescuro") == 0){
        unsigned char paleta[3] = {0, 0, 139};
        achouCor = true;
    }

    //AMARELO
    if (strcmp(corNome, "amarelo") == 0 || strcmp(corNome, "amarela") == 0){
        unsigned char paleta[3] = {255, 255, 0};
        achouCor = true;
    }

    //LARANJA
    if (strcmp(corNome, "laranja") == 0){
        unsigned char paleta[3] = {255, 140, 0};
        achouCor = true;
    }

    //MARROM
    if (strcmp(corNome, "marrom") == 0){
        unsigned char paleta[3] = {139, 69, 19};
        achouCor = true;
    }

    //ROXO
    if (strcmp(corNome, "roxo") == 0 || strcmp(corNome, "roxa") == 0){
        unsigned char paleta[3] = {128, 0, 128};
        achouCor = true;
    }

    //MAGENTA
    if (strcmp(corNome, "magenta") == 0 || strcmp(corNome, "majenta") == 0){
        unsigned char paleta[3] = {255, 0, 255};
        achouCor = true;
    }

    //ROSA
    if (strcmp(corNome, "rosa") == 0){
        unsigned char paleta[3] = {255, 192, 203};
        achouCor = true;
    }

    //BEGE
    if (strcmp(corNome, "bege") == 0 || strcmp(corNome, "beje") == 0){
        unsigned char paleta[3] = {255, 253, 208};
        achouCor = true;
    }

    if(achouCor){
        cor->R = paleta[0];
        cor->G = paleta[1];
        cor->B = paleta[2];

        return 1; //Encontrou a cor
    } else{
        printf("\n  Cor não identificada.");
    }

    return 0; //Não encontrou a cor 
}
