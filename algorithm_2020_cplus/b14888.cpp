//2020.02.07
//boj 14888
//연산자 끼워넣기
//브루트포스
//1. 중복순열(next_permutation)
//next_permutation을 이용하여 중복순열을 구해 문제를 해결

//2. 재귀를 이용한 완탐
//각 연산별로 하나씩해보면 됨
//최소값과 마찬가지로 최대값을 -10억으로 초기화 해줘야한다.

#define INFINITE_VALUE 1000000001
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[12];

int min_val = INFINITE_VALUE;
int max_val = -INFINITE_VALUE;

/* 중복 순열 */
vector<int> operation;
void solve() {
	while (1) {
		int result = A[0];
		/* 처음부터 차례대로 연산자에 맞게 계산 */
		for (int i = 1; i < N; i++) {
			switch (operation[i-1]) {
			case 0:
				result += A[i];
				break;
			case 1:
				result -= A[i];
				break;
			case 2:
				result *= A[i];
				break;
			case 3:
				 result /= A[i];
				break;
			default:
				break;
			}
		}
		min_val = min(min_val, result);
		max_val = max(max_val, result);
		/* 다음 순열 구하기 */
		if (!next_permutation(operation.begin(), operation.end()))
			break;
	}
}

/* 재귀 */
//int operation[4]; //+,-,*,/ 순서
//int visited[4]; //연산자 사용횟수 저장
//
//void solve(int i, int x, int result) {
//	visited[x]++;
//	int current_result;
//	switch (x){
//	case 0:
//		current_result = result + A[i];
//		break;
//	case 1:
//		current_result = result - A[i];
//		break;
//	case 2:
//		current_result = result * A[i];
//		break;
//	case 3:
//		current_result = result / A[i];
//		break;
//	default:
//		break;
//	}
//  /* 모든 계산 끝난 경우 */
//	if (i == N - 1) {
//		min_val = min(min_val, current_result);
//		max_val = max(max_val, current_result);
//		visited[x]--;
//		return;
//	}
// 
//	for (int j = 0; j < 4; j++) {
//		if (operation[j] == 0 || visited[j] == operation[j]) 
//			continue;
//
//		solve(i + 1, j, current_result);
//	}
//
//	visited[x]--;
//}

int main(int argc, char * argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	/* 중복 순열 */
	int o_cnt = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &o_cnt);
		for (int j = 0; j < o_cnt; j++)
			operation.push_back(i);
	}
	/* 순열 전에 sort 먼저 */
	sort(operation.begin(), operation.end());
	solve();

	/* 재귀 */
	/*for (int i = 0; i < 4; i++)
		scanf("%d", &operation[i]);
	for (int i = 0; i < 4; i++) {
		if (operation[i] == 0)
			continue;
		solve(1, i, A[0]);
	}*/

	printf("%d\n%d\n", max_val, min_val);

	return 0;
}
