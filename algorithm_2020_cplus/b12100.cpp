//2020.01.16
//boj 12100
//2048 easy
//브루트포스로 모든 경우의 수를 확인하는 방식으로 문제를 해결(재귀). 
//문제 해결
//1. 배열 복사가 재귀를 호출하는 모든 경우에 필요.
//2. 2048이라 2048까지만 숫자를 제한했는데 그 이상도 가능
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int blocks[21][21];
/* 방향 배열 */
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int answer = 0;
vector<vector<bool> > checked_sum; //sum한건지 아닌지 확인하는 배열

/* checked_sum 초기화 */
void clear_checked_sum() {
	checked_sum.clear();
	checked_sum.resize(N + 1);
	for (int i = 0; i < N + 1; i++) {
		checked_sum[i].resize(N + 1);
	}
}

/* 범위 확인 */
bool chk_range(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	return true;
}

/* 전체 게임을 진행하는 재귀 함수 */
void play_game(int direct, int move_cnt) {
	int previous_blocks[21][21];
	int current_blocks[21][21];

	/* 배열 복사, 끝날 때 되돌리기 위해 저장 */
	copy(&blocks[0][0], &blocks[0][0] + 21 * 21, &previous_blocks[0][0]); //이전 블럭 저장

	int next_x, next_y;

	clear_checked_sum(); //매 라운드마다 clear

	/* 방향에 따라 순서가 다르게 진행 (블록 3개인 경우 움직이는 방향 먼저 합치기 위해) */
	//동,남인 경우 오른쪽 아래부터 시작 
	if (direct == 0 || direct == 2) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = N - 1; j >= 0; j--) {
				if (blocks[i][j] == 0)
					continue;
				next_x = i + dx[direct];
				next_y = j + dy[direct];
				/* 비어있는 부분(0인 부분) 끝까지 움직이기 */
				while (1) {
					if (!chk_range(next_x, next_y))
						break;

					if (blocks[next_x][next_y] != 0)
						break;
		
					next_x += dx[direct];
					next_y += dy[direct];
				}
				/* 범위 끝인 경우 */
				if (!chk_range(next_x, next_y)) {
					next_x -= dx[direct];
					next_y -= dy[direct];
					if (i == next_x && j == next_y)
						continue;

					blocks[next_x][next_y] = blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = checked_sum[i][j];
					checked_sum[i][j] = false;

				}
				/* 아직 block이 더해지지않은 경우, 똑같은 숫자를 만난 경우 */
				else if ((blocks[next_x][next_y] == blocks[i][j]) && (!checked_sum[next_x][next_y])) {
					blocks[next_x][next_y] += blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = true;
				}
				/* 이미 더해진 경우 또는 다른 숫자를 만나 더 이상 게임 진행이 없는 경우 */
				else{
					next_x -= dx[direct];
					next_y -= dy[direct];
					if (i == next_x && j == next_y)
						continue;

					blocks[next_x][next_y] = blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = checked_sum[i][j];
					checked_sum[i][j] = false;
				}
			}
		}
	}
	//서,북인경우 왼쪽 위부터 시작(함수 안에는 위와 동일)
	else if (direct == 1 || direct == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (blocks[i][j] == 0)
					continue;
				next_x = i + dx[direct];
				next_y = j + dy[direct];
				while (1) {
					if (!chk_range(next_x, next_y))
						break;

					if (blocks[next_x][next_y] != 0)
						break;

					next_x += dx[direct];
					next_y += dy[direct];
				}
				if (!chk_range(next_x, next_y)) {
					next_x -= dx[direct];
					next_y -= dy[direct];
					if (i == next_x && j == next_y)
						continue;

					blocks[next_x][next_y] = blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = checked_sum[i][j];
					checked_sum[i][j] = false;
					
				}

				else if ((blocks[next_x][next_y] == blocks[i][j]) && (!checked_sum[next_x][next_y])) {
					blocks[next_x][next_y] += blocks[i][j];
					blocks[i][j] = 0;
 					checked_sum[next_x][next_y] = true;
				}
				else {
					next_x -= dx[direct];
					next_y -= dy[direct];
					if (i == next_x && j == next_y)
						continue;

					blocks[next_x][next_y] = blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = checked_sum[i][j];
					checked_sum[i][j] = false;
				}

			}
		}
	}
	/* 최댓값 찾기 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer = max(answer, blocks[i][j]);
		}
	}
	/* 최대 5번까지만 움직이기 */
	if (move_cnt == 5){
		return;
	}
	/* 현재 block 상태 복사 */
	copy(&blocks[0][0], &blocks[0][0] + 21 * 21, &current_blocks[0][0]);

	/* 다음 step으로 진행, 이 때 현재 배열 상태로 복사해서 진행 */
	for (int i = 0; i < 4; i++) {
		copy(&current_blocks[0][0], &current_blocks[0][0] + 21 * 21, &blocks[0][0]);
		play_game(i, move_cnt + 1);
	}

	/* 현재 step이 끝난 경우 처음 상태로 돌려서 종료 */
	copy(&previous_blocks[0][0], &previous_blocks[0][0] + 21 * 21, &blocks[0][0]);
}

int main(int argc, char * argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &blocks[i][j]);
		}
	}
	/* 모든 경우의 수 확인 */
	for (int i = 0; i < 4; i++) {
		play_game(i, 1);
	}

	printf("%d\n", answer);

	return 0;
}