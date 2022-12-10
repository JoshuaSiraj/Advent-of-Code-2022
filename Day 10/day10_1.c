#include <stdio.h>

int main(int argc, char* argv[]) {
	
	FILE *in = fopen(argv[1], "r");
	int signal_strength = 0; int cycle = 0; int register_value = 1; int value; int check_cycle = 20;
	char instruction[5];

	while (fscanf(in, "%s %d", instruction, &value) != EOF){

		switch(instruction[0]){
			case 'n':
				cycle+=1;

				if (cycle == check_cycle){
					signal_strength += register_value*check_cycle;
                                        check_cycle+=40;
				}

				break;
			case 'a':
				cycle+=2;
				
				if (cycle - 2 < check_cycle && check_cycle <= cycle){
					signal_strength += register_value*check_cycle;
					check_cycle+=40;
				}

				register_value+=value;

				break;
		}

		if (check_cycle > 220) break;
	}

	printf("%d", signal_strength);
}
