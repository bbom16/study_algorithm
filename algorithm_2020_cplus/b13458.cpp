//2020.02.03
//boj 13458
//���� ���� 
//������ ���� �ذ�
//�Ѱ����� ������ �־���ؼ� �� ������ ������ �� �ִ� ����� ����, �� ���������� �ΰ����� ������ �� �ִ� ����� ������ �� ���� �����༭ ������ �ذ��ߴ�.
//������ long long ������ �ٲ� �� ������ ���������� printf�� ����� �� ���������ڸ� �ٲ����ʾҴٴ� ��,,,,(�̰� ������ ���� ��̴�,,)

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