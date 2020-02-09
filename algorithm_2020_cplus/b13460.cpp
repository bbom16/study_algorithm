//2020.01.01
//boj 13460
//���� Ż��2
//���Ʈ������ ���� �ذ�, ��� ��쿡 ���� �� Ȯ���ϱ� ���� ��ͷ� �Լ� �ۼ�
//�Ķ� ������ ���ۿ� �� ���� ������ return
//���� ������ �� ��� Ƚ�� Ȯ��, �� ���� �ּڰ� ����
//10�� �Ѿ�� ���� ������ return
//!���⿡ ���� ���� ���� �����ֱ�!

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXIMUN_VALUE  9999999

/* ���� ��ġ ����ü */
typedef struct location {
	int x;
	int y;
}LC;

int N, M;

/* �� ���� ��ġ�� */
LC red_marble;
LC blue_marble;
LC hole;

char map[11][11]; // ��ü ����
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int answer = MAXIMUN_VALUE; //����

/* ���� Ȯ�� �Լ� */
bool chk_range(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return false;
	return true;
}

/* ���� �����̴� �Լ� */
void move_marble(LC red, LC blue, int direct, int move_cnt) {
	/* �̵� Ƚ���� 10 �Ѿ�� ������ return */
	if (move_cnt == -1)
		return;
	if (move_cnt > 10) {
		move_cnt = -1;
		return;
	}
	
	LC marble1, marble2;
	LC next_marble1, next_marble2;
	bool chk_order = false; // marble1 : red, marble2 : blue, true�̸� �ݴ� 

	/* ���� ���� ���� ���� ���ϱ� */
	switch (direct)
	{
	case 0: // ��
		if (red.y - blue.y > 0) {
			marble1 = red;
			marble2 = blue;
		}
		else {
			marble1 = blue;
			marble2 = red;
			chk_order = true;
		}
		break;
	case 1: // ��
		if (red.y - blue.y > 0) {
			marble1 = blue;
			marble2 = red;
			chk_order = true;
		}
		else {
			marble1 = red;
			marble2 = blue;
		}
		break;
	case 2:	// �� 
		if (red.x - blue.x > 0) {
			marble1 = red;
			marble2 = blue;
		}
		else {
			marble1 = blue;
			marble2 = red;
			chk_order = true;
		}
		break;
	case 3: // ��
		if (red.x - blue.x > 0) {
			marble1 = blue;
			marble2 = red;
			chk_order = true;
		}
		else {
			marble1 = red;
			marble2 = blue;
		}
		break;
	default:
		break;
	}

	/* ���� 1 ��ġ */
	while (1) {
		next_marble1 = { marble1.x + dx[direct], marble1.y + dy[direct] };
		//���� �Ѿ ���
		if (!chk_range(next_marble1.x, next_marble1.y))
			break;
		//���ۿ� ������ ���
		if (next_marble1.x == hole.x && next_marble1.y == hole.y) {
			marble1 = next_marble1;
			break;
		}
		//���� �ε��� �� �̻� ���� �ȵǴ� ���
		if (map[next_marble1.x][next_marble1.y] == '#')
			break;

		marble1 = next_marble1;
	}

	/* ���� 2 ��ġ */
	while (1) {
		next_marble2 = { marble2.x + dx[direct], marble2.y + dy[direct] };
		if (!chk_range(next_marble2.x, next_marble2.y))
			break;
		if (next_marble2.x == hole.x && next_marble2.y == hole.y) {
			marble2 = next_marble2;
			break;
		}
		if (map[next_marble2.x][next_marble2.y] == '#')
			break;

		if (next_marble2.x == marble1.x && next_marble2.y == marble1.y)
			break;

		marble2 = next_marble2;
	}

	/* ���� ����, �Ķ� ���� ��ġ */
	LC result_red, result_blue;
	if (!chk_order) {
		result_red = marble1;
		result_blue = marble2;
	}
	else {
		result_red = marble2;
		result_blue = marble1;
	}

	/* �Ķ��� ������ ��� : ������ return*/
	if (result_blue.x == hole.x && result_blue.y == hole.y)
		return;

	/* ������ ������ ��� : ���� ����, ������ Ƚ�� Ȯ�� */
	if (result_red.x == hole.x && result_red.y == hole.y) {
		if (move_cnt < 0)
			return;
		answer = min(answer, move_cnt);
		return;
	}

	/* ���� step���� ����, ���� ������ ������ �ٸ� �������� ���� ������ */
	for (int i = 0; i < 4; i++) {
		if (i == direct)
			continue;
		move_marble(result_red, result_blue, i, move_cnt + 1);
	}
}

int main(int argc, char * argv[]) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			/* �� ���� �� ���� ��ġ ���� */
			if (map[i][j] == 'R') {
				red_marble = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				blue_marble = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'O')
				hole = { i,j };
		}
	}

	/* 4���� �������� ���� ������ */
	for (int i = 0; i < 4; i++) {
		move_marble(red_marble, blue_marble, i, 1);
	}

	if (answer == MAXIMUN_VALUE)
		answer = -1;

	cout << answer << "\n";

	return 0;
}