//2020.02.04
//boj 14500
//��Ʈ�ι̳�
//���Ʈ����
//�� ��翡 ���ؼ� ��� �迭�� ���� �� ���鸸ŭ ���� ���� ��� ���鿡�� ���� Ȯ���ϴ� ������� ����
//dfs�� �̿��ؼ� ��,��,��,�� ��츸 �����ϸ� �����¿�� 3�� �����̸� �� ������ ���� �� �ִ�. �̸� �̿��Ͽ� ��Ʈ��ŷ�� ����Ͽ� ������ �ذ��� �� �ִ�.(���ܴ� ���� �ذ�) 

#include <iostream>
#include <cstdio>

using namespace std;

/* ���� ���� ���ؼ� ���踦 �迭 ���� */
const int tx[20][4] = { {0,0,0,0}, {0,1,2,3}, {0,0,1,1}, {0,1,2,2}, {0,0,1,2}, {0,1,2,2},
{0,0,1,2}, {0,1,1,1}, {0,1,1,1}, {0,0,0,1}, {0,0,0,1}, {0,1,1,2}, {0,1,1,2}, {0,0,1,1}, {0,0,1,1}, {0,0,0,1}, {0,1,1,1},{0,1,1,2}, {0,1,1,2} };

const int ty[20][4] = { {0,1,2,3}, {0,0,0,0}, {0,1,0,1}, {0,0,0,1}, {0,1,1,1}, {0,0,0,-1},
{0,1,0,0}, {0,0,1,2}, {0,0,-1,-2}, {0,1,2,0}, {0,1,2,2}, {0,0,1,1}, {0,0,-1,-1}, {0,1,1,2}, {0,-1,-1,-2}, {0,1,2,1}, {0,-1,0,1}, {0,-1,0,0}, {0,1,0,0} };

int N, M;
int paper[501][501];

bool chk_range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

int play_game() {
	int next_x, next_y;
	int sum = 0, max_sum = 0;

	/* �� ��ġ���� �ϳ��� ������ ���ƺ� */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				for (int s = 0; s < 4; s++) {
					next_x = i + tx[k][s];
					next_y = j + ty[k][s];
					if (!chk_range(next_x, next_y)) {
						sum = 0;
						break;
					}
					sum += paper[next_x][next_y];
				}
				if (sum !=0 && sum > max_sum) 
					max_sum = sum;
				sum = 0;
			}
		}
	}
	return max_sum;
}

int main(int argc, char * argv[]) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	printf("%d\n", play_game());

	return 0;
}