#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXIMUN_VALUE 9999999
vector<int> num_arr = { 0,0,1,1 };
int main(int argc, char * argv[]) {
	int N;
	scanf("%d", &N);
	
	for (int i = 4; i <= N; i++) {
		num_arr.push_back(MAXIMUN_VALUE);
		if (i % 3 == 0) {
			num_arr[i] = min(num_arr[i], num_arr[i / 3] + 1);
		}
		if (i % 2 == 0) {
			num_arr[i] = min(num_arr[i], num_arr[i / 2] + 1);
		}
		num_arr[i] = min(num_arr[i], num_arr[i - 1] + 1);
	}

	printf("%d\n", num_arr[N]);
	return 0;
}