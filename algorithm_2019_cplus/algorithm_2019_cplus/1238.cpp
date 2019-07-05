// 2019.07.05
// baeckjoon 1238
// 파티 
// 플로이드워셜, 경유지를 i로 설정하자
#define INF 9999999
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int load_info[1001][1001];
;int main(int argc, char * argv[]) {
	int N, M, X;
	scanf("%d %d %d", &N, &M, &X);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (i == j) load_info[i][j] = 0;
			else load_info[i][j] = INF;	
	}

	int start, end, time;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &start, &end, &time);
		load_info[start][end] = time;
	}

	for (int i = 1; i <= N; i++) { //경유지
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (load_info[j][i] == INF) break;
				load_info[j][k] = min(load_info[j][k], load_info[j][i] + load_info[i][k]);
			}
		}
	}

	int max_time = 0; 
	for (int i = 1; i <= N; i++) {
		load_info[i][i] = load_info[i][X] + load_info[X][i];
		max_time = max(load_info[i][i], max_time);
	}

	printf("%d\n", max_time);
	return 0;
}