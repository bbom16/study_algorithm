//2020.02.10
//boj 15684
//사다리 조작
//브루트포스
//M이랑 H를 혼동해서 사다리타기 할 때 잘못 사용함.
//세로선에 사다리를 놓으면 그 다음 cnt에서는 다음 세로선에 놓는 경우를 확인했는데 같은 세로선에 여러번 놓은 경우도 존재할 수 있다.
//그 부분 수정해서 정답

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, H;
int ladder_info[32][12]; //[H][N] [가로][세로]
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

	/* 사다리 게임 시작 */
	bool result = false;
	for (int i = 1; i <= N; i++) {
		result = play_ladder(i, 0, i);
		if (!result)
			break;
	}
	/* 모든 경우 성공 */
	if (result) {
		answer = min(answer, cnt);
		return;
	}

	if (cnt == 3) {
		return;
	}

	for (int i = r; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			/* 현재 사다리가 비어있는지, 가로선이 연속되지않는지 체크 */
			if (ladder_info[j][i] != 0 || ladder_info[j][i + 1] != 0)
				continue;

			/* 사다리 놓기 */
			ladder_info[j][i] = i + 1;
			ladder_info[j][i + 1] = i;

			put_ladder(i, cnt + 1);	//다음 스텝에서도 같은 세로선 확인 

			/* 제거 */
			ladder_info[j][i] = 0;
			ladder_info[j][i + 1] = 0;
		}
	}
}

int main(int argc, char * argv[]) {
	scanf("%d %d %d", &N, &M, &H);

	int row, col; //row : 세로선, col : 가로선
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