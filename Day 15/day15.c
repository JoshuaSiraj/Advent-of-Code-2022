#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int overlap(int range1[], int range2[]);
int find_missing(int no_overlap[][2], int n);

int main(int argc, char* argv[]){
	
	FILE *in;
	if (argc > 0) in = fopen(argv[1], "r");
	int x1, x2, y1, y2, dist, check, sensors[MAX][3]; 
	int n_sensors = 0; int check_row = 20;
       	
	while(fscanf(in, "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &x1, &x2, &y1, &y2) != EOF){
		//printf("%d, %d, %d, %d\n", x1, x2, y1, y2);

		dist = abs(x1-y1) + abs(x2-y2);
		//printf("%d\n", dist);
		sensors[n_sensors][0] = x1; sensors[n_sensors][1] = x2; sensors[n_sensors][2] = dist;
		n_sensors++;
	}

	for (int l = 0; l < 4000001; l++){
	check_row=l;
	
	int ranges[MAX][2];
       	int n = 0;	

	for(int i = 0; i < n_sensors; i++){
		if (check_row <= sensors[i][1] + sensors[i][2] && check_row >= sensors[i][1] - sensors[i][2]){
			 //printf("%d %d %d\n", sensors[i][0], sensors[i][1], sensors[i][2]);
			 ranges[n][0] = sensors[i][0] - (sensors[i][2] - abs(check_row-sensors[i][1]));
			 ranges[n][1] = sensors[i][0] + (sensors[i][2] - abs(check_row-sensors[i][1]));
			 n++;
		}
	}

	int no_overlap[MAX][2];
	int t = 1;
	no_overlap[0][0] = ranges[0][0]; no_overlap[0][1] = ranges[0][1];
	
	for (int i = 1; i < n; i++){
		check = 0;
		for (int j = 0; j < t; j++){
			check = overlap(no_overlap[j], ranges[i]);
			//printf("%d\n", check);
			//printf("%d %d %d %d\n", ranges[i][0], ranges[i][1], no_overlap[j][0], no_overlap[j][1]);
			if (check){
				if(ranges[i][0] < no_overlap[j][0]) no_overlap[j][0] = ranges[i][0];
			       	if(ranges[i][1] > no_overlap[j][1]) no_overlap[j][1] = ranges[i][1];
				//printf("%d %d\n", no_overlap[j][0], no_overlap[j][1]);		
			}
		}
	      	if (!check){
			no_overlap[t][0] = ranges[i][0]; no_overlap[t][1] = ranges[i][1];
			t++;


		}	
	}

	int res = 0;

	//for (int i = 0; i < t; i++){
		//printf("%d, %d\n", no_overlap[i][0], no_overlap[i][1]);
		//res += no_overlap[i][1] - no_overlap[i][0];
	//}

	int missing = find_missing(no_overlap, t);
	//printf("%d %d\n", missing, check_row);	
	if (missing!=-1){
		printf("%d %d", missing, check_row);
		break;
	}

	}
}

int overlap(int range1[], int range2[]){
	if ((range1[0] <= range2[1] && range2[0] <= range1[1])) return 1;
	
	return 0;	
}

int find_missing(int no_overlap[][2], int n){
	int check;
	for (int x = 0; x < 4000001; x++){
		check = 0;
		for (int i = 0; i < n; i++){
			if (no_overlap[i][0] <= x && no_overlap[i][1] >= x) check = 1;
		}
		if (!check) return x; 
	}

	return -1;
}
