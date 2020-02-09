//2020.01.16
//boj 12100
//2048 easy
//���Ʈ������ ��� ����� ���� Ȯ���ϴ� ������� ������ �ذ�(���). 
//���� �ذ�
//1. �迭 ���簡 ��͸� ȣ���ϴ� ��� ��쿡 �ʿ�.
//2. 2048�̶� 2048������ ���ڸ� �����ߴµ� �� �̻� ����
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int blocks[21][21];
/* ���� �迭 */
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int answer = 0;
vector<vector<bool> > checked_sum; //sum�Ѱ��� �ƴ��� Ȯ���ϴ� �迭

/* checked_sum �ʱ�ȭ */
void clear_checked_sum() {
	checked_sum.clear();
	checked_sum.resize(N + 1);
	for (int i = 0; i < N + 1; i++) {
		checked_sum[i].resize(N + 1);
	}
}

/* ���� Ȯ�� */
bool chk_range(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	return true;
}

/* ��ü ������ �����ϴ� ��� �Լ� */
void play_game(int direct, int move_cnt) {
	int previous_blocks[21][21];
	int current_blocks[21][21];

	/* �迭 ����, ���� �� �ǵ����� ���� ���� */
	copy(&blocks[0][0], &blocks[0][0] + 21 * 21, &previous_blocks[0][0]); //���� �� ����

	int next_x, next_y;

	clear_checked_sum(); //�� ���帶�� clear

	/* ���⿡ ���� ������ �ٸ��� ���� (��� 3���� ��� �����̴� ���� ���� ��ġ�� ����) */
	//��,���� ��� ������ �Ʒ����� ���� 
	if (direct == 0 || direct == 2) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = N - 1; j >= 0; j--) {
				if (blocks[i][j] == 0)
					continue;
				next_x = i + dx[direct];
				next_y = j + dy[direct];
				/* ����ִ� �κ�(0�� �κ�) ������ �����̱� */
				while (1) {
					if (!chk_range(next_x, next_y))
						break;

					if (blocks[next_x][next_y] != 0)
						break;
		
					next_x += dx[direct];
					next_y += dy[direct];
				}
				/* ���� ���� ��� */
				if (!chk_range(next_x, next_y)) {
					next_x -= dx[direct];
					next_y -= dy[direct];
					if (i == next_x && j == next_y)
						continue;

					blocks[next_x][next_y] = blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = checked_sum[i][j];
					checked_sum[i][j] = false;

				}
				/* ���� block�� ������������ ���, �Ȱ��� ���ڸ� ���� ��� */
				else if ((blocks[next_x][next_y] == blocks[i][j]) && (!checked_sum[next_x][next_y])) {
					blocks[next_x][next_y] += blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = true;
				}
				/* �̹� ������ ��� �Ǵ� �ٸ� ���ڸ� ���� �� �̻� ���� ������ ���� ��� */
				else{
					next_x -= dx[direct];
					next_y -= dy[direct];
					if (i == next_x && j == next_y)
						continue;

					blocks[next_x][next_y] = blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = checked_sum[i][j];
					checked_sum[i][j] = false;
				}
			}
		}
	}
	//��,���ΰ�� ���� ������ ����(�Լ� �ȿ��� ���� ����)
	else if (direct == 1 || direct == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (blocks[i][j] == 0)
					continue;
				next_x = i + dx[direct];
				next_y = j + dy[direct];
				while (1) {
					if (!chk_range(next_x, next_y))
						break;

					if (blocks[next_x][next_y] != 0)
						break;

					next_x += dx[direct];
					next_y += dy[direct];
				}
				if (!chk_range(next_x, next_y)) {
					next_x -= dx[direct];
					next_y -= dy[direct];
					if (i == next_x && j == next_y)
						continue;

					blocks[next_x][next_y] = blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = checked_sum[i][j];
					checked_sum[i][j] = false;
					
				}

				else if ((blocks[next_x][next_y] == blocks[i][j]) && (!checked_sum[next_x][next_y])) {
					blocks[next_x][next_y] += blocks[i][j];
					blocks[i][j] = 0;
 					checked_sum[next_x][next_y] = true;
				}
				else {
					next_x -= dx[direct];
					next_y -= dy[direct];
					if (i == next_x && j == next_y)
						continue;

					blocks[next_x][next_y] = blocks[i][j];
					blocks[i][j] = 0;
					checked_sum[next_x][next_y] = checked_sum[i][j];
					checked_sum[i][j] = false;
				}

			}
		}
	}
	/* �ִ� ã�� */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer = max(answer, blocks[i][j]);
		}
	}
	/* �ִ� 5�������� �����̱� */
	if (move_cnt == 5){
		return;
	}
	/* ���� block ���� ���� */
	copy(&blocks[0][0], &blocks[0][0] + 21 * 21, &current_blocks[0][0]);

	/* ���� step���� ����, �� �� ���� �迭 ���·� �����ؼ� ���� */
	for (int i = 0; i < 4; i++) {
		copy(&current_blocks[0][0], &current_blocks[0][0] + 21 * 21, &blocks[0][0]);
		play_game(i, move_cnt + 1);
	}

	/* ���� step�� ���� ��� ó�� ���·� ������ ���� */
	copy(&previous_blocks[0][0], &previous_blocks[0][0] + 21 * 21, &blocks[0][0]);
}

int main(int argc, char * argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &blocks[i][j]);
		}
	}
	/* ��� ����� �� Ȯ�� */
	for (int i = 0; i < 4; i++) {
		play_game(i, 1);
	}

	printf("%d\n", answer);

	return 0;
}