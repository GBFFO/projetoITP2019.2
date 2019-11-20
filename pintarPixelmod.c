#include "stdio.h"
#include "funcoes.h"

/* ####################### ESPESSURA DO PIXEL/LINHA #######################
    Explicações: 
        - A espessura do pixel/linha pode possuir três tamanhos: 1, 3 e 5.

    Exemplos: 
        - Dada uma matriz A de dimensão 5x5.
        - Considerando que o pixel central da matriz A vai ser pintado.
        - Elementos 1 representam os pixels pintados, já os elementos 0 não foram pintados.

            (a) Espessura = 1          (b) Espessura = 3           (c) Espessura = 5

               | 0 0 0 0 0 |              | 0 0 0 0 0 |               | 0 0 1 0 0 |  
               | 0 0 0 0 0 |              | 0 0 1 0 0 |               | 0 1 1 1 0 |
               | 0 0 1 0 0 |              | 0 1 1 1 0 |               | 1 1 1 1 1 |
               | 0 0 0 0 0 |              | 0 0 1 0 0 |               | 0 1 1 1 0 |
               | 0 0 0 0 0 |              | 0 0 0 0 0 |               | 0 0 1 0 0 |

*/

//Essa função pinta um pixel cujas coordenadas foram informadas pelo usuário.
int pintarPixelmod(Imagem img, Pixel cor, int x, int y, int espessura){

    //Pixel fora da imagem
    if (x <= 0 || y <= 0 || x > img.col || y > img.lin){
        //printf("    Erro: Pixel fora da imagem.\n");
        return 0;
    }
    
    //Pintando pixel selecionado
    img.pixel[y-1][x-1] = cor; //Espessura 1: Pinta o pixel selecionado

    //Espessura 3 ou 5: 
    if (espessura == 3 || espessura == 5){
        //Pinta os pixels norte, sul, leste e oeste, desde que estejam na imagem.
        if(y<img.lin){
            img.pixel[y-1+1][x-1] = cor; //Sul
        }
        if(y>1){
            img.pixel[y-1-1][x-1] = cor; //Norte
        }
        if(x<img.col){
            img.pixel[y-1][x-1+1] = cor; //Leste
        }
        if(x>1){
            img.pixel[y-1][x-1-1] = cor; //Oeste
        }
        //Espessura 5: 
        if(espessura == 5){
            //Pinta os pixels duas posições ao sul, ao norte, ao leste e ao oeste do pixel central, desde que estejam na imagem.
            if(y<img.lin-1){
                img.pixel[y-1+2][x-1] = cor; //Sul Sul
            }
            if(y>2){
                img.pixel[y-1-2][x-1] = cor; //Norte Norte 
            }
            if(x<img.col-1){
                img.pixel[y-1][x-1+2] = cor; //Leste Leste
            }
            if(x>2){
                img.pixel[y-1][x-1-2] = cor; //Oeste Oeste
            }
            //Pinta os pixels ao sudoeste, noroeste, sudeste e nordeste, desde que estejam na imagem.
            if(y<img.lin && x>1){
                img.pixel[y-1+1][x-1-1] = cor; //Sudoeste
            }
            if(y>1 && x>1){
                img.pixel[y-1-1][x-1-1] = cor; //Noroeste
            }
            if(y<img.lin && x<img.col){
                img.pixel[y-1+1][x-1+1] = cor; //Sudeste
            }
            if(y>1 && x<img.col){
                img.pixel[y-1-1][x-1+1] = cor; //Nordeste
            }
        }
    }

    return 1;
}