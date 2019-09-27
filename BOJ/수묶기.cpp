/*
두 수를 적절히 묶어서 수열의 합을 최대로

: 최대를 만들기 위해서는, 큰수를 큰수끼리, 작은 수는 작은 수끼리
+) 양수는 큰 수끼리, 음수는 작은 수끼리
+) 예외
- 1+1>1*1이므로 1은 묶지 않음, 0도 묶지 않음
- 묶이지 않는 음수의 경우 0을 이용할 수 있음!!!
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	vector<int> plus;
	vector<int> minus;
	cin >> n;
	int zero = 0;
	int one = 0;
	// 입력 후, 처리를 따로 할 것들을 각각 나눈다!
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			one += 1;
		}
		else if(x > 0){
			plus.push_back(x);
		}
		else if (x < 0) {
			minus.push_back(x);
		}
		else {
			zero += 1;
		}
	}
	// 양, 음수를 각각 내림, 오름차순으로 정렬, 순서대로 묶기 위해!
	sort(plus.begin(), plus.end());
	reverse(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	if (plus.size() % 2 == 1) {
		// 양수의 개수가 짝수가 아닐 경우, 곱셈을 할 때 문제가 생기기 때문에,
		// 1을 곱해주기 위해 push back
		plus.push_back(1);
	}
	if (minus.size() % 2 == 1) {
		// 음수의 개수가 짝수가 아닐 경우, zero가 존재할 경우 곱해주기 위해 push back
		minus.push_back(zero > 0 ? 0 : 1);
	}
	int ans = one; // 1의 개수만큼 더해줌
	// 그 후 양수는 양수끼리(큰 순서), 음수는 음수끼리(작은 순서)로 곱함
	for (int i = 0; i < plus.size(); i += 2) {
		ans += plus[i] * plus[i + 1];
	}
	for (int i = 0; i < minus.size(); i += 1) {
		ans += minus[i] * minus[i + 1];
	}
	cout << ans << '\n';
	return 0;
}