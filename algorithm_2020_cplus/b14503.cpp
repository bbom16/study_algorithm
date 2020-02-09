//2020.02.06
//boj 14503
//로봇 청소기
//시뮬레이션, 그냥 하라는대로 움직이면 됨
//문제는 후진이었다. 나는 후진이 전에 있던데로 돌아간다고 생각해 재귀로 돌아가게 했으나, 
//문제에서 요구하는 건 후진을 시작한 위치에서의 방향으로 후진하는 것이었다.
//그렇게 프로그램 수정 후 문제 해결
//디버깅하려고 짰던 코드는 제출 전에 삭제하자!

#include <iostream>
#include <cstdio>
using namespace std;

int N, M;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int room[51][51]; //벽, 방 정보가 있는 배열
bool cleaned[51][51]; //청소 여부 확인하는 배열 
int room_cnt = 0;

bool chk_range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

void clean_room(int x, int y, int d) {
	if (!cleaned[x][y]) {
		cleaned[x][y] = true;
		room_cnt++;
	}

	int next_x, next_y, next_d;
	for (int i = 0; i < 4; i++) {
		// 음수 나오는거 방지하려고 4 더해주고 1 빼준후 mod 4 
		next_d = (d + 4 - 1) % 4;

		next_x = x + dx[next_d];
		next_y = y + dy[next_d];

		/* 벽인 경우나 청소된 경우 */
		if (!chk_range(next_x, next_y) || room[next_x][next_y] == 1 || cleaned[next_x][next_y]) {
			d = next_d;
		}
		else {
			clean_room(next_x, next_y, next_d);
			return;
		}
	}

	/* 후진 - 후진 시작한 위치에서 방향 d로 후진 */
	next_x = x - dx[d];
	next_y = y - dy[d];

	if (!chk_range(next_x, next_y) || room[next_x][next_y] == 1)
		return;

	clean_room(next_x, next_y, d);

}

int main(int argc, char * argv[]) {

	scanf("%d %d", &N, &M);

	int start_x, start_y, direction;
	scanf("%d %d %d", &start_x, &start_y, &direction);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &room[i][j]);
	}

	clean_room(start_x, start_y, direction);

	printf("%d\n", room_cnt);

	return 0;
}