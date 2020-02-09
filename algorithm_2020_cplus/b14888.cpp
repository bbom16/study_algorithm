//2020.02.07
//boj 14888
//������ �����ֱ�
//���Ʈ����
//1. �ߺ�����(next_permutation)
//next_permutation�� �̿��Ͽ� �ߺ������� ���� ������ �ذ�

//2. ��͸� �̿��� ��Ž
//�� ���꺰�� �ϳ����غ��� ��
//�ּҰ��� ���������� �ִ밪�� -10������ �ʱ�ȭ ������Ѵ�.

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

/* �ߺ� ���� */
vector<int> operation;
void solve() {
	while (1) {
		int result = A[0];
		/* ó������ ���ʴ�� �����ڿ� �°� ��� */
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
		/* ���� ���� ���ϱ� */
		if (!next_permutation(operation.begin(), operation.end()))
			break;
	}
}

/* ��� */
//int operation[4]; //+,-,*,/ ����
//int visited[4]; //������ ���Ƚ�� ����
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
//  /* ��� ��� ���� ��� */
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

	/* �ߺ� ���� */
	int o_cnt = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &o_cnt);
		for (int j = 0; j < o_cnt; j++)
			operation.push_back(i);
	}
	/* ���� ���� sort ���� */
	sort(operation.begin(), operation.end());
	solve();

	/* ��� */
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
