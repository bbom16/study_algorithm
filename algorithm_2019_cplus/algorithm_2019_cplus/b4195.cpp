// 2019.07.28
// boj 4195
// 친구 네트워크
// union &  find 

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int > friendInfo; //map안 value 값을 인덱스로 계산
bool find_target;
int root[200001];
int nodeCnt[200001];

/* find -> 경로 압축, root 찾기 */
int find(int x) {
	if (root[x] == x)
		return x;
	else 
		return root[x] = find(root[x]);
}

/* union-> 찾은 root 비교해서 같지않으면 x를 y의 부모로 만들어주고 노드 개수 return */
int merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) {
		root[y] = x;
		nodeCnt[x] += nodeCnt[y];
		nodeCnt[y] = 1;
	}
	return nodeCnt[x];
}

int main(int argc, char * argv[]) {

	/* cout, cin 출력 속도 향상 */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, f;
	cin >> t;
	while (t--) {
		cin >> f;
		string friend1, friend2;
		int idx = 1;

		for (int i = 1; i <= f*2; i++) {
			root[i] = i;
			nodeCnt[i] = 1;
		}

		while (f--) {
			cin >> friend1 >> friend2;
			if (friendInfo.count(friend1) == 0)  
				friendInfo.insert(make_pair(friend1, idx++));
			if (friendInfo.count(friend2) == 0)
				friendInfo.insert(make_pair(friend2, idx++));
			
			cout << merge(friendInfo.find(friend1)->second, friendInfo.find(friend2)->second) << "\n";
		}
		friendInfo.clear();
	}
	return 0;
}