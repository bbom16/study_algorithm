//2020.02.09
//boj 14891
//��Ϲ���
//�ùķ��̼�
//���� �������� �ѱ� �� ��Ϲ����� ������ ����� �� �񱳰� �����ϴ�. 

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int wheel[4][9]; //��Ϲ��� ����
bool played[4]; //�̹� ���������� ���� ����

/* played �迭 �ʱ�ȭ */
void clear_played() {
	for (int i = 0; i < 4; i++)
		played[i] = false;
}

void play_wheel(int num, int direct) {
	int l_wheel = num - 1;
	int r_wheel = num + 1;

	played[num] = true;
	/* �� �� ��Ϲ����� ���ϱ� */
	if (l_wheel >= 0 && !played[l_wheel]) {
		if (wheel[num][6] != wheel[l_wheel][2])
			play_wheel(l_wheel, -direct);
	}
	if (r_wheel < 4 && !played[r_wheel]) {
		if (wheel[num][2] != wheel[r_wheel][6])
			play_wheel(r_wheel, -direct);
	}

	/* ��Ϲ��� ȸ�� */
	//�ð����
	if (direct == 1) {
		for (int i = 7; i >= 0; i--) {
			wheel[num][i + 1] = wheel[num][i];
		}
		wheel[num][0] = wheel[num][8];
	}
	//�ݽð����
	else if (direct == -1) {
		wheel[num][8] = wheel[num][0];
		for (int i = 1; i < 8; i++) {
			wheel[num][i - 1] = wheel[num][i];
		}
		wheel[num][7] = wheel[num][8];
	}
}

int main(int argc, char * argv[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++)
			scanf("%1d", &wheel[i][j]);
	}

	int K;
	scanf("%d", &K);

	int w_num, w_direct;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &w_num, &w_direct);
		clear_played();
		play_wheel(w_num - 1, w_direct);
	}
	
	/* ���� ��� */
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1)
			answer += pow(2, i);
	}
	
	printf("%d\n", answer);

	return 0;
}