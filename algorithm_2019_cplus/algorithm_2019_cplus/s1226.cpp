//2019.09.04
//samsung 1226
//미로
//dfs 3까지 도달 가능한지 여부 확인

#include <stdio.h>
#include <iostream>
#include <utility>

using namespace std;

int maze[17][17];
bool visited[17][17];
pair<int, int> start;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
bool chkEscape = false;

bool chkRange(int x, int y) {
	if (x < 0 || y < 0 || x >= 16 || y >= 16)
		return false;
	return true;
}

void escapeMaze(int x, int y) {
	visited[x][y] = true;
	int nextX, nextY;

	for (int i = 0; i < 4; i++) {
		nextX = x + dx[i];
		nextY = y + dy[i];
		if (!chkRange(nextX, nextY) || visited[nextX][nextY]) continue;
		if (maze[nextX][nextY] == 0)
			escapeMaze(nextX, nextY);
		else if (maze[nextX][nextY] == 3) {
			chkEscape = true;
			return;
		}
			
	}
}

int main(int argc, char *argv[]) {

	freopen("testCase1226.txt", "r", stdin);

	int T;
	while (1) {
		scanf("%d", &T);
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &maze[i][j]);
				if (maze[i][j] == 2) {
					start = make_pair(i, j);
				}
				visited[i][j] = false;
			}
		}
		escapeMaze(start.first, start.second);

		printf("#%d %d\n", T, chkEscape);
		chkEscape = false;

		if (T == 10) break;
	}

	return 0;
}