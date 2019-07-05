// 2019.06.30
// swExpertAcademy 2819
// 격자판의 숫자 이어 붙이기, dfs로 문제 해결
// 테스트케이스 여러개일 땐 초기화 항상!

#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int arr[4][4];
set<int> result;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int x, int y, int cnt, int num) {
	if (cnt > 7) return;

	num = num * 10 + arr[x][y];
	if (cnt == 7) {
		result.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= 4 || next_y < 0 || next_y >= 4) continue;
		dfs(next_x, next_y, cnt + 1, num);
	}

}
int main(int argc, char * argv[]) {

	int T;
	scanf("%d", &T);

	int answer = 0;
	for (int t = 1; t <= T; t++) {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j, 1, 0);
			}
		}

		answer = result.size();
		printf("#%d %d\n", t, answer);
		result.clear(); 
	}
	return 0;
}