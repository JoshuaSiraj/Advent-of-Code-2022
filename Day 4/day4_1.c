#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE *in = fopen(argv[1], "r");
	int num1, num2, num3, num4;
	int total = 0;

	while (fscanf(in, "%d-%d,%d-%d\n", &num1, &num2, &num3, &num4) != EOF) {
		printf("%d %d %d %d\n", num1, num2, num3, num4);
		
		// If either ends of the ranges are equal, one range includes the other
		if (num1 == num3 || num2 == num4){
			total+=1;
		}
		else if (num1 < num3) {
			if (num2 > num4){
				total+=1;	
			}
		}	
		else {
			if (num4 > num2){
				total+=1;
			}
		}
	}

	printf("%d", total);

	return 0;
}
