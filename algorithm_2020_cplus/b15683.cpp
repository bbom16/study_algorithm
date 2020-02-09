//2020.02.09
//boj 15683
//감시
//브루트포스
//모든 cctv가 맞는지 확인하자

#define INFINITY_VALUE 65
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int room[9][9];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<int> cam_x, cam_y; //cctv 위치 
int answer = INFINITY_VALUE;

bool chk_range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

/* 안전 구역을 7로 표시 */
void chk_safety(int x, int y, int d) {
	int next_x = x, next_y = y;
	while (1) {
		next_x += dx[d];
		next_y += dy[d];

		if (!chk_range(next_x, next_y))
			break;
		if (room[next_x][next_y] == 6)
			break;

		if (room[next_x][next_y] == 0)
			room[next_x][next_y] = 7;
	}
}

/* 각 cctv마다 감시할 수 있는 구역 확인하는 재귀 함수 */
void find_safety(int c) {
	if (c == cam_x.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (room[i][j] == 0)
					cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}
	int x = cam_x[c], y = cam_y[c];
	int current_room[9][9];
	copy(&room[0][0], &room[0][0] + 9 * 9, &current_room[0][0]);
	
	int next_x = x, next_y = y;
	int cam = room[cam_x[c]][cam_y[c]];
	//1번 일 때 - 각 방향으로 확인
	if (cam == 1) {
		for (int i = 0; i < 4; i++) {
			chk_safety(x, y, i);
			find_safety(c + 1);
			copy(&current_room[0][0], &current_room[0][0] + 9 * 9, &room[0][0]);
		}
	}
	//2번 - 각 방향에 반대 방향을 확인(0,2)
	else if (cam == 2) {
		int d = 0; //동

		chk_safety(x, y, d);
		chk_safety(x, y, d+1);
		
		find_safety(c + 1);
		copy(&current_room[0][0], &current_room[0][0] + 9 * 9, &room[0][0]);

		d = 2; //남
		chk_safety(x, y, d);
		chk_safety(x, y, d + 1);
		find_safety(c + 1);

	}
	//3번 - 2개씩 직각으로 방향 확인
	else if (cam == 3) {
		for (int i = 0; i < 4; i++) {
			copy(&current_room[0][0], &current_room[0][0] + 9 * 9, &room[0][0]);
			
			chk_safety(x, y, i);
			if (i < 2)
				chk_safety(x, y, i + 2);
			else if(i == 2)
				chk_safety(x, y, 1);
			else if(i == 3)
				chk_safety(x, y, 0);

			find_safety(c + 1);
		}
	}
	//4번 - i만 제외한 모든 방향을 확인
	else if (cam == 4) {
		for (int i = 0; i < 4; i++) {
			copy(&current_room[0][0], &current_room[0][0] + 9 * 9, &room[0][0]);
			chk_safety(x, y, (i + 1) % 4);
			chk_safety(x, y, (i + 2) % 4);
			chk_safety(x, y, (i + 3) % 4);
			find_safety(c + 1);
		}
	}
	//5번 - 4방향 모두 확인
	else if (cam == 5) {
		for (int i = 0; i < 4; i++) {
			chk_safety(x, y, i);
		}
		find_safety(c + 1);
	}

}

int main(int argc, char * argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &room[i][j]);
			if (room[i][j] > 0 && room[i][j] < 6) {
				cam_x.push_back(i);
				cam_y.push_back(j);
			}
		}
	}
	
	find_safety(0);

	printf("%d\n", answer);

	return 0;
}