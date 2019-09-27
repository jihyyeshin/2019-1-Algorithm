/*
30 = 2*3*5
2의 배수: 0, 2, 4, 6, 8 ...
3의 배수: 3, 9, 27, ...
5의 배수: 0, 5, 5, ...
1. 이 때, 2와 5의 배수이려면 0으로 끝나야만 한다!
2. 3의 배수의 특징은 모든 숫자를 다 더해서 3의 배수가 된다면, 3의 배수인 것
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main() {
	/*
	// 입력
	int n, sum = 0, result = 0, count = 1;
	vector<int> a;
	bool is0 = false;
	cin >> n;
	while (n > 0) {
		if (n % 10 == 0) is0 = true;
		sum += (n % 10);
		a.push_back(n % 10);
		n /= 10;
	}
	cout << is0;
	cout << sum;
	if (sum / 3 && is0) {
		// 오름 차순으로 정렬
		sort(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++) {
			result += a[i] * count;
			count *= 10;
		}
		cout << result;
	}

	else cout << "-1";
	*/
//}

// 정수로 처리할 수 없는 문제 - 10^5개의 숫자로 구성되어있기 때문에, 문자열로 처리해야 한다!
// 또한 문자열로 처리하는 것이 훨씬 코드가 간단해짐
// 왜 ? 문자열 자체로 정렬할 수도 있고, 문자열의 부분을 가져올 수도 있기 때문에

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	// 문자열으로 입력받음
	string s;
	int sum = 0;
	cin >> s;
	sort(s.begin(), s.end());
	/* 범위 기반 for문
	array의 요소를 반복!
	*/
	for (char c:s)
		sum += (c - '0');
	if (s[0] == '0' && sum % 3 == 0) {
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	else cout << "-1\n";
	return 0;
}