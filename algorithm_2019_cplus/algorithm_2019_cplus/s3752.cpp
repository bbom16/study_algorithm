//2019.09.01
//samsung 3752
//가능한 시험 점수
//dp

#include <stdio.h>
#include <iostream>
using namespace std;

int scoreArr[101];
bool possibleScore[10001];

int main(int argc, char * argv[]) {
	int T;
	scanf("%d", &T);

	int N;

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);

		int totalSum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &scoreArr[i]);
			totalSum += scoreArr[i];
		}
		
		possibleScore[0] = true;

		for (int i = 0; i < N; i++) {
			for (int j = totalSum; j >= 0; j--) {
				if (possibleScore[j]) {
					possibleScore[scoreArr[i] + j] = true;
				}
			}
		}

		int answer = 0;
		for (int i = 0; i <= totalSum; i++) {
			if (possibleScore[i]) answer++;
		}
		printf("#%d %d\n", tc, answer);
		for (int i = 0; i <= totalSum; i++)
			possibleScore[i] = false;
	}
	return 0;
}