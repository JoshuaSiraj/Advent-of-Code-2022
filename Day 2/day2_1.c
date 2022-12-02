#include <stdio.h>

int main(){
	FILE *in = fopen("input.txt", "r");
	char opp, player;
	int total = 0;
	
	while(fscanf(in, "%c %c\n", &opp, &player) != EOF){
		
		switch(opp){
			// Rock
			case 'A':
				switch(player){
					// Rock
					case 'X':
						total += 4;
						break;
					// Paper
					case 'Y':
						total += 8;
						break;
					// Scissors	
					case 'Z':
						total += 3;
						break;
				}
				break;
			// Paper
			case 'B':
				switch(player){
					// Rock
                                        case 'X':
						total += 1;
                                                break;
					// Paper
                                        case 'Y':
						total += 5;
                                                break;
					// Scissors
                                        case 'Z':
						total += 9;
                                                break;
				}
				break;
			// Scissors
			case 'C':
				switch(player){
					// Rock
                                        case 'X':
						total += 7;
                                                break;
					// Paper
                                        case 'Y':
						total += 2;
                                                break;
					//Scissors
                                        case 'Z':
						total += 6;
                                                break;
				}
				break;
			default:
				printf("Error");
		} 

		printf("opp:%c player:%c\n", opp, player);
	}
	
	printf("%d", total);

	return 0;
}
