//2020.02.08
//boj 14890
//경사로 
//시뮬레이션
//별도의 예외는 없지만 예제 구현에서 시간이 많이 걸렸다.
//L이 1일때가 다른 경우와는 다르게 경사로가 중복되는 것을 예외로 두기가 어려웠다. 
//그래서 바로 전에 경사로를 둔 경우를 알 수 있는 변수와 방향을 나타내는 변수를 이용하여 구분하였다. 

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
	int direct_slope = 0; // 0:없는거, 1:올라오는거, 2:내려가는거 (왼->오 기준)
	
	while(1){
		if (col)
			x++;
		else
			y++;

		if (x >= N || y >= N)
			break;

		/* 전에 숫자랑 같으면 개수 증가 */
		if (map[x][y] == slope_num) {
			slope_cnt++;
			is_slope = false;
		}

		/* 올라가는 모양 */
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
		/* 내려가는 모양 */
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