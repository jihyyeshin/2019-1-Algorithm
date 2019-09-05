/*
식에 괄호를 적절히 쳐서 식의 값을 최소로 만드는 문제
: -가 나오면, 항상 뒤의 식을 -로 만들 수 있음: 이 때 최소가 됨
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	// 입력 값을 받음
	string s;
	cin >> s;
	// num : 숫자, sign : 부호
	vector<int> num;
	vector<int> sign;
	// minus가 true인 경우, 그 값을 빼면 된다.
	bool minus = false;
	int cur = 0;
	// sign에 plus는 1, minus는 -1을 넣음
	// 처음에 1을 넣는 이유는, 맨 처음에는 +부호 없이 +를 의미하기 때문!
	sign.push_back(1);
	for (int i = 0; i < s.size(); i++) {
		// 문자 전체에 대하여 부호(p&m), 숫자를 구분하고 각각 sign, num에 넣음
		if (s[i] == '+' || s[i] == '-') {
			// 부호인 경우, 각 부호에 대한 값을 1, -1로 넣어준다
			if (s[i] == '+') {
				sign.push_back(1);
			}
			else {
				sign.push_back(-1);
			}
			// 부호가 들어오면 그 전까지 들어온 숫자를 num에 넣고 다시 숫자를 초기화 시킴!
			num.push_back(cur);
			cur = 0;
		}
		else {
			/*
			숫자인 경우, 숫자값을 넣어주되 1의 자리 수라는 보장이 없기 때문에
			십, 백 ... 등의 자리 수가 들어왔을 때를 처리하기 위해 만든 부분
			*/
			cur = cur * 10 + (s[i] - '0');
		}
	}
	num.push_back(cur);
	int ans = 0;
	minus = false;
	// 최솟값이 되도록 처리해주기 위한 과정 ! 
	for (int i = 0; i < num.size(); i++) {
		if (sign[i] == -1) {
			minus = true;
		}
		if (minus) {
			ans -= num[i];
		}
		else {
			ans += num[i];
		}
	}
	cout << ans << '\n';
	return 0;
}