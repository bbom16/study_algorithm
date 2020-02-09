//2020.02.03
//boj 14499
//주사위 굴리기
//시뮬레이션 
//주사위의 바닥 및 바뀐 위치정보들을 찾는게 문제 해결의 핵심
//각각 바뀌는 값들을 배열을 이용해 저장해서 문제 해결 

#include <iostream>
#include <cstdio>

using namespace std;

int N, M, x, y, K;
int map[21][21]; 
int current_location[6]; //주사위의 현재 위치 정보
int next_location[6] = { 6,3,4,2,5,1 }; //주사위의 옮긴 위치 정보 (순서는 바닥인 6을 기준으로 각 command에 따라 바뀔 위치정보들)
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
int dice[7] = { 0, }; //주사위의 각 면에 적힌 숫자

bool chk_range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

void play_dice(int x, int y, int c) {

	/* command 값에 따른 반대편 값(1-2, 3-4) */
	int tmp;
	if (c == 1)
		tmp = 2;
	else if (c == 2)
		tmp = 1;
	else if (c == 3)
		tmp = 4;
	else if (c == 4)
		tmp = 3;

	/* 주사위를 굴린 후 바뀐 주사위 배열 */
	next_location[0] = current_location[c];
	next_location[c] = 7 - current_location[0];
	next_location[tmp] = current_location[0];
	next_location[5] = 7 - current_location[c];

	//바닥
	int bottom = next_location[0];

	/* 0이면 지도에 주사위 밑면 값 저장, 아니면 주사위 바닥에 지도 값 저장 후 지도 값 0 */
	if (map[x][y] == 0) {
		map[x][y] = dice[bottom];
	}
	else {
		dice[bottom] = map[x][y];
		map[x][y] = 0;
	}

	printf("%d\n", dice[7 - bottom]);
}

int main(int argc, char *argv[]) {
	
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int command;

	while (K--) {
		/* next 정보를 current 정보로 copy */
		for (int i = 0; i < 6; i++) {
			current_location[i] = next_location[i];
		}

		scanf("%d", &command);
	
		/* 명령에 맞는 위치로 이동 */
		x += dx[command];
		y += dy[command];
		if (!chk_range(x, y)) {
			x -= dx[command];
			y -= dy[command];
			continue;
		}
			
		play_dice(x, y, command);

	}

	return 0;
}