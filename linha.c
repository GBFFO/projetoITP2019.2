#include "funcoes.h"
#include "stdio.h"

/**
 * Esta função traça uma linha entre os pontos p1(x1,y1) e p2(x2,y2). 
 * 
 * @param img - Referencia para a imagem na qual a linha será desenhada
 * @param p1 - Ponto do início da linha
 * @param p2 - Ponto final da linha
 * @param cor - Cor RGB que a linha será colorida
 * @param espessuraLinha - Espessura/densidade da linha
 * @return int
 * @version 18-11-2019
 * @author Danilo Micaías Lima da Silva
 * @author Gabriel Bessa de Freitas Fuezi Oliva 
 */

//Traça uma linha entre os pontos p1(x1,y1) e p2(x2,y2). 
int linha(Imagem img, Ponto p1, Ponto p2, Pixel cor, int espessuraLinha){
    int x, y, quociente, temporario, horizontal, vertical, primeiro, segundo, setimo, oitavo;
    float alfa, beta, resto, deltaY, deltaX;

    //Linha traçada do ponto com menor coordenada 'x' para o ponto com maior coordenada 'x'
    if(p1.x > p2.x){
        //Troca coordenadas 'x' dos pontos p1 e p2
        temporario = p2.x;
        p2.x = p1.x;
        p1.x = temporario;
        //Troca coordenadas 'y' dos pontos p1 e p2
        temporario = p2.y;
        p2.y = p1.y;
        p1.y = temporario;
    }

    //Equação da reta: y = alfa*x + beta, em que alfa = deltaY/deltaX = (p2.y - p1.y)/(p2.x - p1.x)  
    deltaY = p2.y - p1.y;
    deltaX = p2.x - p1.x;
    alfa = deltaY/deltaX;   //Coeficiente angular da reta
    beta = p2.y - alfa*p2.x;    //Coeficiente linear da reta

    //Definindo octante pela inclinação do coeficiente angular da reta
    horizontal = (deltaY == 0); //Linha horizontal
    vertical = (deltaX == 0); //Linha vertical
    primeiro = (alfa > 0 && alfa <= 1); //Primeiro octante
    segundo = ((1/alfa) > 0 && (1/alfa) < 1); //Segundo octante
    setimo = ((1/alfa) > -1 && (1/alfa) < 0); //Setimo octante
    oitavo = (alfa >= -1 && alfa < 0); //Oitavo octante
    //Obs: Como a linha sempre é traçada da esquerda para a direita, não precisa testar demais octantes.
 
    //Preenchimento da linha parte do ponto p1
    x = p1.x;
    y = p1.y;

    //Verifica se as coordenadas do primeiro ponto p1 está na imagem
    if (x > 0 && x<=img.col && y > 0 && y<=img.lin){
        pintarPixelmod(img, cor, x, y, espessuraLinha);
    }

    //Verifica se os pontos p1 e p2 são iguais
    if (p1.x == p2.x && p1.y == p2.y){
        return 1;
    }

    //Parada acontece quando ponto(x,y) for igual ao ponto p2(p2.x,p2.y)
    while (1){

        //Preencher linha horizontal (alfa = 0)
        if (horizontal){        
            x++;
        }

        //Preencher linha vertical (1/alfa tende a 0)
        if (vertical){         
            if(y < p2.y){
                y++; //Cima
            } else{
                y--; //Baixo
            }
        }

        //Primeiro ou Oitavo octante
        if (primeiro || oitavo){
            x++; //Direita
            quociente = alfa*x + beta;
            resto = alfa*x + beta - quociente;
            y = quociente;
            //Reta passa mais perto do centro do pixel acima: Primeiro octante
            if (resto >= 0.5){
                y++; //Cima
            }
            //Reta passa mais perto do centro do pixel abaixo: Oitavo octante
            if (resto <= -0.5){
                y--; //Baixo
            }
        }

        //Segundo ou Setimo octante
        if (segundo || setimo){
            if (segundo){
                y++; //Cima
            } else{
                y--; //Baixo    
            }
            
            quociente = (1/alfa)*y - (beta/alfa);
            resto = (1/alfa)*y - (beta/alfa) - quociente;
            x = quociente;
            //Reta passa mais perto do centro do pixel a direita: Segundo ou Setimo octante
            if (resto >= 0.5){
                x++; //Direita 
            }
        }

        //Verifica se as coordenadas do pixel a ser pintado está na imagem
        if (x > 0 && x<=img.col && y > 0 && y<=img.lin){
            //Preenche pixel
            pintarPixelmod(img, cor, x, y, espessuraLinha);
        }

        if (x == p2.x && y == p2.y){
            break; //Encontrou
        }
    }

    return 1;
}

