//2020.02.05
//boj 14502
//연구소
//백트래킹을 이용한 브루트포스(완탐)

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int room[9][9]; //백트래킹 사용, 기본 방
int visited[9][9]; //dfs 사용
int room_visited[9][9]; //백트래킹 사용
int copy_room[9][9]; //dfs에서 사용

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0, 0 };
int answer = 0;

void clear_visted() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
	}
}

bool chk_range(int x, int y){
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

/* 안전 구역 구하기 */
int find_safety() {
	int safety = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_room[i][j] == 0)
				safety++;
		}
	}
	return safety;
}

/* 병균 퍼뜨리기, dfs를 이용해서 전파 */
void dfs(int x, int y) {
	visited[x][y] = true;
	int next_x, next_y;

	for (int i = 0; i < 4; i++) {
		next_x = x + dx[i];
		next_y = y + dy[i];

		if (!chk_range(next_x, next_y))
			continue;

		if (visited[next_x][next_y] || copy_room[next_x][next_y] != 0) {
			if (copy_room[next_x][next_y] == 2)
				visited[next_x][next_y] = true;
 			continue;
		}
		
		copy_room[next_x][next_y] = 2;
		dfs(next_x, next_y);
	}
}

/* 벽 세우기 */
void set_wall(int x, int y, int wall_cnt) {
	int state = room[x][y];
	room[x][y] = 1;
	room_visited[x][y] = true;

	/* 벽은 3개 까지만 */
	if (wall_cnt == 3) {
		//visited 배열 초기화 및 세균 전파시키기 위해 copy_room 배열로 copy
		clear_visted();
		copy(&room[0][0], &room[0][0] + 9 * 9, &copy_room[0][0]);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_room[i][j] != 2 || visited[x][y])
					continue;
				dfs(i, j);
			}
		}
		answer = max(answer, find_safety());
		room[x][y] = state;
		room_visited[x][y] = false;
		return;
	}

	/* 완탐으로 1개씩 놓으면서 모든 경우의 수 확인 - 중복 방지를 위해 현재 x부터 시작 */
	for (int i = x; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == x && j == y)
				continue;

			if (!chk_range(i, j))
				continue;

			if (room_visited[i][j] || room[i][j] != 0)
				continue;

			set_wall(i, j, wall_cnt + 1);
		}
	}
	/* turn 종료 후 다시 되돌리기 */
	room[x][y] = state;
	room_visited[x][y] = false;
}

int main(int argc, char * argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &room[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (room[i][j] != 0)
				continue;
			set_wall(i, j, 1);
		}
	}

	printf("%d\n", answer);

	return 0;
}