// 선택하는 문젠데, 선택해야 하는 개수가 정해져있으면 순서로 풀 수 있음
// 1억개의 경우의 수면 1초
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));// 능력치 배열
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	vector<int> b(n);// 순열을 위한 배열
	for (int i = 0; i < n / 2; i++)
		b[i] = 1;
	sort(b.begin(), b.end());
	int ans = 2147483647;
	do
	{
		vector<int> first, second;
		for (int i = 0; i < n; i++) {
			if (b[i] == 0)
				first.push_back(i);
			else second.push_back(i);
		}
		int one = 0;
		int two = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				one += a[first[i]][first[j]];
				one += a[second[i]][second[j]];
			}
		}
		int diff = one - two;
		if (diff < 0) diff = -diff;
		if (ans > diff) ans = diff;
	} while (next_permutation(b.begin(), b.end()));
	cout << ans << '\n';
	return 0;
}