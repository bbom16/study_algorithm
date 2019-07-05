// 2019.06.30
// swExpertAcademy 2819
// [S/W 문제해결 기본] 1일차 - Flatten 
// 그냥 sort 문제 

#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int total_dumped;
int boxes[101];

int diff_h;

int main(int argc, char * argv[]) {
	for (int t = 1; t <= 10; t++) {
		scanf("%d", &total_dumped);

		for (int i = 0; i < 100; i++) {
			scanf("%d", &boxes[i]);
		}
		

		while(total_dumped >= 0){
			sort(boxes, boxes+100, greater<int>());
			diff_h = boxes[0] - boxes[99];
			if (diff_h <= 1) break;
			boxes[0]--;
			boxes[99]++;
			total_dumped--;
		}

		printf("#%d %d\n", t, diff_h);
	}
	return 0;
}

