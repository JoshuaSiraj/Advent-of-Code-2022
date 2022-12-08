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
	int top_SC = 0;

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
			int curr_SC = check_left(arr, x, y, 1) * check_right(arr, x, y, 1) * check_up(arr, x, y, 1) * check_down(arr, x, y, 1);
			if (curr_SC > top_SC) top_SC = curr_SC;
		}
	}

	printf("%d", top_SC);
	return 0;
}

int check_left(int arr[M][N], int x, int y, int step) {

	if (arr[x][y] <= arr[x][y-step]) return step;
	
	if (y-step == 0) return step;
                
        return check_left(arr, x, y, ++step);	
}

int check_right(int arr[M][N], int x, int y, int step) {

        if (arr[x][y] <= arr[x][y+step]) return step;

        if (y+step == N-1) return step;

        return check_right(arr, x, y, ++step);
}

int check_up(int arr[M][N], int x, int y, int step) {

        if (arr[x][y] <= arr[x-step][y]) return step;

        if (x-step == 0) return step;

        return check_up(arr, x, y, ++step);
}

int check_down(int arr[M][N], int x, int y, int step) {

        if (arr[x][y] <= arr[x+step][y]) return step;

        if (x+step == M-1) return step;

        return check_down(arr, x, y, ++step);
}

