// 2019.07.28
// boj 4195
// ģ�� ��Ʈ��ũ
// union &  find 

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int > friendInfo; //map�� value ���� �ε����� ���
bool find_target;
int root[200001];
int nodeCnt[200001];

/* find -> ��� ����, root ã�� */
int find(int x) {
	if (root[x] == x)
		return x;
	else 
		return root[x] = find(root[x]);
}

/* union-> ã�� root ���ؼ� ���������� x�� y�� �θ�� ������ְ� ��� ���� return */
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

	/* cout, cin ��� �ӵ� ��� */
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