// 2019.08.13
// boj 17144
// 미세먼지 안녕!
// 시뮬레이션

#include <iostream>
#include <stdio.h>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int originPlace[51][51];
int changePlace[51][51];

int R, C, T;
bool chkSpace(int x, int y) {
	if (x < 0 || y < 0 || x >= R || y >= C)
		return false;
	return true;
}
void spread(int x, int y) {
	int totalSpread = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		
		if (!chkSpace(nextX,nextY)) continue;
		if (originPlace[nextX][nextY] == -1) continue;

		changePlace[nextX][nextY] += originPlace[x][y] / 5;
		totalSpread++;
	}
	changePlace[x][y] -= (totalSpread * (originPlace[x][y] / 5));
}

void clean(int x, int y, int val, int d, bool clock) {
	
	int nextX = x + dx[d];
	int nextY = y + dy[d];
	if (!chkSpace(nextX, nextY)) {
		if (!clock) 
			d = (d + 3) % 4;
		else 
			d = (d + 1) % 4;
	
		nextX = x + dx[d];
		nextY = y + dy[d];
	}
	int tmp = changePlace[nextX][nextY];
	if (tmp == -1) 
		return;
	
	changePlace[nextX][nextY] = val;
	clean(nextX, nextY, tmp, d, clock);
}
int main(int argc, char * argv[]) {

	scanf("%d %d %d", &R, &C, &T);

	int airCleaner[2];
	int aIndex = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &changePlace[i][j]);
			if (changePlace[i][j] == -1) {
				airCleaner[aIndex++] = i;
			}
		}
	}
	while (T--){
		
		copy(&changePlace[0][0], &changePlace[0][0] + 51 * 51, &originPlace[0][0]);
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				spread(i, j);
			}
		}

		for (int i = 0; i < 2; i++) {
			clean(airCleaner[i], 0, 0, 0, i);
		}

	}

	int ans = 2; //공기 청정기 빼고 
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += changePlace[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}
