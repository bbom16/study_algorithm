//2019.09.04
//samsung 1210
//Ladder1
//dfs, 무조건 옆으로 왼/오 로 갈수있으면 그 길 선택

#include <stdio.h>
#include <iostream>
#include <utility>
using namespace std;

int ladder[101][101];
bool visited[101][101];

int startPoint = -1;

int dx[] = { 0,0,-1 };
int dy[] = { -1, 1, 0 };

bool chkRange(int x, int y) {
	if (x < 0 || y < 0 || x >= 100 || y >= 100)
		return false;
	return true;
}

void findStart(int x, int y) {
	visited[x][y] = true;
	if (x == 0) {
		startPoint = y;
		return;
	}
	int nextX, nextY;
	for (int i = 0; i < 3; i++) {
		nextX = x + dx[i];
		nextY = y + dy[i];
		if (!chkRange(nextX, nextY) || visited[nextX][nextY]) continue;
		if (ladder[nextX][nextY] == 1) {
			findStart(nextX, nextY);
			break;
		}
	}
}

int main(int argc, char * argv[]) {
	int T;
	pair<int, int> end;

	//freopen("testCase1210.txt", "r", stdin);

	while(1){
		scanf("%d", &T);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &ladder[i][j]);
				if (ladder[i][j] == 2)
					end = make_pair(i, j);

				visited[i][j] = false;
			}
		}
		findStart(end.first, end.second);

		printf("#%d %d\n", T, startPoint);
		startPoint = 0;
		
		if (T == 10) break;
	}
	return 0;
}