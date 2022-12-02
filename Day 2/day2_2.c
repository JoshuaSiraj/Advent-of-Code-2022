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
					// Lose
					case 'X':
						total += 3;
						break;
					// Draw
					case 'Y':
						total += 4;
						break;
					// Win	
					case 'Z':
						total += 8;
						break;
				}
				break;
			// Paper
			case 'B':
				switch(player){
					// Lose
                                        case 'X':
						total += 1;
                                                break;
					// Draw
                                        case 'Y':
						total += 5;
                                                break;
					// Win
                                        case 'Z':
						total += 9;
                                                break;
				}
				break;
			// Scissors
			case 'C':
				switch(player){
					// Lose
                                        case 'X':
						total += 2;
                                                break;
					// Draw
                                        case 'Y':
						total += 6;
                                                break;
					// Win
                                        case 'Z':
						total += 7;
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
