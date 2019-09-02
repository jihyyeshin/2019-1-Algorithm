/*
그리디 알고리즘

결정해야 할 때, 그 순간에 가장 좋다고 생각하는 것을 선택하면서 답을 찾아감
그 때 그 때는 최적일지도 모르지만, 최종적으로는 최적이 아닐 수 있다.

https://www.acmicpc.net/problem/11047
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);//정수 vector을 만든다
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//입력 끝
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += k / a[i];//뒤에서 부터 순회
		k %= a[i];
	}
	cout << ans << '\n';
	return 0;
}