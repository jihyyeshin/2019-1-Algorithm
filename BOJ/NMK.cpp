/*
최대 부분 증가 수열의 LIS길이 구하는 알고리즘 - 다이나믹 프로그래밍
D[i]=Max(D[j])+1

감소수열의 개수가 M개, MK를 넘을 수 없음, 
*/


#include <iostream>
#include <vector>
using namespace std;
int main() {

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	if (m + k - 1 <= n && n <= m + k) {
		for (int i = 0; i < n; i++)
			a[i] = i + 1;
		vector<int> g;
		g.push_back(0);
		g.push_back(k);
		n -= k;
		m -= 1;
		int gs = m == 0 ? 1 : n / m;
		int r = m == 0 ? 0 : m % m;
		for (int i = 0; i < m; i++) {
			g.push_back(g.back() + gs + (r > 0 ? 1 : 0));
			if (r > 0)
				r -= 1;
		
		}
		for (int i = 0; i < g.size() - 1; i++)
			reverse(a.begin() + g[i], a.begin() + g[i + 1]);
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
	else {
		cout << "-1\n";
	}
	return 0;
}