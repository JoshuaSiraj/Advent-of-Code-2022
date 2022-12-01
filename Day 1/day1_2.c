#include <stdio.h>
#include <stdlib.h> 

int main(){
	char line[50];
	FILE *in = fopen("input.txt", "r");
	int curr = 0;
	
	int *arr = (int*) calloc(3, sizeof(int));
	
	while(fgets(line, sizeof(line), in) != NULL) {
		int num = atoi(line);

		if (line[0] == '\n') {
			printf("curr: %d\n", curr);	
			int min = 0;
			for (int i = 0; i < 3; i++) {
				if (arr[i] < arr[min]) {
					min = i;
				}
			}

			if (curr > arr[min]) {
				arr[min] = curr;
			}
			curr = 0;
			printf("%d %d %d\n", arr[0], arr[1], arr[2]);
		}
		else {
			curr += num;
		}
	}
	
	printf("Total is %d", arr[0] + arr[1] + arr[2]);
	return 0;

}
