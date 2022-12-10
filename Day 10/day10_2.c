#include <stdio.h>
#include <stdlib.h>

void print_CRT(char CRT[6][40]);

int main(int argc, char* argv[]) {
	FILE *in = fopen(argv[1], "r");
	int register_value = 1; int cycle = 0; int i = 0; int value, dist;
	char instruction[5];
	char CRT[6][40];
	
	while (i < 6){
		if (fscanf(in, "%s %d", instruction, &value) == EOF){
			return 1;
		}
		switch(instruction[0]){
			case 'n':
				
				dist = abs(register_value - cycle);
				if (dist < 2){
					CRT[i][cycle] = '#';
				}
				else {
					CRT[i][cycle] = '.';
				}

				cycle++;
				if (cycle == 40) {
					i++;
					cycle = cycle % 40;
				}
				break;
			case 'a':

				for (int n = 0; n < 2; n++){

					dist = abs(register_value - cycle);
					if (dist < 2){
						CRT[i][cycle] = '#';
					}
					else {
						CRT[i][cycle] = '.';
					}

					cycle++;
					if (cycle == 40) {
						i++;
						cycle = cycle % 40;
					}

				}

				register_value+=value;
	
				break;
		}	
			
	}

	print_CRT(CRT);
	return 0;
}

void print_CRT(char CRT[6][40]){
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 40; j++){
			printf("%c ", CRT[i][j]);
		}
		printf("\n");
	}
}
