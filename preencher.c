#include "funcoes.h"

//Essa função preenche com cor uma determinada região da imagem a partir das coordenadas (xi,yi) informadas. 
int preencher(Imagem img, int x, int y, Pixel cor, Pixel corInicial){
    int pixelsIguais = (cor.R == corInicial.R && cor.G == corInicial.G && cor.B == corInicial.B);
    
    //Pixel fora da imagem ou cor a ser pintada igual a cor do pixel inicial: Caso base
    if (x <= 0 || y <= 0 || x>img.col || y>img.lin || pixelsIguais){
        return 0;
    }

    //Verifica se o pixel possui a mesma cor inicial do pixel com coordenadas (xi,yi)
    if (img.pixel[y-1][x-1].R == corInicial.R &&
        img.pixel[y-1][x-1].G == corInicial.G &&
        img.pixel[y-1][x-1].B == corInicial.B ){
        
        //Pinta pixel com a última cor selecionada pelo usuário
        img.pixel[y-1][x-1] = cor;

        preencher(img, x+1, y, cor, corInicial); //Direita
        preencher(img, x-1, y, cor, corInicial); //Esquerda
        preencher(img, x, y-1, cor, corInicial); //Acima
        preencher(img, x, y+1, cor, corInicial); //Abaixo             
    }

    //Caso base: Pixel tem cor diferente da cor inicial do pixel de coordenadas (xi, yi)
    return 0;

}
