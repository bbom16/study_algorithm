// 2019.07.15
// boj 15486
// 퇴사 2
// dp 일할 수 있을 때와 없을 때로 나눠서 문제 해결

#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char * argv[]) {
	int N;
	scanf("%d", &N);

	vector<pair<int, int> > meeting;
	vector<int> dp(N+1);
	int money, time;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &time, &money);
		meeting.push_back(make_pair(time, money));
	}

	for (int i = N-1; i >= 0; i--) {
		if (i + meeting[i].first > N) //일 x
			dp[i] = dp[i + 1];
		else //일 o
			dp[i] = max(dp[i + 1], meeting[i].second + dp[i + meeting[i].first]);
	}
	printf("%d\n", dp[0]);

	return 0;
}