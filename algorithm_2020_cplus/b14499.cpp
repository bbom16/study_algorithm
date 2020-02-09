//2020.02.03
//boj 14499
//�ֻ��� ������
//�ùķ��̼� 
//�ֻ����� �ٴ� �� �ٲ� ��ġ�������� ã�°� ���� �ذ��� �ٽ�
//���� �ٲ�� ������ �迭�� �̿��� �����ؼ� ���� �ذ� 

#include <iostream>
#include <cstdio>

using namespace std;

int N, M, x, y, K;
int map[21][21]; 
int current_location[6]; //�ֻ����� ���� ��ġ ����
int next_location[6] = { 6,3,4,2,5,1 }; //�ֻ����� �ű� ��ġ ���� (������ �ٴ��� 6�� �������� �� command�� ���� �ٲ� ��ġ������)
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
int dice[7] = { 0, }; //�ֻ����� �� �鿡 ���� ����

bool chk_range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

void play_dice(int x, int y, int c) {

	/* command ���� ���� �ݴ��� ��(1-2, 3-4) */
	int tmp;
	if (c == 1)
		tmp = 2;
	else if (c == 2)
		tmp = 1;
	else if (c == 3)
		tmp = 4;
	else if (c == 4)
		tmp = 3;

	/* �ֻ����� ���� �� �ٲ� �ֻ��� �迭 */
	next_location[0] = current_location[c];
	next_location[c] = 7 - current_location[0];
	next_location[tmp] = current_location[0];
	next_location[5] = 7 - current_location[c];

	//�ٴ�
	int bottom = next_location[0];

	/* 0�̸� ������ �ֻ��� �ظ� �� ����, �ƴϸ� �ֻ��� �ٴڿ� ���� �� ���� �� ���� �� 0 */
	if (map[x][y] == 0) {
		map[x][y] = dice[bottom];
	}
	else {
		dice[bottom] = map[x][y];
		map[x][y] = 0;
	}

	printf("%d\n", dice[7 - bottom]);
}

int main(int argc, char *argv[]) {
	
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int command;

	while (K--) {
		/* next ������ current ������ copy */
		for (int i = 0; i < 6; i++) {
			current_location[i] = next_location[i];
		}

		scanf("%d", &command);
	
		/* ��ɿ� �´� ��ġ�� �̵� */
		x += dx[command];
		y += dy[command];
		if (!chk_range(x, y)) {
			x -= dx[command];
			y -= dy[command];
			continue;
		}
			
		play_dice(x, y, command);

	}

	return 0;
}