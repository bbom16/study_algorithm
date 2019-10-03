//2019.09.01
//samsung 1240
//단순 2진 암호코드
//단순 구현

#include <stdio.h>
#include <iostream>
#include <utility>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

int spyCode[50][100];
int pwdCode[9];

pair<int, int> lastOne;
map<int, int> pwdMap;

void settingMap() {
	pwdMap.insert(make_pair(3211, 0));
	pwdMap.insert(make_pair(2221, 1));
	pwdMap.insert(make_pair(2122, 2));
	pwdMap.insert(make_pair(1411, 3));
	pwdMap.insert(make_pair(1132, 4));
	pwdMap.insert(make_pair(1231, 5));
	pwdMap.insert(make_pair(1114, 6));
	pwdMap.insert(make_pair(1312, 7));
	pwdMap.insert(make_pair(1213, 8));
	pwdMap.insert(make_pair(3112, 9));
}

void findNum(int numArr[4], int i) {
	int totalNum = 0;
	for (int i = 0; i < 4; i++) {
		totalNum += numArr[i] * pow(10, (3 - i));
	}
	pwdCode[i] = pwdMap.find(totalNum)->second;
}

void findPwdCode() {
	stack<int> pwdStack;

	for (int i = 0; i < 56; i++) {
		pwdStack.push(spyCode[lastOne.first][lastOne.second - i]);
	}

	int numArr[4];
	int k;
	for (int i = 1; i <= 8; i++) {
		for (k = 0; k < 4; k++)
			numArr[k] = 0;

		bool chkZero = false;
		k = 0;
		for (int j = 0; j < 7; j++) {
			int topNum = pwdStack.top();
			pwdStack.pop();
			//처음 숫자가 0인 경우
			if (j == 0 && topNum == 0) {
				chkZero = true;
				numArr[k]++;
			}
			//1 -> 0 , 0 -> 1로 바뀌는 경우
			else if ((j != 0 && !chkZero && topNum == 0) || (chkZero && topNum == 1)) {
				chkZero = !chkZero;
				numArr[++k]++;
			}
			//바뀌지않는 경우
			else {
				numArr[k]++;
			}
		}
		findNum(numArr, i);
	}
}

bool checkCode() {
	findPwdCode();
	int oddSum = 0, evenSum = 0;
	for (int i = 1; i <= 8; i++){
		if (i % 2 == 0) 
			evenSum += pwdCode[i];
		else
			oddSum += pwdCode[i];
	}
	if ((oddSum * 3 + evenSum) % 10 == 0)
		return true;
	return false;
}

int main(int argc, char * argv[]) {
	int T;
	scanf("%d", &T);
	int width, hight;

	settingMap();
	
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &hight, &width );
		for (int i = 0; i < hight; i++) {
			for (int j = 0; j < width; j++) {
				scanf("%1d", &spyCode[i][j]);
				if (spyCode[i][j] == 1) {
					lastOne = make_pair(i, j);
				}
			}
		}
	
		bool chk = checkCode();
		int answer = 0;
		if (chk) {
			for (int i = 1; i <= 8; i++) {
				answer += pwdCode[i];
			}
		}
		printf("#%d %d\n", tc, answer);
	}
	return 0;
}