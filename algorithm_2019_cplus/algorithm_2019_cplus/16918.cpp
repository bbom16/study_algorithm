// 2019.07.05
// baeckjoon 16918
// º½¹ö¸Ç
// ±¸Çö

#include <stdio.h>
#include <iostream>
using namespace std;

char check[201][201];
int bomb_time[201][201];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(int argc, char * argv[]){
	int R, C, N;
	scanf("%d %d %d", &R, &C, &N);
	getchar();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &check[i][j]);
			if (check[i][j] == 'O')
				bomb_time[i][j] = 0;
		}
		getchar();
	}

	int time = 2;
	while (1) {
		if (time > N) break;
		if (time%2 == 0) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (check[i][j] == 'O') continue;
					check[i][j] = 'O';
					bomb_time[i][j] = time;
				}
			}
		}
		else if (time%2 == 1) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (check[i][j] == 'O' && bomb_time[i][j] + 3 == time) {
						bomb_time[i][j] = -1;
						check[i][j] = '.';
						for (int k = 0; k < 4; k++) {
							int next_j = j + dx[k];
							int next_i = i + dy[k];
							if (next_i < 0 || next_i >= R || next_j < 0 || next_j >= C) continue;
							if (bomb_time[next_i][next_j] + 3 == time) continue;
							check[next_i][next_j] = '.';
							bomb_time[next_i][next_j] = -1;
						}
					}
				}
			}
		}	
		time++;
	}

	printf("\n");
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", check[i][j]);
		}
		printf("\n");
	}
	return 0;
}