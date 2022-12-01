#include <stdio.h>
#include <stdlib.h> 

int main(){
	char line[50];
	FILE *in = fopen("input.txt", "r");
	int max = 0;
	int maxelf = 1;
	int curr = 0;
	int currelf = 1;
	
	while(fgets(line, sizeof(line), in) != NULL) {
		int num = atoi(line);

		if (num == 0) {
			if (curr >= max) {
				max = curr;
			       	maxelf = currelf;
			}

			curr = 0;
			currelf += 1;
		//	printf("bruh\n");
		}
		else {
			curr += num;
		//	printf("%d\n", num);
		}
	}

	printf("The max elf is %d with a value of %d", maxelf, max);
	return 0;

}
