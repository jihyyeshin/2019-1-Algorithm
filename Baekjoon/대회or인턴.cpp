/*
한 팀에 여2, 남1일 때, 몇 팀을 만들 수 있을까?
N+M>=k+3
N>=2
M>=1
이 조건이 만족될 경우에, 한 팀을 만들 수 있다.
따라서 이 조건이 만족된다면 N-=2, M-=1하고, 이 조건이 만족되지 않을 때 까지 반복!
*/
#include <iostream>
using namespace std;

int main() {
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	while (n + m >= k + 3 && n >= 2 && m >= 1) {
		ans += 1;
		n -= 2;
		m -= 1;
	}
	cout << ans << '\n';

	return 0;
}