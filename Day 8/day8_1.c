#include <stdio.h>
#include <stdlib.h>
#define M 99
#define N 99

int str_len(char str[]);
int check_left(int arr[M][N], int x, int y, int step);
int check_right(int arr[M][N], int x, int y, int step);
int check_up(int arr[M][N], int x, int y, int step);
int check_down(int arr[M][N], int x, int y, int step);

int main(int argc, char* argv[]){
	int result = (2 * M) + (2 * (N-2));

	//int arr[M][N] = {{3, 0, 3, 7, 3}, {2, 5, 5, 1, 2}, {6, 5, 3, 3, 2}, {3, 3, 5, 4, 9}, {3, 5, 3, 9, 0}};
	int arr[M][N];
	char str[N+2];

	FILE* in;

	if ((in = fopen("input.txt", "r")) == NULL) return 1; 
	
	for (int i = 0; i < M; i++){
		if (fgets(str, N+2, in) == NULL) break;
		
		for (int j = 0; j < N; j++){
			arr[i][j] = str[j] - '0';
		}
	}

	for (int x = 1; x < M-1; x++) {
		for (int y = 1; y < N-1; y++){
			if (check_left(arr, x, y, 1) || check_right(arr, x, y, 1) || check_up(arr, x, y, 1) || check_down(arr, x, y, 1)) {
				result+=1;
			}
		}
	}

	printf("%d", result);
	return 0;
}

int check_left(int arr[M][N], int x, int y, int step) {

	if (arr[x][y] <= arr[x][y-step]) return 0;
	
	if (y-step == 0) return 1;
                
        return check_left(arr, x, y, ++step);	
}

int check_right(int arr[M][N], int x, int y, int step) {

        if (arr[x][y] <= arr[x][y+step]) return 0;

        if (y+step == N-1) return 1;

        return check_right(arr, x, y, ++step);
}

int check_up(int arr[M][N], int x, int y, int step) {

        if (arr[x][y] <= arr[x-step][y]) return 0;

        if (x-step == 0) return 1;

        return check_up(arr, x, y, ++step);
}

int check_down(int arr[M][N], int x, int y, int step) {

        if (arr[x][y] <= arr[x+step][y]) return 0;

        if (x+step == M-1) return 1;

        return check_down(arr, x, y, ++step);
}

