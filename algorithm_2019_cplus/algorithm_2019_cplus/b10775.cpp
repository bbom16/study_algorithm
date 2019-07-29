// 2019.07.29
// boj 10775
// 공항
// union &  find 

#include <stdio.h>
#include <iostream>
using namespace std;

int root[100001];

void init(int g) {
	for (int i = 1; i <= g; i++)
		root[i] = i;
}

int find(int g) {
	if (root[g] == g)
		return g;
	else
		return root[g] = find(root[g]);
}
int main(int argc, char * argv[]) {
	
	/* cout, cin 출력 속도 향상 */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int G, P;
	cin >> G >> P;

	init(G);

	int gate; 
	int cnt = 0;
	for (int i = 0; i < P; i++) {
		cin >> gate;
		int next = find(gate);
		if (next == 0) break;
		cnt++;
		root[gate] = find(next - 1);
		if (cnt == G) break;
	}
	cout << cnt << "\n";
	return 0;
}