//2020.01.01
//boj 13460
//구슬 탈출2
//브루트포스로 문제 해결, 모든 경우에 수를 다 확인하기 위해 재귀로 함수 작성
//파란 구슬이 구멍에 들어간 경우는 무조건 return
//빨간 구슬이 들어간 경우 횟수 확인, 그 값에 최솟값 구함
//10번 넘어가는 경우는 무조건 return
//!방향에 따라 구슬 순서 정해주기!

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXIMUN_VALUE  9999999

/* 구슬 위치 구조체 */
typedef struct location {
	int x;
	int y;
}LC;

int N, M;

/* 각 구슬 위치들 */
LC red_marble;
LC blue_marble;
LC hole;

char map[11][11]; // 전체 지도
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int answer = MAXIMUN_VALUE; //정답

/* 범위 확인 함수 */
bool chk_range(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return false;
	return true;
}

/* 구슬 움직이는 함수 */
void move_marble(LC red, LC blue, int direct, int move_cnt) {
	/* 이동 횟수가 10 넘어가면 무조건 return */
	if (move_cnt == -1)
		return;
	if (move_cnt > 10) {
		move_cnt = -1;
		return;
	}
	
	LC marble1, marble2;
	LC next_marble1, next_marble2;
	bool chk_order = false; // marble1 : red, marble2 : blue, true이면 반대 

	/* 방향 따라 구슬 순서 정하기 */
	switch (direct)
	{
	case 0: // 동
		if (red.y - blue.y > 0) {
			marble1 = red;
			marble2 = blue;
		}
		else {
			marble1 = blue;
			marble2 = red;
			chk_order = true;
		}
		break;
	case 1: // 서
		if (red.y - blue.y > 0) {
			marble1 = blue;
			marble2 = red;
			chk_order = true;
		}
		else {
			marble1 = red;
			marble2 = blue;
		}
		break;
	case 2:	// 남 
		if (red.x - blue.x > 0) {
			marble1 = red;
			marble2 = blue;
		}
		else {
			marble1 = blue;
			marble2 = red;
			chk_order = true;
		}
		break;
	case 3: // 북
		if (red.x - blue.x > 0) {
			marble1 = blue;
			marble2 = red;
			chk_order = true;
		}
		else {
			marble1 = red;
			marble2 = blue;
		}
		break;
	default:
		break;
	}

	/* 구슬 1 위치 */
	while (1) {
		next_marble1 = { marble1.x + dx[direct], marble1.y + dy[direct] };
		//범위 넘어간 경우
		if (!chk_range(next_marble1.x, next_marble1.y))
			break;
		//구멍에 도달한 경우
		if (next_marble1.x == hole.x && next_marble1.y == hole.y) {
			marble1 = next_marble1;
			break;
		}
		//벽에 부딪혀 더 이상 진행 안되는 경우
		if (map[next_marble1.x][next_marble1.y] == '#')
			break;

		marble1 = next_marble1;
	}

	/* 구슬 2 위치 */
	while (1) {
		next_marble2 = { marble2.x + dx[direct], marble2.y + dy[direct] };
		if (!chk_range(next_marble2.x, next_marble2.y))
			break;
		if (next_marble2.x == hole.x && next_marble2.y == hole.y) {
			marble2 = next_marble2;
			break;
		}
		if (map[next_marble2.x][next_marble2.y] == '#')
			break;

		if (next_marble2.x == marble1.x && next_marble2.y == marble1.y)
			break;

		marble2 = next_marble2;
	}

	/* 최종 빨간, 파란 구슬 위치 */
	LC result_red, result_blue;
	if (!chk_order) {
		result_red = marble1;
		result_blue = marble2;
	}
	else {
		result_red = marble2;
		result_blue = marble1;
	}

	/* 파란공 빠지는 경우 : 무조건 return*/
	if (result_blue.x == hole.x && result_blue.y == hole.y)
		return;

	/* 빨간공 빠지는 경우 : 게임 종료, 움직인 횟수 확인 */
	if (result_red.x == hole.x && result_red.y == hole.y) {
		if (move_cnt < 0)
			return;
		answer = min(answer, move_cnt);
		return;
	}

	/* 다음 step으로 진행, 현재 방향을 제외한 다른 방향으로 구슬 보내기 */
	for (int i = 0; i < 4; i++) {
		if (i == direct)
			continue;
		move_marble(result_red, result_blue, i, move_cnt + 1);
	}
}

int main(int argc, char * argv[]) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			/* 각 구슬 및 구멍 위치 저장 */
			if (map[i][j] == 'R') {
				red_marble = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				blue_marble = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'O')
				hole = { i,j };
		}
	}

	/* 4가지 방향으로 구슬 보내기 */
	for (int i = 0; i < 4; i++) {
		move_marble(red_marble, blue_marble, i, 1);
	}

	if (answer == MAXIMUN_VALUE)
		answer = -1;

	cout << answer << "\n";

	return 0;
}