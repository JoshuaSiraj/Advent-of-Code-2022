#include <stdio.h>

int str_len(char str[]);

int main(int argc, char* argv[]){
	FILE *in = fopen(argv[1], "r");
	char str[10000];
	int dis;

	fgets(str, 10000, in);
	int len = str_len(str);
	
	switch (argv[2][0]){
		case '1':
			dis = 4;
			break;
		case '2':
			dis = 14;
			break;
	}

	int mark = dis;

	while(mark < len) {
		int check = 1;
		
		for (int i = mark-dis; i < mark - 1; i++){
			for (int j = i+1; j < mark; j++){
				if (str[i] == str[j]){
					check = 0;
				}
			}
		}

		if (check) break;

		mark++;
	}

	printf("First Marker : %d", mark);

	return 0;

}

int str_len(char str[]) {
        int len;

        for (len = 0; str[len] != '\0'; len++);

	return len;
}
