//2019.08.05
//boj 9663
//N-Queen
//백 트래킹, 행을 기준으로 확인

#include <stdio.h>
#include <iostream>

using namespace std;

int chess[16][16];
int visited[16][16];
int N;
int dy[4] = { -1,-1,1,1 };
int dx[4] = { -1,1,-1,1 };

void takeChess(int x, int y, int d) {
	if (d == -1) {
		visited[x][y]--;
		for (int i = 0; i < N; i++) {
			if (i != y)
				visited[x][i]--;
			if (i != x)
				visited[i][y]--;
		}
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
				continue;
			visited[nextX][nextY]--;
			takeChess(nextX, nextY, i);
		}
		return;
	}
	int nextX = x + dx[d];
	int nextY = y + dy[d];
	if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) return;
	visited[nextX][nextY]--;
	takeChess(nextX, nextY, d);
}

void putChess(int x, int y, int d) {
	if (d == -1) {
		visited[x][y]++;
		for (int i = 0; i < N; i++) {
			if (i != y )
				visited[x][i]++;
			if(i != x)
				visited[i][y]++;
		}
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
				continue;
			visited[nextX][nextY]++;
			putChess(nextX, nextY, i);
		}
		return;
	}
	int nextX = x + dx[d];
	int nextY = y + dy[d];
	if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) return;
	visited[nextX][nextY]++;
	putChess(nextX, nextY, d);
}

int findNQueen(int x, int y, int cnt) {
	if (cnt == N) 
		return 1;
	int NQueenCnt = 0;
	chess[x][y] = cnt;
	putChess(x, y, -1);
	for (int i = 0; i < N; i++) {
		if (chess[cnt][i] > 0 || visited[cnt][i] > 0) continue;
			NQueenCnt += findNQueen(cnt,i,cnt+1);
	}
	takeChess(x, y, -1);
	chess[x][y] = 0;
	return NQueenCnt;
}

int main(int argc, char * argv[]) {

	scanf("%d", &N);
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += findNQueen(0, i, 1);
	}

	printf("%d\n", answer);

	return 0;
}