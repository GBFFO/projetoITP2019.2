#include "funcoes.h"
#include "string.h"

/**
 * Essa função converte as letras maiúsculas de uma string em letras minúsculas.
 * 
 * @param string - Entrada da palavra que será convertida totalmente para letras minúsculas
 * @return int 
 * @version 18-11-2019
 * @author Danilo Micaías Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva
 */
int minuscula(char *string){
    int tamanhoString;

    tamanhoString = strlen(string);

    for(int i=0; i<tamanhoString; i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32; //Converte a letra em minúscula
        }
    }

    return 1;
}