//2019.10.04
//boj 6603 
//로또
//조합, prev_permutation 이용

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(int agrc, char * argv[]) {
	int N;
	vector<int> num, combi;
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		num.resize(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
		}

		for (int i = 0; i < 6; i++)
			combi.push_back(1);
		for (int i = 0; i < N - 6; i++)
			combi.push_back(0);
		
		sort(num.begin(), num.end());

		while (1) {
			for (int i = 0; i < N; i++) {
				if (combi[i] == 1)
					printf("%d ", num[i]);
			}
			printf("\n");
			if (!prev_permutation(combi.begin(), combi.end()))
				break;
		}
		combi.clear();
		num.clear();
		printf("\n");
	}
	return 0;
}