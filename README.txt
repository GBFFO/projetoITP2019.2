Projeto 3ª Unidade: ITP 2019.2

Dupla: 
	Danilo
	Gabriel Bessa de F. F. Oliva

Professor: 
	André Maurício Cunha

Data da atualizacação: 
	23/10/2019 (14:45)


EXECUTADO RECENTEMENTE
- Implementei alocacao e desalocacao dinamica da imagem dentro do proprio main()

- Inicialmente imagem alocada dinamicamente possui todos os pixels na cor branca

- Enxuguei alguns comandos do main(), por exemplo, incluindo uma variavel com tipo Pixel chamada "cor" para evitar criar 3 variaveis corR, corG, corB. Então chamo cor.R ou cor.G ou cor.B. 

- Criei as funcoes:
	color.c (usuario seleciona a cor a ser utilizada nas proximas operacoes)
	clear.c (pinta toda a imagem com uma mesma cor pre-selecionada)
	pintarPixel.c (pinta 1 pixel)
	
- Criei o arquivo funcoes.h que contem os structs, enums, etc, além das assinaturas das funcoes já implementadas (semelhante aos slides)

- Alterei o struct do tipo pixel retirando aquele enum bool (depois explico o porque fiz isso, mas foi uma dica do professor). Adicionei naquele struct outra variavel para armazenar as coordenadas xPixel e yPixel do pixel (talvez nem seja necessaria, entao se nao for, podemos excluir)

- A funcao linha.c nao faz parte do projeto ainda, é apenas a logica usando uma matriz de 0s e 1s para criar uma linha entre os pontos (x1,y1) e (x2,y2). Usei recursão para elaborar a funcao. A linha é representada pelos numeros 2. Os dois pontos por 1s. Os demais elementos são zero.

- Para COMPILAR digite: gcc projeto.c color.c clear.c pintarPixel.c -o ./projeto

PROXIMAS ETAPAS
- Alocar e desacolar a imagem dinamicamente em funcoes fora do main?
- Criar funcao para escrever o arquivo.txt fora do main? (dessa forma podemos enxugar o codigo do main)
- Reestruturar a funcao linha.c para funcionar com os pixels da matriz imagem (ao inves da matriz com 0s e 1s), alem de testar se a funcao esta funcionando corretamente. Além disso, tentar enxugar a funcao sem que ela deixe de funcionar para qualquer caso.
- Permitir entrada de dados de um arquivo txt, por exemplo, entradas.txt para que nao seja necessario o usuario ficar "conversando com o terminal" para executar os comandos (semelhante ao que tem no PDF do projeto...). Ex:
	color 100 150 200
	clear 255 255 255
	etc
- Criar funcao para desenhar poligonos (talvez um for ou while utilizando 'n' vezes a funcao linha)
- Criar condicoes de erro (por exemplo, quando for ler o entradas.txt verificar se o formato esta correto, caso nao esteja deve-se fechar o executavel ou algo do tipo.




EXPLICO DEPOIS PESSOALMENTE (Ideias)

//Possiveis extras: 
    //Entrada de dados de um .txt ou conversando com o usuario (teclado)
    //Programa pode associar 1- Clear, 2- Color, 3- PintarPixel, 4- Reta... etc 



