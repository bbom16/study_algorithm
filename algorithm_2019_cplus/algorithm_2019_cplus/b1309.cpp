//2019.08.26
//backjoon 1309
//동물원
// dp, 점화식 lion[i] = lion[i-1]*2 + lion[i-2]
#include <stdio.h>
#include <iostream>

using namespace std;

int lion[100001];
int main(int argc, char * argv[]) {
	int N;
	scanf("%d", &N);

	lion[0] = 1; lion[1] = 3;
	for (int i = 2; i <= N; i++) {
		lion[i] = (lion[i - 1] * 2 + lion[i - 2]) % 9901;
	}

	printf("%d\n", lion[N]);
}