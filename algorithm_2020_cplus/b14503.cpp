//2020.02.06
//boj 14503
//�κ� û�ұ�
//�ùķ��̼�, �׳� �϶�´�� �����̸� ��
//������ �����̾���. ���� ������ ���� �ִ����� ���ư��ٰ� ������ ��ͷ� ���ư��� ������, 
//�������� �䱸�ϴ� �� ������ ������ ��ġ������ �������� �����ϴ� ���̾���.
//�׷��� ���α׷� ���� �� ���� �ذ�
//������Ϸ��� ®�� �ڵ�� ���� ���� ��������!

#include <iostream>
#include <cstdio>
using namespace std;

int N, M;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int room[51][51]; //��, �� ������ �ִ� �迭
bool cleaned[51][51]; //û�� ���� Ȯ���ϴ� �迭 
int room_cnt = 0;

bool chk_range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

void clean_room(int x, int y, int d) {
	if (!cleaned[x][y]) {
		cleaned[x][y] = true;
		room_cnt++;
	}

	int next_x, next_y, next_d;
	for (int i = 0; i < 4; i++) {
		// ���� �����°� �����Ϸ��� 4 �����ְ� 1 ������ mod 4 
		next_d = (d + 4 - 1) % 4;

		next_x = x + dx[next_d];
		next_y = y + dy[next_d];

		/* ���� ��쳪 û�ҵ� ��� */
		if (!chk_range(next_x, next_y) || room[next_x][next_y] == 1 || cleaned[next_x][next_y]) {
			d = next_d;
		}
		else {
			clean_room(next_x, next_y, next_d);
			return;
		}
	}

	/* ���� - ���� ������ ��ġ���� ���� d�� ���� */
	next_x = x - dx[d];
	next_y = y - dy[d];

	if (!chk_range(next_x, next_y) || room[next_x][next_y] == 1)
		return;

	clean_room(next_x, next_y, d);

}

int main(int argc, char * argv[]) {

	scanf("%d %d", &N, &M);

	int start_x, start_y, direction;
	scanf("%d %d %d", &start_x, &start_y, &direction);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &room[i][j]);
	}

	clean_room(start_x, start_y, direction);

	printf("%d\n", room_cnt);

	return 0;
}