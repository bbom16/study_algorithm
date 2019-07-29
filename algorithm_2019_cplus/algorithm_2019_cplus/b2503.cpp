// 2019.07.29
// boj 2503
// 숫자 야구
// 브루트포스

#include <stdio.h>
#include <iostream>
using namespace std;

int numArr[1000];

void findNum(int query, int s, int b) {
	int q[3] = { query / 100, query / 10 % 10, query % 10 };
	int strike = 0, ball = 0;
	for (int i = 123; i < 1000; i++) {
		strike = 0; ball = 0;
		int exam[3] = { i / 100, i / 10 % 10,  i % 10, };
		if (exam[1] == 0 || exam[2] == 0 || exam[0] == exam[1] || exam[1] == exam[2] || exam[2] == exam[0]) continue;
		if (exam[0] == q[0]) strike++;
		if (exam[1] == q[1]) strike++;
		if (exam[2] == q[2]) strike++;
		if (q[0] == exam[1] || q[0] == exam[2]) ball++;
		if (q[1] == exam[0] || q[1] == exam[2]) ball++;
		if (q[2] == exam[0] || q[2] == exam[1]) ball++;

		if (s == strike && b == ball) numArr[i]++;
	}
	
}
	

int main(int argc, char * argv[]) {
	
	int N;
	cin >> N;

	int query, strike, ball;
	for (int i = 0; i < N; i++) {
		cin >> query >> strike >> ball;
		if (strike == 3) {
			cout << 1 << endl;
			return 0;
		}
		findNum(query, strike, ball);
	}
	
	int answer = 0;
	for (int i = 123; i < 1000; i++) {
		if (numArr[i] == N) answer++;
	}
	cout << answer << "\n";

	return 0;
}