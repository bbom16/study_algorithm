//2019.09.04
//samsung 1249
//보급로
//dfs , 백트래킹 

#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int load[101][101];
int changeLoad[101][101];
bool visited[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N;
bool chkRange(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N) {
		return false;
	}
	return true;
}

void findDays() {
	queue<pair<int, int> > que;
	que.push(make_pair(0, 0));
	visited[0][0] = true;
	int x, y, nextX, nextY;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			nextX = x + dx[i];
			nextY = y + dy[i];
			
			if (!chkRange(nextX, nextY)) continue;
			if (!visited[nextX][nextY] || changeLoad[nextX][nextY] > load[nextX][nextY] + changeLoad[x][y]) {
				changeLoad[nextX][nextY] = load[nextX][nextY] + changeLoad[x][y];
				que.push(make_pair(nextX, nextY));
				visited[nextX][nextY] = true;
			}
		}
	}

}

int main(int argc, char * argv[]) {

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &load[i][j]);
				visited[i][j] = false;
			}
		}

		findDays();
		printf("#%d %d\n", tc, changeLoad[N - 1][N - 1]);
	}

	return 0;
}