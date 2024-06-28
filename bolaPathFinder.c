#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	char andares[10][5][5];
	int i, j, k;
	srand(time(NULL));
	
	// preencher a matriz com w
	for(i = 0; i < 10; i++){
		for(j = 0; j < 5; j++){
			for(k = 0; k < 5; k++){
				andares[i][j][k] = 'w'; // w para simular grama
			}
		}
	}
	
	// colocar um buraco representado por o
	// em uma posicao aleatoria de cada andar
	for(i = 0; i < 10; i++){
		int posicaoDoBuraco[2];
		posicaoDoBuraco[0] = rand() % 5;
		posicaoDoBuraco[1] = rand() % 5;
		
		andares[i][posicaoDoBuraco[0]][posicaoDoBuraco[1]] = 'o';
	}
	
	// criacao do player
	int bolinha[3]; // vetor de 3 posicoes para armazenar as coordenadas do player: andar, x , y
	bolinha[0] = 0; // player inicia no topo do predio
	
	// posicionar o player em uma posicao aleatoria
	bolinha[1] = rand() % 5;  
	bolinha[2] = rand() % 5;
	
	// impressao da matriz
	printf("Andares do predio:\n");
	sleep(1);
	for(i = 0; i < 10; i++){
		for(j = 0; j < 5; j++){
			for(k = 0; k < 5; k++){
				// imprimir x na posicao do player sem alterar a matriz dos andares
				if(i == bolinha[0] && j == bolinha[1] && k == bolinha[2]){
					printf("x "); 
				}
				else{
					printf("%c ", andares[i][j][k]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	sleep(3);
	system("cls");
	
	// iniciar a variavel dos movimentos possiveis do player
	char movimento = 'u';
	
	// iniciar as variaveis de controle de distancia 
	// o auxiliar comeca como 12 pois e a maior distancia possivel
	int distancia, distanciaAux = 12;
	
	// iniciar as variaveis de contagem de passos
	/* 
	   passos por andar e necessario pois no comeco de cada andar
	   e feita a tomada de decisao da direcao com base
	*/
	int contadorPassos = 0;
	int passosPorAndar[10] = {0};
	
	// criacao do loop de busca da bolinha
	do{
		while(andares[bolinha[0]][bolinha[1]][bolinha[2]] != 'o'){
			// encontrar a posicao do buraco do andar do player
			int buracoDoAndar[2];
			for(i = 0; i < 5; i++){
				for(j = 0; j < 5; j++){
					if(andares[bolinha[0]][i][j] == 'o'){
						buracoDoAndar[0] = i;
						buracoDoAndar[1] = j;
					}
				}
			}
			
			// calcular a distancia do player ate o buraco
			distancia = abs(bolinha[1] - buracoDoAndar[0]) + abs(bolinha[2] - buracoDoAndar[1]);
			
			// tomada de decisao da direcao com base na variavel de movimento e distancia
			// u = cima; d = baixo; r = direita; l = esquerda
			
			// se a nova distancia for menor que a anterior continua naquela direcao
			// a direcao muda caso o player esteja no limite do mundo
			if(distancia < distanciaAux){
				switch(movimento){
					case 'u':
						if(bolinha[1] != 0){
							bolinha[1]--;
						}
						else{
							if(passosPorAndar[bolinha[0]] > 2){
								movimento = 'r';
								bolinha[2]++;
							}
							else{
								movimento = 'd';
								bolinha[1]++;
							}
						}
						passosPorAndar[bolinha[0]]++;
						break;
					case 'd':
						if(bolinha[1] != 4){
							bolinha[1]++;
						}
						else{
							movimento = 'r';
							bolinha[2]++;
						}
						passosPorAndar[bolinha[0]]++;
						break;
					case 'r':
						if(bolinha[2] != 4){
							bolinha[2]++;
						}
						else{
							movimento = 'l';
							bolinha[2]--;
						}
						passosPorAndar[bolinha[0]]++;
						break;
					case 'l':
						if(bolinha[2] != 0){
							bolinha[2]--;
						}
						else{
							movimento = 'u';
							bolinha[1]--;
						}
						passosPorAndar[bolinha[0]]++;
						break;
				}
			}
			// se a nova distancia for maior que a anterior volta um passo e muda a direcao
			else{
				switch(movimento){
					case 'u':
						bolinha[1]++;
						movimento = 'd';
						break;
					case 'd':
						bolinha[1]--;
						movimento = 'r';
						break;
					case 'r':
						bolinha[2]--;
						movimento = 'l';
						break;
					case 'l':
						bolinha[2]++;						
						movimento = 'u';
						break;
				}
				passosPorAndar[bolinha[0]]++;
			}
			
			// guardar a distancia anterior para compara na proxima repeticao
			distanciaAux = distancia;
			
			// limpa a tela e imprime as informacoes
			system("cls");
			printf("Bolinha: andar(%d) linha(%d) coluna(%d)\n", bolinha[0], bolinha[1], bolinha[2]);
			printf("Movimento: %c\n", movimento);
			
			for(i = 0; i < 5; i++){
				for(j = 0; j < 5; j++){
					// imprimir x na posicao do player sem alterar a matriz dos andares
					if(i == bolinha[1] && j == bolinha[2]){
						printf("x "); 
					}
					else{
						printf("%c ", andares[bolinha[0]][i][j]);
					}
				}
				printf("\n");
			}
			for(i = 0; i <= bolinha[0]; i++){
				printf("Passos no andar %d: %d\n", i, passosPorAndar[i]);
			}
			printf("\n");
			sleep(1);
		}
		// o player desce um andar
		bolinha[0]++;
		
		// reset das variaveis que controlam a direcao do player
		movimento = 'u';
		distanciaAux = 12;
		
		// soma a quantidade de passos no andar
		contadorPassos += passosPorAndar[bolinha[2]];
	}while(bolinha[0] <= 9);
	
	// calcula e imprime a media de passos
	float mediaPassos = (float)contadorPassos/10;
	printf("Media de passos por andar: %.1f", mediaPassos);
}

//Autores Ian Alves, Mateus Cajaiba e Pedro Henrique
