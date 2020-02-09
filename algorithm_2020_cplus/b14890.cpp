//2020.02.08
//boj 14890
//���� 
//�ùķ��̼�
//������ ���ܴ� ������ ���� �������� �ð��� ���� �ɷȴ�.
//L�� 1�϶��� �ٸ� ���ʹ� �ٸ��� ���ΰ� �ߺ��Ǵ� ���� ���ܷ� �αⰡ �������. 
//�׷��� �ٷ� ���� ���θ� �� ��츦 �� �� �ִ� ������ ������ ��Ÿ���� ������ �̿��Ͽ� �����Ͽ���. 

#include <iostream>
#include <cstdio>
using namespace std;

int N, L;
int map[101][101];
int slope_num, slope_cnt;
int answer = 0;


bool chk_road(int start_x, int start_y, bool col) {
	slope_num = map[start_x][start_y];
	slope_cnt = 1;
	int x = start_x, y = start_y;
	bool is_slope = false;
	int direct_slope = 0; // 0:���°�, 1:�ö���°�, 2:�������°� (��->�� ����)
	
	while(1){
		if (col)
			x++;
		else
			y++;

		if (x >= N || y >= N)
			break;

		/* ���� ���ڶ� ������ ���� ���� */
		if (map[x][y] == slope_num) {
			slope_cnt++;
			is_slope = false;
		}

		/* �ö󰡴� ��� */
		else if (map[x][y] - slope_num == 1) {
			if (L > 1 && slope_cnt < L)
				return false;
			if (is_slope && direct_slope == 2)
				return false;
		
			slope_num = map[x][y];
			slope_cnt = 0;
			is_slope = true;
			direct_slope = 1;
		}
		/* �������� ��� */
		else if (slope_num - map[x][y] == 1) {
			int tmp = map[x][y];
			int tmp_x = x, tmp_y = y;
			for (int j = 0; j < L; j++) {
				if (col)
					tmp_x = x + j;
				else
					tmp_y = y + j;
				if (tmp_x >= N || tmp_y >= N)
					return false;
				if (map[tmp_x][tmp_y] != tmp)
					return false;
			}

			slope_num = tmp;
			slope_cnt = 0;
			x = tmp_x, y = tmp_y;
			is_slope = true;
			direct_slope = 2;
		}
		else {
			return false;
		}
	}

	return true;
}

int main(int argc, char * argv[]) {
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 0; i < N; i++) {
		if (chk_road(0, i, true))
			answer++;
		if (chk_road(i, 0, false))
			answer++;
	}

	printf("%d\n", answer);

	return 0;
}