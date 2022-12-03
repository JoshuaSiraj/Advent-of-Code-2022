#include <stdio.h>

int str_len(char str[]);
char priority(char str[], int len);

int main() {
	char str[100];
	FILE *in = fopen("input.txt", "r");
	int total = 0;

	while(fgets(str, 100, in) != NULL) {
		int len = str_len(str);
		// priority
		char p = priority(str, len);
		// lower case
		if (p >= 'a' && p <= 'z') {
			total += p - 96;	
		}
		// upper case
		else {
			total += p -38;
		}
	}
	
	printf("%d", total);
	return 0;
}

char priority(char str[], int len){
	for (int i = 0; i < len/2; i++){
                        for (int j = len/2; j < len; j++){
                                if (str[i] == str[j]) {
                                	return str[i];
				}
                        }
                }

}

int str_len(char str[]) {
        int len;

        for (len = 0; str[len] != '\0'; len++);

	return len;
}

