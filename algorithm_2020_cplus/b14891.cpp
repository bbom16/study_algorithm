//2020.02.09
//boj 14891
//톱니바퀴
//시뮬레이션
//먼저 다음으로 넘긴 후 톱니바퀴를 돌려야 제대로 된 비교가 가능하다. 

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int wheel[4][9]; //톱니바퀴 정보
bool played[4]; //이미 움직였는지 여부 저장

/* played 배열 초기화 */
void clear_played() {
	for (int i = 0; i < 4; i++)
		played[i] = false;
}

void play_wheel(int num, int direct) {
	int l_wheel = num - 1;
	int r_wheel = num + 1;

	played[num] = true;
	/* 양 옆 톱니바퀴와 비교하기 */
	if (l_wheel >= 0 && !played[l_wheel]) {
		if (wheel[num][6] != wheel[l_wheel][2])
			play_wheel(l_wheel, -direct);
	}
	if (r_wheel < 4 && !played[r_wheel]) {
		if (wheel[num][2] != wheel[r_wheel][6])
			play_wheel(r_wheel, -direct);
	}

	/* 톱니바퀴 회전 */
	//시계방향
	if (direct == 1) {
		for (int i = 7; i >= 0; i--) {
			wheel[num][i + 1] = wheel[num][i];
		}
		wheel[num][0] = wheel[num][8];
	}
	//반시계방향
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
	
	/* 점수 계산 */
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1)
			answer += pow(2, i);
	}
	
	printf("%d\n", answer);

	return 0;
}