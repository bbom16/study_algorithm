//2020.02.10
//boj 15684
//��ٸ� ����
//���Ʈ����
//M�̶� H�� ȥ���ؼ� ��ٸ�Ÿ�� �� �� �߸� �����.
//���μ��� ��ٸ��� ������ �� ���� cnt������ ���� ���μ��� ���� ��츦 Ȯ���ߴµ� ���� ���μ��� ������ ���� ��쵵 ������ �� �ִ�.
//�� �κ� �����ؼ� ����

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, H;
int ladder_info[32][12]; //[H][N] [����][����]
int answer = 4;

bool chk_range(int x) {
	if (x < 1 || x > N)
		return false;
	return true;
}

bool play_ladder(int r, int c, int start) {
	int i;
	bool result = false;
	for (i = c + 1; i <= H; i++) {
		if (ladder_info[i][r] > 0) {
			result = play_ladder(ladder_info[i][r], i, start);
			break;
		}
	}
	if (i > H && r == start)
		return true;
	return result;
}

void put_ladder(int r, int cnt) {

	/* ��ٸ� ���� ���� */
	bool result = false;
	for (int i = 1; i <= N; i++) {
		result = play_ladder(i, 0, i);
		if (!result)
			break;
	}
	/* ��� ��� ���� */
	if (result) {
		answer = min(answer, cnt);
		return;
	}

	if (cnt == 3) {
		return;
	}

	for (int i = r; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			/* ���� ��ٸ��� ����ִ���, ���μ��� ���ӵ����ʴ��� üũ */
			if (ladder_info[j][i] != 0 || ladder_info[j][i + 1] != 0)
				continue;

			/* ��ٸ� ���� */
			ladder_info[j][i] = i + 1;
			ladder_info[j][i + 1] = i;

			put_ladder(i, cnt + 1);	//���� ���ܿ����� ���� ���μ� Ȯ�� 

			/* ���� */
			ladder_info[j][i] = 0;
			ladder_info[j][i + 1] = 0;
		}
	}
}

int main(int argc, char * argv[]) {
	scanf("%d %d %d", &N, &M, &H);

	int row, col; //row : ���μ�, col : ���μ�
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &col, &row);
		ladder_info[col][row] = row + 1;
		ladder_info[col][row + 1] = row;
	}
	put_ladder(1, 0);
	if (answer == 4)
		answer = -1;

	printf("%d\n", answer);

	return 0;
}