/*
ATM 
오름차순(non-decreasing)으로 푸는 것이 정답 - S<=S'

greedy는 감을 잡는 것이 중요하다!
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	// 입력
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	// 오름차순으로 정렬
	sort(a.begin(), a.end());
	int sum = 0;
	int ans = 0;
	// 앞에서 부터 누적 합
	for (int i = 0; i < n; i++) {
		sum += a[i];
		ans += sum;
	}
	cout << ans << '\n';
	return 0;
}