//2019.08.26
//baekjoon 3020
//개똥벌레
//lower, upperbound로 문제 해결, 처음엔 단순 구현이라 생각햇는데 시간 초과남
//algorithm에 lower_bound(upper_bound도 마찬가지)는 위치를 return하기 때문에 인덱스값을 얻고 싶다면 처음위치를 빼줘야함.

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int upRock[100001], downRock[100001];

int main(int argc, char * argv[]) {
	int N, H;
	scanf("%d %d", &N, &H);

	int rock;
	int start = 0;
	for (int i = 0; i < N / 2; i++) {
		scanf("%d %d", &downRock[i], &upRock[i]);
	}
	int len = N / 2;

	sort(downRock, downRock + len);
	sort(upRock, upRock + len);
	
	int minRock = 999999, minHeight = 0;

	for (int i = 1; i <= H; i++) {
		int rock = len - (lower_bound(downRock, downRock + len, i) - downRock);
		rock += len - (upper_bound(upRock, upRock + len, H - i) - upRock);
		if (minRock > rock) {
			minRock = rock;
			minHeight = 1;
		}
		else if (minRock == rock) {
			minHeight++;
		}
	}
	printf("%d %d\n", minRock, minHeight);
	return 0;
}