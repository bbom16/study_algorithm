//2020.02.04
//boj 14500
//테트로미노
//브루트포스
//각 모양에 대해서 상수 배열로 만들어서 그 값들만큼 종이 위에 모든 점들에서 전부 확인하는 방법으로 진행
//dfs를 이용해서 ㅗ,ㅓ,ㅜ,ㅏ 경우만 제외하면 상하좌우로 3번 움직이면 각 모양들이 나올 수 있다. 이를 이용하여 백트래킹을 사용하여 문제를 해결할 수 있다.(예외는 따로 해결) 

#include <iostream>
#include <cstdio>

using namespace std;

/* 각각 모양들 구해서 관계를 배열 저장 */
const int tx[20][4] = { {0,0,0,0}, {0,1,2,3}, {0,0,1,1}, {0,1,2,2}, {0,0,1,2}, {0,1,2,2},
{0,0,1,2}, {0,1,1,1}, {0,1,1,1}, {0,0,0,1}, {0,0,0,1}, {0,1,1,2}, {0,1,1,2}, {0,0,1,1}, {0,0,1,1}, {0,0,0,1}, {0,1,1,1},{0,1,1,2}, {0,1,1,2} };

const int ty[20][4] = { {0,1,2,3}, {0,0,0,0}, {0,1,0,1}, {0,0,0,1}, {0,1,1,1}, {0,0,0,-1},
{0,1,0,0}, {0,0,1,2}, {0,0,-1,-2}, {0,1,2,0}, {0,1,2,2}, {0,0,1,1}, {0,0,-1,-1}, {0,1,1,2}, {0,-1,-1,-2}, {0,1,2,1}, {0,-1,0,1}, {0,-1,0,0}, {0,1,0,0} };

int N, M;
int paper[501][501];

bool chk_range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

int play_game() {
	int next_x, next_y;
	int sum = 0, max_sum = 0;

	/* 각 위치별로 하나씩 모양들을 놓아봄 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				for (int s = 0; s < 4; s++) {
					next_x = i + tx[k][s];
					next_y = j + ty[k][s];
					if (!chk_range(next_x, next_y)) {
						sum = 0;
						break;
					}
					sum += paper[next_x][next_y];
				}
				if (sum !=0 && sum > max_sum) 
					max_sum = sum;
				sum = 0;
			}
		}
	}
	return max_sum;
}

int main(int argc, char * argv[]) {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	printf("%d\n", play_game());

	return 0;
}