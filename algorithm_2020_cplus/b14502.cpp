//2020.02.05
//boj 14502
//������
//��Ʈ��ŷ�� �̿��� ���Ʈ����(��Ž)

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int room[9][9]; //��Ʈ��ŷ ���, �⺻ ��
int visited[9][9]; //dfs ���
int room_visited[9][9]; //��Ʈ��ŷ ���
int copy_room[9][9]; //dfs���� ���

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0, 0 };
int answer = 0;

void clear_visted() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
	}
}

bool chk_range(int x, int y){
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

/* ���� ���� ���ϱ� */
int find_safety() {
	int safety = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_room[i][j] == 0)
				safety++;
		}
	}
	return safety;
}

/* ���� �۶߸���, dfs�� �̿��ؼ� ���� */
void dfs(int x, int y) {
	visited[x][y] = true;
	int next_x, next_y;

	for (int i = 0; i < 4; i++) {
		next_x = x + dx[i];
		next_y = y + dy[i];

		if (!chk_range(next_x, next_y))
			continue;

		if (visited[next_x][next_y] || copy_room[next_x][next_y] != 0) {
			if (copy_room[next_x][next_y] == 2)
				visited[next_x][next_y] = true;
 			continue;
		}
		
		copy_room[next_x][next_y] = 2;
		dfs(next_x, next_y);
	}
}

/* �� ����� */
void set_wall(int x, int y, int wall_cnt) {
	int state = room[x][y];
	room[x][y] = 1;
	room_visited[x][y] = true;

	/* ���� 3�� ������ */
	if (wall_cnt == 3) {
		//visited �迭 �ʱ�ȭ �� ���� ���Ľ�Ű�� ���� copy_room �迭�� copy
		clear_visted();
		copy(&room[0][0], &room[0][0] + 9 * 9, &copy_room[0][0]);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_room[i][j] != 2 || visited[x][y])
					continue;
				dfs(i, j);
			}
		}
		answer = max(answer, find_safety());
		room[x][y] = state;
		room_visited[x][y] = false;
		return;
	}

	/* ��Ž���� 1���� �����鼭 ��� ����� �� Ȯ�� - �ߺ� ������ ���� ���� x���� ���� */
	for (int i = x; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == x && j == y)
				continue;

			if (!chk_range(i, j))
				continue;

			if (room_visited[i][j] || room[i][j] != 0)
				continue;

			set_wall(i, j, wall_cnt + 1);
		}
	}
	/* turn ���� �� �ٽ� �ǵ����� */
	room[x][y] = state;
	room_visited[x][y] = false;
}

int main(int argc, char * argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &room[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (room[i][j] != 0)
				continue;
			set_wall(i, j, 1);
		}
	}

	printf("%d\n", answer);

	return 0;
}