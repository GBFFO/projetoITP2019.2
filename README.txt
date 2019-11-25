Projeto 3ª Unidade: ITP 2019.2

Dupla: 
	Danilo Micaías Lima da Silva
	Gabriel Bessa de Freitas Fuezi Oliva

Professor: 
	André Maurício Cunha Campos

Data da atualização: 
	18/11/2019 

########## COMPILAR ##########

gcc alocaImagem.c circulo.c coresNome.c desalocaImagem.c escolheCor.c limpar.c linha.c poligono.c preencher.c rotacionar.c inverter.c redimensionar.c plotar.c  salvar.c pintarPixelmod.c espessura.c contaGota.c minuscula.c inicializa.c paralelepipedo.c projeto.c -o projeto -lm


########## GUIA DE UTILIZAÇÃO DO PROGRAMA ##########

1) INICIALIZAÇÃO DO PROGRAMA
 Há duas formas de gerar uma imagem com o programa, a partir de comandos executados pelo TERMINAL ou comandos a partir de um ARQUIVO DE TEXTO.
 
 1.1) TERMINAL: 
  1.1.1) Para que o programa seja executado pelo terminal, digite: ./projeto terminal
  1.1.2) Neste caso o terminal exibirá uma série de comandos que podem ser executados pelo usuário e quais informações devem se inseridas em cada um desses comandos (interação usuário vs terminal).
		
 1.2) ARQUIVO DE TEXTO:
  1.2.1) Para que o programa seja executado a partir de comandos já inseridos em um arquivo de texto, é possível que isto seja feito de duas formas:
   1.2.1.1) Para que o programa seja executado por um arquivo de texto com nome 'nomearquivo.txt', digite: ./projeto nomearquivo.txt
   1.2.1.2) Para que o programa seja executado por um arquivo de texto com nome 'entradas.txt' (padrão), digite: ./projeto 


2) INFORMAÇÕES IMPORTANTES
 2.1) Considera-se que uma imagem de dimensões colunas x linhas tem o pixel (1,1) como sendo o pixel superior esquerdo da imagem e o pixel (colunas, linhas) o do canto inferior direito da imagem.
 2.2) Para finalizar o programa, deve ser inserido o comando 'fim, 'end' ou '0'. 
	Obs: O arquivo de texto deve conter um desses comandos para que a execução das operações seja terminada.


3) COMANDOS DO PROGRAMA

 3.1) Comando: imagem
  3.1.1) Definição: Cria uma nova imagem com dimensões escolhidas (colunas x linhas)
  3.1.2) Forma: imagem COLUNAS LINHAS
  3.1.3) Exemplo: Gerar nova imagem com dimensões 800 x 600
  3.1.3.1) imagem 800 600


 3.2) Comando: cor
  3.2.1) Definição: Seleciona uma cor RGB a ser utilizada nas próximas operações
  3.2.2) Forma: cor R G B
  3.2.3) Exemplo: Selecionar a cor vermelha
  3.2.3.1) cor 250 0 0
  3.2.2.2) cor vermelho
	Obs: É possível ao invés de escolher as cores R, G e B após ser informado o comando 'cor' utilizar o nome de 17 cores pré-definidas
