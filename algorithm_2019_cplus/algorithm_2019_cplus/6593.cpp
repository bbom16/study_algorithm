// 2019.06.29
//  6593.cpp
//  상범빌딩, bfs 이용해서 구하기 / 문자열 입력 조심하기!!! (scnaf 이용해서 받을꺼면 버퍼 비워주기 ) - first touch
//  원래 빌딩 정보 위에서 값을 더했는데 .(아스키코드 46) 숫자일 때 방문여부가 확인이 제대로 안됨 -> 새로운 time이라는 벡터로 visit여부와 걸린 시간 저장으로 해결!

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct spot {
	int x;
	int y;
	int z;
}SPOT;

// k : 높이, j : 열, i: 행
vector<vector<vector<char > > > building; // 건물 정보
vector<vector<vector<int > > > time;	// 걸린 시간(visit 확인용)
queue<SPOT> que;

int L, R, C;

int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

SPOT start_spot, end_spot;

int bfs() {
	int x, y, z, next_x, next_y, next_z;
	while (!que.empty()) {
		SPOT current = que.front();
		que.pop();

		x = current.x;
		y = current.y;
		z = current.z;

		for (int i = 0; i<6; i++) {
			next_x = x + dx[i];
			next_y = y + dy[i];
			next_z = z + dz[i];

			/* 경계 확인 */
			if (next_x < 0 || next_x >= C || next_y < 0 || next_y >= R || next_z < 0 || next_z >= L) continue;

			/* .이고 방문한 적 없으면*/
			if (building[next_z][next_y][next_x] == '.' && time[next_z][next_y][next_x] == 0) {
				time[next_z][next_y][next_x] = time[z][y][x] + 1;
				que.push({ next_x, next_y, next_z });
			}

			/* 도착! */
			else if (building[next_z][next_y][next_x] == 'E') {
				return time[z][y][x] + 1;
			}
		}
	}
	return -1;
}

int main(int argc, char * argv[]) {
	while (1) {
		scanf("%d %d %d", &L, &R, &C);
		getchar();  //버퍼비우기
		if (L == 0 && R == 0 && C == 0) break;

		building.resize(L + 1);
		time.resize(L + 1);
		for (int i = 0; i<L; i++) {
			building[i].resize(R + 1);
			time[i].resize(R + 1);
			for (int j = 0; j<R; j++) {
				building[i][j].resize(C + 1);
				time[i][j].resize(C + 1);
				for (int k = 0; k<C; k++) {
					char tmp;
					tmp = getchar();
					building[i][j][k] = tmp;
					if (building[i][j][k] == 'S')
						start_spot = { k,j,i };
					if (building[i][j][k] == 'E')
						end_spot = { k,j,i };
				}
				getchar();
			}
			if (i < L - 1) getchar();
		}

		que.push(start_spot);

		int answer = bfs();
		if (answer == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", answer);

		building.clear(); time.clear();
		while (!que.empty())
			que.pop();

	}
	return 0;
}