#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>


// Se define la matriz de 9x9
int sudoku[9][9];

int main(int argc, char* argv[]){
	char buf[81];
	int i, j, k;
	unsigned char *file_in_memory;
	int file_size = 81;
	int array;

	int file = open("sudoku.txt", O_RDONLY);
	if(file < 0) {
		printf("El archivo no tiene nada");
	}
	
	file_in_memory = (char *)mmap(0, file_size, PROT_READ, MAP_SHARED, file, 0);
	for(k = 0; k < 81; k++){
		/*for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				sudoku[i][j] = (int)file_in_memory[k]- '0';
				printf("%d", sudoku);
			}
		}*/
		int new = (int)file_in_memory[k] - '0';
		printf("%d", new);
	}
}

void column(){
	int i, j;
	int col1, col2, col3, col4, col5, col6, col7, col8, col9 = 0;
	int numCounter = 0;
	int colCounter = 0;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if(j == 0){
				col1 += sudoku[i][0];
				if(col1 == 45){
					printf("La columna 1 esta bien");
				}
				else{
					printf("La columna 1 esta mal");
				}
			}
			if(j == 1){
				col2 += sudoku[i][1];
				if(col2 == 45){
					printf("La columna 2 esta bien");
				}
				else{
					printf("La columna 2 esta mal");
				}
			}
			if(j == 2){
				col3 += sudoku[i][2];
				if(col3 == 45){
					printf("La columna 3 esta bien");
				}
				else{
					printf("La columna 3 esta mal");
				}
			}
			if(j == 3){
				col4 += sudoku[i][3];
				if(col4 == 45){
					printf("La columna 4 esta bien");
				}
				else{
					printf("La columna 4 esta mal");
				}
			}
			if(j == 4){
				col5 += sudoku[i][4];
				if(col5 == 45){
					printf("La columna 5 esta bien");
				}
				else{
					printf("La columna 5 esta mal");
				}
			}
			if(j == 5){
				col6 += sudoku[i][5];
				if(col6 == 45){
					printf("La columna 6 esta bien");
				}
				else{
					printf("La columna 6 esta mal");
				}
			}
			if(j == 6){
				col7 += sudoku[i][6];
				if(col7 == 45){
					printf("La columna 7 esta bien");
				}
				else{
					printf("La columna 7 esta mal");
				}
			}
			if(j == 7){
				col8 += sudoku[i][7];
				if(col8 == 45){
					printf("La columna 8 esta bien");
				}
				else{
					printf("La columna 8 esta mal");
				}
			}
			if(j == 8){
				col9 += sudoku[i][8];
				if(col9 == 45){
					printf("La columna 9 esta bien");
				}
				else{
					printf("La columna 9 esta mal");
				}
			}
			
			
		}
	}
}

int row(){
	int i, j;
	int row1, row2, row3, row4, row5, row6, row7, row8, row9 = 0;
	int numCounter = 0;
	int rowCounter = 0;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if(i == 0){
				row1 += sudoku[0][j];
				if(row1 == 45){
					printf("La fila 1 esta bien");
				}
				else{
					printf("La fila 1 esta mal");
				}
			}
			if(i == 1){
				row2 += sudoku[1][j];
				if(row2 == 45){
					printf("La fila 2 esta bien");
				}
				else{
					printf("La f 2 esta mal");
				}
			}
			if(i == 2){
				row3 += sudoku[2][j];
				if(row3 == 45){
					printf("La fila 3 esta bien");
				}
				else{
					printf("La fila 3 esta mal");
				}
			}
			if(i == 3){
				row4 += sudoku[3][j];
				if(row4 == 45){
					printf("La fila 4 esta bien");
				}
				else{
					printf("La fila 4 esta mal");
				}
			}
			if(i == 4){
				row5 += sudoku[4][j];
				if(row5 == 45){
					printf("La fila 5 esta bien");
				}
				else{
					printf("La fila 5 esta mal");
				}
			}
			if(i == 5){
				row6 += sudoku[5][i];
				if(row6 == 45){
					printf("La fila 6 esta bien");
				}
				else{
					printf("La fila 6 esta mal");
				}
			}
			if(i == 6){
				row7 += sudoku[6][j];
				if(row7 == 45){
					printf("La fila 7 esta bien");
				}
				else{
					printf("La fila 7 esta mal");
				}
			}
			if(i == 7){
				row8 += sudoku[7][j];
				if(row8 == 45){
					printf("La fila 8 esta bien");
				}
				else{
					printf("La fila 8 esta mal");
				}
			}
			if(i == 8){
				row9 += sudoku[8][j];
				if(row9 == 45){
					printf("La fila 9 esta bien");
				}
				else{
					printf("La fila 9 esta mal");
				}
			}
			
			
		}
	}
}

int square(){
	int i, j, m, n;
	int s0, s1, s2, s3, s4, s5, s6, s7, s8;

	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
					s0 += sudoku[i][j];
					if(s0 == 45){
						printf("El cuadrante 1 esta bien");
					}
					else{
						printf("El cuadrante 1 esta mal");
					}
				}
			}
			for(i = 0; i < 3; i++){
				for(j = 3; j < 6; j++){
					s1 += sudoku[i][j];
					if(s1 == 45){
						printf("El cuadrante 2 esta bien");
					}
					else{
						printf("El cuadrante 2 esta mal");
					}
				}
			}
			for(i = 0; i < 3; i++){
				for(j = 6; j < 9; j++){
					s2 += sudoku[i][j];
					if(s2 == 45){
						printf("El cuadrante 3 esta bien");
					}
					else{
						printf("El cuadrante 3 esta mal");
					}
				}
			}
			for(i = 3; i < 6; i++){
				for(j = 0; j < 3; j++){
					s3 += sudoku[i][j];
					if(s3 == 45){
						printf("El cuadrante 4 esta bien");
					}
					else{
						printf("El cuadrante 4 esta mal");
					}
				}
			}
			for(i = 3; i < 6; i++){
				for(j = 3; j < 6; j++){
					s4 += sudoku[i][j];
					if(s4 == 45){
						printf("El cuadrante 5 esta bien");
					}
					else{
						printf("El cuadrante 5 esta mal");
					}
				}
			}
			for(i = 3; i < 6; i++){
				for(j = 6; j < 9; j++){
					s5 += sudoku[i][j];
					if(s5 == 45){
						printf("El cuadrante 6 esta bien");
					}
					else{
						printf("El cuadrante 6 esta mal");
					}
				}
			}
			for(i = 6; i < 9; i++){
				for(j = 0; j < 3; j++){
					s6 += sudoku[i][j];
					if(s6 == 45){
						printf("El cuadrante 7 esta bien");
					}
					else{
						printf("El cuadrante 7 esta mal");
					}
				}
			}
			for(i = 6; i < 9; i++){
				for(j = 3; j < 6; j++){
					s7 += sudoku[i][j];
					if(s7 == 45){
						printf("El cuadrante 8 esta bien");
					}
					else{
						printf("El cuadrante 8 esta mal");
					}
				}
			}
			for(i = 6; i < 9; i++){
				for(j = 6; j < 9; j++){
					s8 += sudoku[i][j];
					if(s8 == 45){
						printf("El cuadrante 9 esta bien");
					}
					else{
						printf("El cuadrante 9 esta mal");
					}
				}
			}
		}
	}
}
