/*
재귀

k개가 있을 때 그 중 6개를 고르는 문제
k<=12, 2^12의 경우의 수
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto;// 함수가 고른 수
void solve(vector<int> &a, int index, int cnt) {
	if (cnt == 6) { // 6개 골랐으면 출력
		for (int num : lotto)
			cout << num;
		cout << '\n';
		return;
	}
	int n = a.size();
	if (n == index) return;
	lotto.push_back(a[index]);// index번째를 선택한 경우
	solve(a, index + 1, cnt + 1);
	lotto.pop_back();// index번째를 선택하지 않은 경우
	solve(a, index + 1, cnt);

}
int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		solve(a, 0, 0);
		cout << '\n';
	}
	return 0;
}