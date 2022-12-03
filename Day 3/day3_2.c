#include <stdio.h>

int str_len(char str[]);
char priority(char str1[], char str2[], char str3[], int len1, int len2, int len3);

int main() {
	char str1[100];
	char str2[100];
	char str3[100];
	FILE *in = fopen("input.txt", "r");
	int total = 0;

	while(fscanf(in, "%s\n%s\n%s\n", str1, str2, str3) != EOF) {
		// priority
		char p = priority(str1, str2, str3, str_len(str1), str_len(str2), str_len(str3));
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

char priority(char str1[], char str2[], char str3[], int len1, int len2, int len3) {
	for (int i = 0; i < len1; i++){
		for (int j = 0; j < len2; j++){
			if (str1[i] == str2[j]){
				for (int z = 0; z < len3; z++){
					if (str1[i] == str3[z]){
						return str1[i];
					}
				}
			}
		}
	}
}

int str_len(char str[]) {
        int len;

        for (len = 0; str[len] != '\0'; len++);

	return len;
}

