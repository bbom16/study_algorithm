// 2019.07.21
// boj 14499
// 주사위 굴리기
// 시뮬레이션

#include <stdio.h>
#include <iostream>

using namespace std;

int dice[7];
int map[21][21];
int dice_info[6] = { 6, 3, 4, 5, 2 };
int N, M;

bool checked_map(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

int main(int argc, char * argv[]) {
	int x, y, K;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int query;
	int badak = 1, dir = 0;
	int tmpdice_info[6];
	while (K--) {
		scanf("%d", &query);
		for (int i = 0; i < 6; i++) 
			tmpdice_info[i] = dice_info[i];
		switch (query)
		{
		// 동
		case 1:
			y = y + 1;
			if (!checked_map(x, y)) {
				y--;
				continue;
			}
			dice_info[0] = 7 - tmpdice_info[query];
			dice_info[1] = tmpdice_info[0];
			dice_info[2] = badak;
			break;
		//서
		case 2:
			y = y - 1;
			if (!checked_map(x, y)) {
				y++;
				continue;
			}
			dice_info[0] = 7 - tmpdice_info[query];
			dice_info[1] = badak;
			dice_info[2] = tmpdice_info[0];
			break;
		//북
		case 3:
			x = x - 1;
			if (!checked_map(x, y)) {
				x++;
				continue;
			}
			dice_info[0] = 7 - tmpdice_info[query];
			dice_info[3] = tmpdice_info[0];
			dice_info[4] = badak;
			break;
		//남
		case 4:
			x = x + 1;
			if (!checked_map(x, y)) {
				x--;
				continue;
			}
			dice_info[0] = 7 - tmpdice_info[query];
			dice_info[3] = badak;
			dice_info[4] = tmpdice_info[0];
			break;
		default:
			break;
		}

		badak = tmpdice_info[query];
		if (map[x][y] == 0) 
			map[x][y] = dice[badak];
		
		else {
			dice[badak] = map[x][y];
			map[x][y] = 0;
		}
		printf("%d\n", dice[7 - badak]);
	}
	return 0;
}