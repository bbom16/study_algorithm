// 2019.08.02
// boj 6549
// 히스토그램에서 가장 큰 직사각형
// dfs-> 시간초과, 세그먼트 트리 + 분할정복

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> high;
vector<ll> tree;

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return -1;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	
	int leftNode = query(node * 2, start, mid, left, right);
	int rightNode = query(node * 2 + 1, mid + 1, end, left, right);

	if (leftNode == -1) return rightNode;
	if (rightNode == -1) return leftNode;

	return high[leftNode] <= high[rightNode] ? leftNode : rightNode;
}


ll solveArea(int left, int right, int n) {
	int minIndex = query(1, 0, n - 1, left, right);
	ll maxArea = (ll)high[minIndex] * (right - left + 1);
	if (left <= minIndex - 1) {
		ll ans = solveArea(left, minIndex - 1, n);
		maxArea = max(ans, maxArea);
	}
	if (minIndex + 1 <= right) {
		ll ans = solveArea(minIndex + 1, right, n);
		maxArea = max(ans, maxArea);
	}
	return maxArea;
}

ll init(int node, int start, int end) {
	if (start == end)
		return tree[node] = start;

	int mid = (start + end) / 2;

	int leftNode = init(node * 2, start, mid);
	int rightNode = init(node * 2 + 1, mid + 1, end);
	return tree[node] = high[leftNode] <= high[rightNode] ? leftNode : rightNode;
}

int main(int argc, char * argv[]) {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		high.resize(n + 1);
		tree.resize(n*4);

		for (int i = 0; i < n; i++) 
			scanf("%d", &high[i]);
		init(1, 0, n - 1);
		printf("%lld\n", solveArea(0, n - 1, n));

		high.clear();
		tree.clear();
	}
	return 0;
}