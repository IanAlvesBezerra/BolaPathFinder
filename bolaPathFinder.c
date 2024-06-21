#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	
	// criacao do loop de busca da bolinha
	do{
		while(andares[bolinha[0]][bolinha[1]][bolinha[2]] == 'o'){
			int distancia; // calcular a distancia
		}
		bolinha[0]++;
	}while(bolinha[0] <= 9);
}

//Autores Ian Alves, Mateus Cajaiba e Pedro Henrique
