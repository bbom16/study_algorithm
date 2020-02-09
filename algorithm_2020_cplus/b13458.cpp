//2020.02.03
//boj 13458
//시험 감독 
//구현을 문제 해결
//총감독은 무조건 있어야해서 총 감독이 감독할 수 있는 명수를 빼고, 그 나머지에서 부감독이 감시할 수 있는 명수로 나눠서 그 값을 더해줘서 문제를 해결했다.
//문제는 long long 범위로 바꾼 거 까지는 생각했지만 printf로 출력할 때 형식지정자를 바꾸지않았다는 것,,,,(이거 때문에 한참 헤맸다,,)

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N, B, C;
vector<long long> people_num;
long long answer = 0;

int main(int agrc, char *argv[]) {	
	scanf("%d", &N);
	people_num.resize(N + 1);

	for (int i = 0; i < N; i++) {
		scanf("%d", &people_num[i]);
	}
	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		answer++;
		people_num[i] -= B;
		if (people_num[i] <= 0)
			continue;
		if (people_num[i] % C == 0) {
			answer += (people_num[i] / C);
		}
		else {
			answer += (people_num[i] / C + 1);
		}
	}
	
	printf("%lld\n", answer);

	return 0;
}