branco, preto, cinza, vermelho, verde, verdeclaro, verdeescuro, azul, azulclaro, azulescuro, amarelo, laranja, marrom, roxo, magenta,rosa e bege


 3.3) Comando: linha
  3.3.1) Definição: Traça uma linha entre dois pontos
  3.3.2) Forma: linha x1 y1 x2 y2
  3.3.3) Exemplo: Traçar uma linha entre os pontos com coordenadas (10,20) e (15 25)
  3.3.3.1) linha 10 20 15 25


 3.4) Comando: poligono
  3.4.1) Definição: Desenha um poligono com n vértices
  3.4.2) Forma: poligono nVertices x1 y1 x2 y2 x3 y3 ... xn yn
  3.4.3) Exemplo: Desenhar um poligono com 3 vertices com coordenadas (1,1), (10,20) e (5, 100)
  3.4.3.1) poligono 3 1 1 10 20 5 100


 3.5) Comando: circulo
  3.5.1) Definição: Desenha um circulo com centro (xc,yc) e raio R
  3.5.2) Forma: circulo xc yc R
  3.5.3) Exemplo: Desenhar um circulo com centro posicionado na coordenada (30,20) e raio 10
  3.5.3.1) circulo 30 20 10


 3.6) Comando: paralelepipedo
  3.6.1) Definição: Desenha um paralelepipedo dadas a altura, largura, comprimento, ângulo de rotação e a coordenada de 1 vértice (xi,yi)
  3.6.2) Forma: paralelepipedo xi yi Altura Largura Comprimento anguloRotacao
  3.6.3) Exemplo: Desenhar um paralelepipedo a partir do vértice 100 200, com altura 50, largura 30 e comprimento 80 e rotação de 45 graus
  3.6.3.1) paralelepipedo 100 200 50 30 80 45


 3.7) Comando: preencher
  3.7.1) Definição: Preenche com cor uma determinada região da imagem dada a coordenada (xi,yi) a partir da qual a imagem vai ser preenchida 
  3.7.2) Forma: preencher xi yi
  3.7.3) Exemplo: Preencher a partir da coordenada (50,60) uma determinada região da imagem 
  3.7.3.1) preencher 50 60
	Obs: Usa-se a cor que estiver selecionada naquele momento


 3.8) Comando: plotar
  3.8.1) Definição: Plota uma função polinominal de grau 'n' dado o grau 'n' do polinomio e os coeficiente (ai), 
	 - Considera-se o ponto (0,0) como sendo o centro da imagem, o x cresce para a direita e o y para cima. 
	 - Função polinomial do tipo: y = an*x^n + a(n-1)*x^(n-1) + ... + a2*x^2 + a1*x^1 + a0*x^0
  3.8.2) Forma: plotar n an a(n-1) a(n-2) ... a0
  3.8.3) Exemplos:
  3.8.3.1) Plotar função do 1º grau y = x + 10
	   plotar 1 1 10
  3.8.3.2) Plotar função do 2º grau y = -5x^2 + 14x - 10
	   plotar 2 -5 14 -10
  3.8.3.3) Plotar função do 3º grau y = 0.01x^3 + 0x^2 + 0x^1 + 15
	   plotar 3 0.01 0 0 15
  3.8.3.4) Plotar função y = 100
	   plotar 0 100


 3.9) Comando: rotacionar
  3.9.1) Definição: Rotaciona a imagem 90, 180 ou 270 graus no sentido horario
  3.9.2) Forma: rotacionar anguloRotacao
  3.9.3) Exemplos:
  3.9.3.1) Rotacionar a imagem em 90 graus (para a direita). Possíveis comandos:
	   rotacionar 90
	   rotacionar direita
	   girar 90
	   girar direita
  3.9.3.2) Rotacionar a imagem em 180 graus (de cabeça para baixo). Possíveis comandos:
	   rotacionar 180
	   girar 180
  3.9.3.3) Rotacionar a imagem em 270 graus (para a esquerda). Possíveis comandos:
	   rotacionar 270
	   rotacionar esquerda
	   girar 270
	   girar esquerda


 3.10) Comando: inverter
  3.10.1) Definição: Inverte a imagem horizontalmente ou verticalmente (imagem é 'espelhada')
  3.10.2) Forma: inverter tipoInversao
  3.10.3) Exemplos:
  3.10.3.1) Inverter a imagem horizontalmente. Possíveis comandos:
	    inverter horizontalmente
	    inverter horizontal
  3.10.3.1) Inverter a imagem verticalmente. Possíveis comandos:
	    inverter verticalmente
	    inverter vertical


 3.11) Comando: redimensionar
  3.11.1) Definição: Redimensiona uma imagem já existente informando a nova quantidade de colunas x linhas
	  - A imagem original não é apagada
	  - Se as dimensões forem maiores que a imagem original, a nova região externa da imagem é branca
	  - Se as dimensões forem menores que a imagem original, a imagem original é cortada
  3.11.2) Forma: redimensionar novasColunas novasLinhas
  3.11.3) Exemplo: Redimensionar uma imagem para que ela fique com dimensões 150 x 200
  3.11.3.1) redimensionar 150 200


 3.12) Comando: pintarpixel
  3.12.1) Definição: Pinta um determinado pixel da imagem dadas as coordenadas (xPixel, yPixel) do pixel
  3.12.2) Forma: pintarpixel xPixel yPixel
  3.12.3) Exemplo: Pintar o pixel de coordenadas 250 x 600
  3.12.3.1) pintarpixel 250 600
		

 3.13) Comando: espessura
  3.13.1) Definição: Escolhe a espessura das linhas e desenhos a ser usada nas próximas operações
	  - Possíveis valores de espessura: 1, 3 ou 5
      Explicação: 
           - Dada uma imagem A de dimensão 5x5.
           - Considerando que o pixel central da imagem A vai ser pintado.
           - Elementos 1 representam os pixels pintados, já os elementos 0 os pixels que não foram pintados.
   
               (a) Espessura = 1          (b) Espessura = 3           (c) Espessura = 5
   
                  | 0 0 0 0 0 |              | 0 0 0 0 0 |               | 0 0 1 0 0 |  
                  | 0 0 0 0 0 |              | 0 0 1 0 0 |               | 0 1 1 1 0 |
                  | 0 0 1 0 0 |              | 0 1 1 1 0 |               | 1 1 1 1 1 |
                  | 0 0 0 0 0 |              | 0 0 1 0 0 |               | 0 1 1 1 0 |
                  | 0 0 0 0 0 |              | 0 0 0 0 0 |               | 0 0 1 0 0 |

  3.13.2) Forma: espessura Tamanho
  3.13.3) Exemplo: Escolher espessura de tamanho 3
  3.13.3.1) espessura 3


 3.14) Comando: limpar
  3.14.1) Definição: Pinta todos os pixels da imagem com a última cor que estiver selecionada antes de se executar o comando limpar
  3.14.2) Forma: limpar
  3.14.3) Exemplo: Limpar toda uma imagem
  3.14.3.1) limpar


 3.15) Comando: salvar
  3.15.1) Definição: Salvar uma imagem com formato .ppm dado o nome da imagem
	  - Podem ser salvas diversas imagens com nomes distintos quando se estiver desenhando a imagem
	  - Por padrão, ao final dos comandos gerados, uma imagem com nome 'imagem.ppm' é gerada.
  3.15.2) Forma: salvar nomeImagem
  3.15.3) Exemplo: Salvar imagem com o nome Figura01
  3.15.3.1) salvar Figura01


 3.16) Comando: fim
  3.16.1) Definição: Finaliza a execução dos comandos
	  - Caso algum comando inválido seja executado, o programa também é encerrado.
	  - Nomes alternativos para finalizar o programa: 'end' ou '0'
  3.16.2) Forma: fim
  3.16.3) Exemplo: Encerrar comandos do programa
  3.16.3.1) fim


