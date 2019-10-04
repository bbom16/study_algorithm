#include <iostream>
#include <stdio.h>
using namespace std;

int computer_set[101][101];
bool visited[101];
int N, C;

int dfs(int num) {
	visited[num] = true;
	int cnt = 1;
	for (int i = 1; i < N+1; i++) {
		if (computer_set[num][i] && !visited[i]) {
			cnt += dfs(i);
		}
	}
	return cnt;
}
int main(int argc, char * argv[]) {
	scanf("%d %d", &N, &C);

	int c1, c2;
	for (int i = 0; i < C; i++) {
		scanf("%d %d", &c1, &c2);
		computer_set[c1][c2] = 1;
		computer_set[c2][c1] = 1;
	}

	printf("%d\n",dfs(1)-1);

	return 0;
}