########## O QUE FARÍAMOS DIFERENTE? ##########
 - Utilizaríamos mais o GitHub para trocar os códigos e facilitar a identificação dos trechos que foram sendo modificados por cada integrante da dupla;
 - Reservaríamos mais tempo para tentar adicionar uma interface gráfica ao programa, visto que selecionar as coordenadas dos pixels para gerar uma imagem é algo muito trabalhoso (demanda muito tempo e paciência a depender da complexidade da imagem que se queira desenhar).


########## EXEMPLOS DE CÓDIGOS ##########

# BANDEIRA DO BRASIL #
imagem 400 250
cor verde
limpar
espessura 5
cor branco
plotar 2 -0.001 -0.15 10
plotar 2 -0.001 -0.15 5
espessura 1
cor azulescuro
circulo 200 125 70
preencher 200 80
preencher 200 170
cor verde
preencher 1 130
preencher 400 185
cor amarelo
poligono 4 200 30 370 125 200 220 30 125
preencher 200 31
circulo 200 125 70
cor branca
espessura 5
pintarpixel 220 110
espessura 3
pintarpixel 220 150
pintarpixel 200 150
pintarpixel 180 170
pintarpixel 150 125
pintarpixel 240 140
espessura 1
pintarpixel 205 160
pintarpixel 235 165
pintarpixel 211 180
pintarpixel 145 160
pintarpixel 155 190
salvar brasil
fim


# IMAGEM INICIAL DO PROJETO #
imagem 1000 500
cor 60 120 216
limpar
cor preta
circulo 350 150 50
cor 255 229 153
preencher 350 150
espessura 1
cor preta
poligono 8 150 350 550 200 950 300 650 290 625 320 560 295 450 345 450 290
linha 1 406 150 350
linha 950 300 1000 313
cor 183 183 183
preencher 500 250
cor preta
linha 560 295 560 500
cor 19 79 92
preencher 500 400
preencher 600 400
linha 560 295 560 500
cor preta
pintarpixel 560 295
salvar imagemProjeto
fim


# PRÉDIO DO IMD #
imagem 750 500
cor 143 164 100
limpar
espessura 5
cor branca
paralelepipedo 400 200 200 300 400 20
cor cinza
preencher 400 150
cor 115 0 5
preencher 200 250
preencher 600 250
espessura 1
cor preta
circulo 500 300 10
preencher 500 300
circulo 550 280 20
preencher 550 280
circulo 510 230 15
preencher 510 230
circulo 600 320 10
preencher 600 320
circulo 650 300 20
preencher 650 300
circulo 610 250 15
preencher 610 250
circulo 450 370 10
preencher 450 370
circulo 500 350 20
preencher 500 350
circulo 460 300 15
preencher 460 300
espessura 1
cor preta
paralelepipedo 150 150 30 0 100 20
preencher 149 151
paralelepipedo 150 200 30 0 100 20
preencher 149 201
paralelepipedo 150 250 30 0 100 20
preencher 149 251
paralelepipedo 285 200 30 0 100 20
preencher 284 201
paralelepipedo 285 250 30 0 100 20
preencher 284 251
paralelepipedo 285 300 30 0 100 20
preencher 284 301
paralelepipedo 350 330 10 40 60 20
cor branca
preencher 350 329
preencher 349 335
preencher 351 335
cor preta
linha 1 360 285 360
linha 1 400 396 400
cor bege
preencher 1 380
cor preta
linha 390 341 390 394
linha 320 330 320 368
preencher 389 360
salvar IMD
fim

# BANDEIRA DE ISRAEL #
image 800 400
cor azul
espessura 5
linha 0 20 800 20
linha 0 50 800 50 
preencher 400 30
linha 0 350 800 350
linha 0 380 800 380 
preencher 400 360
poligono 3 400 100 500 250 300 250
poligono 3 300 150 400 300 500 150
salvar Israel
fim






